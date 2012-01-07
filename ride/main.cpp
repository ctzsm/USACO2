/*
ID: ctzsm2
PROG: ride
LANG: C++
*/
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

char s[7],t[7];
int calc(char x[]){
	int ret = 1,len = strlen(x);
	for(int i = 0;i < len; ++i) ret *= (x[i] - 'A' + 1),ret %= 47;
	return ret;
}
int main(int argc, char** argv) {
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	scanf("%s%s",s,t);
	if(calc(s) == calc(t)) printf("GO\n");
	else printf("STAY\n");
	return 0;
}

