#define ll unsigned long
#include <stdint.h>
#include <bits/stdc++.h>
using namespace std;
#define int ll

uint64_t ps[1000001];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n, c;
    cin >> n >> c;

    for (uint64_t i = 0; i < n; i++) {
        int x; cin >> x;
        ps[x]++;
    }
    for (uint64_t i = 1; i < c; i++)
        ps[i] += ps[i-1];

    uint64_t ans = (n*(n-1)*(n-2))/6;

    for (int i = 0; i < c; i++) {
        int j = (i+(c/2))%c;
        uint64_t psi = ps[i] - (i > 0 ? ps[i-1] : 0);
        uint64_t psitj = ps[j] - ps[i]; // not including at i
        if ((i >= c/2 && c%2 == 0) || i > c/2)
            psitj = ps[j] + ps[c-1] - ps[i];
        if (psi >= 3)
            ans -= (psi*(psi-1)*(psi-2))/6;
        if (psi >= 2 && psitj > 0)
            ans -= (psi*(psi-1)*psitj)/2;
        if (psitj >= 2 && psi > 0)
            ans -= (psi*psitj*(psitj-1))/2;
        if (c%2 == 0 && i >= c/2) {
            uint64_t psj = ps[j] - (j > 0 ? ps[j-1] : 0);
            if (psi >= 2 && psj > 0)
                ans += (psi*(psi-1)*psj)/2;
            if (psj >= 2 && psi > 0)
                ans += (psi*psj*(psj-1))/2;
        }
    }

    cout << ans << '\n';

    return 0;
}