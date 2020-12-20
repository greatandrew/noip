#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define ll long long

using namespace std;
const int N = 100005;
struct bigInt {
	int num[N];
	int len;
};

inline int max (int x, int y) {
    if(x > y) return x;
    return y;
}

bigInt operator + (bigInt &x, bigInt &y) {
    static bigInt ans;
    ans.len = max(x.len, y.len);
    
    int add = 0;
    for(int i = 1; i <= ans.len + 1; ++ i) {
    	int a = x.num[i], b = y.num[i];
    	if(i > x.len) a = 0;
    	if(i > y.len) b = 0;
    	ans.num[i] = a + b + add;
    	add = ans.num[i] / 10;
    	ans.num[i] %= 10;
	}

	if(ans.num[ans.len + 1] != 0) ++ ans.len;
	return ans;
}

bigInt operator + (bigInt &x, int c) {
    if(!c) return x;
	static bigInt y;
    
	while(c) {
    	y.num[++ y.len] = c % 10;
    	c /= 10;
	}
	return x + y;
}

bigInt operator - (bigInt &x, bigInt &y) {
    static bigInt ans;
    ans.len = x.len;
    int mul = 0;
    for(int i = 1; i <= x.len; ++ i) {
    	if(i <= y.len) ans.num[i] = x.num[i] - y.num[i] - mul;
    	else ans.num[i] = x.num[i] - mul;
    	
		if(ans.num[i] < 0) {
    		ans.num[i] += 10;
    		mul = 1;
		}
		else mul = 0;
	}
	
	while(ans.len > 1 && ans.num[ans.len] == 0) -- ans.len;
	return ans;
}

bigInt operator * (bigInt &x, bigInt &y) {
    static bigInt ans; 
	ans.len = x.len + y.len - 1;
	for(int i = 1; i <= ans.len + 1; ++ i) ans.num[i] = 0;
    for(int i = 1; i <= x.len; ++ i) {
    	for(int j = 1; j <= y.len; ++ j) {
    		ans.num[i + j - 1] += x.num[i] * y.num[j];
    		ans.num[i + j] += ans.num[i + j - 1] / 10;
    		ans.num[i + j - 1] %= 10;
		} 
	}
	
	if(ans.num[ans.len + 1] != 0) ++ ans.len;
	while(ans.len > 1 && ans.num[ans.len] == 0) -- ans.len;
	return ans;
}

bigInt operator * (bigInt &x, int c) {
    static bigInt y; y.len = 0;
    if(!c) { y.len = 1; y.num[1] = 0; return y; }
	while(c) {
    	y.num[ ++ y.len] = c % 10;
    	c /= 10;
	}
	
	return x * y;
}

bigInt operator / (bigInt &x, int c) {
	static bigInt ans;
	static ll last = 0;
	ans.len = x.len;
	for(int i = ans.len; i; -- i) {
		last = last * 10 + x.num[i];
		ans.num[i] = last / c;
		last %= c;
	}
	
	while(ans.len > 1 && ans.num[ans.len] == 0) -- ans.len;
	return ans;
}

bool operator < (bigInt &x, bigInt &y) {
	if(x.len < y.len) return true;
	if(x.len > y.len) return false;
	for(int i = x.len; i; -- i) {
	    if(x.num[i] > y.num[i]) return false;
	    if(x.num[i] < y.num[i]) return true;
	}
	return false;
}

bool operator > (bigInt &x, bigInt &y) {
	if(x.len < y.len) return false;
	if(x.len > y.len) return true;
	for(int i = x.len; i; -- i) {
	    if(x.num[i] > y.num[i]) return true;
	    if(x.num[i] < y.num[i]) return false;
	}
	return false;
}

bool operator <= (bigInt &x, bigInt &y) {
    if(x > y) return false;
	return true;
}


bool operator >= (bigInt &x, bigInt &y) {
    if(x < y) return false;
	return true;
}

bool operator == (bigInt &x, bigInt &y) {
	if(x.len != y.len) return false;
	for(int i = x.len; i; -- i) if(x.num[i] != y.num[i]) return false;
	return true;
}

inline void same (bigInt &x, int y) {
    x.len = 0;
	if(!y) { x.len = 1; x.num[1] = 0; }
	else {
		while(y) {
			x.num[ ++ x.len] = y % 10;
			y /= 10;
		}
	}
}

inline void read (bigInt &x) {
    static char s[N];
    scanf("%s", s);
    int len = strlen(s);
    x.len = len;
    for(int i = 0; i < len; ++ i) x.num[len - i] = s[i] - '0';
}

inline void print (bigInt &x) {
	for(int i = x.len; i > 0; -- i) printf("%d", x.num[i]);
}

bigInt a;
bigInt b;

int main () {

    read(a); read(b);
    a = a - b;
    print(a);
    
	return 0;
}

