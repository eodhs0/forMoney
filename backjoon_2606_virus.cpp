#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int numOfComputer, numOfConnection;

bool check[101];
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> numOfComputer >> numOfConnection;
	vector<vector<int>> v(numOfConnection, vector<int>(2, 0)); // testCase 행 2열 2차원 배열 만들기.
	int answer = 0;
	for (int i = 0; i < numOfConnection; i++) {
		int  a, b; cin >> a >> b;
		if (a > b) {
			v[i][0] = b;
			v[i][1] = a;
		}
		else {
			v[i][0] = a;
			v[i][1] = b;
		}
	}
	for (int i = 1; i <= numOfComputer; i++) {
		check[i] = false;
	}

	sort(v.begin(), v.end());
	if (v[0][0] != 1) {
		answer = 0;
	}
	else {
		check[v[0][0]] = true;
		check[v[0][1]] = true;
		for (int i = 0; i < numOfConnection; i++) {
			for (int i = 1; i < numOfConnection; i++) {
				if (check[v[i][0]]) {
					check[v[i][1]] = true;
				}
				if (check[v[i][1]]) {
					check[v[i][0]] = true;
				}
			}
		}
		for (int i = 0; i <= numOfComputer; i++) {
			if (check[i]) {
				answer++;
				//cout << i << endl;
			}
		}
		answer -= 1;
	}
	
	cout << answer << "\n";
}