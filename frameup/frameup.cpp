/*
ID: ctzsm2
PROG: frameup
LANG: C++
*/
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int H, W, C;
char s[35][35];
bool visited[26], dv[26];
int x[26][2], y[26][2];
vector<int> adj[26];
int in[26];
bool remove(int c) {
	vector<int> prev;
	for (int i = x[c][0]; i <= x[c][1]; ++i) {
		for (int j = 0; j < 2; ++j) {
			int d = s[y[c][j]][i] - 'A';
			if (d == c) continue;
			if (!visited[d]) return false;
			prev.push_back(d);
		}
	}
	for (int i = y[c][0]; i <= y[c][1]; ++i) {
		for (int j = 0; j < 2; ++j) {
			int d = s[i][x[c][j]] - 'A';
			if (d == c) continue;
			if (!visited[d]) return false;
			prev.push_back(d);
		}
	}
	sort(prev.begin(), prev.end());
	prev.resize((int)(unique(prev.begin(), prev.end()) - prev.begin()));
	for (int i = 0; i < (int)prev.size(); ++i) {
		adj[c].push_back(prev[i]);
		in[prev[i]] ++;
	}
	return true;
}
char ans[27];
void dfs(int d) {
	if (d == C) {
		printf("%s\n", ans);
		return;
	}
	for (int i = 0; i < 26; ++i) {
		if (x[i][0] == H + W) continue;
		if (!in[i] && !dv[i]) {
			ans[d] = i + 'A';
			for (int j = 0; j < (int)adj[i].size(); ++j) in[adj[i][j]] --;
			dv[i] = true;
			dfs(d + 1);
			dv[i] = false;
			for (int j = 0; j < (int)adj[i].size(); ++j) in[adj[i][j]] ++;
		}
	}
}
int main() {
	freopen("frameup.in", "r", stdin);
	freopen("frameup.out", "w", stdout);
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; ++i) scanf("%s", s[i]);
	for (int i = 0; i < 26; ++i) x[i][0] = y[i][0] = H + W;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			if (isalpha(s[i][j])) {
				int c = s[i][j] - 'A';
				x[c][0] = min(x[c][0], j);
				y[c][0] = min(y[c][0], i);
				x[c][1] = max(x[c][1], j);
				y[c][1] = max(y[c][1], i);
			}
	for (int i = 0; i < 26; ++i)
		if (x[i][0] != H + W) C++;
	while (true) {
		bool flag = true;
		for (int i = 0; i < 26; ++i) {
			if (x[i][0] == H + W) continue;
			if (visited[i]) continue;
			visited[i] = remove(i);
			flag = false;
		}
		if (flag) break;
	}
	dfs(0);
	return 0;
}
