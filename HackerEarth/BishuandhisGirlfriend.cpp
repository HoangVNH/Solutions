#include <bits/stdc++.h>
#define MAXX 1001

using namespace std;

vector<int> graph[MAXX];
int dist[MAXX];
int N;

void dfs(int s) {

	for(int i = 1; i <= N; ++i)	dist[i] = -1;

	stack<int> st;
	st.push(s);
	dist[s] = 0;

	while(!st.empty()) {
		int u = st.top();
		st.pop();
		for(int i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i];
			if(dist[v] == -1) {
				dist[v] = dist[u] + 1;
				st.push(v);
			}
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N;

	for(int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1);

	int Q;
	cin >> Q;

	int minDist = INT_MAX, minNum = 0;

	while(Q--) {
		int x;
		cin >> x;

		if(dist[x] < minDist) {

			minDist = dist[x];
			minNum = x;
		} else if(dist[x] == minDist && x < minNum)
			minNum = x;
	}

	cout << minNum;

	return 0;
}