/*
ID: ctzsm2
PROG: runround
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[10],n,len,ans;
int frac[10] = {1,1};
char s[10];
bool is[10],gflag = false;
bool check(){
	memset(is,false,sizeof(is));
	int run = a[0];
	while(!is[run % len]){
		is[run % len] = true;
		run += a[run % len];
	}
	for(int i = 0;i < len; ++i) if(!is[i]) return false;
	return true;
}
void print(){
	for(int i = 0;i < len; ++i) printf("%d ",a[i]);
	printf("\n");
}
void work(){
	for(int i = 0;i < frac[len]; ++i){
		int x = 0;
		for(int j = 0;j < len; ++j){
			x *= 10;x += a[j];
		}
//		print();
		if(x <= n) { next_permutation(a,a+len);continue; }
		if(check()) ans = min(ans,x);
		next_permutation(a,a+len);
	}
}
void dfs(int d,int pos){
	if(d == len){ work();return; }
	for(int i = pos;i <= 10 - len + d; ++i){
		a[d] = i;
		dfs(d + 1,i + 1);
	}
}
int main(int argc, char** argv) {
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	for(int i = 2;i <= 9; ++i) frac[i] = frac[i-1] * i;
	scanf("%d",&n);sprintf(s,"%d",n);len = strlen(s);
	ans = 0x3fffffff;
	dfs(0,1);
	if(ans != 0x3fffffff) gflag = true;
	if(len <= 8 && !gflag){ len++;dfs(0,1); }
	printf("%d\n",ans);
	return 0;
}

