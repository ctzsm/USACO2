/*
ID: ctzsm2
PROG: frac1
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
void dfs(int a,int b,int c,int d){
	if(b + d <= n){
		dfs(a,b,a+c,b+d);
		printf("%d/%d\n",a+c,b+d);
		dfs(a+c,b+d,c,d);
	}
}
int main(int argc, char** argv) {
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	printf("0/1\n");
	dfs(0,1,1,1);
	printf("1/1\n");
	return 0;
}

