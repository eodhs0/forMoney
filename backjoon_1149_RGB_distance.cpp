#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int N; // 집의 수
int home[MAX][3]; // 입력 값 저장을 위한 배열
int minCost[MAX][3];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int a, b, c; cin >> a >> b >> c;
		home[i][0] = a; home[i][1] = b; home[i][2] = c;
	}
	minCost[0][0] = 0;
	minCost[0][1] = 0;
	minCost[0][2] = 0;

	for (int i = 1; i <= N; i++) {
		minCost[i][0] = min(minCost[i - 1][1], minCost[i - 1][2]) + home[i][0];
		minCost[i][1] = min(minCost[i - 1][0], minCost[i - 1][2]) + home[i][1];
		minCost[i][2] = min(minCost[i - 1][0], minCost[i - 1][1]) + home[i][2];
	}

	int answer = min(min(minCost[N][0], minCost[N][1]), minCost[N][2]);
	cout << answer << "\n";
}