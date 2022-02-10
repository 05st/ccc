#include <bits/stdc++.h>

using namespace std;

vector<array<int, 3>> edges;
int repr[102];
int dsize[102];

void makeSet(int n) {
    repr[n] = n;
    dsize[n] = 1;
}

int findRepr(int n) {
    if (repr[n] == n)
        return n;
    return repr[n] = findRepr(repr[n]);
}

bool unify(int a, int b) {
    int ar = findRepr(a);
    int br = findRepr(b);
    if (ar != br) {
        if (dsize[ar] > dsize[br])
            swap(ar, br);
        repr[ar] = br;
        dsize[br] += dsize[ar];
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;

    map<array<int, 3>, int> emap;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        vector<int> corners;
        for (int j = 0; j < p; j++) {
            int c; cin >> c;
            corners.push_back(c);
        }
        for (int j = 0; j < p; j++) {
            int c; cin >> c;
            int corner2 = (j == p-1 ? corners[0] : corners[j+1]);
            array<int, 3> e = {c, min(corners[j], corner2), max(corners[j], corner2)};
            if (emap.count(e) > 0) {
                edges.push_back({c, i, emap[e]});
                emap.erase(e);
            } else {
                emap[e] = i;
            }
        }
    }
    for (pair<array<int, 3>, int> e : emap)
        edges.push_back({e.first[0], e.second, 101});

    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++)
        makeSet(i);
    makeSet(101);

    int ans = 0;
    int maybeSub = 0;
    int outsideDeg = 0;
    for (array<int, 3> edge : edges) {
        if (unify(edge[1], edge[2])) {
            ans += edge[0];
            if (edge[2] == 101) {
                maybeSub += edge[0];
                outsideDeg++;
            }
        }
    }

    if (outsideDeg < 2)
        ans -= maybeSub;

    cout << ans << '\n';

    return 0;
}