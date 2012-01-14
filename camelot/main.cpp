/*
ID: ctzsm2
PROG: camelot
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int cost[26][30], kingcost[26][30];
int kdist[26][30];
int dist[26][30][2];
int R,C;
int king[2],knight[2];
int do_step(int x,int y,int kflag){
	int ret = 0;
	int d = dist[x][y][kflag];
	if(y > 0){
		if(x > 1)
			if(dist[x-2][y-1][kflag] > d + 1){
				dist[x-2][y-1][kflag] = d + 1;
				ret = 1;
			}
		if(x < R - 2)
			if(dist[x+2][y-1][kflag] > d + 1){
				dist[x+2][y-1][kflag] = d + 1;
				ret = 1;
			}
		if(y > 1){
			if(x > 0)
				if(dist[x-1][y-2][kflag] > d + 1){
					dist[x-1][y-2][kflag] = d + 1;
					ret = 1;
				}
			if(x < R - 1)
				if(dist[x+1][y-2][kflag] > d + 1){
					dist[x+1][y-2][kflag] = d + 1;
					ret = 1;
				}
		}
	}
	if(y < C - 1){
		if(x > 1)
			if(dist[x-2][y+1][kflag] > d + 1){
				dist[x-2][y+1][kflag] = d + 1;
				ret = 1;
			}
		if(x < R - 2)
			if(dist[x+2][y+1][kflag] > d + 1){
				dist[x+2][y+1][kflag] = d + 1;
				ret = 1;
			}
		if(y < C - 2){
			if(x > 0)
				if(dist[x-1][y+2][kflag] > d + 1){
					dist[x-1][y+2][kflag] = d + 1;
					ret = 1;
				}
			if(x < R - 1)
				if(dist[x+1][y+2][kflag] > d + 1){
					dist[x+1][y+2][kflag] = d + 1;
					ret = 1;
				}
		}
	}
	if(kflag == 0 && dist[x][y][1] > d + kdist[x][y]){
		dist[x][y][1] = d + kdist[x][y];
		if(kdist[x][y] > ret) ret = kdist[x][y];
	}
	return ret;
}
void getDist(){
	memset(dist,0x3f,sizeof(dist));
	int bound,ret;
	dist[knight[0]][knight[1]][0] = 0;
	bound = dist[knight[0]][knight[1]][1] = kdist[knight[0]][knight[1]];
	for(int d = 0;d <= bound; ++d){
		for(int i = 0;i < R; ++i) for(int j = 0;j < C; ++j){
			if(dist[i][j][0] == d){
				ret = do_step(i,j,0);
				bound = max(bound,d + ret);
			}
			if(dist[i][j][1] == d){
				ret = do_step(i,j,1);
				bound = max(bound,d + ret);
			}
		}
	}
}
void debug(int x[][30]){
	for(int i = 0;i < R; ++i){
		for(int j = 0;j < C; ++j) printf("%d ",x[i][j]);
		printf("\n");
	}
}
void debug2(int flag){
	for(int i = 0;i < R; ++i){
		for(int j = 0;j < C; ++j) printf("%d ",dist[i][j][flag]);
		printf("\n");
	}
}
int main(){
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	char t[2];int x;
	scanf("%d%d",&C,&R);
	scanf("%s%d",t,&x);
	king[0] = t[0] - 'A',king[1] = x - 1;
	for(int i = 0;i < R; ++i) for(int j = 0;j < C; ++j){
		kingcost[i][j] = kdist[i][j] = max(abs(i-king[0]),abs(j-king[1]));
	}
	while(scanf("%s%d",t,&x)!=EOF){
		knight[0] = t[0] - 'A',knight[1] = x - 1;
		getDist();
//		debug2(0);printf("\n");debug2(1);printf("\n");
		for(int i = 0;i < R; ++i) for(int j = 0;j < C; ++j){
			cost[i][j] += dist[i][j][0];
			if(dist[i][j][0] == 0x3f3f3f3f)cost[i][j] = 0x3f3f3f3f; 
			kingcost[i][j] = min(kingcost[i][j],dist[i][j][1] - dist[i][j][0]);
		}
	}
//	debug(cost);
//	printf("\n");
//	debug(kingcost);
	int out = cost[0][0] + kingcost[0][0];
	for(int i = 0;i < R; ++i) for(int j = 0;j < C; ++j)
		out = min(out,cost[i][j] + kingcost[i][j]);
	printf("%d\n",out);
	return 0;
}
