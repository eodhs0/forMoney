#include <iostream>
#include <algorithm>

using namespace std;
int n; // °Å½º¸§µ·
int answer;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n;
	if (n == 1 || n == 3)
		answer = -1;
	else {
		answer = 9999999999;
		int count5 = n / 5;
		int count2 = n / 2;

		for (int i = count5; i >= 0; i--) {
			for (int j = 0; j <= count2; j++) {
				if ((5 * i + 2 * j) == n)
					answer = min(answer, i + j);
			}
		}
	}
	cout << answer << "\n";
}