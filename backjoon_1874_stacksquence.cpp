#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n, data;
	cin >> n;

	vector<int> sequenceNum; // 만들어야하는 순열
	stack<int> stack; // 반드시 오름차순으로
	vector<string> answerVector; // +, - 출력을 위한 string vector

	for (int i = 0; i < n; i++) {
		cin >> data;
		sequenceNum.push_back(data);
	}

	int point = 0; // sequenceNum 위치 좌표
	int pushNum = 1; // stack 에 push할 데이터
	stack.push(pushNum++);
	answerVector.push_back("+");
	//cout << "+" << endl;

	while (point != sequenceNum.size()) {
		if (pushNum > n + 1) {  // 무한루프 방지
			break;
		}

		if (sequenceNum[point] == stack.top()) {  // 만들어야 하는 순열과 현재 stack top 이 같을 때 pop 하고 순열 point ++
			stack.pop();
			answerVector.push_back("-");
			point++;
			//cout << "-" << endl;
			if (pushNum <= n && stack.empty()) {  // 3  1 2 3 이런거 일 때 push 하고 바로 pop 하면 stack empty 되니까 바로 push 갯수랑 empty 인지 같이 확인해서 push .
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