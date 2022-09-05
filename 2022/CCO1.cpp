#define ll long long
#include <bits/stdc++.h>
using namespace std;

int n, k, q, x, y;
int arr[3001];
unordered_set<int> adj[3001];

int tmpvs[3001];
bool cyc[3001][3001];

bool dfs(int cur) {
    if (tmpvs[cur]) return true;
    tmpvs[cur] = true;

    for (int e : adj[cur]) {
        if (dfs(e)) return true;
    }

    tmpvs[cur] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k >> q;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int l = 0; l < n-1; l++) {
        cyc[l][l] = false;

        for (int i = l; i < n; i++) {
            tmpvs[arr[i]] = false;
            adj[arr[i]] = {};
        }

        bool evn = true;
        for (int r = l; r < n; r++) {
            if (r > l) {
                if (cyc[l][r-1]) {
                    cyc[l][r] = true;
                    continue;
                }
            }
            if (evn) {
                if (r > l) adj[arr[r]].insert(arr[r-1]);
            }
            if (dfs(arr[r])) {
                cyc[l][r] = true;
                continue;
            }
            if (evn) {
                if (r < n-1) adj[arr[r]].insert(arr[r+1]);
            }
            evn = !evn;
        }
    }

    while (q--) {
        cin >> x >> y;
        cout << (cyc[x-1][y-1] ? "NO" : "YES") << '\n';
    }
    
    return 0;
}