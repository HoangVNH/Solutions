#include <bits/stdc++.h>
using namespace std;

typedef pair<long, long> pll;
typedef map<long, long> mll;
 
int main() {
 
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	int n;
	cin >> n;

	mll m;

	for(int i = 0; i < n; ++i) {
		long x;
		cin >> x;
		m.insert(pll(x, i));
	}

	long minLoss = LONG_MAX;

	for(auto itr = next(m.begin(), 1); itr != m.end(); ++itr) {
		auto it = prev(itr, 1);

		long loss = itr->first - it->first;
		int i = itr->second;
		int j = it->second;

		if(loss < minLoss && i < j)
			minLoss = loss;
	}

    cout << minLoss << endl;
	return 0;
}