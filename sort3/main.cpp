/*
ID: ctzsm2
PROG: sort3
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n,a[1005],ans = 0;
int cnt[4] = {0,0,0,0};
int cnt12 = 0,cnt13 = 0,cnt21 = 0,cnt23 = 0,cnt31 = 0,cnt32 = 0;
int main(int argc, char** argv) {
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
	for(int i = 0;i < n; ++i) cnt[a[i]]++;
	cnt[2] += cnt[1];
	for(int i = 0;i < cnt[1]; ++i){
		if(a[i] == 2) cnt12++;
		if(a[i] == 3) cnt13++;
	}
	for(int i = cnt[1];i < cnt[2]; ++i){
		if(a[i] == 1) cnt21++;
		if(a[i] == 3) cnt23++;
	}
	for(int i = cnt[2];i < n; ++i){
		if(a[i] == 1) cnt31++;
		if(a[i] == 2) cnt32++;
	}
//	printf("12=%d, 13=%d, 21=%d, 23=%d, 31=%d, 32=%d\n",cnt12,cnt13,cnt21,cnt23,cnt31,cnt32);
	int t = min(cnt12,cnt21);cnt12 -= t;cnt21 -= t;
	ans += t;
	t = min(cnt13,cnt31);cnt13 -= t;cnt31 -= t;
	ans += t;
	t = min(cnt23,cnt32);cnt23 -= t;cnt32 -= t;
	ans += t;
//	printf("12=%d, 13=%d, 21=%d, 23=%d, 31=%d, 32=%d\n",cnt12,cnt13,cnt21,cnt23,cnt31,cnt32);
	ans += (cnt12 + cnt13 + cnt21 + cnt23 + cnt31 + cnt32) / 3 * 2;
	printf("%d\n",ans);
	return 0;
}

