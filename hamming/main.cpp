/*
ID: ctzsm2
PROG: hamming
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int N,B,D,mask;
int ans[65] = {0};
bool gflag = false;
inline bool check(int a,int b){
	int t = (a ^ b) & mask,c = 0;
	while(t){
		int p = t & -t;
		t -= p;
		c++;
	}
	if(c >= D) return true;
	return false;
}
void print(){
	for(int i = 0;i < N; ++i)
		printf("%d%c",ans[i],((i + 1) % 10 == 0 || i == N - 1 ) ? '\n' : ' ');
}
void dfs(int d,int pos){
	if(gflag) return;
	if(d == N){
		print();gflag = true;return;
	}
	for(int i = pos;i <= mask; ++i){
		bool flag = true;
		for(int j = 0;j < d; ++j){
			if(!check(ans[j],i)) {flag = false;break;}
		}
		if(flag){
			ans[d] = i;
			dfs(d+1,i+1);
		}
		if(gflag) return;
	}
}
int main(int argc, char** argv) {
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d%d%d",&N,&B,&D);
	mask = (1 << B) - 1;
//	printf("%d\n",mask);
	dfs(1,1);
	return 0;
}

