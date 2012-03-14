/*
ID: ctzsm2
PROG: nuggets
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 256 * 258;
int N;
int a[15];
bool is[maxn];
int main(int argc, char** argv) {
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	scanf("%d",&N);
	for(int i = 0;i < N; ++i) scanf("%d",&a[i]);
	for(int i = 0;i < N; ++i) if(a[i] == 1) { printf("0\n");return 0; }
	int gcd = a[0];
	for(int i = 1;i < N; ++i){
		gcd = __gcd(gcd,a[i]);
	}
	if(gcd != 1) { printf("0\n");return 0; }
	is[0] = true;
	for(int i = 0;i < N; ++i){
		for(int j = a[i];j < maxn; ++j)
			is[j] |= is[j-a[i]];
	}
//	for(int i = 0;i < maxn; ++i) printf("%d %d\n",i,is[i]);
	for(int i = maxn - 1;i >= 0; --i) if(!is[i]){
		printf("%d\n",i);break;
	}
	return 0;
}

