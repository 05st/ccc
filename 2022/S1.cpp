#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    
    for (int i = 0; i < 4 && n >=0; i++) {
        if (n%5 != 0)
            n-=4;
        else break;
    }
    if (n%5 == 0 && n >= 0) {
        cout << 1 + floor(n/20) << '\n';
    } else {
        cout << "0\n";
    }
    
    return 0;
}