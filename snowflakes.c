#include <stdio.h>

#define MAX_LINES 100000
#define ARMS 6

int get_the_start_point(int first[ARMS], int second[ARMS]);
int  check_towords(int first[], int second[], int start_point, char dir);
int are_two_snowflakes_identicals(int first[ARMS], int second[ARMS]);
int solve(int snowflakes[][ARMS], int n);
void printSnowflake(int snowflake[ARMS], int lineNum);

int main() {
    int n;
    int snowflakes[MAX_LINES][ARMS];

    scanf("%d", &n);

    if (n < 1 || n > MAX_LINES) {
        printf("The number of snowflakes should be more than 0 or less than %d\n", MAX_LINES + 1);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ARMS; j++) {
            int arm;
            scanf("%d", &arm);
            if (arm < 0 || arm > 10000001) {
                printf("The length of snowflake's arm must be more than or equal 0 or less than or eqaul 10,000,000");
                return 1;
            }

            snowflakes[i][j] = arm;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     printSnowflake(snowflakes[i], i+1);
    // }

    solve(snowflakes, n);

    return 0;
}


int get_the_start_point(int first[ARMS], int second[ARMS]) {

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

int are_two_snowflakes_identicals(int first[ARMS], int second[ARMS]) {
    int start_point = get_the_start_point(first, second);

    if (start_point == -1) return 0;
        
    return check_towords(first, second, start_point, 'r') || check_towords(first, second, start_point, 'l');
}


int solve(int snowflakes[][ARMS], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
          
            if (are_two_snowflakes_identicals(snowflakes[i], snowflakes[j])) {
                printf("Twin snowflakes found.\n");
                return 0;
            }
        }
    }

    printf("No two snowflakes are alike.\n");
    return 0;
}


void printSnowflake(int snowflake[ARMS], int lineNum) {
    printf("Line %d: [ ", lineNum);
    for (int j = 0; j < ARMS; j++) {
        printf("%d, ", snowflake[j]);
    }
    printf("]\n");
};


// [ 12, 5, 18, 5, 12, 5, ]
// [ 12, 5, 18, 5, 12, 5, ]
