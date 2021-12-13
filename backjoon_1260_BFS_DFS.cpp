#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>


using namespace std;
int N, M, start;
vector<int>v[1001];
bool check[1001];
queue<int> cq; // connected queue

bool cmp(const int &a, const int &b) {
	return a > b;
}

void dfs() {
	stack<int>s;
	s.push(start);
	while (!s.empty()) {
		int curNode = s.top();
		s.pop();
		if (check[curNode]) continue;
		check[curNode] = true;
		cout << curNode << " ";
		for (int i = 0; i < v[curNode].size(); i++) {
			int nextNode = v[curNode][i];
			if (!check[nextNode]) {
				s.push(nextNode);
			}
		}
	}
}

void bfs() {
	queue<int>q;
	check[start] = true;
	q.push(start);
	cout << start << " ";
	while (!q.empty()) {
		int curNode = q.front();
		q.pop();
		for (int i = 0; i < v[curNode].size(); i++) {
			int nextNode = v[curNode][i];
			if (!check[nextNode]) {
				q.push(nextNode);
				check[nextNode] = true;
				cout << nextNode << " ";
			}
		}
	}
}

int main() {
	cin >> N >> M >> start;
	int node1, node2;
	for (int i = 0; i < M; i++) {
		 cin >> node1 >> node2;
		v[node1].push_back(node2);
		v[node2].push_back(node1);
		check[node1] = false;
		check[node2] = false;
	}

	
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), cmp);
	}
	dfs();
	cout << "\n";
	for (int i = 0; i < 1001; i++) {
		check[i] = false;
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	bfs();

}