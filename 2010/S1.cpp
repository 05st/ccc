#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    if (n == 0) return 0;
    
    vector<pair<int, string>> arr;
    for (int i = 0; i < n; i++) {
        string name;
        int r, s, d;
        cin >> name >> r >> s >> d;

        arr.push_back({2*r + 3*s + d, name});
    }

    sort(arr.begin(), arr.end(), [](auto lhs, auto rhs) {
        if (lhs.first == rhs.first)
            return lhs.second < rhs.second;
        else
            return lhs.first > rhs.first;
    });

    if (n == 1) {
        cout << arr[0].second;
    } else {
        cout << arr[0].second << '\n' << arr[1].second;
    }

    return 0;
}