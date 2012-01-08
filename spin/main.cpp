/*
ID: ctzsm2
PROG: spin
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool spin[5][360];
int speed[5];
int main(int argc, char** argv) {
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	for(int i = 0;i < 5; ++i){
		int w;scanf("%d%d",&speed[i],&w);
		for(int j = 0;j < w; ++j){
			int begin,end;scanf("%d%d",&begin,&end);
			for(int k = begin;k <= begin + end; ++k){
				spin[i][k % 360] = true;
			}
		}
	}
	bool tocheck[360],flag = true;
	for(int t = 0;t <= 360; ++t){
		for(int i = 0;i < 360; ++i) tocheck[i] = true;
		for(int i = 0;i < 5; ++i){
			int shift = speed[i] * t;
			for(int j = 0;j < 360; ++j){
				tocheck[(shift+j) % 360] &= spin[i][j];
			}
		}
		for(int i = 0;i < 360; ++i) if(tocheck[i]){
			flag = false;break;
		}
		if(!flag){
//			for(int j = 0;j < 360; ++j) printf("%d",tocheck[j]);
//			printf("\n");
//			for(int i = 0;i < 5; ++i){
//				memset(tocheck,false,sizeof(tocheck));
//				int shift = speed[i] * t;
//				for(int j = 0;j < 360; ++j) tocheck[(shift + j) % 360] |= spin[i][j];
//				for(int j = 0;j < 360; ++j) printf("%d",tocheck[j]);
//				printf("\n");
//			}
			printf("%d\n",t);break;
		}
	}
	if(flag) printf("none\n");
	return 0;
}

