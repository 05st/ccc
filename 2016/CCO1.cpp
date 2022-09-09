#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000001];
bool vs[1000001];
int tv[1000001];

bool dfs2(int cur, int p) {
	if (tv[cur] == 1) return true;
	tv[cur] = 1;
	for (int e : adj[cur]) {
		if (tv[e] != 2 && e != p) {
			if (dfs2(e, cur)) return true;
		}
	}
	tv[cur] = 2;
	return false;
}

int dfs1(int cur) {
	vs[cur] = true;
	int res = 1;
	for (int e : adj[cur]) {
		if (!vs[e]) {
			res += dfs1(e);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans_a = 0, ans_b = 0;
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			int size = dfs1(i);
			// cout << "TST: " << size << ", " << cycle << endl;
			if (size == k) {
				ans_a += k;
			} else if (size > k) {
				int grps = (size + k - 1) / k;
				ans_a += (size / k)*k;
				ans_b += (grps - 1) + dfs2(i, -1);
			}
		}
	}
	cout << ans_a << " " << ans_b << '\n';

	return 0;
}
