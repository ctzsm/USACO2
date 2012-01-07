/*
ID: ctzsm2
PROG: zerosum
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;
char s[] = "1+2+3+4+5+6+7+8+9";
void work(){
	int now = 1,sign = 1,ans = 0;
	for(int i = 1;i < n * 2 - 1; i += 2){
		if(s[i] != ' '){
			ans += now * sign;
			sign = (s[i] == '+') ? 1 : -1;
			now = s[i+1] - '0';
		}else{
			now *= 10;
			now += s[i+1] - '0';
		}
	}
	ans += now * sign;
	if(ans == 0) printf("%s\n",s);
}
void dfs(int d){
	if(d == n){work();return;}
	s[d*2-1] = ' ';
	dfs(d + 1);
	s[d*2-1] = '+';
	dfs(d + 1);
	s[d*2-1] = '-';
	dfs(d + 1);
}
int main(int argc, char** argv) {
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	scanf("%d",&n);s[n*2-1] = 0;
//	printf("%d %d %d",'+','-',' ');
	dfs(1);
	return 0;
}

