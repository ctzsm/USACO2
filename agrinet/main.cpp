/*
ID: ctzsm2
PROG: agrinet
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int oo = 0x3ffffff;
int n;
int map[105][105],dis[105],ans = 0;
bool intree[105];
void Prim(){
	for(int i = 0;i < n; ++i) dis[i] = map[0][i];
	intree[0] = true;
	for(int i = 0;i < n - 1; ++i){
		int u,len = oo;
		for(int j = 0;j < n; ++j){
			if(!intree[j]){
				if(len > dis[j]){
					len = dis[j];u = j;
				}
			}
		}
		ans += len;
		for(int j = 0;j < n; ++j)
			dis[j] = min(dis[j],map[u][j]);
		intree[u] = true;
	}
	printf("%d\n",ans);
}
int main(int argc, char** argv) {
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) for(int j = 0;j < n; ++j)
		scanf("%d",&map[i][j]);
	Prim();
	return 0;
}

