#include <iostream>
#include <algorithm>

using namespace std;
int N; // 퇴사 날짜
int dayNPay[16][2]; // 상담이 걸리는 시간과 그 상담의 페이

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int day, pay; cin >> day >> pay;
		dayNPay[i][0] = day; dayNPay[i][1] = pay;
	}
	int answer = 0; // 최대 pay
	if (N == 1) {
		answer = dayNPay[1][1];
	}
	else {
		for (int i = N; i >= 1; i--) {
			if (i + dayNPay[i][0] > N) { // i 번째 상담이 걸리는 시간이 퇴사날짜보다 같거나 크면 pass
				cout << "pass" << " " << i << "\n";
				continue;
			}
			else {
				answer = max(answer, answer + dayNPay[i][1]);
			}
		}
	}
	cout << answer << "\n";
}