/*
ID: ctzsm2
PROG: subset
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int N;
long long a[1000];
int main(int argc, char** argv) {
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	scanf("%d",&N);
	int m = N * (N + 1) / 2 ;
	if(m & 1){
		printf("0\n");return 0;
	}
	m /= 2;
	memset(a,0,sizeof(a));a[0] = 1;
	for(int i = 1;i <= N; ++i){
		for(int j = m;j >= i; --j){
			if(a[j-i]){
				a[j] += a[j-i];
			}
		}
//		for(int j = 0;j <= m; ++j) printf("%d ",a[j]);
//		printf("\n");
	}
	printf("%lld\n",a[m] / 2);
	return 0;
}

