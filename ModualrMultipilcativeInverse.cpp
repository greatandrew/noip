//print the inverse from 1 to n (mod P)
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
 
using namespace std;
typedef long long ll;
const int N = 3000005;
int n, P;
int inv[N];

int main () {

    scanf("%d%d", &n, &P);
    inv[0] = 0; inv[1] = 1;
    for(int i = 2; i <= n; ++ i) {
        ll tmp = inv[P % i];
		inv[i] = P - tmp * (P / i) % P;
    }
    for(int i = 1; i <= n; ++ i) printf("%d\n", inv[i]);

	return 0;
}
