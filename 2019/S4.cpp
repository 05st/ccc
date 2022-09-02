#define ll long long
#include <bits/stdc++.h>
using namespace std;

#include <stdint.h>

ll arr[1000001];
ll dp[1000001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, k;
	cin >> n >> k;
	
	ll nmk = n % k;
	
	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	if (nmk == 0) {
		ll ans = 0;
		for (ll i = 0; i < n; i += k) {
			ll mm = 0;
			for (ll j = i; j < i + k; j++) {
				mm = max(mm, arr[j]);
			}
			ans += mm;
		}
		cout << ans << '\n';
		return 0;
	}

	ll days = (n + k - 1) / k;
	for (ll day = 0; day < days; day++) {
		ll b0 = (day > 0 ? dp[day-1][0] : 0);
		ll b1 = (day > 0 ? dp[day-1][1] : 0);

		ll m0 = 0;
		if (k*(day+1) <= n) {
			for (ll i = k*day; i < k*(day+1); i++)
				m0 = max(m0, arr[i]);
		}
		dp[day][0] = b0 + m0;
		
		ll m1y = 0;
		if (day > 0) {
			for (ll i = k*(day-1) + nmk; i < k*day + nmk; i++)
				m1y = max(m1y, arr[i]);
		}

		if (day > 0) {
			ll max1 = 0;
			ll max2 = 0;
			for (ll i = k*(day-1); i < k*day + nmk; i++) {
				if (arr[i] > max1) {
					max2 = max1;
					max1 = arr[i];
				} else if (arr[i] > max2) {
					max2 = arr[i];
				}
			}
			
			ll maxl = 0;
			ll maxr = 0;

			for (ll i = k*(day-1); i < k*day; i++) {
				maxl = max(maxl, arr[i]);
			}
			
			for (ll i = k*(day-1) + nmk; i < k*day + nmk; i++) {
				maxr = max(maxr, arr[i]);
			}
			
			if (maxl == maxr) {
				maxl = max2;
			}

			ll bbb = (day > 1 ? dp[day-2][0] : 0);
			dp[day][1] = max(bbb + maxl + maxr, b1 + m1y);
		} else {
			ll m1n = 0;
			for (ll i = k*day; i < k*day + nmk; i++)
				m1n = max(m1n, arr[i]);
			dp[day][1] = max(b1 + m1y, b0 + m1n);
		}
	}
	
	ll ans = dp[days-1][1];

	cout << ans << '\n';

	return 0;
}