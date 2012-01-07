/*
ID: ctzsm2
PROG: transform
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n,ans = 0;
char org[11][11],tar[11][11],tmp[11][11],t[11][11];
void tran1(){
	for(int i = 0;i < n; ++i) for(int j = 0;j < n; ++j) t[i][j] = tmp[i][j];
	for(int i = 0;i < n; ++i) for(int j = 0;j < n; ++j) tmp[j][n - 1 - i] = t[i][j];
}
void tran2(){
	tran1();tran1();
}
void tran3(){
	tran1();tran1();tran1();
}
void tran4(){
	for(int i = 0;i < n; ++i) for(int j = 0;j < n; ++j) t[i][j] = tmp[i][j];
	for(int i = 0;i < n; ++i) for(int j = 0;j < n; ++j) tmp[i][n - 1 - j] = t[i][j];
}
void copy(){
	for(int i = 0;i < n; ++i) for(int j = 0;j < n; ++j) tmp[i][j] = org[i][j];
}
bool compare(){
	for(int i = 0;i < n; ++i) for(int j = 0;j < n; ++j) if(tmp[i][j] != tar[i][j]) return false;
	return true;
}
void print(){
	for(int i = 0;i < n; ++i) printf("%s\n",tmp[i]);
}
int main(int argc, char** argv) {
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) scanf("%s",org[i]);
	for(int i = 0;i < n; ++i) scanf("%s",tar[i]);
//	copy();tran4();print();
	for(int i = 1;i <= 6; ++i){
		switch(i){
			case 1:copy();tran1();break;
			case 2:copy();tran2();break;
			case 3:copy();tran3();break;
			case 4:copy();tran4();break;
			case 6:copy();break;
		}
		if(i == 5){
			copy();tran1();tran4();if(compare()){ ans = i;break;}
			copy();tran2();tran4();if(compare()){ ans = i;break;}
			copy();tran3();tran4();if(compare()){ ans = i;break;}
		}
		if(compare()){ ans = i;break;}
	}
	if(ans) printf("%d\n",ans);
	else printf("7\n");
	return 0;
}

