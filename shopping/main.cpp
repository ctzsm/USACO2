/*
ID: ctzsm2
PROG: shopping
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct scase{
	int c,p;
	int code[5],num[5];
}combine[106];
struct object{
	int c,k,p;
}obj[5];
int S,B;
bool need[1000];
int tran[1000];
int ans[6][6][6][6][6];
int dfs(int a,int b,int c,int d,int e){
	if(ans[a][b][c][d][e] != -1) return ans[a][b][c][d][e];
	ans[a][b][c][d][e] = 0x3fffffff;
	for(int i = 0;i < S; ++i){
		bool flag = false;
		int w[6];memset(w,0,sizeof(w));
		for(int j = 0;j < combine[i].c; ++j){
			if(!need[combine[i].code[j]]) { flag = true;break; }
		}
		if(flag) continue;
		for(int j = 0;j < combine[i].c; ++j) w[combine[i].code[j]] = combine[i].num[j];
		if(a >= w[1] && b >= w[2] && c >= w[3] && d >= w[4] && e >= w[5])
			ans[a][b][c][d][e] = min(ans[a][b][c][d][e],dfs(a-w[1],b-w[2],c-w[3],d-w[4],e-w[5]) + combine[i].p);
	}
	return ans[a][b][c][d][e];
}
int main(int argc, char** argv) {
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d",&S);
	for(int i = 0;i < S; ++i){
		scanf("%d",&combine[i].c);
		for(int j = 0;j < combine[i].c; ++j){
			scanf("%d%d",&combine[i].code[j],&combine[i].num[j]);
		}
		scanf("%d",&combine[i].p);
	}
	scanf("%d",&B);
	memset(ans,-1,sizeof(ans));
	ans[0][0][0][0][0] = 0;
	for(int i = 0;i <= 999; ++i) tran[i] = 1000;
	for(int i = 0;i < B; ++i){
		scanf("%d%d%d",&obj[i].c,&obj[i].k,&obj[i].p);
		tran[obj[i].c] = i + 1;obj[i].c = tran[obj[i].c];
		need[obj[i].c] = true;
	}
	for(int i = B;i < 5; ++i){
		obj[i].c = 1000;obj[i].k = obj[i].p = 0;
	}
	for(int i = 0;i < S; ++i) for(int j = 0;j < combine[i].c; ++j){
		combine[i].code[j] = tran[combine[i].code[j]];
	}
	for(int i = S;i < S + B; ++i){
		combine[i].c = 1;
		combine[i].code[0] = obj[i-S].c;
		combine[i].num[0] = 1;
		combine[i].p = obj[i-S].p;
	}
	S += B;
	dfs(obj[0].k,obj[1].k,obj[2].k,obj[3].k,obj[4].k);
	printf("%d\n",ans[obj[0].k][obj[1].k][obj[2].k][obj[3].k][obj[4].k]);
	return 0;
}

