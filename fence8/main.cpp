/*
ID: ctzsm2
PROG: fence8
LANG: C++
*/
#include <ios>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N,R;
int board[55],rail[1024],bsum = 0;
void read(){
	scanf("%d",&N);
	for(int i = 0;i < N; ++i) scanf("%d",&board[i]);
	scanf("%d",&R);
	for(int i = 0;i < R; ++i) scanf("%d",&rail[i]);
}
int have[55],stack[1030];
bool check(int R){
	int sum = bsum,k = 0,dep = 0,m = 0;
	for(int i = 0;i < N; ++i) have[i] = board[i];
	for(int i = 0;i < R; ++i) sum -= rail[i];
	while(true){
		int i;
		for(i = k;i < N; ++i) if(have[i] >= rail[R-dep-1]) break;
		if(i == N){
			if(!dep) return false;
			k = stack[dep--];
			if(have[k] < rail[0]) m -= have[k];
			have[k++] += rail[R-dep-1];
		}else{
			have[i] -= rail[R-dep-1];
			if(have[i] < rail[0]) m += have[i];
			stack[++dep] = i;
			if(dep == R) return true;
			if(m > sum){
				dep--;
				if(have[i] < rail[0]) m -= have[i];
				have[i] += rail[R-dep-1];
				k = i + 1;
				continue;
			}
			if(rail[R-dep-1] == rail[R-dep-2]) k = i;
			else k = 0;
		}
	}
	return false;
}
void solve(){
	for(int i = 0;i < N; ++i) bsum += board[i];
	sort(board,board + N,greater<int>());
	sort(rail,rail + R);
	while(R >= 0 && rail[R-1] > board[0]) R--;
	while(N >= 0 && board[N-1] < rail[0]) N--;
	int l,r = 1,mid;
	while(r <= R && check(r)) r *= 2;
	l = r / 2;if(r > R) r = R + 1;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%d\n",l);
}
int main(int argc, char** argv) {
	freopen("fence8.in","r",stdin);
	freopen("fence8.out","w",stdout);
	read();
	solve();
	return 0;
}

