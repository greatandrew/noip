#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

const int N = 100005;
const int M = 200005;
const int INF = 2000000000;

int n, m, s;
int cnt;
int head[N];
int dis[N];
bool isVisited[N];

struct edge {
	int to, dis, nxt;
} e[M];

struct data {
	int p;
	int dis;
	
	bool operator < (data x) const {
		return x.dis < dis;
	}
};

priority_queue <data> q;

inline void add (int u, int v, int d) {
	e[++ cnt].nxt = head[u];
	e[cnt].to = v;
	e[cnt].dis = d;
	head[u] = cnt;
}

inline void dij () {
    for(int i = 1; i <= n; i ++ ) dis[i] = INF;
    dis[s] = 0;
	q.push((data){s, 0});
	while(!q.empty()) {
		data t = q.top();
		q.pop();
		int u = t.p;
		if(isVisited[u]) continue;
		isVisited[u] = true;
		
		for(int i = head[u]; i; i = e[i].nxt ) {
			int to = e[i].to;
			if(dis[to] > dis[u] + e[i].dis) {
				dis[to] = dis[u] + e[i].dis;
				if(!isVisited[to]) q.push((data){to, dis[to]});
			}
		}
	}
}

int main () {

    scanf("%d%d%d", &n, &m, &s);
	while(m -- ) {
    	int u, v, d;
    	scanf("%d%d%d", &u, &v, &d);
    	add(u, v, d);
	}

    dij();

    for(int i = 1; i <= n; i ++ ) printf("%d ", dis[i]);

	return 0;
}
