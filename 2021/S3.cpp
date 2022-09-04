#define ll long long
#include <bits/stdc++.h>
using namespace std;

#include <stdint.h>
#define int long long

int n;
array<int, 3> frs[200001];

int calc(int pos) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        auto fr = frs[i];
        int dist = max(0LL, abs(fr[0] - pos) - fr[2]);
        res += dist * fr[1];
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, w, d;
        cin >> p >> w >> d;
        frs[i] = {p, w, d};
    }

    int l = -2000000000;
    int r = 2000000000;
    while (true) {
        int i = (l+r)/2;
        int fa = calc(i-1);
        int f = calc(i);
        int fb = calc(i+1);
        if (f <= fa && f <= fb) {
            cout << f << '\n';
            break;
        } else if (fa < f) {
            r = i-1;
        } else if (fb < f) {
            l = i+1;
        }
    }

    return 0;
}