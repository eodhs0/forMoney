#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001;
vector<pair<int, int>> network[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // �켱���� ť ����.. greater ���� ���ָ� ���� ���� ���� Top

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int numOfCom; cin >> numOfCom; // ��ǻ���� ��
	int numOfLine; cin >> numOfLine; // ���� ��	

	bool check[MAX];

	for (int i = 1; i <= numOfCom; i++) {
		network[i].clear();
		check[i] = false;
	}

	for (int i = 0; i < numOfLine; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a != b) {
			network[a].push_back({ c,b });
			network[b].push_back({ c,a });
		}
	}

	int answer = 0; // �ּ� ���
	q.push({ 0, 1 }); // 1�� ��ǻ�ͺ��� ����

	while (!q.empty()) {
		int cost = q.top().first; // ���� ���� ���� top �� ������ cost pop
		int computer = q.top().second; // ���� ���� cost �� ��ǻ�� pop
		q.pop();
		//cout << cost << " " << computer << endl;

		if (!check[computer]) {
			//cout << "hi" << endl;
			check[computer] = true;
			answer += cost;
			for (int i = 0; i < network[computer].size(); i++) {
				int nextCost = network[computer][i].first;
				int nextComputer = network[computer][i].second;
				if (!check[nextComputer]) {
					q.push({ nextCost, nextComputer });  // ���� �� ��ǻ�� �켱���� ť�� ��� push
				}
			}
		}
	}
	cout << answer << "\n";
}