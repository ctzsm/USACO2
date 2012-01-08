/*
ID: ctzsm2
PROG: butter
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int oo = 0x3fffffff;

struct edge{
	int v,len;
	edge(){}
	edge(int _v,int _len){v = _v,len = _len;}
};
vector<edge> adj[805];
int N,P,C,ans = 0x3fffffff;
int dis[805];
int cow[805];
bool isIn[805];
void SPFA(int source){
	memset(isIn,false,sizeof(isIn));
	for(int i = 1;i <= P; ++i) dis[i] = oo;
	dis[source] = 0;isIn[source] = true;
	queue<int> q;q.push(source);
	while(!q.empty()){
		int u = q.front();q.pop();isIn[u] = false;
		for(int i = 0;i < adj[u].size(); ++i){
			int v = adj[u][i].v,len = adj[u][i].len;
			if(dis[v] > dis[u] + len){
				dis[v] = dis[u] + len;
				if(!isIn[v]) q.push(v);
				isIn[v] = true; 
			}
		}
	}
	int ret = 0;
	for(int i = 0;i < N; ++i) ret += dis[cow[i]];
	ans = min(ans,ret);
}
int main(int argc, char** argv) {
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	scanf("%d%d%d",&N,&P,&C);
	for(int i = 0;i < N; ++i) scanf("%d",&cow[i]);
	for(int i = 0;i < C; ++i){
		int x,y,len;scanf("%d%d%d",&x,&y,&len);
		adj[x].push_back(edge(y,len));
		adj[y].push_back(edge(x,len));
	}
	for(int i = 1;i <= P; ++i) SPFA(i);
	printf("%d\n",ans);
	return 0;
}

