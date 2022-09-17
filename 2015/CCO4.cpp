#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<short> carsR[2000];
vector<short> carsC[2000];
char grid[2000][2000];
bool vs[2000][2000];

void dfs(short curR, short curC) {
    vs[curR][curC] = true;
	char gv = grid[curR][curC];
	
	if (gv == 'W') {
		for (short c : carsR[curR])
			if (c < curC && !vs[curR][c]) dfs(curR, c);
	} else if (gv == 'N') {
		for (short r : carsC[curC])
			if (r < curR && !vs[r][curC]) dfs(r, curC);
	} else if (gv == 'E') {
		for (short c : carsR[curR])
			if (c > curC && !vs[curR][c]) dfs(curR, c);
	} else if (gv == 'S') {
		for (short r : carsC[curC])
			if (r > curR && !vs[r][curC]) dfs(r, curC);
	} else return;
    
    cout << "(" << curR << "," << curC << ")\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    short n, m;
    cin >> n >> m;
    
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] != '.') {
				carsR[i].emplace_back(j);
				carsC[j].emplace_back(i);
			}
        }
    }
    
	for (short i = 0; i < n; ++i)
		for (short j = 0; j < m; ++j)
			if (grid[i][j] != '.' && !vs[i][j])
				dfs(i, j);
    
	return 0;
}