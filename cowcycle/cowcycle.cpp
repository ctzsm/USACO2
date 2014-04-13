/*
ID: ctzsm2
PROG: cowcycle
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int F, R, F1, F2, R1, R2;
double cur[51], d[51], ans, f[6], af[6], r[11], ar[11];
void dfsr(int start, int end, int depth) {
	if (depth > R) {
		if ((f[F] / r[1]) / (f[1] / r[R]) < 3.0) return;
		int k = 0;
		for (int i = 1; i <= F; ++i) 
			for (int j = 1; j <= R; ++j)
				cur[k++] = f[i] / r[j];
		std::sort(cur, cur + k);
		double sum = 0;
		for (int i = 1; i < k; ++i) {
			d[i] = cur[i] - cur[i - 1];
			sum += d[i];
		}
		double mean = sum / (double)(k - 1), tans = 0;
		for (int i = 1; i < k; ++i) 
			tans += (d[i] - mean) * (d[i] - mean);
		tans = tans / (double)(k - 1);
		if (tans < ans) {
			memcpy(af, f, (F + 1) * sizeof(double));
			memcpy(ar, r, (R + 1) * sizeof(double));
			ans = tans;
		}
		return;
	}
	for (int i = start; i <= end; ++i) {
		r[depth] = i;
		dfsr(i + 1, R2 - R + depth + 1, depth + 1);
	}
}
void dfsf(int start, int end, int depth) {
	if (depth > F) {
		dfsr(R1, R2 - R + 1, 1); 
		// for (int i = 1; i <= F; ++i) printf("%0.0f ", f[i]); printf("\n");
		return;
	}
	for (int i = start; i <= end; ++i) {
		f[depth] = i;
		dfsf(i + 1, F2 - F + depth + 1, depth + 1);
	}
}
int main() {
	freopen("cowcycle.in", "r", stdin);
	freopen("cowcycle.out", "w", stdout);
	scanf("%d%d%d%d%d%d", &F, &R, &F1, &F2, &R1, &R2);
	ans = 1e200;
	dfsf(F1, F2 - F + 1, 1);
	for (int i = 1; i < F; ++i) printf("%0.0f ", af[i]);
	printf("%0.0f\n", af[F]);
	for (int i = 1; i < R; ++i) printf("%0.0f ", ar[i]);
	printf("%0.0f\n", ar[R]);
	return 0;
}