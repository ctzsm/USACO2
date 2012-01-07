/*
ID: ctzsm2
PROG: lamps
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>

using namespace std;

int N,C,x,deep;
bool a[105];
int on[105],off[105],cnton = 0,cntoff = 0;
set<vector<bool> > ans;
void button1(){ for(int i = 0;i < N; ++i) a[i] = !a[i]; }
void button2(){ for(int i = 0;i < N; i += 2) a[i] = !a[i]; }
void button3(){ for(int i = 1;i < N; i += 2) a[i] = !a[i]; }
void button4(){ for(int i = 0;i < N; i += 3) a[i] = !a[i]; }
bool check(){
	for(int i = 0;i < cnton; ++i) if(!a[on[i]]) return false;
	for(int i = 0;i < cntoff; ++i) if(a[off[i]]) return false;
	return true;
}

void dfs(int d){
	if(d == deep){
		if(!check()) return;
		vector<bool> lights;
		for(int i = 0;i < N; ++i) lights.push_back(a[i]);
		ans.insert(lights);
		return;
	}
	dfs(d + 1);button1();dfs(d + 1);button1();
	dfs(d + 1);button2();dfs(d + 1);button2();
	dfs(d + 1);button3();dfs(d + 1);button3();
	dfs(d + 1);button4();dfs(d + 1);button4();
}
int main(int argc, char** argv) {
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d%d",&N,&C);
	while(scanf("%d",&x),~(x)) on[cnton++] = x - 1;
	while(scanf("%d",&x),~(x)) off[cntoff++] = x - 1;
	if(C > 4){ 
		if(C % 4 == 0) deep = 4;
		else deep = C % 4;
	}else{ deep = C; }
	for(int i = 0;i < N; ++i) a[i] = true;
	dfs(0);
	for(set<vector<bool> >::iterator it = ans.begin();it != ans.end(); ++it){
		for(int i = 0;i < N; ++i) printf("%d",(*it)[i]);
		printf("\n");
	}
	if(ans.size() == 0) printf("IMPOSSIBLE\n");
	return 0;
}

