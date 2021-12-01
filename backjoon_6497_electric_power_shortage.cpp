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
		if (numOfHome == 0 && numOfRoad == 0) // ���� �� �о������... �������� �׽�Ʈ ���̽��� �־����� �׽�Ʈ ���̽��� ������ �ٿ��� 0 0 �� �Էµ�.
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
			v[h1].push_back({ distance, h2 }); // �켱���� ť���� distance ª�� �� ���� top �� ��ġ��Ű�� ���� distance, h2 ������ ����.
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
				check[home] = true; // �ش� �� ������.
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