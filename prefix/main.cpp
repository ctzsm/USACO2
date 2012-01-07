/*
ID: ctzsm2
PROG: prefix
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt = 0,len = 1;
bool gflag[200005];
char S[200005];
char list[205][15];
int llen[205];
int main(int argc, char** argv) {
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	while(scanf("%s",list[cnt])){
		if(list[cnt][0] == '.')break;
		cnt++;
	}
	while(~scanf("%s",S+len)){
		int tlen = strlen(S+len);
		len += tlen;
	}
	for(int i = 0;i < cnt; ++i) llen[i] = strlen(list[i]);
//	for(int i = 0;i < cnt; ++i) printf("%s\n",list[i]);
//	printf("%s\n",S+1);
	int ans = 0;gflag[0] = true;
	for(int i = 1;i <= len; ++i){
		if(!gflag[i-1]) continue;
		for(int j = 0;j < cnt; ++j){
			bool flag = true;
			for(int k = 0;k < llen[j]; ++k){
				if(S[i+k] != list[j][k]) {flag = false;break;}
			}
			if(i + llen[j] <= len + 1 && flag){
				gflag[i+llen[j]-1] = true;
				ans = max(ans,i + llen[j]-1);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

