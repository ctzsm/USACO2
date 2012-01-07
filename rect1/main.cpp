/*
ID: ctzsm2
PROG: rect1
LANG: C++
*/
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int x1[1005],y1[1005],x2[1005],y2[1005],color[1005];
int ans[2505];
void cover(int now,int c,int lx,int ly,int ux,int uy){
	while((now<=n)and((lx>=x2[now])or(ux<=x1[now])or(uy<=y1[now])or(ly>=y2[now]))) now++;
	if(now > n){ ans[c] += (ux - lx) * (uy - ly); return; }
	if(now <= n){
		if(lx<=x1[now]){cover(now+1,c,lx,ly,x1[now],uy); lx=x1[now];}
		if(ux>=x2[now]){cover(now+1,c,x2[now],ly,ux,uy); ux=x2[now];}
		if(ly<=y1[now]){cover(now+1,c,lx,ly,ux,y1[now]); ly=y1[now];}
		if(uy>=y2[now]){cover(now+1,c,lx,y2[now],ux,uy); uy=y2[now];}
	}
}
int main(int argc, char** argv) {
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);
	memset(ans,0,sizeof(ans));
	scanf("%d%d%d",&x2[0],&y2[0],&n);
	x1[0] = y1[0] = 0;color[0] = 1;
	for(int i = 1;i <= n; ++i) scanf("%d%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i],&color[i]);
	for(int i = n;i >= 0; --i) cover(i+1,color[i],x1[i],y1[i],x2[i],y2[i]);
	for(int i = 1;i <= 2500; ++i) if(ans[i]) printf("%d %d\n",i,ans[i]);
	return 0;
}

