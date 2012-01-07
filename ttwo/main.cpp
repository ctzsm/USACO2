/*
ID: ctzsm2
PROG: ttwo
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

char map[11][11];
int fi,fj,ci,cj,fd,cd;
void change(int &d,int &i,int &j){
	if(d == 0){
		if(i - 1 >= 0 && map[i-1][j] != '*') i -= 1;
		else d = 1;
		return;
	}
	if(d == 1){
		if(j + 1 < 10 && map[i][j+1] != '*') j += 1;
		else d = 2;
		return;
	}
	if(d == 2){
		if(i + 1 < 10 && map[i+1][j] != '*') i += 1;
		else d = 3;
		return;
	}
	if(d == 3){
		if(j - 1 >= 0 && map[i][j-1] != '*') j -= 1;
		else d = 0;
		return;
	}
	
}
int main(int argc, char** argv) {
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	for(int i = 0;i < 10; ++i) scanf("%s",map[i]);
	for(int i = 0;i < 10; ++i) for(int j = 0;j < 10; ++j){
		if(map[i][j] == 'F') fi = i,fj = j;
		if(map[i][j] == 'C') ci = i,cj = j;
	}
	int ans = 0;
	fd = cd = 0;
	while(true){
		change(fd,fi,fj);
		change(cd,ci,cj);
		ans++;
		if(fi == ci && fj == cj) break;
		if(ans >= 1000000){ans = 0;break;}
	}
	printf("%d\n",ans);
	return 0;
}

