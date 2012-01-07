/*
ID: ctzsm2
PROG: friday
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n,ans[7];
int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleapyear(int year){
	if(year % 100 == 0) return (year % 400 == 0);
	else return year % 4 == 0;
}
int main(int argc, char** argv) {
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	scanf("%d",&n);
	int t = -1;memset(ans,0,sizeof(ans));
	for(int i = 1900;i <= 1899 + n; ++i){
		for(int j = 1;j <= 12; ++j){
			if(j == 2 && isleapyear(i)){
				for(int k = 1;k <= days[j] + 1; ++k){
					t++;t %= 7;
					if(k == 12) ans[t]++;
				}
			}else{
				for(int k = 1;k <= days[j]; ++k){
					t++;t %= 7;
					if(k == 12) ans[t]++;
				}
			}
		}
	}
	printf("%d %d %d %d %d %d %d\n",ans[4],ans[5],ans[6],ans[0],ans[1],ans[2],ans[3]);
	return 0;
}

