/*
ID: ctzsm2
PROG: shuttle
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
int s[500] = {1}, p = 1;
int main() {
	freopen("shuttle.in", "r", stdin);
	freopen("shuttle.out", "w", stdout);
	scanf("%d", &n);
	int sign = 1;
	for (int i = 1; i < n; ++i, sign *= -1) {
		for (int j = 0; j < i; ++j) s[p++] = sign * 2;
		s[p++] = sign;
	}
	for (int i = 0; i < n; ++i) s[p++] = sign * 2;
	sign *= -1;
	for (int i = n - 1; i >= 1; --i, sign *= -1) {
		s[p++] = sign;
		for (int j = 0; j < i; ++j) s[p++] = sign * 2;
	}
	s[p++] = sign;
	int g = n - 1;
	for (int i = 0; i < p - 1; ++i)
		printf("%d%c", (g += s[i]), (i + 1) % 20 == 0 ? '\n' : ' ');
	printf("%d\n", (g += s[p - 1]));
	return 0;
}
