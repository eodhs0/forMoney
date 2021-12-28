#include <iostream>
#include <algorithm>

using namespace std;
int N; // ��� ��¥
int dayNPay[16][2]; // ����� �ɸ��� �ð��� �� ����� ����

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int day, pay; cin >> day >> pay;
		dayNPay[i][0] = day; dayNPay[i][1] = pay;
	}
	int answer = 0; // �ִ� pay
	if (N == 1) {
		answer = dayNPay[1][1];
	}
	else {
		for (int i = N; i >= 1; i--) {
			if (i + dayNPay[i][0] > N) { // i ��° ����� �ɸ��� �ð��� ��糯¥���� ���ų� ũ�� pass
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