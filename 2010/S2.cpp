#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    unordered_map<string, char> map;
    for (int i = 0; i < k; i++) {
        char c;
        string s;
        cin >> c >> s;
        map[s] = c;
    }

    string inp;
    cin >> inp;

    string cur;
    for (char c : inp) {
        cur += c;
        if (map.count(cur) > 0) {
            cout << map[cur];
            cur = "";
        }
    }

    return 0;
}