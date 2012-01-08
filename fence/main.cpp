/*
ID: ctzsm2
PROG: fence
LANG: C++
*/
#include <ios>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int F,map[501][501],maxn = 0;
int ans[1050],cnt = 0,degree[501];
void Euler(int u){
	if(degree[u] == 0){
		ans[cnt++] = u;return;
	}
	for(int i = 1;i <= maxn; ++i){
		if(map[u][i]){
			map[u][i]--;map[i][u]--;
			degree[u]--;degree[i]--;
			Euler(i);
		}
	}
	ans[cnt++] = u;
}
int main(int argc, char** argv) {
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%d",&F);
	for(int i = 0;i < F; ++i){
		int x,y;scanf("%d%d",&x,&y);
		map[x][y]++;map[y][x]++;
		degree[x]++;degree[y]++;
		maxn = maxn > x ? maxn : x;
		maxn = maxn > y ? maxn : y;
	}
	bool flag = false;
	for(int i = 1;i <= maxn; ++i) if(degree[i] & 1){
		Euler(i);flag = true;break;
	}	
	if(!flag){
		for(int i = 1;i <= maxn; ++i) if(degree[i]){
			Euler(i);break;
		}
	}
	for(int i = cnt - 1;i >= 0; --i) printf("%d\n",ans[i]);
	return 0;
}

