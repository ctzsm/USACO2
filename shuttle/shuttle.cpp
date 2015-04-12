/*
ID: ctzsm2
PROG: shuttle
LANG: C++
*/
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int ds[] = {-2, -1, 1, 2};
int n, ac = 0;
int ans[500];
map<pair<int, short>, pair<int, short> > h;
pair<int, short> start, goal;
queue<pair<int, short> > q;
int swapBit(int status, int i, int j) {
	int si = (status & (1 << i)) > 0, sj = (status & (1 << j)) > 0;
	return status - (si << i) - (sj << j) + (sj << i) + (si << j);
}
void debug(int status) {
	for (int i = 0; i <= 2 * n; ++i)
		printf("%d", (status & (1 << i)) > 0);
	printf("\n");
}
int main() {
	freopen("shuttle.in", "r", stdin);
	// freopen("shuttle.out", "w", stdout);
	scanf("%d", &n);
	start = make_pair((1 << n) - 1, n);
	goal = make_pair(0, n - (n & 1));
	for (int i = (n & 1); i <= 2 * n; i += 2) goal.first |= (1 << i);
	if (n % 2 == 0) goal.first -= (1 << n);
	h[start] = make_pair(-1, -1);
	q.push(start);
	debug(start.first);
	debug(goal.first);
	// return 0;
	while (!q.empty()) {
		pair<int, short> now = q.front(); q.pop();
		bool found = false;
		for (int i = 0; i < 4; ++i) {
			short ns = now.second + ds[i];
			if (ns < 0 || ns > 2 * n) continue;
			pair<int, short> nst = make_pair(swapBit(now.first, now.second, ns), ns);
			if (h.find(nst) == h.end()) {
				h[nst] = now;
				q.push(nst);
			}
			if (nst == goal) {
				found = true;
				break;
			}
		}
		if (found) break;
	}
	pair<int, short> now = goal;
	while (true) {
		if (now == start) break;
		ans[ac++] = now.second;
		now = h[now];
	}
	printf("%d %d\n", (int)h.size(), ac);
	int j = 0;
	for (int i = ac - 1; i >= 0; --i, ++j)
		printf("%d%c", ans[i] + 1, (j + 1) % 20 == 0 ? '\n' : ' ');
	for (int i = (n & 1) ^ 1; i < ac; ++i, ++j)
		printf("%d%c", 2 * n + 1 - ans[i], (j + 1) % 20 == 0 ? '\n' : ' ');
	printf("%d\n", n + 1);
	return 0;
}
