/*
ID: ctzsm2
PROG: lgame
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int w[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
char dict[40005][8], s[8];
int dw[40005], l[40005], dc = 0, sw, tw;
int ss[26], st[40005][26], ans[40005][2];
int main() {
	freopen("lgame.in", "r", stdin);
	freopen("lgame.out", "w", stdout);
	FILE *fp = fopen("lgame.dict", "r");
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) sw += w[s[i] - 'a'];
	for (int i = 0; i < n; ++i) ss[s[i] - 'a'] ++;
	while (true) {
		fscanf(fp, "%s", dict[dc]);
		if (dict[dc][0] == '.') break;
		l[dc] = strlen(dict[dc]);
		for (int i = 0; i < l[dc]; ++i) dw[dc] += w[dict[dc][i] - 'a'];
		for (int i = 0; i < l[dc]; ++i) st[dc][dict[dc][i] - 'a'] ++;
		bool ok = true;
		for (int i = 0; i < 26; ++i) if (st[dc][i] > ss[i]) {
			ok = false;
			break;
		}
		if (dw[dc] > sw) ok = false;
		if (!ok) {
			for (int i = 0; i < 26; ++i) st[dc][i] = 0;
			dw[dc] = 0;
			continue;
		}
		dc++;
	}
	fclose(fp);
	int ac = 0, tw = 0;
	for (int i = 0; i < dc; ++i) {
		if (tw <= dw[i]) {
			if (tw < dw[i]) ac = 0;
			ans[ac][0] = i, ans[ac][1] = -1;
			tw = dw[i], ac++;
		}
		for (int j = i + 1; j < dc; ++j) {
			if (dw[i] + dw[j] > sw) continue;
			bool ok = true;
			for (int k = 0; k < 26; ++k) {
				if (st[i][k] + st[j][k] > ss[k]) {
					ok = false;
					break;
				}
			}
			if (!ok) continue;
			if (tw <= dw[i] + dw[j]) {
				if (tw < dw[i] + dw[j]) ac = 0;
				ans[ac][0] = i, ans[ac][1] = j;
				tw = dw[i] + dw[j], ac++;
			}
		}
	}
	printf("%d\n", tw);
	for (int i = 0; i < ac; ++i)
		if (ans[i][1] == -1) printf("%s\n", dict[ans[i][0]]);
		else printf("%s %s\n", dict[ans[i][0]], dict[ans[i][1]]);
	return 0;
}
