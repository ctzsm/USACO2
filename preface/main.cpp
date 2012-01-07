/*
ID: ctzsm2
PROG: preface
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

char ROMANSET[] = "IVXLCDM";
string BASIC_ROMAN_NUMBERS[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
int BASIC_VALUES[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
int ans[7],n;
string toRoman(int value){
	string ret("");
	for(int i = 0;i < 13; ++i){
		while(value >= BASIC_VALUES[i]){
			ret += BASIC_ROMAN_NUMBERS[i];
			value -= BASIC_VALUES[i];
		}
	}
	return ret;
}
int main(int argc, char** argv) {
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i){
		string s = toRoman(i);
		for(int j = 0;j < s.size(); ++j){
			if(s[j] == 'I') ans[0]++;
			if(s[j] == 'V') ans[1]++;
			if(s[j] == 'X') ans[2]++;
			if(s[j] == 'L') ans[3]++;
			if(s[j] == 'C') ans[4]++;
			if(s[j] == 'D') ans[5]++;
			if(s[j] == 'M') ans[6]++;
		}
	}
	for(int i = 0;i < 7; ++i){
		if(ans[i]){
			printf("%c %d\n",ROMANSET[i],ans[i]);
		}
	}
	return 0;
}

