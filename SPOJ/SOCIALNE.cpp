#include <bits/stdc++.h>
#define MAX 52
#define INF 1e9
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;
typedef vector<vi> vvi;

bool FloydWarshall(int m, vector<vector<int> > &dist) {

	for(int k = 0; k < m; ++k) {
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < m; ++j) {
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for(int i = 0; i < m; ++i)
		if(dist[i][i] < 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		int m = s.size();
		
		vector<string> a;
		a.push_back(s);

		vector<vector<int> > dist = vector<vector<int> >(m, vector<int>(m));

		for(int i = 1; i < m; ++i) {
			cin >> s;
			a.push_back(s);
		}

		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < m; ++j) {
				if(i == j)
					dist[i][j] = 0;
				else if(a[i][j] == 'Y') {
					dist[i][j] = 1;
					dist[j][i] = 1;
				} else {
					dist[i][j] = INF;
					dist[j][i] = INF;
				}
			}
		}

		bool ans = FloydWarshall(m, dist);

		int max = -1;
		int index = -1;
		
		for(int i = 0; i < m; ++i) {
			int count = 0;
			for(int j = 0; j < m; ++j) {
				if(dist[i][j] == 2)
					++count;
			}

			if(count > max) {
				max = count;
				index = i;
			}
		}

		cout << index << " " << max << endl;
	}

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

	return 0;
}