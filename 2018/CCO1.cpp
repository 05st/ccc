#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool gs[1002], hs[1002];
int gps[1002], hps[1002];
int dp[1002][1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        gs[i] = c == 'W';
    }
    for (int i = 0; i < N; i++) cin >> gps[i];
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        hs[i] = c == 'W';
    }
    for (int i = 0; i < N; i++) cin >> hps[i];

    for (int i = N-1; i >= 0; i--) {
        for (int j = N-1; j >= 0; j--) {
            if ((gs[i] && !hs[j] && gps[i] > hps[j]) || (hs[j] && !gs[i] && hps[j] > gps[i])) {
                dp[i][j] = max(dp[i+1][j], max(dp[i][j+1], dp[i+1][j+1] + gps[i] + hps[j]));
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout << dp[0][0] << '\n';

    return 0;
}