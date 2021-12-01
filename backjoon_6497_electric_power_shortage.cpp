#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 200001;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);


	int numOfHome = -1, numOfRoad = -1;

	while (true) {
		cin >> numOfHome >> numOfRoad;
		if (numOfHome == 0 && numOfRoad == 0) // 문제 잘 읽어봐야함... 여러개의 테스트 케이스가 주어지고 테스트 케이스의 마지막 줄에는 0 0 이 입력됨.
			break;

		vector<pair<int, int>> v[MAX];
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		bool check[MAX];
		int sumAllDistance = 0;

		for (int i = 0; i < numOfHome; i++) {
			check[i] = false;
			v[i].clear();
		}

		for (int i = 0; i < numOfRoad; i++) {
			int h1, h2, distance; cin >> h1 >> h2 >> distance;
			v[h1].push_back({ distance, h2 }); // 우선순위 큐에서 distance 짧은 것 부터 top 에 위치시키기 위해 distance, h2 순으로 저장.
			v[h2].push_back({ distance, h1 });
			sumAllDistance += distance;
		}

		int answer = 0;
		q.push({ 0, 0 });
		while (!q.empty()) {
			int distance = q.top().first;
			int home = q.top().second;
			q.pop();
			if (!check[home]) {
				check[home] = true; // 해당 집 지나감.
				answer += distance;
				//cout << answer << "\n";
				for (int i = 0; i < v[home].size(); i++) {
					int nextDistance = v[home][i].first;
					int nextHome = v[home][i].second;
					if (!check[nextHome]) {
						q.push({ nextDistance, nextHome });
					}
				}
			}
		}
		cout << sumAllDistance - answer << "\n";
	}
}