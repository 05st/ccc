// #define ll long long
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("avx2")

int _, _d;
char __[3<<20], ___[12];
inline void pint(int x) {do ___[_++]=x%10;while(x/=10);do __[_d++]=___[--_]+'0';while(_);}
inline void pspc() {__[_d++]=' ';}
inline int sint() {
	int result = 0;
	char ch;
	ch = getchar();
	for (;;) {
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	result = ch-'0';
	for (;;) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	return result;
}

int n, m, x, y, z;
int ans[150001];
int dif[150001][16];
int st[150001][18];
int reqs[150001][3];

/*
inline int lcm(int a, int b) {
	return (a*b)/__gcd(a, b);
}
*/

const int tab32[32] = {0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30, 8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31};
inline int log2_32 (uint32_t value) {
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    return tab32[(uint32_t)(value*0x07C4ACDD) >> 27];
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

	n = sint(), m = sint();
	for (int i = 0; i < m; i++) {
		x = sint(), y = sint(), z = sint();
		x--; y--;
		reqs[i][0] = x;
		reqs[i][1] = y;
		reqs[i][2] = z;

		dif[x][z-1]++;
		if (y < n-1) dif[y+1][z-1]--;
	}
	
	for (int i = 0; i < n; i++) {
		ans[i] = 1;
		for (int z = 0; z < 16; z++) {
			if (i > 0) dif[i][z] += dif[i-1][z];
			if (dif[i][z]) ans[i] = lcm(ans[i], z+1);
		}
		st[i][0] = ans[i];
	}
	
	int l2n = log2_32(n);
	for (int k = 1; k <= l2n; k++)
		for (int i = 0; i + (1 << k) <= n; i++)
			st[i][k] = __gcd(st[i][k-1], st[i + (1 << (k - 1))][k-1]);

	for (int i = 0; i < m; i++) {
		x = reqs[i][0];
		y = reqs[i][1];
		z = reqs[i][2];
		int j = log2_32(y-x+1);
		if (__gcd(st[x][j], st[y - (1 << j) + 1][j]) != z) {
			printf("Impossible");
			return 0;
		}
	}

	for (int i = 0; i < n; i++)
		pint(ans[i]), pspc();
	fwrite(__, 1, _d, stdout);
	
	return 0;
}