/*
ID: ctzsm2
PROG: contact
LANG: C++
*/
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct ansstruct{
	string s;
	int n;
	bool operator < (const ansstruct &b)const{
		if(n == b.n){
			if(s.size() == b.s.size()) return s < b.s;
			return s.size() < b.s.size();
		}
		return n > b.n;
	}
}ans[10000];
int A,B,N,len = 1,anscnt = 0;
char s[200005];
map<string,int> dic;
int cnt[200005];
int main(int argc, char** argv) {
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	scanf("%d%d%d",&A,&B,&N);
	while(s[0] = getchar()){
		if(s[0] == '1' || s[0] == '0') break;
	}
	while(fgets(s+len,1024,stdin)){
		int t = strlen(s+len);
		len += t;
		while((s[len] != '0' && s[len] != '1' && len >= 0)) len--;len++;
	}
	for(int i = 0;i < len; ++i){
		string t("");
		for(int k = 0;k < B && k + i < len; ++k){
			t += s[k+i];
			if(k >= A - 1)	dic[t]++;
		}
	}
//	cerr << dic["1"] << endl;
	for(map<string,int>::iterator it = dic.begin();it != dic.end(); ++it){
		ans[anscnt].s = (*it).first;
		ans[anscnt].n = (*it).second;
		cnt[ans[anscnt].n]++;
		anscnt++;
	}
	sort(ans,ans+anscnt);
//	for(int i = 10000;i >= 0; --i) if(cnt[i]) printf("%d\n",cnt[i]);
	int outcnt = 0;
	for(int i = 0;i < anscnt;){
		int x = ans[i].n;
		printf("%d\n",x);
		for(int j = 0;j < cnt[x]; ++j,++i){
			printf("%s%c",ans[i].s.c_str(),(j == cnt[x] - 1 || (j + 1) % 6 == 0)? '\n' : ' ');
		}
		outcnt++;
		if(outcnt >= N) break;
	}
	return 0;
}

//Compiling...
//Compile: OK
//
//Executing...
//   Test 1: TEST OK [0.000 secs, 4244 KB]
//   Test 2: TEST OK [0.000 secs, 4244 KB]
//   Test 3: TEST OK [0.011 secs, 4244 KB]
//   Test 4: TEST OK [0.043 secs, 4244 KB]
//   Test 5: TEST OK [0.238 secs, 4508 KB]
//   Test 6: TEST OK [0.227 secs, 4244 KB]
//   Test 7: TEST OK [0.346 secs, 4508 KB]
//
//All tests OK.
//Your program ('contact') produced all correct answers!  This is your
//submission #7 for this problem.  Congratulations!



