/*
ID: ctzsm2
PROG: cowtour
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const double oo = 1e200;
struct pnt{
	double x,y;
};
pnt p[160];
int n;
char s[160];
bool map[160][160];
double dis[160][160];
inline double dist(pnt a,pnt b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int main(int argc, char** argv) {
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i) scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i = 1;i <= n; ++i) {
		scanf("%s",s);
		for(int j = 0;j < n; ++j)
			map[i][j+1] = (s[j] == '0') ? false : true;
	}
	for(int i = 1;i <= n; ++i) for(int j = i + 1;j <= n; ++j){
		if(map[i][j]) dis[i][j] = dis[j][i] = dist(p[i],p[j]);
		else dis[i][j] = dis[j][i] = oo;
	}
//	for(int i = 1;i <= n; ++i){
//		for(int j = 1;j <= n; ++j) printf("%.3f\t",dis[i][j]);
//		printf("\n");
//	}
	for(int k = 1;k <= n; ++k)for(int i = 1;i <= n; ++i)for(int j = 1;j <= n; ++j)
		if(dis[i][j] > dis[i][k] + dis[k][j])
			dis[i][j] = dis[i][k] + dis[k][j];
	double ans = oo,lans = 0.0;
	for(int i = 1;i <= n; ++i) for(int j = i + 1;j <= n; ++j) 
		if(dis[i][j] < oo) lans = max(lans,dis[i][j]);
	for(int i = 1;i <= n; ++i) for(int j = i + 1;j <= n; ++j){
		if(dis[i][j] < oo) continue;
		double imax = 0.0,jmax = 0.0;
		for(int k = 1;k <= n; ++k) if(dis[i][k] != oo && k != i) imax = max(imax,dis[i][k]);
		for(int k = 1;k <= n; ++k) if(dis[j][k] != oo && k != j) jmax = max(jmax,dis[j][k]);
		ans = min(ans,dist(p[i],p[j]) + imax + jmax);
	}
	printf("%.6f\n",max(ans,lans));
	return 0;
}

