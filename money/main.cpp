/*
ID: ctzsm2
PROG: money
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int V,N;
int coin[26];
long long ways[10005];
int main(int argc, char** argv) {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d%d",&V,&N);
	for(int i = 0;i < V; ++i) scanf("%d",&coin[i]);
	ways[0] = 1;
	for(int i = 0;i < V; ++i){
		for(int j = coin[i];j <= N; ++j)
			ways[j] += ways[j - coin[i]];
	}
	printf("%lld\n",ways[N]);
	return 0;
}

