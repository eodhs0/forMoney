#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001; // 섬의 최대 수

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int testCase; cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int numOfIsland; cin >> numOfIsland;
		vector<int>x;
		vector<int>y;
		vector<int>distance;
		for (int j = 0; j < numOfIsland; j++) {
			int pointX; cin >> pointX;
			x.push_back(pointX);
		}
		for (int j = 0; j < numOfIsland; j++) {
			int pointY; cin >> pointY;
			y.push_back(pointY);
		}
		int tax; cin >> tax;
		//각 섬들끼리의 거리 저장
		/*for (int j = 0; j < numOfIsland; j++) {
			int pointY; cin >> pointY;
			y.push_back(pointY);
		}*/

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	}
}