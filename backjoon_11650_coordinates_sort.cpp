#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int testCase; cin >> testCase;

	vector<vector<int>> coordinates(testCase, vector<int>(2,0)); // testCase �� 2�� 2���� �迭 �����.
	//multimap<int, int> a;
	for (int i = 0; i < testCase; i++) {
		int x, y;
		cin >> x >> y;
		coordinates[i][0] = x;
		coordinates[i][1] = y;
		//a.insert({ x, y });
	}
	sort(coordinates.begin(), coordinates.end());

	for (int i = 0; i < testCase; i++) {
		cout << coordinates[i][0] << " " << coordinates[i][1] << "\n";
	}
}