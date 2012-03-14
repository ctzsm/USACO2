/*
ID: ctzsm2
PROG: cryptcow
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int TAR;
const char target[] = "Begin the Escape execution at the Break of Dawn";
bool hash[1000005];
char start[100],STR[80],fir[80];
inline unsigned int BKDRhash(const char *str){
	unsigned int seed = 131313,ret = 0;
	while(*str) ret = ret * seed + (*str++);
	return (ret & 0x7fffffff) % 1000003;
}
inline void change(char *str,int c,int o,int w){
	int len = 0,s = strlen(str);
	memset(STR,0,sizeof(STR));
	for(int i = 0;i < c; ++i) STR[len++] = str[i];
	for(int i = o+1;i < w; ++i) STR[len++] = str[i];
	for(int i = c+1;i < o; ++i) STR[len++] = str[i];
	for(int i = w+1;i < s; ++i) STR[len++] = str[i];
	STR[len] = '\0';strcpy(str,STR);
}
inline bool dfscut(const char *str){
	int len = -1,Len,i,lens  = strlen(str);
	bool flag,Flag;
	while(++len < lens && str[len] != 'C')
		if(target[len] != str[len]) return true;
	i = 47;Len = len + 1;len = lens;
	while(len > 0 && str[len-1] != 'W')
		if(target[--i] != str[--len]) return true;
	lens = len;len = Len;Len = -1;
	while(len < lens){
		while(++len < lens && str[len] != 'C' && str[len] != 'O' && str[len] != 'W')
			fir[++Len] = str[len];
		Flag = false;
		if(len <= lens){
			for(int i = 0;i < 47 - Len; ++i){
				flag = true;
				for(int j = i;j <= i + Len; ++j)
					if(fir[j-i] != target[j]){ flag = false;break; }
				if(flag) { Flag = true; break; }
			}
		}
		if(!Flag) return true;
		Len = -1;
	}
	return false;
}
bool dfs(char *str,int d){
	char DFS[77];
	int HASH = BKDRhash(str);
	if(hash[HASH]) return false;
	else if(HASH == TAR) {
		printf("1 %d\n",d);return true;
	}
	hash[HASH] = true;
	if(dfscut(str)) return false;
	int len = strlen(str);
	for(int o = 0;o < len; ++o){
		if(str[o] == 'O')
			for(int c = 0;c < o; ++c)
				if(str[c] == 'C')
					for(int w = len - 1;w > o; --w)
						if(str[w] == 'W'){
							strcpy(DFS,str);
							change(DFS,c,o,w);
							if(dfs(DFS,d+1)) return true;
						}
	}
	return false;
}
int main(int argc, char** argv) {
	freopen("cryptcow.in","r",stdin);
	freopen("cryptcow.out","w",stdout);
	TAR = BKDRhash(target);
	cin.getline(start,100,'\n');
	cerr << start[0] << endl;
	if(!((strlen(start) - 47) % 3) && !dfs(start,0))
		printf("0 0\n");
	return 0;
}

