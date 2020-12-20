#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define ll long long

using namespace std;

const int N = 100005;

int n, m;
ll a[N];
ll tag[N << 2], ans[N << 2];

inline ll ls (int p) { return p << 1; }
inline ll rs (int p) { return p << 1 | 1; }

inline void pushup (ll p) {
	ans[p] = ans[ls(p)] + ans[rs(p)];
}

inline void build (ll p, ll l, ll r) {
	if(l == r) {
		ans[p] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	pushup(p);
}

inline void f (ll p, ll l, ll r, ll k) {
	tag[p] += k;
	ans[p] += k * (r - l + 1);
}

inline void pushdown (ll p, ll l, ll r) {
	ll mid = (l + r) >> 1;
	f(ls(p), l, mid, tag[p]);
	f(rs(p), mid + 1, r, tag[p]);
	tag[p] = 0;
}

inline void update (ll p, ll ul, ll ur, ll l, ll r, ll k) {
	if(ul <= l && r <= ur) {
		tag[p] += k;
		ans[p] += k * (r - l + 1);
		return;
	}
	ll mid = (l + r) >> 1;
	pushdown(p, l, r);
	if(ul <= mid) update(ls(p), ul, ur, l, mid, k);
	if(ur > mid) update(rs(p), ul, ur, mid + 1, r, k);
	pushup(p);
}

inline ll query (ll p, ll ql, ll qr, ll l, ll r) {
	ll res = 0;
	if(ql <= l && r <= qr) return ans[p];
	ll mid = (l + r) >> 1;
	pushdown(p, l, r);
	if(ql <= mid) res += query(ls(p), ql, qr, l, mid);
	if(qr > mid) res += query(rs(p), ql, qr, mid + 1, r);
	return res;
}

int main () {

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
    build(1, 1, n);
    while(m -- ) {
    	int t;
    	scanf("%d", &t);
    	if(t == 1) {
    		ll x, y, k;
    		scanf("%lld%lld%lld", &x, &y, &k);
    		update(1, x, y, 1, n, k);
		}
		if(t == 2) {
			ll x, y;
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", query(1, x, y, 1, n));
		}
	}

	return 0;
}
/*
5 6
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
2 1 4
1 1 5 1
2 1 4

5 3
1 2 3 4 5
2 1 4
1 1 1 1
2 1 2

5 3
1 2 3 4 5
2 1 4
1 1 3 1
2 1 2
*/
