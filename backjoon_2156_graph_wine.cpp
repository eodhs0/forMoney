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
		dp[i] = max(dp[i - 2] + wine[i], dp[i-3] + wine[i - 1] + wine[i]); // n-1 ���� �ȸ��� ���� n-1 ���� ���� ����� max �� dp ����
		dp[i] = max(dp[i - 1], dp[i]); // (6, 13, 2, 3, 4, 9) �� ��� 2ĭ�� �ǳ� �پ����. ���� ���� max ���� ���� max���� �ٽ� ������.
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