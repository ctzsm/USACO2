/*
ID: ctzsm2
PROG: calfflac
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;
string tofind,s,trans;
int pos[200005],cpos = 0,ans = 0;
int main(int argc, char** argv) {
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	while(getline(cin,s)) tofind += s,tofind += '\n';
	int n = tofind.size();
	for(int i = 0;i < n; ++i){
		if(isalpha(tofind[i])){
			trans += toupper(tofind[i]);
			pos[cpos++] = i;
		}
	}
	int posb,pose;
	n = trans.size();
	for(int i = 0;i < n; ++i){
		int j = 0;
		while(i - j >= 0 && i + j < n){
			if(trans[i-j] != trans[i+j]) break;
			j++;
		}
		int t = (j - 1) * 2 + 1;
		if(ans < t){
			ans = t;posb = pos[i - j + 1];pose = pos[i + j - 1];
		}
		j = 0;
		while(i - j >= 0 && i + j + 1 < n){
			if(trans[i-j] != trans[i+j+1]) break;
			j++;
		}
		t = j * 2;
		if(ans < t){
			ans = t;posb = pos[i - j + 1];pose = pos[i + j];
		}
	}
	printf("%d\n%s\n",ans,tofind.substr(posb,pose - posb + 1).c_str());
	return 0;
}
