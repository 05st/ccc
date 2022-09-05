#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int g, p;
    cin >> g >> p;

    vector<int> ps;
    for (int i = 0; i < p; i++) {
        int x; cin >> x;
        ps.push_back(x);
    }
    set<int> open;
    for (int i = 0; i < g; i++) {
        open.insert(i+1);
    }
    int ans = 0;
    for (int p : ps) {
        auto lb = open.lower_bound(p);
        int lbg = *lb;
        if (lbg > p) {
            auto lbp = prev(lb);
            if (lbp != open.end()) {
                lbg = *lbp;
            } else {
                break;
            }
        }
        if (lbg <= p) {
            open.erase(lbg);
            ans++;
        } else {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}