#define ll long long
#include <bits/stdc++.h>
using namespace std;

int ans[150001];
int dif[150001][16];

int lcm(int a, int b) {
	return (a*b)/__gcd(a, b);
}

int st[150001*4];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        st[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        st[v] = __gcd(st[v*2], st[v*2+1]);
    }
}
int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return st[v];
    int tm = (tl + tr) / 2;
    return __gcd(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<array<int, 3>> reqs;
	
	for (int i = 0; i < n; i++)
		ans[i] = 1;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		reqs.push_back({x, y, z});

		dif[x][z-1]++;
		if (y < n-1)
			dif[y+1][z-1]--;
	}
	
	for (int z = 0; z < 16; z++) {
		for (int i = 0; i < n; i++) {
			if (i > 0) dif[i][z] += dif[i-1][z];
			if (dif[i][z]) ans[i] = lcm(ans[i], z+1);
		}
	}
	build(ans, 1, 0, n-1);

	bool valid = true;
	for (array<int, 3> req : reqs) {
		int x = req[0];
		int y = req[1];
		int z = req[2];
		if (query(1, 0, n-1, x, y) != z) {
			valid = false;
			break;
		}
	}

	if (valid) {
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	} else {
		cout << "Impossible\n";
	}
	
	return 0;
}