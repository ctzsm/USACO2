/*
ID: ctzsm2
PROG: ditch
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct CNode{
	int v,i;
	CNode(int _v,int _i){
		v = _v;i = _i;
	}
};
int N,M;
const int inf = 0x3fffffff;
const int maxn = 500;
vector<CNode> a[maxn];
vector<int> flow;
vector<int> cap;
int cur[maxn],sumd[maxn],d[maxn],pre[maxn];
void AddEdge(int u,int v,int c){
	a[u].push_back(CNode(v,cap.size()));
	a[v].push_back(CNode(-u,cap.size()));
	cap.push_back(c);
	flow.push_back(0);
}
int SAP(int s,int t,int n){
	memset(sumd,0,sizeof(sumd));
	memset(cur,0,sizeof(cur));
	memset(d,0,sizeof(d));
	sumd[0] = n;pre[s] = s;
	int ans = 0;
	int now = s;
	int modify = inf;
	while(d[s] < n){
		bool flag = false;
		if(now == s) modify = inf;
		for(int &j = cur[now];j < a[now].size(); ++j){
			int i = a[now][j].i;
			int v = a[now][j].v;
			if(v > 0 && d[now] == d[v] + 1 && flow[i] < cap[i]){
				flag = true;
				pre[v] = now;
				now = v;
				modify = min(modify,cap[i] - flow[i]);
				break;
			}
			if(v < 0 && d[now] == d[-v] + 1 && flow[i] > 0){
				flag = true;
				pre[-v] = now;
				now = -v;
				modify = min(modify,flow[i]);
				break;
			}
		}
		if(now == t){
			ans += modify;
			while(now != s){
				now = pre[now];
				if(a[now][cur[now]].v > 0) flow[a[now][cur[now]].i] += modify;
				else flow[a[now][cur[now]].i] -= modify;
			}
		}
		if(flag) continue;
		cur[now] = 0;
		int mind = n;
		for(int tt = 0;tt < a[now].size(); ++tt){
			int i = a[now][tt].i;
			int v = a[now][tt].v;
			if(v > 0 && d[v] < mind && flow[i] < cap[i])
				mind = d[v];
			if(v < 0 && d[-v] < mind && flow[i] > 0)
				mind = d[-v];
		}
		sumd[d[now]]--;
		if(sumd[d[now]] == 0) d[s] = n;
		sumd[d[now] = mind + 1]++;
		now = pre[now];
	}
	return ans;
}
void init(){
	scanf("%d%d",&N,&M);
	cap.clear();flow.clear();
	for(int i = 0;i < M + 5; ++i) a[i].clear();
	for(int i = 0;i < N; ++i){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		AddEdge(u,v,c);
	}
}
int main(int argc, char** argv) {
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);
	init();
	printf("%d\n",SAP(1,M,M));
	return 0;
}

