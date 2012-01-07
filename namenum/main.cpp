/*
ID: ctzsm2
PROG: namenum
LANG: C++
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <set>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

string s;
set<string> dic;
char name[15];
bool gflag = false;
int n;
char tran[][5] = {
	"",
	"",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PRS",
	"TUV",
	"WXY"
};
void dfs(int d){
	if(d == n){
		name[d] = '\0';
		string tofind(name);
		if(dic.find(tofind) != dic.end()){
			gflag = true; cout << tofind << endl;
		}
		return;
	}
	for(int i = 0;i < 3; ++i){
		name[d] = tran[s[d] - '0'][i];
		dfs(d+1);
	}
}
int main(int argc, char** argv) {
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	ifstream readdic("dict.txt");
	while(readdic >> s)dic.insert(s);
	cin >> s;n = s.size();
	dfs(0);
	if(!gflag) cout << "NONE" << endl;
	return 0;
}

