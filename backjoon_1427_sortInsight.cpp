#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr;
	int multiple = 10;
	if (N < 10) {
		cout << N;
	}
	else {
		while (N > 0) {
			//cout << N % 10 << endl;
			arr.push_back(N % 10);
			N = N / 10;
		}
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
	}
	
	cout << '\n';
}