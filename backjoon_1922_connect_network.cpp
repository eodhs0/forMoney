#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001;
vector<pair<int, int>> network[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // 우선순위 큐 선언.. greater 선언 해주면 가장 작은 값이 Top

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int numOfCom; cin >> numOfCom; // 컴퓨터의 수
	int numOfLine; cin >> numOfLine; // 선의 수	

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

	int answer = 0; // 최소 비용
	q.push({ 0, 1 }); // 1번 컴퓨터부터 시작

	while (!q.empty()) {
		int cost = q.top().first; // 가장 작은 값이 top 에 있으니 cost pop
		int computer = q.top().second; // 가장 작은 cost 의 컴퓨터 pop
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
					q.push({ nextCost, nextComputer });  // 다음 갈 컴퓨터 우선순위 큐에 모두 push
				}
			}
		}
	}
	cout << answer << "\n";
}