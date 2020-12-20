#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define ll long long

using namespace std;

const int N = 5005;
const int M = 200005;
const int INF = 1e9;

struct edge {
	int to, nxt, dis;
};
edge e[M << 1];
int dis[N];
int head[N];
int n, m;
int cnt;
int ans;
bool isVisited[N];

inline void add (int u, int v, int d) {
	e[++ cnt].nxt = head[u];
	e[cnt].to = v;
	e[cnt].dis = d;
	head[u] = cnt;
}

inline void prim () {
	for(int i = 2; i <= n; i ++ ) dis[i] = INF;
	for(int i = head[1]; i; i = e[i].nxt)
		if(dis[e[i].to] > e[i].dis) dis[e[i].to] = e[i].dis;
	int already = 0; int now = 1;
	
	while(++ already < n) {
		int Min = INF;
		isVisited[now] = true;
		for(int i = 1; i <= n; i ++ ) 
		    if(isVisited[i] == false && dis[i] < Min) Min = dis[i], now = i;
		ans += Min;
		for(int i = head[now]; i; i = e[i].nxt) {
			int u = e[i].to;
			if(isVisited[u] == false && dis[u] > e[i].dis) dis[u] = e[i].dis;
		}
	}
}

int main () {

//    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++ ) {
    	int u, v, d;
	    scanf("%d%d%d", &u, &v, &d);
	    add(u, v, d);
	    add(v, u, d);
	}

    prim();
    printf("%d", ans);

	return 0;
}
