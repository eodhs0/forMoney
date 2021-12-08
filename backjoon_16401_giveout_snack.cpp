// binary search
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<int> snackDistance;

bool cmp(int i, int j) {  // �������� ����
	return i > j;
}

int binarySearch(int size) {
	int idx = 0;
	int eat = 0;
	while (idx < N && eat < M) {
		if (snackDistance[idx] >= size) {
			eat += snackDistance[idx] / size;
			idx += 1;
		}
		else {
			break;
		}
	}
	if (eat >= M)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	 cin >> M >> N; // M: ��ī�� ��, N: ������ ��
	
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		snackDistance.push_back(a);
	}
	sort(snackDistance.begin(), snackDistance.end(), cmp); // ������������ ����

	int first = 0;
	int end = snackDistance[0];

	while (end - first > 1) {
		int mid = (end + first) / 2;
		if (binarySearch(mid)) {
			first = mid;
		}
		else {
			end = mid;
		}
	}
	if (binarySearch(end))
		cout << end << "\n";
	else
		cout << first << "\n";
}