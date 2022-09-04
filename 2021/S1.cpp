#include <bits/stdc++.h>
#define FOR(i, j) for(int i = 0; i < j; i++)
#define REP(n) FOR(_, n)
using namespace std;

int heights[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(100);

    int n; cin >> n;
    long double area = 0;

    FOR(i, n+1) {
        cin >> heights[i];
    }

    FOR(i, n) {
        int width; cin >> width;
        int mi = min(heights[i], heights[i+1]);
        int ma = max(heights[i], heights[i+1]);
        area += (long double)(mi * width) + (long double)((ma - mi) * width) / 2;
    }

    cout << area;

    return 0;
}