/*
ID: ctzsm2
PROG: ratios
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int target[3],t[3];
int food[3][3];
int main(int argc, char** argv) {
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	for(int i = 0;i < 3; ++i) scanf("%d\n",&target[i]);
	for(int i = 0;i < 3; ++i) for(int j = 0;j < 3; ++j)
		scanf("%d",&food[i][j]);
	for(int i = 0;i < 100; ++i) for(int j = 0;j < 100; ++j) for(int k = 0;k < 100; ++k){
		for(int v = 0;v < 3; ++v) t[v] = i * food[0][v] + j * food[1][v] + k * food[2][v];
		int ratio;bool flag = false;
		for(int v = 0;v < 3; ++v){
			if(target[v] == 0) continue;
			if(t[v] % target[v] == 0){
				ratio = t[v] / target[v];flag = true;
				break;
			}
		}
		if(!flag || ratio == 0) continue;
		flag = false;
		for(int v = 0;v < 3; ++v) if(ratio * target[v] != t[v]){
			flag = true;break;
		}
		if(!flag){
			printf("%d %d %d %d\n",i,j,k,ratio);
			exit(0);
		}
	}
	printf("NONE\n");
	return 0;
}

