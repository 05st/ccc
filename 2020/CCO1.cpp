#define ll long long
#include <bits/stdc++.h>
using namespace std;

int seenby[100001];
map<int, int> upd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int l, r, y;
    cin >> l >> r >> y;

    for (int i = 0; i < n; i++) {
        int x, v, h;
        cin >> x >> v >> h;

        int diff = ((y*h + v - 1)/v) - 1;
        int rend = min(r, x + diff);
        int lend = max(l, x - diff);

        upd[lend-1]++;
        upd[rend]--;
    }
    
    int prev = 0;
    int prevcoord = l;
    for (auto& updv : upd) {
        seenby[prev] += updv.first - prevcoord + 1;
        prevcoord = updv.first+1;
        prev += updv.second;
    }
    seenby[0] += r - prevcoord + 1;

    for (int i = 0; i <= n; i++) {
        if (i > 0) seenby[i] += seenby[i-1];
        cout << seenby[i] << '\n';
    }

    return 0;
}