/*
ID: ctzsm2
PROG: milk
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct milkstruct{
	int P,A;
	bool operator < (const milkstruct &m)const{
		return P < m.P;
	}
};
milkstruct milk[5005]; 
int N,M,ans = 0;
int main(int argc, char** argv) {
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i = 0;i < M; ++i) scanf("%d%d",&milk[i].P,&milk[i].A);
	sort(milk,milk + M);
	for(int i = 0;i < M; ++i){
		if(N >= milk[i].A){
			N -= milk[i].A;
			ans += milk[i].P * milk[i].A;
		}else{
			ans += N * milk[i].P;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}

