/*
ID: ctzsm2
PROG: kimbits
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

unsigned int N,L,I;
int a[35];
int C[35][35];
char out[35];
void init(){
	for(int i = 0;i <= 31; ++i) C[i][0] = C[i][i] = 1;
	for(int i = 2;i <= 31; ++i){
		for(int j = 1;j < i; ++j){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
	scanf("%u%u%u",&N,&L,&I);
	out[N] = '\0';
}
void work(){
	int cnt = L;
	for(int i = N - 1;i >= 1; --i){
		int t = 0;
		for(int j = min(i,cnt);j >= 0; --j){
			t += C[i][j];
//			printf("i = %d, j = %d\n",i,j);
		}
//		printf("t - - - - - - %d\n",t);
		if(I > t){
			I -= t;cnt--;
			out[N - i - 1] = '1';
		}else{
			out[N - i - 1] = '0';
		}
//		printf("I = %d\n",I);
	}
//	printf("\n");
	if(I == 2) out[N - 1] = '1';
	if(I == 1) out[N - 1] = '0';
	printf("%s\n",out);
}
int main(int argc, char** argv) {
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	init();
	work();
	return 0;
}

//Remember The bigest L is 2^31, and the value exceeded the signed int.
