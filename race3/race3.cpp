/*
ID: ctzsm2
PROG: race3
LANG: C++
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<int> adj[105], ans1, ans2;
int n, x, visited[105];
bool flag;
bool dfs(int u, int g = 1) {
	visited[u] = g;
	bool res = false;
	if (u == n - 1) return true;
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (visited[v] == 1) flag = false;
		if (visited[v]) continue;
		res |= dfs(v, g);
	}
	return res;
}
int main() {
	freopen("race3.in", "r", stdin);
	freopen("race3.out", "w", stdout);
	for (; ; ++n) {
		scanf("%d", &x);
		if (x == -1) break;
		while (x != -2) {
			adj[n].push_back(x);
			scanf("%d", &x);
		}
	}
	for (int i = 1; i < n - 1; ++i) {
		memset(visited, 0, sizeof visited);
		visited[i] = 1;
		if (!dfs(0)) {
			ans1.push_back(i);
			flag = true;
			dfs(i, 2);
			if (flag) ans2.push_back(i);
		}
	}
	printf("%d", (int)ans1.size());
	for (int i = 0; i < (int)ans1.size(); ++i) printf(" %d", ans1[i]);
	printf("\n%d", (int)ans2.size());
	for (int i = 0; i < (int)ans2.size(); ++i) printf(" %d", ans2[i]);
	printf("\n");
	return 0;
}