/*
ID: ctzsm2
PROG: milk3
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int a,b,c,d;
bool label[25];
int main(int argc, char** argv) {
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	if(a > c) a = c;if(b > c) b = c;
	if(a <= b){
		for(int i = 0;i <= 20; ++i){
			d = c + a * i;
			while(d >= c) d -= b;
			label[d] = true;
			if(d < b && c < d + a) break;
		}
	}else{
		for(int i = 0;i <= 20; ++i){
			d = c - b * i;
			while(d >= b){
				d -= b;
				if(c - d > a){
					d = d + a;
					label[d] = true;
				}
			}
		}
	}
	label[c - b] = true;
	for(int i = 0;i <= 20; ++i){
		d = c - a * i;
		while(d < c - b) d += b;
		label[d] = true;
		if(d < a && c - d < b) break;
	}
	for(int i = 0;i < c; ++i) if(label[i]) printf("%d ",i);
	printf("%d\n",c);
	return 0;
}

