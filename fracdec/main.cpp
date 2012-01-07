/*
ID: ctzsm2
PROG: fracdec
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int N,D,cnt = 1,begin = 0;
int visit[100005];
char ans[100005];
char s[100005];
int main(int argc, char** argv) {
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	scanf("%d%d",&N,&D);
	if(N % D == 0){
		printf("%d.0\n",N / D);return 0;
	}
	sprintf(s,"%d",N / D);
	string out(s);out += '.';
	int t = -1;N %= D;
	while(true){
//		printf("%d\n",t);
		t = N % D;
		if(t == 0){visit[0] = true;break;}
		N *= 10;
		if(t != -1 && visit[t]){begin = visit[t];break;}
		ans[cnt] = (N / D) + '0';
		visit[t] = cnt++;
		N %= D;
	}
	if(visit[0]){
		for(int i = 1;i < cnt; ++i) out += ans[i];
	}else{
		for(int i = 1;i < cnt; ++i){
			if(i == begin) out += '(';
			out += ans[i];
		}
		out += ')';
	}
	for(int i = 0;i < out.size(); ++i){
		printf("%c",out[i]);
		if((i + 1) % 76 == 0 || i == out.size() - 1) printf("\n");
	}
	return 0;
}

