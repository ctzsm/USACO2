/*
ID: ctzsm2
PROG: concom
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
int map[105][105];
bool control[105][105];
int maxn = 0;
void dfs(int i,int j){
	if(control[i][j]) return;
	control[i][j] = true;
	for(int k = 1;k <= maxn; ++k)
		map[i][k] += map[j][k];
	for(int k = 1;k <= maxn; ++k)
		if(control[k][i]) dfs(k,j);
	for(int k = 1;k <= maxn; ++k)
		if(map[i][k] > 50) dfs(i,k);
}
int main(int argc, char** argv) {
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	scanf("%d",&n);
	memset(map,0,sizeof(map));
	memset(control,false,sizeof(control));
	for(int i = 0;i < n; ++i){
		int x,y,p;
		scanf("%d%d%d",&x,&y,&p);
		maxn = max(maxn,max(x,y));
		map[x][y] += p;
	}
	for(int i = 1;i <= maxn; ++i) control[i][i] = true;
	for(int i = 1;i <= maxn; ++i) for(int j = 1;j <= maxn; ++j)
		if(map[i][j] > 50) dfs(i,j);
	for(int i = 1;i <= maxn; ++i) for(int j = 1;j <= maxn; ++j)
		if(i != j && control[i][j]) printf("%d %d\n",i,j);
	return 0;
}

