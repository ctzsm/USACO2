/*
ID: ctzsm2
PROG: holstein
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int V,G,ans = 0x3fffffff,ansi;
int target[1005];
int vitamin[16][1005];
int combine[1005];
int main(int argc, char** argv) {
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	scanf("%d",&V);
	for(int i = 0;i < V; ++i) scanf("%d",&target[i]);
	scanf("%d",&G);
	for(int i = 0;i < G; ++i) for(int j = 0;j < V; ++j) scanf("%d",&vitamin[i][j]);
	int n = (1 << G);
	for(int i = 1;i < n; ++i){
		memset(combine,0,V * sizeof(int));
		int cnt = 0;
		for(int j = 0;j < G; ++j){
			if(i & (1 << j)){
				cnt++;
				for(int k = 0;k < V; ++k) combine[k] += vitamin[j][k];
			}
		}
		bool flag = true;
		for(int j = 0;j < V; ++j) if(combine[j] < target[j]){
			flag = false;break;
		}
		if(flag && (ans > cnt)){
			if(ans > cnt){ ans = cnt;ansi = i; }
		}
	}
	printf("%d",ans);
	for(int i = 0;i < G; ++i) if(ansi & (1 << i)) printf(" %d",i+1);
	printf("\n");
	return 0;
}

