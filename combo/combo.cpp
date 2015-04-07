/*
ID: ctzsm2
PROG: combo
LANG: C++
*/
#include <cstdio>

int n, f[3], m[3], d[3];
int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) scanf("%d", &f[i]);
	for (int i = 0; i < 3; ++i) f[i] --;
	for (int i = 0; i < 3; ++i) scanf("%d", &m[i]);
	for (int i = 0; i < 3; ++i) m[i] --;
	int ans = 0;
	for (d[0] = 0; d[0] < n; ++d[0]) 
		for (d[1] = 0; d[1] < n; ++d[1])
			for (d[2] = 0; d[2] < n; ++d[2]) {
				bool flag = true;
				for (int i = 0; i < 3; ++i)
					if ((d[i] - f[i] + n) % n > 2 && (f[i] - d[i] + n) % n > 2) {
						flag = false;
						break;
					}
				if (flag) {
					ans ++;
					continue;
				}
				flag = true;
				for (int i = 0; i < 3; ++i)
					if ((d[i] - m[i] + n) % n > 2 && (m[i] - d[i] + n) % n > 2) {
						flag = false;
						break;
					}
				if (flag)
					ans++;
			}
	printf("%d\n", ans);
	return 0;
}