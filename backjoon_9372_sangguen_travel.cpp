#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int T; cin >> T; 
	
	for (int i = 0; i < T; i++) {
		int N, M; cin >> N >> M; // 국가의 수, 비행기의 종류
		vector<int>travel[1001];
		bool check[1001];
		for (int j = 1; j <= N; j++) {
			travel[j].clear();
			check[j] = false;
		}
		for (int j = 0; j < M; j++) {
			int a, b; cin >> a >> b; // 왕복 비행기 a, b
			travel[a].push_back(b);
			travel[b].push_back(a);
		}
		int count = 0;

		queue<int>q;
		q.push(1);
		check[1] = true;
		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			for (int j = 0; j < travel[idx].size(); j++) {
				int next = travel[idx][j];
				if (!check[next]) {
					q.push(next);
					check[next] = true;
					count++;
				}
			}
		}
		cout << count << "\n";
	}
}