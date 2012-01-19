/*
ID: ctzsm2
PROG: heritage
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char in[30],pre[30],post[30];
int cnt = 0,pos = 0;
void dfs(int b,int e){
	if(e == b) return;
	if(e == b + 1){
		pos++;
		post[cnt++] = in[b];
		return;
	}
	int p;
	for(int i = b;i < e; ++i){
		if(pre[pos] == in[i]){
			pos++;
			p = i;
			dfs(b,p);
			dfs(p+1,e);
			break;
		}
	}
	post[cnt++] = in[p];
}
int main(int argc, char** argv) {
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	scanf("%s%s",in,pre);
	int len = strlen(pre);
	dfs(0,len);
	post[len] = '\0';
	printf("%s\n",post);
	return 0;
}

