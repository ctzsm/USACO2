/*
ID: ctzsm2
PROG: buylow
LANG: C++
*/
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int p = 1000000000;
struct hpi {
    int t[50], n;
    hpi() {
        for (int i = 0; i < 30; ++i) t[i] = 0;
        n = 1;
    }
    void operator += (const hpi &x) {
    	int len = std::max(n, x.n);
    	for (int i = 0; i < len; ++i) {
    		t[i] += x.t[i];
    		if (t[i] >= p) {
    			t[i + 1] += t[i] / p;
    			t[i] %= p;    			
    		}
    	}
    	if (t[len] > 0) len += 1;
    	n = len;
    }
    void operator = (const hpi &x) {
    	n = x.n;
    	memset(t, 0, sizeof(t));
    	for (int i = 0; i < n; ++i) t[i] = x.t[i];    	
    }
    void print() const{
    	printf("%d", t[n - 1]);
    	for (int i = n - 2; i >= 0; --i) {
    		int p1 = p / 10;
    		while (t[i] < p1) {
    			printf("0");
    			p1 /= 10;
    		}
    		printf("%d", t[i]);
    	}
    }
} c[5005], ans2;
int N, ans1 = 0, stock[5005], l[5005];
std::set<int> e;
int main() {
    freopen("buylow.in", "r", stdin);
    freopen("buylow.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &stock[i]);
    for (int i = 0; i < N; ++i) {
        l[i] = 1;
        c[i].t[0] = 1;
        e.clear();
        for (int j = i - 1; j >= 0; --j) {
            if (stock[j] > stock[i]) {
                if (l[i] < l[j] + 1) {
                    l[i] = l[j] + 1;
                    c[i] = c[j];
                    e.clear();
                    e.insert(stock[j]);
                } else if (l[i] == l[j] + 1 && e.find(stock[j]) == e.end()) {
                    c[i] += c[j];
                    e.insert(stock[j]);
                }
            }
        }
        ans1 = std::max(ans1, l[i]);
    }
    e.clear();
    for (int i = N - 1; i >= 0; --i)
        if (l[i] == ans1 && e.find(stock[i]) == e.end()) {
            ans2 += c[i];
            e.insert(stock[i]);
        }
    printf("%d ", ans1);
    ans2.print();
    printf("\n");
}