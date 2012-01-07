/*
ID: ctzsm2
PROG: castle
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,total,maxarea1,maxarea2;
int ansi,ansj;
int map[55][55];
int visit[55][55];
int cnt[2505];
char ansd;
int dx[] = {0,1},dy[] = {-1,0};
void print(){
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < m - 1; ++j) printf("%d ",visit[i][j]);
		printf("%d\n",visit[i][m-1]);
	}
}
void floodfill(int i,int j){
	visit[i][j] = total;
	if((visit[i][j-1] == -1) && (!(map[i][j] & 1))) floodfill(i,j-1); 
	if((visit[i-1][j] == -1) && (!(map[i][j] & 2))) floodfill(i-1,j); 
	if((visit[i][j+1] == -1) && (!(map[i][j] & 4))) floodfill(i,j+1); 
	if((visit[i+1][j] == -1) && (!(map[i][j] & 8))) floodfill(i+1,j); 
}
int main(int argc, char** argv) {
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j)
		scanf("%d",&map[i][j]);
	memset(visit,-1,sizeof(visit));
	total = 0;maxarea1 = maxarea2 = 0;
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j) if(visit[i][j] == -1){
		total++;floodfill(i,j);
	}
	for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j) cnt[visit[i][j]]++;
	for(int i = 1;i <= total; ++i) maxarea1 = max(maxarea1,cnt[i]);
	for(int j = 0;j < m; ++j) for(int i = n - 1;i >= 0; --i){
		for(int v = 0;v < 2; ++v){
			int jj = j + dx[v],ii = i + dy[v];
			if(ii >= 0 && ii < n && jj >= 0 && jj < m){
				if(visit[i][j] != visit[ii][jj]){
					if(maxarea2 < cnt[visit[i][j]] + cnt[visit[ii][jj]]){
						maxarea2 = cnt[visit[i][j]] + cnt[visit[ii][jj]];
						ansi = i;ansj = j;
						if(v == 0){ ansd = 'N';break; }
						ansd = 'E';
					}
				}
			}
		}
	}
	printf("%d\n%d\n%d\n%d %d %c\n",total,maxarea1,maxarea2,ansi + 1,ansj + 1,ansd);
	return 0;
}

