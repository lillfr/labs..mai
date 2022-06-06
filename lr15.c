#include <stdio.h>
void scanmatr(int n, int m[n][n]) {
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++) 
            scanf("%d", &m[i][j]);
}
void printmatr(int n, int m[n][n]) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) 
            printf("%d ", m[i][j]);
        putchar('\n');
    }
}
void shift(int n, int m[n][n]) {
    int t = m[n/2][(n-1)/2];
    for (int k = n; k > 1; k--) {
        if (k % 2 == 0) {
            for (int j = k/2-1; j < n - k/2; j++) 
                m[n-k/2][j] = m[n-k/2][j+1];
            for (int i = n - k/2; i > k/2-1; i--)
                m[i][n-k/2] = m[i-1][n-k/2];
        } else {
            for (int j = n - k/2-1; j > k/2 - 1; j--) 
                m[k/2][j] = m[k/2][j-1];
            for (int i = k/2; i < n-k/2; i++) 
                m[i][k/2-1] = m[i+1][k/2-1];
        }
    }
    for (int j = n-1; j>0; j--) 
        m[0][j] = m[0][j-1];
    m[0][0] = t;
}
int main() {
    int n; 
    while (scanf("%d", &n) == 1) {
        int m[n][n];
        scanmatr(n, m);
        shift(n, m);
        putchar('\n');
        printmatr(n, m);
        putchar('\n');
    }
    return 0;
}
