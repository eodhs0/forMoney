#include <iostream>
#include <vector>

using namespace std;

int main() {
	int input1[2] = {};
	vector<int> inputNums;

	for (int i = 0; i < 2; i++) {
		cin >> input1[i];   // input[0]�� ī�� ��, input[1]�� ī�� 3�� ���ؼ� ���� ������ �������ϴ� ����. ������ ���� ���ڰ� input[1] ���� ���� ���� ����.
	}


	for (int i = 0; i < input1[0]; i++) {
		int data;
		cin >> data;
		inputNums.push_back(data);
	}

	int cardNum = input1[0];
	int blackJackNum = input1[1];

	int card1, card2, card3; // ī�� 3��
	int blackJackNumMinusAddNum = 300001;
	int sumCard = 0;
	int answer = 0;

	// 3�� ������.
	for (int i = 0; i < cardNum - 2; i++) {
		card1 = inputNums[i];
		for (int j = i + 1; j < cardNum - 1; j++) {
			card2 = inputNums[j];
			for (int k = j + 1; k < cardNum; k++) {
				card3 = inputNums[k];
				sumCard = card1 + card2 + card3;

				if (sumCard == blackJackNum) {
					answer = sumCard;
					// ���� ���ڿ� ���� ��� 3�� �ݺ��� �������;���.
					j = cardNum;
					i = cardNum;
					break;
				}

				if (sumCard > blackJackNum) {
					continue;
				}

				if ((blackJackNum - sumCard) < blackJackNumMinusAddNum) {
					answer = sumCard;
					blackJackNumMinusAddNum = blackJackNum - sumCard;
				}
			}
		}
	}
	cout << answer << endl;
}