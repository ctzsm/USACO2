/*
ID: ctzsm2
PROG: inflate
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int M,N,p,t;
int score[10005];
int main(int argc, char** argv) {
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	scanf("%d%d",&M,&N);
	for(int i = 0;i < N; ++i){
		scanf("%d%d",&p,&t);
		for(int j = t;j <= M; ++j)
			score[j] = max(score[j],score[j-t] + p);
	}
	int ans = 0;
	for(int i = 0;i <= M; ++i) ans = max(ans,score[i]);
	printf("%d\n",ans);
	return 0;
}

