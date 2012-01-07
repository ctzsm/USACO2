/*
ID: ctzsm2
PROG: sprime
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxn = 10001;
int prime[maxn],num_prime = 0;
bool isNotPrime[maxn] = {true,true};
int n;
void getPrime(){
	for(int i = 2;i < maxn; ++i){
		if(!isNotPrime[i]) prime[num_prime++] = i;
		for(int j = 0;j < num_prime && i * prime[j] < maxn; ++j){
			isNotPrime[i * prime[j]] = true;
			if(!(i % prime[j])) break;
		}
	}
}
int num[2][5] = {
	{2,3,5,7},
	{1,3,5,7,9}
};
int x;
void dfs(int d){
	if(d == n){
		printf("%d\n",x);
		return;
	}
	if(d == 0){
		for(int i = 0;i < 4; ++i){
			x = num[0][i];
			dfs(d + 1);
			x = 0;
		}
	}else{
		for(int i = 0;i < 5; ++i){
			x *= 10;
			x += num[1][i];
			if(x < maxn && !isNotPrime[x]) dfs(d + 1);
			if(x >= maxn){
				bool flag = true;
				for(int j = 0;j < num_prime; ++j){
					if(x % prime[j] == 0){ flag = false;break; }
				}
				if(flag) dfs(d + 1);
			}
			x /= 10;
		}
	}
}
int main(int argc, char** argv) {
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	getPrime();
	scanf("%d",&n);
	dfs(0);
	return 0;
}

