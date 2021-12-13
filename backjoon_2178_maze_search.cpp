#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int maze[100][100];
bool check[100][100]; // �湮�� ������ ����
int dist[100][100]; // �� ���� �̵��Ÿ� ����
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int startX, int startY) {
	queue<pair<int, int>>q;
	q.push(make_pair(startX, startY));
	dist[startX][startY] = 1;
	check[startX][startY] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < M && maze[nextX][nextY] == 1 && !check[nextX][nextY]) {
				q.push(make_pair(nextX, nextY));
				dist[nextX][nextY] += dist[x][y] + 1;
				check[nextX][nextY] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			maze[i][j] = temp[j] - '0';
		}
	}

	bfs(0, 0); // 0, 0���� ����
	cout << dist[N - 1][M - 1] << "\n";
}