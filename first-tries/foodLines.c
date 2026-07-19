#include <stdio.h>

#define MAX_LINES 100

int shortest_line_indx(int lines[], int n) {
    int shortest = 0;
    // 1. find the shortest line
    for (int j = 0; j < n; j++) {
        shortest = (lines[j] < lines[shortest]) ? j : shortest;
    }

    return shortest;
}

int solveFoodLines(int lines[], int n, int m) {

    for(int i = m; i > 0; i--) {
        int shortest_index = shortest_line_indx(lines, n);
        // 2. print this line
        printf("%d\n", lines[shortest_index]);
        // 3. add one to this line
        lines[shortest_index]++;
    }
}

int main(void) {
    int lines[MAX_LINES];
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &lines[i]);
    }

    printf("The number of lines is: %d\n", n);
    printf("How many people arrived: %d\n", m);
    printf("The lines array: [ ");
    for (int i =0; i < n; i++) {
        printf("%d ", lines[i]);
    }
    printf("]\n");
    printf("output\n");
    solveFoodLines(lines, n, m);

    return 0;
}