/*
ID: ctzsm2
PROG: packrec
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct seqstruct{
	int p,q;
	bool operator < (const seqstruct &b)const{
		return p < b.p;
	}
}seq[100000];
int rec[4][2];
int a[4],ans,poss = 0,p,q;
bool visit[4];
void compare(){
	if(ans > p * q){
		poss = 0;
		ans = p * q;seq[poss].p = min(p,q);
		seq[poss].q = max(p,q);poss++;
	}else if(ans == p * q){
		seq[poss].p = min(p,q);
		seq[poss].q = max(p,q);poss++;
	}
}
void getans(){
	//1
	p = rec[a[0]][0] + rec[a[1]][0] + rec[a[2]][0] + rec[a[3]][0];
	q = max(rec[a[0]][1],max(rec[a[1]][1],max(rec[a[2]][1],rec[a[3]][1])));
	compare();
	//2
	p = max(rec[a[0]][0] + rec[a[1]][0] + rec[a[2]][0],rec[a[3]][0]);
	q = max(rec[a[0]][1],max(rec[a[1]][1],rec[a[2]][1])) + rec[a[3]][1];
	compare();
	//3
	p = max(rec[a[0]][0] + rec[a[1]][0],rec[a[2]][0]) + rec[a[3]][0];
	q = max(max(rec[a[0]][1],rec[a[1]][1]) + rec[a[2]][1],rec[a[3]][1]);
	compare();
	//4
	p = rec[a[0]][0] + max(rec[a[1]][0],rec[a[2]][0]) + rec[a[3]][0];
	q = max(rec[a[0]][1],max(rec[a[1]][1] + rec[a[2]][1],rec[a[3]][1]));
	compare();
	//5
	p = max(rec[a[0]][0],rec[a[1]][0]) + rec[a[2]][0] + rec[a[3]][0];
	q = max(max(rec[a[0]][1] + rec[a[1]][1],rec[a[2]][1]),rec[a[3]][1]);
	compare();
	//6
	p = rec[a[0]][0] + rec[a[1]][0];
	q = max(rec[a[0]][1] + rec[a[2]][1],rec[a[1]][1] + rec[a[3]][1]);
	if(rec[a[0]][1] < rec[a[1]][1])
		p = max(p,rec[a[2]][0] + rec[a[1]][0]);
	if(rec[a[0]][1] + rec[a[2]][1] > rec[a[1]][1])
		p = max(p,rec[a[2]][0] + rec[a[3]][0]);
	if(rec[a[1]][1] < rec[a[0]][1])
		p = max(p,rec[a[0]][0] + rec[a[3]][0]);
	p = max(p,rec[a[2]][0]);
	p = max(p,rec[a[3]][0]);
	compare();
}
void work(){
	for(int i = 0;i < 2; ++i) for(int j = 0;j < 2; ++j) for(int k = 0;k < 2; ++k) for(int l = 0;l < 2; ++l){
		if(i == 1) swap(rec[a[0]][0],rec[a[0]][1]);
		if(j == 1) swap(rec[a[1]][0],rec[a[1]][1]);
		if(k == 1) swap(rec[a[2]][0],rec[a[2]][1]);
		if(l == 1) swap(rec[a[3]][0],rec[a[3]][1]);
		getans();
		if(i == 1) swap(rec[a[0]][0],rec[a[0]][1]);
		if(j == 1) swap(rec[a[1]][0],rec[a[1]][1]);
		if(k == 1) swap(rec[a[2]][0],rec[a[2]][1]);
		if(l == 1) swap(rec[a[3]][0],rec[a[3]][1]);
	}
}
void generate(int d){
	if(d == 4){
		work();
//		printf("%d%d%d%d\n",a[0],a[1],a[2],a[3]);
		return;
	}
	for(int i = 0;i < 4; ++i){
		if(!visit[i]){
			visit[i] = true;
			a[d] = i;
			generate(d+1);
			visit[i] = false;
		}
	}
}
int main(int argc, char** argv) {
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	for(int i = 0;i < 4; ++i) scanf("%d%d",&rec[i][0],&rec[i][1]);
	ans = 0x3fffffff;
	generate(0);
	printf("%d\n",ans);
	sort(seq,seq + poss);
	for(int i = 0;i < poss; ++i){
		while(seq[i].p == seq[i+1].p && seq[i].q == seq[i+1].q) i++;
		printf("%d %d\n",seq[i].p,seq[i].q);
	}
	return 0;
}

