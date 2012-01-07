/*
ID: ctzsm2
PROG: checker
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int n,m,ans,cnt;
bool chess[15][15];
int a[13];
int base[15] = {1};
void print(){
	for(int i = 0;i < n - 1; ++i) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
}
void getFirstThree(int d,int row,int lslash,int rslash){
	if(cnt == 3) return;
	if(row == m){
		print();cnt++;return;
	}
	int pos = m & ~(row|lslash|rslash),p;
	while(pos){
		p = pos & -pos;
		for(int i = 0;i <= n; ++i) if(p == base[i]){
			a[d] = i + 1;
			break;
		}
		pos -= p;
		getFirstThree(d + 1,row + p,(lslash + p) << 1,(rslash + p) >> 1);
		if(cnt == 3) return;
	}
}
void dfs(int row,int lslash,int rslash){
	if(row == m){
		ans++;return;
	}
	int pos = m & ~(row|lslash|rslash),p;
	while(pos){
		p = pos & -pos;
		pos -= p;
		dfs(row + p,(lslash + p) << 1,(rslash + p) >> 1);
	}
}
int main(int argc, char** argv) {
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i) base[i] = base[i - 1] * 2;
	ans = 0;m = (1 << n) - 1;cnt = 0;
	getFirstThree(0,0,0,0);
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}

//TASK: checker
//LANG: C++
//
//Compiling...
//Compile: OK
//
//Executing...
//   Test 1: TEST OK [0.000 secs, 3048 KB]
//   Test 2: TEST OK [0.000 secs, 3048 KB]
//   Test 3: TEST OK [0.000 secs, 3048 KB]
//   Test 4: TEST OK [0.000 secs, 3048 KB]
//   Test 5: TEST OK [0.000 secs, 3048 KB]
//   Test 6: TEST OK [0.000 secs, 3048 KB]
//   Test 7: TEST OK [0.022 secs, 3048 KB]
//   Test 8: TEST OK [0.108 secs, 3048 KB]
//
//All tests OK.
