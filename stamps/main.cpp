/*
ID: ctzsm2
PROG: stamps
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int K,N;
int stamp[205];
int cnt[2000005];
bool flag = false;
int main(int argc, char** argv) {
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	scanf("%d%d",&N,&K);
	for(int i = 0;i < K; ++i) scanf("%d",&stamp[i]);
	sort(stamp,stamp+K);
	int m = stamp[K-1] * N;
	memset(cnt,0x7f,(m+2)*sizeof(int));cnt[0] = 0;
	for(int i = 1;i <= m; ++i){
		for(int j = 0;j < K; ++j){
			if(i < stamp[j]) continue;
			cnt[i] = min(cnt[i],cnt[i-stamp[j]]+1);
		}
		if(cnt[i] > N){
			flag = true;
			printf("%d\n",i-1);
			break;
		}
	}
	if(!flag) printf("%d\n",m);
	return 0;
}

//Compiling...
//Compile: OK
//
//Executing...
//   Test 1: TEST OK [0.000 secs, 10860 KB]
//   Test 2: TEST OK [0.000 secs, 10860 KB]
//   Test 3: TEST OK [0.000 secs, 10860 KB]
//   Test 4: TEST OK [0.000 secs, 10860 KB]
//   Test 5: TEST OK [0.000 secs, 10860 KB]
//   Test 6: TEST OK [0.000 secs, 10860 KB]
//   Test 7: TEST OK [0.000 secs, 10860 KB]
//   Test 8: TEST OK [0.000 secs, 10860 KB]
//   Test 9: TEST OK [0.000 secs, 10860 KB]
//   Test 10: TEST OK [0.065 secs, 10860 KB]
//   Test 11: TEST OK [0.389 secs, 10860 KB]
//   Test 12: TEST OK [0.119 secs, 10860 KB]
//   Test 13: TEST OK [0.000 secs, 10860 KB]
//
//All tests OK.
//Your program ('stamps') produced all correct answers!  This is your
//submission #5 for this problem.  Congratulations!
