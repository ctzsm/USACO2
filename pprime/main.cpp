/*
ID: ctzsm2
PROG: pprime
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 10005;
int prime[maxn],num_prime = 0;
bool isNotPrime[maxn] = {true,true};
int a,b;
char s[15];
int base[] = {1,10,100,1000};
void getPrime(){
	for(int i = 2;i < maxn; ++i){
		if(!isNotPrime[i]) prime[num_prime++] = i;
		for(int j = 0;j < num_prime && i * prime[j] < maxn; ++j){
			isNotPrime[i * prime[j]] = true;
			if(!(i % prime[j])) break;
		}
	}
}
int main(int argc, char** argv) {
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	getPrime();
	scanf("%d%d",&a,&b);
	int x;
	if(a <= 5 && 5 <= b) printf("5\n");
	if(a <= 7 && 7 <= b) printf("7\n");
	if(a <= 11 && 11 <= b) printf("11\n");
	for(int i = 4;i < 10000; ++i){
		sprintf(s,"%d",i);
		int len = strlen(s);
		x = 0;
		int t = s[0] - '0';
		if(!(t & 1)){
			i = s[0] - '0' + 1;
			for(int j = 0;j < len - 1; ++j){
				i *= 10;
			}
			continue;
		}
		if(len == 1) x = i;
		else{
			for(int j = 0;j < len; ++j){
				x *= 10;x += (s[j] - '0');
			}
			for(int j = len - 2;j >= 0; --j){
				x *= 10;x += (s[j] - '0');
			}
		}
		if(x < a) continue;
		if(x > b) break;
		if(x < maxn && isNotPrime[x]) continue;
		if(x >= maxn){
			bool flag = true;
			for(int j = 0;j < num_prime; ++j){
				if((x % prime[j]) == 0) {flag = false;break;}
			}
			if(!flag) continue;
		}
		printf("%d\n",x);
	}
	return 0;
}

//Executing...
//   Test 1: TEST OK [0.000 secs, 3096 KB]
//   Test 2: TEST OK [0.000 secs, 3096 KB]
//   Test 3: TEST OK [0.000 secs, 3096 KB]
//   Test 4: TEST OK [0.011 secs, 3096 KB]
//   Test 5: TEST OK [0.011 secs, 3096 KB]
//   Test 6: TEST OK [0.011 secs, 3096 KB]
//   Test 7: TEST OK [0.043 secs, 3096 KB]
//   Test 8: TEST OK [0.032 secs, 3096 KB]
//   Test 9: TEST OK [0.032 secs, 3096 KB]
//
//All tests OK.
