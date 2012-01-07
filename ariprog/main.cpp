/*
ID: ctzsm2
PROG: ariprog
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct ansstruct{
	int dev,start;
	bool operator < (const ansstruct& b)const{
		if(dev == b.dev) return start < b.start;
		return dev < b.dev;
	}
}ans[10005];
bool is[260000];
int n,m;
int num[130000],cnt = 0,anscnt = 0;

int main(int argc, char** argv) {
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(is,false,sizeof(is));
	for(int i = 0;i <= m; ++i) for(int j = 0;j <= m; ++j)
		is[i*i + j*j] = true;
	m = m * m * 2;
	for(int i = 0;i <= m; ++i){
		if(is[i]) num[cnt++] = i;
	}
//	for(int i = 0;i < cnt; ++i) printf("%d\n",num[i]);
	for(int i = cnt - 1;i > 0; --i){
		for(int j = i - 1;j >= 0; --j){
			int c = 2;int dev = num[i] - num[j];
			if(num[i] - (n - 1) * dev < 0) break;
			while(true){
				int t = num[i] - dev * c;
				if(t >= 0 && is[t]) c++;
				else break;
				if(t + dev * (n - 1) == num[i]){
					ans[anscnt].dev = dev;
					ans[anscnt].start = t;
					anscnt++;
					break;
				}
			}
		}
	}
	if(anscnt == 0){
		printf("NONE\n");
		return 0;
	}
	sort(ans,ans+anscnt);
	for(int i = 0;i < anscnt; ++i) printf("%d %d\n",ans[i].start,ans[i].dev);
	return 0;
}

//Executing...
//   Test 1: TEST OK [0.000 secs, 3892 KB]
//   Test 2: TEST OK [0.000 secs, 3892 KB]
//   Test 3: TEST OK [0.000 secs, 3892 KB]
//   Test 4: TEST OK [0.000 secs, 3892 KB]
//   Test 5: TEST OK [0.000 secs, 3892 KB]
//   Test 6: TEST OK [0.022 secs, 3892 KB]
//   Test 7: TEST OK [0.108 secs, 3892 KB]
//   Test 8: TEST OK [0.173 secs, 3892 KB]
//   Test 9: TEST OK [0.173 secs, 3892 KB]
//
//All tests OK.