/*
ID: ctzsm2
PROG: nocows
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

const int mod = 9901;
int N,K;
int ans[200][100];
void solve(){
	for(int i = 1;i <= K; ++i) ans[1][i] = 1;
	for(int i = 3;i <= N; ++i){
		for(int j = 1;j <= K; ++j){
			ans[i][j] = 0;
			for(int k = 1;k <= i - 2; ++k){
				ans[i][j] += (ans[k][j-1]*ans[i-1-k][j-1]);
			}
			ans[i][j] %= mod;
		}
	}
	printf("%d\n",(ans[N][K] - ans[N][K-1] + mod) % mod);
}
int main(int argc, char** argv) {
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	scanf("%d%d",&N,&K);
	if((2 * K - 1 > N) || !(N & 1)){ printf("0\n"); return 0; }
	solve();
	return 0;
}
// This problem is not solved by myself.
// With the first glance, I thought this promblem is a math problem.
// After 2 hours, I haven't got the formula from my thought.
// In fact, this is a basic DP problem.
// Let's consider dp[i][j] represent that with i nodes
// we can get how many trees with at most j depth.
// so dp[i][j] = sum{dp[k][j-1]*dp[i-1-k][j-1]} k is from 1 to i - 2.
// count all possible ways with a root node and two subtree.