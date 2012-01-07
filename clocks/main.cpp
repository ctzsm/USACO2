/*
ID: ctzsm2
PROG: clocks
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


int clock[10];
int ans[40],cnt = 0;
int move[9][6] = {
	{4,0,1,  3,4},
	{3,0,1,2},
	{4,  1,2,  4,5},
	{3,0,    3,    6},
	{5,  1,  3,4,5,  7},
	{3,    2,    5,    8},
	{4,      3,4,  6,7},
	{3,            6,7,8},
	{4,        4,5,  7,8}
};
int main(int argc, char** argv) {
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	for(int i = 0;i < 9; ++i) scanf("%d",&clock[i]);
	for(int i = 0;i < 9; ++i) { clock[i] /= 3;clock[i] &= 3; }
	for(int a = 0;a < 4; ++a) for(int b = 0;b < 4; ++b) for(int c = 0;c < 4; ++c)
		for(int d = 0;d < 4; ++d) for(int e = 0;e < 4; ++e) for(int f = 0;f < 4; ++f)
			for(int g = 0;g < 4; ++g) for(int h = 0;h < 4; ++h) for(int i = 0;i < 4; ++i){
				if((clock[0] + a + b + d) & 3) continue;
				if((clock[1] + a + b + c + e) & 3) continue;
				if((clock[2] + b + c + f) & 3) continue;
				if((clock[3] + a + d + e + g) & 3) continue;
				if((clock[4] + a + c + e + g + i) & 3) continue;
				if((clock[5] + c + e + f + i) & 3) continue;
				if((clock[6] + d + g + h) & 3) continue;
				if((clock[7] + e + g + h + i) & 3) continue;
				if((clock[8] + f + h + i) & 3) continue;
				while(a--) ans[cnt++] = 1;
				while(b--) ans[cnt++] = 2;
				while(c--) ans[cnt++] = 3;
				while(d--) ans[cnt++] = 4;
				while(e--) ans[cnt++] = 5;
				while(f--) ans[cnt++] = 6;
				while(g--) ans[cnt++] = 7;
				while(h--) ans[cnt++] = 8;
				while(i--) ans[cnt++] = 9;
				for(int j = 0;j < cnt - 1; ++j) printf("%d ",ans[j]);
				printf("%d\n",ans[cnt - 1]);
				return 0;
			}
	return 0;
}

