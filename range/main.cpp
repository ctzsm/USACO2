/*
ID: ctzsm2
PROG: range
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,cnt[62510];
char map[250][252];
int ans[250][250];
void debug(int x[][250]){
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j) printf("%d\t",x[i][j]);
		printf("\n");
	}
}
int main(int argc, char** argv) {
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) scanf("%s",map[i]);
	for(int i = 0;i < n; ++i) ans[0][i] = map[0][i] == '1' ? 1 : 0;
	for(int i = 1;i < n; ++i) ans[i][0] = map[i][0] == '1' ? 1 : 0;
	for(int i = 1;i < n; ++i){
		for(int j = 1;j < n; ++j){
			if(map[i][j] == '1'){
				ans[i][j] = min(ans[i][j-1],min(ans[i-1][j-1],ans[i-1][j])) + 1;
			}else{
				ans[i][j] = 0;
			}
		}
	}
	for(int i = 1;i < n; ++i){
		for(int j = 1;j < n; ++j){
			for(int k = 2;k <= ans[i][j]; ++k) cnt[k]++;
		}
	}
	for(int i = 2;i <= n * n; ++i){
		if(cnt[i]) printf("%d %d\n",i,cnt[i]);
	}
	return 0;
}

