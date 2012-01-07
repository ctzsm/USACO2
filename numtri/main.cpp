/*
ID: ctzsm2
PROG: numtri
LANG: C++
*/

#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int R,mat[1001][1001];
int main(int argc, char** argv) {
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	scanf("%d",&R);
	for(int i = 0;i < R; ++i){
		for(int j = 0;j <= i; ++j) scanf("%d",&mat[i][j]);
	}
	for(int i = R - 2;i >= 0; --i){
		for(int j = 0;j <= i; ++j){
			mat[i][j] += max(mat[i+1][j],mat[i+1][j+1]);
		}
	}
	printf("%d\n",mat[0][0]);
	return 0;
}

