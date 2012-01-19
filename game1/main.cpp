/*
ID: ctzsm2
PROG: game1
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n,a[100],sum = 0;
int dp[100][100];
int dfs(int i,int j){
	if(j < i) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int t = a[i] + min(dfs(i+2,j),dfs(i+1,j-1));
	t = max(t,a[j] + min(dfs(i,j-2),dfs(i+1,j-1)));
	dp[i][j] = t;
	return dp[i][j];
}
int main(int argc, char** argv) {
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
	for(int i = 0;i < n; ++i) sum += a[i];
	for(int i = 0;i < n; ++i) dp[i][i] = a[i];
	int ans = dfs(0,n-1);
	printf("%d %d\n",ans,sum - ans);
	return 0;
}

//Compiling...
//Compile: OK
//
//Executing...
//   Test 1: TEST OK [0.000 secs, 3084 KB]
//   Test 2: TEST OK [0.000 secs, 3084 KB]
//   Test 3: TEST OK [0.000 secs, 3084 KB]
//   Test 4: TEST OK [0.000 secs, 3084 KB]
//   Test 5: TEST OK [0.000 secs, 3084 KB]
//   Test 6: TEST OK [0.000 secs, 3084 KB]
//   Test 7: TEST OK [0.000 secs, 3084 KB]
//   Test 8: TEST OK [0.000 secs, 3084 KB]
//   Test 9: TEST OK [0.000 secs, 3084 KB]
//   Test 10: TEST OK [0.000 secs, 3084 KB]
//   Test 11: TEST OK [0.000 secs, 3084 KB]
//   Test 12: TEST OK [0.000 secs, 3084 KB]
//   Test 13: TEST OK [0.000 secs, 3084 KB]
//   Test 14: TEST OK [0.000 secs, 3084 KB]
//   Test 15: TEST OK [0.000 secs, 3084 KB]
//   Test 16: TEST OK [0.000 secs, 3084 KB]
//
//All tests OK.
//YOUR PROGRAM ('game1') WORKED FIRST TIME!  That's fantastic
//-- and a rare thing.  Please accept these special automated
//congratulations.