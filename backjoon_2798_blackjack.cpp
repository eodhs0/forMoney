#include <iostream>
#include <vector>

using namespace std;

int main() {
	int input1[2] = {};
	vector<int> inputNums;

	for (int i = 0; i < 2; i++) {
		cin >> input1[i];   // input[0]은 카드 수, input[1]은 카드 3장 더해서 제일 가깝게 만들어야하는 숫자. 하지만 더한 숫자가 input[1] 값을 넘을 수는 없다.
	}


	for (int i = 0; i < input1[0]; i++) {
		int data;
		cin >> data;
		inputNums.push_back(data);
	}

	int cardNum = input1[0];
	int blackJackNum = input1[1];

	int card1, card2, card3; // 카드 3장
	int blackJackNumMinusAddNum = 300001;
	int sumCard = 0;
	int answer = 0;

	// 3장 골라야함.
	for (int i = 0; i < cardNum - 2; i++) {
		card1 = inputNums[i];
		for (int j = i + 1; j < cardNum - 1; j++) {
			card2 = inputNums[j];
			for (int k = j + 1; k < cardNum; k++) {
				card3 = inputNums[k];
				sumCard = card1 + card2 + card3;

				if (sumCard == blackJackNum) {
					answer = sumCard;
					// 블랙잭 숫자와 같을 경우 3중 반복문 빠져나와야함.
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