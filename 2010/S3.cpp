#include <bits/stdc++.h>

using namespace std;

int h, k;
vector<int> houses;
vector<int> houses2;

bool checkLength(int length, bool dir) {
    int k_used = 0;
    int l_used = 0;
    int pos = 0;
    for (int i = 0; i < h; i++) {
        int npos = (dir ? houses[i] : houses2[i]);
        if (i == 0) {
            pos = npos;
            k_used = 1;
            l_used = 0;
        } else {
            if (npos - pos > length - l_used) {
                k_used++;
                l_used = 0;
            } else {
                l_used += npos - pos;
            }
        }
        if (k_used > k) return false;
        pos = npos;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h;
    for (int i = 0; i < h; i++) {
        int x; cin >> x;
        houses.push_back(x);
        houses2.push_back((1000000-x)%1000000);
    }
    cin >> k;

    if (k >= h) {
        cout << 0;
        return 0;
    }

    sort(houses.begin(), houses.end());
    sort(houses2.begin(), houses2.end());

    int max = 2000000;
    int min = 0;
    while (min < max) {
        int avg = (max + min) / 2;
        if (checkLength(avg, true) || checkLength(avg, false)) {
            max = avg;
        } else {
            min = avg+1;
        }
    }

    cout << ceil((double)min / 2.0);

    return 0;
}