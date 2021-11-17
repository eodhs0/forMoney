#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n, data;
	cin >> n;

	vector<int> sequenceNum; // �������ϴ� ����
	stack<int> stack; // �ݵ�� ������������
	vector<string> answerVector; // +, - ����� ���� string vector

	for (int i = 0; i < n; i++) {
		cin >> data;
		sequenceNum.push_back(data);
	}

	int point = 0; // sequenceNum ��ġ ��ǥ
	int pushNum = 1; // stack �� push�� ������
	stack.push(pushNum++);
	answerVector.push_back("+");
	//cout << "+" << endl;

	while (point != sequenceNum.size()) {
		if (pushNum > n + 1) {  // ���ѷ��� ����
			break;
		}

		if (sequenceNum[point] == stack.top()) {  // ������ �ϴ� ������ ���� stack top �� ���� �� pop �ϰ� ���� point ++
			stack.pop();
			answerVector.push_back("-");
			point++;
			//cout << "-" << endl;
			if (pushNum <= n && stack.empty()) {  // 3  1 2 3 �̷��� �� �� push �ϰ� �ٷ� pop �ϸ� stack empty �Ǵϱ� �ٷ� push ������ empty ���� ���� Ȯ���ؼ� push .
				stack.push(pushNum++);
				answerVector.push_back("+");
				//cout << "+" << endl;
			}
		}
		else {
			stack.push(pushNum++);
			answerVector.push_back("+");
			//cout << "+" << endl;
		}
	}

	if (stack.empty()) {
		for (unsigned int i = 0; i < answerVector.size(); i++) {
			cout << answerVector[i] << "\n";
		}
	}
	else {
		cout << "NO" << "\n";
	}
}