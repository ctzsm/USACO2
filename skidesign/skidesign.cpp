/*
ID: ctzsm2
PROG: skidesign
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n, a[1005];
int main() {
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int ans = 100000000;
	for (int i = 0; i <= 100; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j] < i) sum += (a[j] - i) * (a[j] - i);
			if (a[j] > i + 17) sum += (a[j] - 17 - i) * (a[j] - 17 - i);
		}
		ans = std::min(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}
