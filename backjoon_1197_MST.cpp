#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	const int MAX = 100001;
	int V, E; cin >> V >> E;

	vector <pair<int, int>> tree[MAX];
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	bool check[MAX];

	for (int i = 1; i <= V; i++) {
		tree[i].clear();
		check[i] = false;
	}

	for (int i = 0; i < E; i++) {
		int a, b, cost; cin >> a >> b >> cost;
		tree[a].push_back({ cost, b });
		tree[b].push_back({ cost, a });
	}

	int answer = 0;
	q.push({ 0, 1 });
	//check[1] = true;
	while (!q.empty()) {
		int node = q.top().second;
		int cost = q.top().first;
		q.pop();
		if (!check[node]) {
			check[node] = true;
			answer += cost;
			for (int i = 0; i < tree[node].size(); i++) {
				int nextNode = tree[node][i].second;
				int nextCost = tree[node][i].first;
				if (!check[nextNode]) {
					q.push({ nextCost, nextNode });
				}
			}
		}
	}
	cout << answer << "\n";
}