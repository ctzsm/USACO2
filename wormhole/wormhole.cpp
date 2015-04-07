/*
ID: ctzsm2
PROG: wormhole
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n;
bool ch[12], f[12];
int x[12], y[12], p[12], ans = 0;
int r[12];
bool check() {
	for (int i = 0; i < n; ++i) {
		memset(f, false, sizeof f);
		int x = i;
		while (!f[x]) {
			f[x] = true;
			if (r[x] == -1) break;
			x = p[r[x]];
			if (f[x]) return true;
		}
	}
	return false;
}
void dfs(int d, int i, int u) {
	if (d == n) {
		if (check()) ans++;
		return;
	}
	if (d & 1) {
		for (int j = i; j < n; ++j) {
			if (ch[j]) continue;
			p[u] = j;
			p[j] = u;
			ch[j] = true;
			dfs(d + 1, 0, j);
			ch[j] = false;
		}
	} else {
		for (int j = 0; j < n; ++j) {
			if (ch[j]) continue;
			ch[j] = true;
			dfs(d + 1, j + 1, j);
			ch[j] = false;
			break;
		}
	}
}
int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	scanf("%d", &n);
	memset(r, -1, sizeof r);
	for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (y[i] == y[j] && x[j] > x[i]) {
				if (r[i] == -1 || x[j] < x[r[i]])
					r[i] = j;
			}
		}
	dfs(0, 0, -1);
	printf("%d\n", ans);
	return 0;
}
