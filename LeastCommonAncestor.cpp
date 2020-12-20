#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

inline bool isdigit (char c) {
	if(c < '0' || c > '9') return false;
	return true;
}

inline int read () {
	int ans = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) ans = ans * 10 + ch - '0', ch = getchar();
	return ans;
}

inline void scan (int &x) {
	x = read();
}

inline void swap (int &x, int &y) {
	x ^= y; y ^= x; x ^= y;
}

void print (int x) {
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

const int N = 500005;
const int M = 30;
struct edge {
	int to, nxt;
} e[N << 1];
int n, m, s;
int cnt, head[N];
int depth[N], fa[N][M];
int lg[N];

inline void add (int u, int v) {
	e[++ cnt].nxt = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void dfs (int u, int father) {
	fa[u][0] = father; depth[u] = depth[father] + 1;
	for(int i = 1; i < lg[depth[u]]; ++ i)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(int i = head[u]; i; i = e[i].nxt)
	    if(e[i].to != father) dfs(e[i].to, u);
}

inline int LCA (int x, int y) {
	if(depth[x] > depth[y]) swap(x, y);
	while(depth[x] < depth[y])
		y = fa[y][lg[depth[y] - depth[x]] - 1];
	if(x == y) return x;
	for(int i = lg[depth[x]] - 1; i >= 0; -- i) {
		if(fa[x][i] == fa[y][i]) continue;
		x = fa[x][i];
		y = fa[y][i];
	}
	
	return fa[x][0];
}

int main () {

    int x, y;
	scan(n); scan(m); scan(s);
    for(int i = 1; i < n; ++ i ) {
    	scan(x); scan(y);
    	add(x, y); add(y, x);
	}

    lg[0] = 0;
    for(int i = 1; i <= n; ++ i)
    	lg[i] = lg[i - 1] + ((1 << lg[i - 1]) == i ? 1 : 0);
    dfs(s, 0);

    while(m -- ) {
    	scan(x); scan(y);
    	print(LCA(x, y)); putchar('\n');
	}

	return 0;
}

