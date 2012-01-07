/*
ID: ctzsm2
PROG: maze1
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

struct node{
	int i,j;
	int step;
};
node entrance[3];
int W,H,cnt = 0,ans = 0;
char readin[220][100];
int map[105][40];
int wall[] = {1,2,4,8},di[] = {-1,0,1,0},dj[] = {0,1,0,-1};
bool visit[105][40];
int main(int argc, char** argv) {
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	scanf("%d%d",&W,&H);
	fgets(readin[0],1024,stdin);
	for(int i = 0;i < H * 2 + 1; ++i) fgets(readin[i],1024,stdin);
//	for(int i = 0;i < H * 2 + 1; ++i) printf("%s\n",readin[i]);
	for(int i = 0;i < H; ++i) for(int j = 0;j < W; ++j){
		int ii = (i + 1) * 2 - 1,jj = (j + 1) * 2 - 1;
		for(int v = 0;v < 4; ++v){
			if(readin[ii+di[v]][jj+dj[v]] != ' ')
				map[i][j] |= wall[v];
		}
	}
//	for(int i = 0;i < H; ++i){
//		for(int j = 0;j < W; ++j) printf("%d ",map[i][j]);
//		printf("\n");
//	}
	for(int i = 0;i < H; ++i){
		if(!(map[i][0] & 8)){ entrance[cnt].i = i,entrance[cnt].j = 0,entrance[cnt].step = 0;cnt++; }
		if(!(map[i][W-1] & 2)){ entrance[cnt].i = i,entrance[cnt].j = W-1,entrance[cnt].step = 0;cnt++; }
	}
	for(int i = 0;i < W; ++i){
		if(!(map[0][i] & 1)){ entrance[cnt].i = 0,entrance[cnt].j = i,entrance[cnt].step = 0;cnt++; }
		if(!(map[H-1][i] & 4)){ entrance[cnt].i = H-1,entrance[cnt].j = i,entrance[cnt].step = 0;cnt++; }
	}
	queue<node> q;q.push(entrance[0]);q.push(entrance[1]);
	visit[entrance[0].i][entrance[0].j] = visit[entrance[1].i][entrance[1].j] = true;
//	for(int i = 0;i < H; ++i){
//		for(int j = 0;j < W; ++j) printf("%d ",visit[i][j]);
//		printf("\n");
//	}
	while(!q.empty()){
		node now = q.front();q.pop();
		ans = max(ans,now.step);
		for(int i = 0;i < 4; ++i){
			int ii = now.i + di[i],jj = now.j + dj[i],step = now.step + 1;
			if(ii >= 0 && ii < H && jj >= 0 && jj < W && !(map[now.i][now.j] & wall[i]) && !visit[ii][jj]){
				visit[ii][jj] = true;
				node x;x.i = ii,x.j = jj,x.step = step;
				q.push(x);
			}
		}
	}
//	for(int i = 0;i < H; ++i){
//		for(int j = 0;j < W; ++j) printf("%d ",visit[i][j]);
//		printf("\n");
//	}
	printf("%d\n",ans + 1);
	return 0;
}

