/*
ID: ctzsm2
PROG: fence6
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 202;
int N;
int s,L[maxn],n1,n2;
int ans = 0x3fffffff;
int n[maxn][maxn][2];
bool map[maxn][maxn][2],flag[maxn];
int b[maxn],v;
void init(){
	scanf("%d",&N);
	memset(map,false,sizeof(map));
	for(int i = 0;i < N; ++i){
		scanf("%d",&s);
		scanf("%d%d%d",&L[s],&n[s][0][0],&n[s][0][1]);
		for(int j = 1;j <= n[s][0][0]; ++j){
			scanf("%d",&n[s][j][0]);
			map[s][n[s][j][0]][0] = true;
		}
		for(int j = 1;j <= n[s][0][1]; ++j){
			scanf("%d",&n[s][j][1]);
			map[s][n[s][j][1]][1] = true;
		}
	}
}
void dfs(int k,int p,int t){
	for(int i = 1;i <= n[p][0][t]; ++i){
		if(!flag[n[p][i][t]] && L[n[p][i][t]] + b[k-1] < ans){
			flag[n[p][i][t]] = true;
			b[k] = b[k-1] + L[n[p][i][t]];
			if(n[p][i][t] == v){
				flag[n[p][i][t]] = false;
				ans = min(ans,b[k]);
				continue;
			}
			if(!map[n[p][i][t]][p][0]) dfs(k+1,n[p][i][t],0);
			else dfs(k+1,n[p][i][t],1);
			flag[n[p][i][t]] = false;
		}
	}
}
void solve(){
	for(v = 1;v <= N; ++v){
		dfs(1,v,0);
		dfs(1,v,1);
	}
	printf("%d\n",ans);
}
int main(int argc, char** argv) {
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	init();
	solve();
	return 0;
}

