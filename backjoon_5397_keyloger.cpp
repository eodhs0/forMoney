#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		string input, answer;
	
		int cursorLocation = 0;
		stack<char> answerStack, arrowStack; // 정답을 실을 스택과 우측 화살표, 좌측 화살표에 따라 사용할 스택
		
		cin >> input;
		
		for (int j = 0; j < input.size(); j++) {
			if (input[j] == '<') {
				if (answerStack.empty()) {
					continue;
				}
				arrowStack.push(answerStack.top());
				answerStack.pop();
			}
			else if (input[j] == '>') {
				if (arrowStack.empty()) {
					continue;
				}
				answerStack.push(arrowStack.top());
				arrowStack.pop();
			}
			else if (input[j] == '-') {
				if (answerStack.empty()) {
					continue;
				}
				answerStack.pop();
			}
			else {
				answerStack.push(input[j]);
			}
			/*
			for (int j = 0; j < answer.size(); j++) {
				cout << answer[j];
			}
			cout << "\n";
			*/
		}

		while (!arrowStack.empty()) {
			answerStack.push(arrowStack.top());
			arrowStack.pop();
		}

		while (!answerStack.empty()) {
			answer += answerStack.top();
			answerStack.pop();
		}

		reverse(answer.begin(), answer.end());

		cout << answer;
		cout << "\n";
	}
	
}