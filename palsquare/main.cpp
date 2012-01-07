/*
ID: ctzsm2
PROG: palsquare
LANG: C++
*/
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

char tochar[2][100],num[] = "0123456789ABCDEFGHIJKLMNOPQRST";
int B;
bool check(int x){
	int cnt = 0,y = x * x;
	while(x){
		tochar[0][cnt++] = num[x % B];
		x /= B;
	}
	char t;
	for(int i = 0;i < cnt / 2; ++i)t = tochar[0][i],tochar[0][i] = tochar[0][cnt - 1 - i],tochar[0][cnt - 1- i] = t;
	tochar[0][cnt] = '\0';
	cnt = 0;
	while(y){
		tochar[1][cnt++] = num[y % B];
		y /= B;
	}
	tochar[1][cnt] = '\0';
	for(int i = 0;i < cnt; ++i){
		if(tochar[1][i] != tochar[1][cnt - 1 - i]) return false;
	}
	return true;
}
int main(int argc, char** argv) {
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	scanf("%d",&B);
	for(int i = 1;i <= 300; ++i){
		if(check(i)){
			printf("%s %s\n",tochar[0],tochar[1]);
		}
	}
	return 0;
}

