#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N; cin >> N;
	vector<int> numVector;
	for (int i = 0; i < N; i++) {
		int data; cin >> data;
		numVector.push_back(data);
	}

	int M; cin >> M;
	vector<int> findNum;
	for (int i = 0; i < M; i++) {
		int data; cin >> data;
		findNum.push_back(data);
	}

	sort(numVector.begin(), numVector.end());
	
	for (int i = 0; i < M; i++) {
		int data = findNum[i];
		if (binary_search(numVector.begin(), numVector.end(), data)) {
			cout << "1" << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	}
}