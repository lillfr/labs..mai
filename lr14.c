#include <stdio.h>
#include <stdbool.h>
const int maxn = 100;
int abs(int a) {
	if (a < 0) a = -a;
	return a;
}
int main() {
	int m[maxn][maxn];
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &m[i][j]);
	int i = n-1, j = n-1;
	int l = 0;
	while (true) {
		int i2 = i, j2 = j;
		for (int k = 0; k <= abs(i2 -j2); ++k) {
			printf("%d ", m[i][j]);
			if (k != abs(i2 - j2)) {
				if (l % 2 == 0) {
					i += 1;
					j -= 1;
				} else {
					i -= 1;
					j += 1;
				}
			}
		}
		l += 1;
		if (l % 2 == 0) {
			if (i != 0) i -= 1;
			else j -= 1;
		} else {
			if (j != 0) j -= 1;
			else i -= 1;
		}
		if (l == 2*n-1) break;
	}
	putchar('\n');
	return 0;
}
