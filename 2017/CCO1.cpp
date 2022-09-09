#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	
	int noded = 0;
	vector<pair<int, int>> edges;
    while (k) {
        int node = 1;
        
        if (noded > 0) {
            edges.push_back({noded, noded+1});
        }
        
    	if (k == 1) {
    	    edges.push_back({node+noded, node+noded+1});
    	    node++;
    	    edges.push_back({node+noded, node+noded-1});
    	    k--;
    	    noded += node;
    	    break;
    	}
    	
    	while (node*(node+1) <= k*2) {
    	    node++;
    	}
    	
    	for (int i = 1; i < node; i++) {
    	    edges.push_back({i+noded, i+noded+1});
    	}
    	edges.push_back({node+noded, noded+1});
    	
    	k -= (node-1)*node/2;
    	noded += node;
    }
	cout << noded << " " << edges.size() << '\n';
	for (pair<int, int> e : edges) {
	    cout << e.first << " " << e.second << '\n';
	}

	return 0;
}