/*
ID: ctzsm2
PROG: barn1
LANG: C++
*/

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int M,S,C,x,ans;
bool stall[202];
int record[202],cnt = 0;
int main(int argc, char** argv) {
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	scanf("%d%d%d",&M,&S,&C);
	for(int i = 0;i < C; ++i){
		scanf("%d",&x);stall[x] = true;
	}
	int begin = 1,end = S;
	while(!stall[begin])begin++;
	while(!stall[end])end--;
	stall[end+1] = true;
	int cnti = 0;
	for(int i = begin;i <= end; ++i){
		if(stall[i] && !stall[i+1]){
			cnti = 0;
		}
		if(!stall[i]) cnti ++;
		if(!stall[i] && stall[i+1]){
			record[cnt++] = cnti;
		}
	}
	sort(record,record + cnt);
	ans = end - begin + 1;
	for(int i = 0;i < M - 1 && cnt - 1 - i >= 0; ++i){
		ans -= record[cnt - 1 - i];
	}
	printf("%d\n",ans);
	return 0;
}

