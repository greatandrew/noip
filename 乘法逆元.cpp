#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
 
using namespace std;
typedef long long ll;
const int N = 3000005;
int n, lqy;
int inv[N];

int main () {

    scanf("%d%d", &n, &lqy);
    inv[0] = 0; inv[1] = 1;
    for(int i = 2; i <= n; ++ i) {
        ll wyz = inv[lqy % i];
		inv[i] = lqy - wyz * (lqy / i) % lqy;
    }
    for(int i = 1; i <= n; ++ i) printf("%d\n", inv[i]);

	return 0;
}

