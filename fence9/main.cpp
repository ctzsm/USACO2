/*
ID: ctzsm2
PROG: fence9
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int n,m,p;
int main(int argc, char** argv) {
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	int ans = 0;
	double k1 = 1.0 * n / m;
	double k2 = 1.0 * (n - p) / m;
	for(int i = 1;i < m; ++i){
		int a = (int)floor(k1 * i + 1.0 + 1e-9);
		int b = (int)ceil(k2 * i + p - 1.0 - 1e-9);
//		printf("%d %d\n",a,b);
		ans += (b - a + 1);
	}
	printf("%d\n",ans);
	return 0;
}

