#include <stdio.h>


#define SIZE 100000


void identify_identical(int values[][6], int n);
int indentical_right(int snow1[], int snow2[], int start);
int indentical_left(int snow1[], int snow2[], int start);
int are_identical(int snow1[], int snow2[]);

int main() {
    static int snowflakes[SIZE][6];

    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) scanf("%d", &snowflakes[i][j]);
    }

    identify_identical(snowflakes, n);
   
    return 0;
}


void identify_identical(int values[][6], int n) {  
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (are_identical(values[i], values[j])) {
                printf("Twin integers found.\n");
                return;
            }
        }
    }

    printf("No two integers are alike.\n");
}


int indentical_right(int snow1[], int snow2[], int start) {
    int offset;
    for (offset = 0; offset < 6; offset++) {
        if (snow1[offset] != snow2[(start + offset) % 6]) return 0;
    }
    return 1;
}


int indentical_left(int snow1[], int snow2[], int start) {
    int offset, snow2_index;

    for (offset = 0; offset < 6; offset++){
        snow2_index = start - offset;
        if (snow2_index < 0) snow2_index = snow2_index + 6;
        
        if (snow1[offset] != snow2[snow2_index]) return 0;
    }

    return 1;
}

// 6 * (6 + 6) 
int are_identical(int snow1[], int snow2[]) {
    int start;
    for (start = 0 ; start < 6; start++) {
        if (indentical_right(snow1, snow2, start)) return 1;
        if (indentical_left(snow1, snow2, start)) return 1;
    }

    return 0;
}


