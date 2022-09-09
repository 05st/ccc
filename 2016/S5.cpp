#define ll long long
#include <bits/stdc++.h>
using namespace std;

#include <stdint.h>
#define int long long

bool arr[52][100001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        arr[0][i] = c == '1';
    }

    int idx = 0;
    while (t) {
        int dist = 1;
        while (dist*2 < t) {
            dist *= 2;
        }
        idx++;
        for (int i = 0; i < n; i++)
            arr[idx][i] = (arr[idx-1][(i+dist)%n]) ^ (arr[idx-1][(i+n-(dist%n))%n]);
        t -= dist;
    }

    for (int i = 0; i < n; i++)
        cout << arr[idx][i];
    cout << '\n';

    return 0;
}