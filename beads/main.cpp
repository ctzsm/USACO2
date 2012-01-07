/*
ID: ctzsm2
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n,ans;
char beads[1100];
int main(int argc, char** argv) {
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d%s",&n,beads);ans = 0;
	for(int i = 0;i < n; ++i) beads[i+n] = beads[i+2*n] = beads[i];
	for(int i = n;i < 2 * n; ++i){
		int k = i,l = i + 1;
		int cntk = 0,cntl = 0;
		char ck = 0,cl = 0;
		while(k >= 0){
			if(beads[k] == 'w') { k--;cntk++;continue; }
			if(ck == 0) ck = beads[k];
			else if(ck != beads[k]) break;
			k--;cntk++;
		}
		while(l < 3 * n){
			if(beads[l] == 'w') { l++;cntl++;continue; }
			if(cl == 0) cl = beads[l];
			else if(cl != beads[l]) break;
			l++;cntl++;
		}
		ans = max(ans,cntk + cntl);
	}
	if(ans > n) ans = n;
	printf("%d\n",ans);
	return 0;
}

