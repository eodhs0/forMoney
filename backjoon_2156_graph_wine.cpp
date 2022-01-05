#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
int wine[10003];
int dp[10003];

void solve() {
	for (int i = 3; i < n + 3; i++) {
		dp[i] = max(dp[i - 2] + wine[i], dp[i-3] + wine[i - 1] + wine[i]); // n-1 잔을 안마신 경우와 n-1 잔을 마신 경우의 max 값 dp 저장
		dp[i] = max(dp[i - 1], dp[i]); // (6, 13, 2, 3, 4, 9) 일 경우 2칸을 건너 뛰어야함. 따라서 이전 max 값과 현재 max값을 다시 봐야함.
		//cout << dp[i] << endl;
	}
	cout << dp[n + 2] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 3; i++) {
		wine[i] = 0;
		dp[i] = 0;
	}
	for (int i = 3; i < n+3; i++) {
		cin >> wine[i];
	}

	solve();
}