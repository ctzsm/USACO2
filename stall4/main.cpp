/*
ID: ctzsm2
PROG: stall4
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 401;
int n,m;
vector<int> adj[maxn];
bool used[401];
int mat[maxn],match = 0;
bool crosspath(int k){
	for(int i = 0;i < adj[k].size(); ++i){
		int v = adj[k][i];
		if(mat[v] == -1){
			mat[v] = k;return true;
		}
	}
	for(int i = 0;i < adj[k].size(); ++i){
		int j = adj[k][i];
		if(used[j]) continue;
		used[j] = true;
		if(crosspath(mat[j])){
			mat[j] = k;
			return true;
		}
	}
	return false;
}
void hungary(){
	memset(mat,-1,sizeof(mat));
	for(int i = 1;i <= n + m; ++i){
		memset(used,false,sizeof(used));
		if(crosspath(i)) match++;
	}
	printf("%d\n",match);
}
int main(int argc, char** argv) {
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i){
		int s,x;scanf("%d",&s);
		for(int j = 0;j < s; ++j){
			scanf("%d",&x);
			adj[i].push_back(x+n);
//			adj[s+n].push_back(i);
		}
	}
	hungary();
	return 0;
}

