#include <bits/stdc++.h>
#include <stdint.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    if (k < n) {
        cout << "-1\n";
        return 0;
    }

    k -= n;

    int prev = -1;
    int pfl = 0;
    vector<int> prefix;
    while (k && n) {
        if (prev == -1) {
            prev = 1;
            pfl = 1;
            prefix.push_back(1);
        } else {
            if (pfl < m) {
                // cout << "K: " << k << endl;
                if (k >= pfl) {
                    prefix.push_back(prev+1);
                    k -= pfl;

                    pfl++;
                    prev++;
                } else {
                    // cout << "LAST: " << pfl << endl;
                    prefix.push_back(prefix[pfl-k-1]);
                    prev = prefix[pfl-k-1];
                    k = 0;
                }
            } else {
                int next = 0;
                if (prev < m) {
                    next = prev+1;
                } else {
                    next = 1;
                }
                prev = next;
                if (k >= m-1) {
                    k -= (m-1);
                    prefix.push_back(next);
                    pfl++;
                } else {
                    prefix.push_back(prefix[pfl-k-1]);
                    prev = prefix[pfl-k-1];
                    k = 0;
                }
            }
        }
        n--;
    }
    
    if (k) {
        cout << "-1\n";
        return 0;
    }

    prev = (prev != -1 ? prev : 1);
    while (n) {
        prefix.push_back(prev);
        n--;
    }
    
    for (int x : prefix)
        cout << x << ' ';
    cout << '\n';

    return 0;
}