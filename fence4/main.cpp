/*
ID: ctzsm2
PROG: fence4
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 201;
int n;
double pos[maxn][2],obx,oby;
int cansee[maxn];
int side(double sx,double sy,double ex,double ey,int p){
	double dx = ex - sx,dy = ey - sy;
	double px = pos[p][0] - sx,py = pos[p][1] - sy;
	double t = dx * py - dy * px;
	if(t > 1e-5) return 0;
	if(t < -1e-5) return 1;
	return 2;
}
int first_inter(double sx,double sy,double ex,double ey){
	double mmin = 1e10,mlbrush = 1e10,mrbrush = 1e10;
	int mloc = n;
	for(int i = 0;i < n; ++i){
		double ax = pos[i][0],ay = pos[i][1];
		double bx = pos[i+1][0],by = pos[i+1][1];
		double t = (ex - sx) * (ay - by) - (ey - sy) * (ax - bx);
		if(t > -1e-5 && t < 1e-5) continue;
		double cnst = (ax - sx) * (by - ay) - (ay - sy) * (bx - ax);
		double coef = (ex - sx) * (by - ay) - (ey - sy) * (bx - ax);
		if(coef > -1e-5 && coef < 1e-5){
			if(bx - ax > -1e-5 && bx - ax < 1e-5){
				cnst = ax - sx;
				coef = ex - sx;
			}else{
				cnst = ay - sy;
				coef = ey - sy;
			}
		}
		double j = cnst / coef;
		if(j < -1e-5) continue;
		cnst = sx + (ex - sx) * j - ax;
		coef = bx - ax;
		if(coef > -1e-5 && coef < 1e-5){
			cnst = sy + (ey - sy) * j - ay;
			coef = by - ay;
		}
		double ii = cnst / coef;
		if(ii < -1e-5 || ii > 1.00001) continue;
		double x = ax + (bx - ax) * ii;
		double y = ay + (by - ay) * ii;
		int t1,t2;
		t = (x - sx) * (ex - sx) + (y - sy) * (ey - sy);
		if(t < -1e-5 || t > mmin) continue;
		if(ii < 1e-5 || ii > 0.99999){
			if(ii < 1e-5){
				t1 = i - 1;
				if(t1 < 0) t1 += n;
				t2 = i + 1;
			}else{
				t1 = i;
				t2 = i + 2;
				if(t2 >= n) t2 -= n;
			}
			int s1 = side(sx,sy,ex,ey,t1);
			int s2 = side(sx,sy,ex,ey,t2);
			if(s1 == s2){
				if(s1 == 0 && t < mlbrush) mlbrush = t;
				if(s1 == 1 && t < mrbrush) mrbrush = t;
				continue;
			}
		}
		mmin = t;
		mloc = i;
	}
	if(mmin > mlbrush && mmin > mrbrush) return n;
	return mloc;
}
bool intersect(int i,int j){
	if(side(pos[i][0],pos[i][1],pos[i+1][0],pos[i+1][1],j) == side(pos[i][0],pos[i][1],pos[i+1][0],pos[i+1][1],j+1))
		return false;
	if(side(pos[j][0],pos[j][1],pos[j+1][0],pos[j+1][1],i) == side(pos[j][0],pos[j][1],pos[j+1][0],pos[j+1][1],i+1))
		return false;
	return true;
}
int main(int argc, char** argv) {
	freopen("fence4.in","r",stdin);
	freopen("fence4.out","w",stdout);
	scanf("%d",&n);scanf("%lf%lf",&obx,&oby);
	for(int i = 0;i < n; ++i) scanf("%lf%lf",&pos[i][0],&pos[i][1]);
	pos[n][0] = pos[0][0];
	pos[n][1] = pos[0][1];
	for(int i = 0;i < n; ++i) for(int j = i + 2;j < n; ++j){
		if(intersect(i,j)){
			if(i == 0 && j == n - 1) continue;
			printf("NOFENCE\n");
			return 0;
		}
	}
	for(int i = 0;i < n; ++i){
		cansee[first_inter(obx,oby,pos[i][0],pos[i][1])] = 1;
		cansee[first_inter(obx,oby,(pos[i][0] + pos[i+1][0]) * 0.5,(pos[i][1] + pos[i+1][1]) * 0.5)] = 1;
	}
	int cnt = 0;
	for(int i = 0;i < n; ++i) if(cansee[i]) cnt++;
	printf("%d\n",cnt);
	for(int i = 0;i < n - 2; ++i){
		if(cansee[i])
			printf("%.0f %.0f %.0f %.0f\n",pos[i][0],pos[i][1],pos[i+1][0],pos[i+1][1]);
	}
	if(cansee[n-1]) printf("%.0f %.0f %.0f %.0f\n",pos[0][0],pos[0][1],pos[n-1][0],pos[n-1][1]);
	if(cansee[n-2]) printf("%.0f %.0f %.0f %.0f\n",pos[n-2][0],pos[n-2][1],pos[n-1][0],pos[n-1][1]);
	return 0;
}

