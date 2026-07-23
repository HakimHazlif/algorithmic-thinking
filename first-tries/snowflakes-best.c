#include <stdio.h>
#include <stdlib.h>


#define MAX_LINES 100000
#define ARMS 6

typedef struct Snowflake_Node {
    int snowflake[ARMS];
    struct  Snowflake_Node *next;   
} Snowflake_Node;

int get_the_start_point(int first[], int second[]);
int check_towords(int first[], int second[], int start_point, char dir);
int are_two_snowflakes_identicals(int first[], int second[]);
void solve(Snowflake_Node *snowflakes[], int *indexes, int n);
void printSnowflake(int snowflake[], int lineNum);



int sum_elements(int snowflake[ARMS]) {
    int code = 0;
    for (int i = 0; i < ARMS; i++) {
        code+= snowflake[i];
    }
    return code % MAX_LINES;
    // To avoid storing very large integers,
    // even if two sums become equal after exceeding MAX_LINES
    // (for example, 100006 % 100000 == 6 and 6 % 100000 == 6),
    // we will still use the regular comparisons.
}

int main() {
    static Snowflake_Node *snowflakes[MAX_LINES] = {NULL}; // snowflakes_list is not a linked list itself. It is an array of pointers, where each pointer can point to the head of a linked list.
    Snowflake_Node *snow;
    int i, n, snowflake_code;
    int *code_indexes = (int *)malloc(n * sizeof(int));

     if (code_indexes == NULL) {
        fprintf(stderr, "malloc error for code_indexes\n");
        return 1;
    }

    if (scanf("%d", &n) != 1) {
        printf("Error reading input\n");
        free(code_indexes);
        return 1;
    }

    if (n < 1 || n > MAX_LINES) {
        printf("The number of snowflakes should be more than 0 or less than %d\n", MAX_LINES + 1);
        free(code_indexes);
        return 1;
    }

    for (i = 0; i < n; i++) {
        snow = malloc(sizeof(Snowflake_Node));
        if (snow == NULL) {
            fprintf(stderr, "malloc error\n");
            free(code_indexes);
            exit(1);
        }
        for (int j = 0; j < ARMS; j++) {
            scanf("%d", &snow->snowflake[j]);
        }

        snowflake_code = sum_elements(snow->snowflake); // ex: [1,3,4,5,8,8] => 29
        snow->next = snowflakes[snowflake_code]; 
        // snow->next = NULL, because The new node's `next` pointer is assigned the current head of the linked list stored at this index.
        // Initially, all elements of `snowflakes` are NULL because the array was
        // initialized with {NULL}. Therefore, if this is the first snowflake with this code (for example, index 29), snow->next will be NULL.
        // If another snowflake with the same code already exists, then
        // snowflakes[snowflake_code] contains the address of the current head node.
        // In that case, the new node's `next` pointer will point to the existing list, preserving the previously stored snowflakes.
        snowflakes[snowflake_code] = snow; 
        // The new node becomes the new head of the linked list at this index.
        // Example:
        // Before:
        // snowflakes[29] -> [1,3,4,5,8,8] -> NULL
        // After inserting another snowflake with code 29:
        // snowflakes[29] -> [new snowflake] -> [1,3,4,5,8,8] -> NULL
        // This works because the previous head was saved in `snow->next` before replacing the pointer stored in the array.

        code_indexes[i] = snowflake_code;
    }

    
    solve(snowflakes, code_indexes, n);

    free(code_indexes);
    return 0;
}

int get_the_start_point(int first[], int second[]) {
    for (int i = 0; i < ARMS; i++) {
        if (first[0] == second[i]) {
            return i;
        }
    }

    return -1;
}


int check_towords(int first[], int second[], int start_point, char dir) {
    int pos = start_point;
    for (int i = 0; i < ARMS; i++) {
        if (first[i] != second[pos]) return 0;
        if (dir == 'r') {
            pos = (pos + 1) % ARMS;
        } else {
            pos = (pos + ARMS - 1) % ARMS;
        }
    }

    return 1;
}

int are_two_snowflakes_identicals(int first[], int second[]) {
    int start_point = get_the_start_point(first, second);

    if (start_point == -1) return 0;
          
    return check_towords(first, second, start_point, 'r') || check_towords(first, second, start_point, 'l');
}

// (n(n - 1))/2 
// In the worst case with 100,000 line the amount of operations is 4,999,950,000 
void solve(Snowflake_Node *snowflakes[], int *indexes, int n) {
    for (int i = 0; i < n; i++) {
        int index = indexes[i];
        Snowflake_Node *current = snowflakes[index];

        while (current && current->next)
        {
            Snowflake_Node *compare = current->next; 
            while (compare)
            {
                if (are_two_snowflakes_identicals(current->snowflake, compare->snowflake)) {
                    printf("Twin snowflakes found.\n");
                    return;
                }
                compare = compare->next;
            }
            
            /* code */
            current = current->next; 
        }
        
    }

    printf("No two snowflakes are alike.\n");
}


void printSnowflake(int snowflake[], int lineNum) {
    printf("Line %d: [ ", lineNum);
    for (int j = 0; j < ARMS; j++) {
        printf("%d, ", snowflake[j]);
    }
    printf("]\n");
};



// [5,6,2,4,9,3] -> [1,3,4,5,8,8] -> [9,9,5,1,2,3] -> NULL