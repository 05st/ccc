#pragma GCC optimize("Ofast")
#define ll long long
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> adj[200001];
bool ps[200001];
int cs[200001];
int dp[200001][3];

void dfs(int n, int p) {
    int dp1sum = 0, dp2sum = 0;
    int be_inf = INT32_MAX, be_inf_spread = INT32_MAX;
    for (int e : adj[n]) {
        if (e != p) {
            dfs(e, n);
            dp1sum += dp[e][1];
            dp2sum += dp[e][2];
        }
    }
    for (int e : adj[n]) {
        if (e != p) {
            be_inf = min(be_inf, dp1sum - dp[e][1] + dp[e][0]);
            be_inf_spread = min(be_inf_spread, cs[n] + dp2sum - dp[e][2] + dp[e][0]);
        }
    }
    if (ps[n]) {
        dp[n][0] = cs[n] + dp2sum;
        dp[n][1] = min(dp1sum, cs[n] + dp2sum);
    } else {
        dp[n][0] = be_inf_spread;
        dp[n][1] = min(be_inf, be_inf_spread);
    }
    dp[n][2] = min(cs[n] + dp2sum, dp1sum);
    // cout << n << ": " << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        ps[i+1] = c == 'Y';
    }
    for (int i = 0; i < N; i++)
        cin >> cs[i+1];

    dfs(1, -1);

    cout << dp[1][1] << '\n';
    
    return 0;
}