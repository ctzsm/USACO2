/*
ID: ctzsm2
PROG: gift1
LANG: C++
*/
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int n;
vector<string> name;
map<string,int> hash;
int money[15];
int main(int argc, char** argv) {
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	cin >> n;
	memset(money,0,sizeof(money));
	name.clear();hash.clear();
	for(int i = 0;i < n; ++i){
		string s;cin >> s;
		name.push_back(s);hash[s] = i;
	}
	for(int i = 0;i < n; ++i){
		string s;cin >> s;
		int a,m;cin >> a >> m;
		if(m == 0) continue;
		money[hash[s]] -= a;
		money[hash[s]] += (a % m);
		for(int j = 0;j < m; ++j){
			cin >> s;
			money[hash[s]] += (a / m);
		}
	}
	for(int i = 0;i < n; ++i) cout << name[i] << " " << money[i] << endl;
	return 0;
}

