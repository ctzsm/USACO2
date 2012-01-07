/*
ID: ctzsm2
PROG: dualpal
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

bool check(int x){
	int cnt = 0;
	char tochar[100];
	for(int b = 2;b <= 10; ++b){
		int xx = x,c = 0;
		while(xx){
			tochar[c++] = xx % b;
			xx /= b;
		}
		bool flag = true;
		for(int i = 0;i < c / 2; ++i){
			if(tochar[i] != tochar[c - 1 - i]){flag = false;break;}
		}
		if(flag) cnt++;
		if(cnt == 2) break;
	}
	if(cnt >= 2) return true;
	else return false;
}
int N,S;
int main(int argc, char** argv) {
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	scanf("%d%d",&N,&S);
	int cnt = 0;
	for(int i = S + 1;; ++i){
		if(check(i)){
			printf("%d\n",i);
			cnt++;
		}
		if(cnt >= N) break;
	}
	return 0;
}

