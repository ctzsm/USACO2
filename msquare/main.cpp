/*
ID: ctzsm2
PROG: msquare
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>

using namespace std;

set<int> hash;
int target = 0;
struct statu{
	int a;
	short step;
	char ans[20];
}init;
// A87654321
int opA(int s){
	int a[8],cnt = 0,ret = 0;
	while(s){ a[cnt++] = s % 10;s /= 10; }
	for(int i = 0;i < 8; ++i) ret *= 10,ret += a[i];
	return ret;
}
// B41236785
int opB(int s){
	int a[8],cnt = 0,ret = 0,t;
	while(s){ a[7-cnt] = s % 10;s /= 10;cnt++; }
	t = a[3];a[3] = a[2];a[2] = a[1];a[1] = a[0];a[0] = t;
	t = a[4];a[4] = a[5];a[5] = a[6];a[6] = a[7];a[7] = t;
	for(int i = 0;i < 8; ++i) ret *= 10,ret += a[i];
	return ret;
}
// C17245368
int opC(int s){
	int a[8],cnt = 0,ret = 0,t;
	while(s){ a[7-cnt] = s % 10;s /= 10;cnt++; }
	t = a[1];a[1] = a[2];a[2] = t;
	t = a[1];a[1] = a[6];a[6] = a[5];a[5] = t;
	for(int i = 0;i < 8; ++i) ret *= 10,ret += a[i];
	return ret;
}
void BFS(){
	queue<statu> q;q.push(init);
	while(!q.empty()){
		statu now = q.front();
		if(now.a == target){
			printf("%d\n",now.step);
			now.ans[now.step] = '\0';
			printf("%s\n",now.ans);
			break;
		}
		q.pop();
		statu next = now;
		next.step = now.step + 1;
		next.a = opA(now.a);
		if(hash.find(next.a) == hash.end()){
			hash.insert(next.a);next.ans[next.step - 1] = 'A';
			q.push(next);
		}
		next.a = opB(now.a);
		if(hash.find(next.a) == hash.end()){
			hash.insert(next.a);next.ans[next.step - 1] = 'B';
			q.push(next);
		}
		next.a = opC(now.a);
		if(hash.find(next.a) == hash.end()){
			hash.insert(next.a);next.ans[next.step - 1] = 'C';
			q.push(next);
		}
	}
}
int main(int argc, char** argv) {
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	for(int i = 0;i < 8; ++i){
		int x;scanf("%d",&x);
		target *= 10;target += x;
	}
	init.a = 12345678;init.step = 0;
	BFS();
	return 0;
}

