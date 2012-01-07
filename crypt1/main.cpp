/*
ID: ctzsm2
PROG: crypt1
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n,num[11],ans = 0;
bool is[11];
char s[10];
int main(int argc, char** argv) {
	freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i){
		scanf("%d",&num[i]);
		is[num[i]] = true;
	}
	int x = 0;
	for(int i = 0;i < n; ++i) for(int j = 0;j < n; ++j) for(int k = 0;k < n; ++k){
		x = num[i] * 100 + num[j] * 10 + num[k];
		sprintf(s,"%d",x);
		if(strlen(s) != 3) continue;
		for(int a = 0;a < n; ++a){
			int y = num[a];if(y == 0) continue;
			sprintf(s,"%d",x * y);
			if(strlen(s) != 3) continue;
			bool aflag = true;
			for(int l = 0;l < 3; ++l) if(!is[s[l] - '0']){
				aflag = false;break;
			}
			if(!aflag) continue;
			for(int b = 0;b < n; ++b){
				int z = num[b];sprintf(s,"%d",x * z);
				if(strlen(s) != 3) continue;
				bool bflag = true;
				for(int l = 0;l < 3; ++l) if(!is[s[l] - '0']){
					bflag = false;break;
				}
				if(!bflag) continue;
				int xx = y * 10 + z;
				sprintf(s,"%d",xx * x);
				if(strlen(s) != 4) continue;
				for(int l = 0;l < 4; ++l) if(!is[s[l] - '0']){
					bflag = false;break;
				}
				if(bflag) ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

