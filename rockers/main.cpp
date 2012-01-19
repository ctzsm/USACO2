/*
ID: ctzsm2
PROG: rockers
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N,T,M,cnt = 1;
int song[22];
int ans[22][22][2];
int main(int argc, char** argv) {
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	scanf("%d%d%d",&N,&T,&M);
	for(int i = 0;i < N; ++i){
		scanf("%d",&song[cnt]);
		if(song[cnt] <= T) cnt++;
	}
	N = cnt - 1;
	for(int i = 0;i <= N; ++i) for(int j = 0;j <= N; ++j)
		ans[i][j][0] = 0x3ffffff,ans[i][j][1] = T + 1;
	for(int i = 0;i <= N; ++i) ans[i][0][0] = 1,ans[i][0][1] = 0;
	for(int i = 1;i <= N; ++i) for(int j = 1;j <= i; ++j){
		ans[i][j][0] = ans[i-1][j][0];
		ans[i][j][1] = ans[i-1][j][1];
		if(ans[i-1][j-1][1] + song[i] <= T){
			if(ans[i-1][j-1][0] < ans[i][j][0] || (ans[i-1][j-1][0] == ans[i][j][0] && ans[i-1][j-1][1] + song[i] < ans[i][j][1]))
				ans[i][j][0] = ans[i-1][j-1][0],ans[i][j][1] = ans[i-1][j-1][1] + song[i];
		}else{
			if(ans[i-1][j-1][0] + 1 < ans[i][j][0] || (ans[i-1][j-1][0] + 1 == ans[i][j][0] && song[i] < ans[i][j][1]))
				ans[i][j][0] = ans[i-1][j-1][0] + 1,ans[i][j][1] = song[i];
		}
	}
	for(int i = N;i >= 0; --i){
		if(ans[N][i][0] <= M){
			printf("%d\n",i);break;
		}
	}
	return 0;
}

