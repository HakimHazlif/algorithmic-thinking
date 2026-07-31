#include <stdio.h>
#include <stdlib.h>


#define MAX_LINES 100000
#define ARMS 6

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)


unsigned long oaat(char *key, unsigned long len, unsigned long bits) {
    unsigned long hash, i;

    for (hash = 0, i = 0; i < len; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash & hashmask(bits);
}

void solve(int snowflakes[], int n);

int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}


int main(void) { 
    int n;
    static int snowflakes[MAX_LINES];

    scanf("%d", &n);

    if (n < 1 || n > MAX_LINES) {
        printf("The number of snowflakes should be more than 0 or less than %d\n", MAX_LINES + 1);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int snowflake[ARMS] = {};

        for (int j = 0; j < ARMS; j++) {
            int arm;
            scanf("%d", &arm);
            if (arm < 0 || arm > 10000001) {
                printf("The length of snowflake's arm must be more than or equal 0 or less than or eqaul 10,000,000");
                return 1;
            }

            snowflake[j] = arm;
        }

        qsort(snowflake, ARMS, sizeof(int), compare);
        snowflakes[i] = oaat((char *)snowflake, sizeof(snowflake), 17);
        printf("%d\n", snowflakes[i]);
    }

    solve(snowflakes, n);

    return 0;
}



void solve(int snowflakes[], int n) {
    qsort(snowflakes, n, sizeof(int), compare);

    for (int i = 0; i < n - 1; i++) {
        printf("%d == %d\n", snowflakes[i], snowflakes[i+1]);
        if (snowflakes[i] == snowflakes[i+1]) {
            printf("Twin snowflakes found.\n");
            return;
        }
    }

    printf("No two snowflakes are alike.\n");
}




// [12454785, 14578864, 205487648, 12454785]