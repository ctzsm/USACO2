/*
ID: ctzsm2
PROG: job
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int n,m1,m2;
int a[35],b[35];
int timea[35],timeb[35];
int cost[2][1005];
int main(int argc, char** argv) {
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 0;i < m1; ++i) scanf("%d",&timea[i]);
	for(int i = 0;i < m2; ++i) scanf("%d",&timeb[i]);
	int ans1 = 0,ans2 = 0;
	for(int i = 0;i < n; ++i){
		int label = -1,nowa = 0x3ffffff;
		for(int j = 0;j < m1; ++j){
			if(nowa > a[j] + timea[j]){
				nowa = a[j] + timea[j];
				label = j;
			}
		}
		a[label] += timea[label];
		cost[0][i] = a[label];
		int nowb = 0x3ffffff;
		for(int j = 0;j < m2; ++j){
			if(nowb > b[j] + timeb[j]){
				nowb = b[j] + timeb[j];
				label = j;
			}
		}
		b[label] += timeb[label];
		cost[1][i] = b[label];
	}
	for(int i = 0;i < n; ++i){
		ans1 = ans1 < cost[0][i] ? cost[0][i] : ans1;
		ans2 = ans2 < (cost[0][i] + cost[1][n - i - 1]) ? (cost[0][i] + cost[1][n - i - 1]) : ans2;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}

