/*
ID: ctzsm2
PROG: humble
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,k;
int a[105],pre[105];
long long h[100005] = {1};
int main(int argc, char** argv) {
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	scanf("%d%d",&k,&n);
	for(int i = 0;i < k; ++i) scanf("%d",&a[i]);
	sort(a,a+k);
	for(int i = 1;i <= n; ++i){
		int next = 0x7fffffff,label;
		for(int j = 0;j < k; ++j){
			if(a[j] * h[pre[j]] < next){
				label = j;
				next = a[j] * h[pre[j]];
			}
		}
		h[i] = next;
		for(int j = 0;j < k; ++j){
			while(a[j] * h[pre[j]] <= h[i]) pre[j]++;
		}
//		printf("%d\n",h[i]);
	}
	printf("%lld\n",h[n]);
	return 0;
}

