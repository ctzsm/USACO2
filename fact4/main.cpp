/*
ID: ctzsm2
PROG: fact4
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int N, ans = 1;
int main(int argc, char** argv) {
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	scanf("%d",&N);
	for(int i = 2;i <= N; ++i){
		ans *= i;
		while(ans % 10 == 0) ans /= 10;
		ans %= 100000;
	}
	printf("%d\n",ans % 10);
	return 0;
}

