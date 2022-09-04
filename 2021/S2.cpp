#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n, k;
    cin >> m >> n >> k;

    int rs = 0;
    int cs = 0;

    set<pair<char, int>> instrs;
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        int x; cin >> x;
        pair<char, int> instr = {c, x};
        if (!instrs.count(instr)) {
            if (c == 'R') rs++;
            if (c == 'C') cs++;
            instrs.insert(instr);
        } else {
            if (c == 'R') rs--;
            if (c == 'C') cs--;
            instrs.erase(instr);
        }
    }

    cout << (n-cs)*rs + (m-rs)*cs << '\n';

    return 0;
}