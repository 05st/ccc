#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<pair<string, string>> xcs;
	set<pair<string, string>> ycs;
	
	int x; cin >> x;
	
	for (int i = 0; i < x; i++) {
		string a, b;
		cin >> a >> b;
		xcs.insert({min(a, b), max(a, b)});
	}

	int y; cin >> y;

	for (int i = 0; i < y; i++) {
		string a, b;
		cin >> a >> b;
		ycs.insert({min(a, b), max(a, b)});
	}

	int g; cin >> g;
	
	set<pair<string, string>> ing;
	
	int ans = 0;
	for (int i = 0; i < g; i++) {
		string a, b, c;
		cin >> a >> b >> c;
		
		string grp[3] = {a, b, c};
		for (int i = 0; i < 3; i++) {
			for (int j = i+1; j < 3; j++) {
				if (ycs.count({min(grp[i], grp[j]), max(grp[i], grp[j])}))
					ans++;
			}
		}

		ing.insert({min(a, b), max(a, b)});
		ing.insert({min(a, c), max(a, c)});
		ing.insert({min(b, c), max(b, c)});
	}

	for (pair<string, string> xc : xcs) {
		if (!ing.count({min(xc.first, xc.second), max(xc.first, xc.second)}))
			ans++;
	}

	cout << ans << '\n';

	return 0;
}
