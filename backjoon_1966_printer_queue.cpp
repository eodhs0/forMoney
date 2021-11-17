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
	int numberOfDoc; // ������ ����
	int locationOfDoc; // �� ��°�� �μ�Ǿ����� �ñ��� ������ queue ��ġ (���� ������ 0)
	int answer = 0;
	vector<int> answerVector; // ���� ���� ����
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		vector<int> docPriorityQueue;
		vector<int> helpVector; // ���� �켱������ ���� ��츦 ���� ����
	
		int doc;
		cin >> numberOfDoc >> locationOfDoc;
		for (int j = 0; j < numberOfDoc; j++) {
			cin >> doc;
			docPriorityQueue.push_back(doc);
			helpVector.push_back(j);  // ���� �켱������ ���� ��츦 ���� ����. docPriorityQueue�� �ߺ��� ���� �� ���� 
		}
		
		if (docPriorityQueue.size() == 1) {
			answer = 1;
		}
		else {
			bool answerFlag = false;
			while (!answerFlag) {
				int topPriority = *max_element(docPriorityQueue.begin(), docPriorityQueue.end()); // �߿䵵�� 1�̻� 9���� ����. �ִ� priority ���ϱ�.
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