#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	int numberOfDoc; // 문서의 개수
	int locationOfDoc; // 몇 번째로 인쇄되었는지 궁금한 문서의 queue 위치 (제일 왼쪽이 0)
	int answer = 0;
	vector<int> answerVector; // 정답 넣을 벡터
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		vector<int> docPriorityQueue;
		vector<int> helpVector; // 같은 우선순위가 있을 경우를 위한 벡터
	
		int doc;
		cin >> numberOfDoc >> locationOfDoc;
		for (int j = 0; j < numberOfDoc; j++) {
			cin >> doc;
			docPriorityQueue.push_back(doc);
			helpVector.push_back(j);  // 같은 우선순위가 있을 경우를 위한 벡터. docPriorityQueue에 중복값 있을 때 내가 
		}
		
		if (docPriorityQueue.size() == 1) {
			answer = 1;
		}
		else {
			bool answerFlag = false;
			while (!answerFlag) {
				int topPriority = *max_element(docPriorityQueue.begin(), docPriorityQueue.end()); // 중요도는 1이상 9이하 정수. 최대 priority 구하기.
				//cout << "topPrior : " <<  topPriority << endl;
				
				for (int k = 0; k < docPriorityQueue.size(); k++) {
					/*
					cout << "priority queue : ";

					for (int m = 0; m < docPriorityQueue.size(); m++) {
						cout << docPriorityQueue[m] << " ";
					}
					cout << endl;
					cout << "help queue : ";
					for (int m = 0; m < helpVector.size(); m++) {
						cout << helpVector[m] << " ";
					}
					cout << endl;*/
					if (docPriorityQueue[k] == topPriority) {
						answer++;
						if (helpVector[k] == locationOfDoc) {
							answerFlag = true;
							break;
						}
						else {
							docPriorityQueue.erase(docPriorityQueue.begin() + k);
							helpVector.erase(helpVector.begin() + k);
							break;
						}
					}
					else {
						int tempVal = helpVector[k];
						helpVector.erase(helpVector.begin() + k);
						helpVector.push_back(tempVal);
						tempVal = docPriorityQueue[k];
						docPriorityQueue.erase(docPriorityQueue.begin() + k);
						docPriorityQueue.push_back(tempVal);

						break;
					}
				}
			}
		}
		
		answerVector.push_back(answer);
		answer = 0;
	}

	for (int i = 0; i < answerVector.size(); i++) {
		cout << answerVector[i] << endl;
	}

}