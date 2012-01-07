/*
ID: ctzsm2
PROG: comehome
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int oo = 0x3ffffff;
struct edge{
	int v,len;
	edge(){}
	edge(int _v,int _len){v = _v,len = _len;}
};
int n,x;
int dis[60];
vector<edge> adj[60];
char s[2],t[2];
int getNum(char c){
	if(c >= 'A' && c <= 'Z') return c - 'A';
	if(c >= 'a' && c <= 'z') return 26 + c - 'a';
}
void SPFA(int source){
	dis[source] = 0;
	queue<int> q;q.push(source);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i = 0;i < adj[u].size(); ++i){
			int v = adj[u][i].v,len = adj[u][i].len;
			if(dis[v] > dis[u] + len){
				dis[v] = dis[u] + len;
				q.push(v);
			}
		}
	}
}
int main(int argc, char** argv) {
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < 60; ++i) adj[i].clear();
	for(int i = 0;i < n; ++i){
		scanf("%s%s%d",s,t,&x);
		adj[getNum(s[0])].push_back(edge(getNum(t[0]),x));
		adj[getNum(t[0])].push_back(edge(getNum(s[0]),x));
	}
	for(int i = 0;i <= 60; ++i) dis[i] = oo;
	SPFA(getNum('Z'));
	int ans = oo;
	for(int i = 0;i < 25; ++i){
		if(ans > dis[i]){ans = dis[i];s[0] = i + 'A';}
	}
	printf("%c %d\n",s[0],ans);
	return 0;
}

