/*
ID: ctzsm2
PROG: milk2
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool time[1000005];
int n,begin = 1000000,end = 0;
int main(int argc, char** argv) {
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i){
		int a,b;scanf("%d%d",&a,&b);
		begin = begin < a ? begin : a;
		end = end > b ? end : b;
		for(int j = a + 1;j <= b; ++j) time[j] = true;
	}
	begin++;
	int ans1 = 0,ans2 = 0,cnt1,cnt2;
	for(int i = begin;i <= end; ++i){
		if(time[i] != time[i-1]){
			if(time[i]){
				cnt1 = 1;ans1 = ans1 > cnt1 ? ans1 : cnt1;
			}else{
				cnt2 = 1;ans2 = ans2 > cnt2 ? ans2 : cnt2;
			}
		}else{
			if(time[i]){
				cnt1++;ans1 = ans1 > cnt1 ? ans1 : cnt1;
			}else{
				cnt2++;ans2 = ans2 > cnt2 ? ans2 : cnt2;
			}
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}

