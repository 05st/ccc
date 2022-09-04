#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int train[200001];
multiset<int> totals;

int n;
int dist[200001];
bool vs[200001];

void bfs() {
    for (int i = 0; i <= n; i++)
        dist[i] = INT32_MAX;
    
    queue<int> q;
    q.push(n);
    vs[n] = true;
    dist[n] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int e : adj[cur]) {
            if (!vs[e]) {
                vs[e] = true;
                dist[e] = dist[cur]+1;
                q.push(e);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w, d;
    cin >> n >> w >> d;

    for (int i = 0; i < w; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    bfs();

    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        if (dist[s] == INT32_MAX)
            train[i] = INT32_MAX;
        else
            train[i] = dist[s] + i;
        totals.insert(train[i]);
    }

    for (int i = 0; i < d; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        if (train[a] != INT32_MAX) {
            totals.erase(totals.lower_bound(train[a]));
            train[a] -= a;
        }
        if (train[b] != INT32_MAX) {
            totals.erase(totals.lower_bound(train[b]));
            train[b] -= b;
        }

        int tmp = train[a];
        train[a] = train[b];
        train[b] = tmp;

        if (train[a] != INT32_MAX) {
            train[a] += a;
            totals.insert(train[a]);
        }
        if (train[b] != INT32_MAX) {
            train[b] += b;
            totals.insert(train[b]);
        }
        
        int ans = *(totals.begin());
        cout << ans << '\n';
    }

    return 0;
}