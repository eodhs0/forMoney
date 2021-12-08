#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long numOfTree, treeDistance;
vector<long long>tree;

bool cmp(long long i, long long j) {
	return i > j;
}

bool binarySearch(long long middle) {
	long long sum = 0;
	for (int i = 0; i < numOfTree; i++) {
		if (tree[i] - middle > 0) {
			sum += tree[i] - middle;
		}
	}
	if (sum >= treeDistance) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> numOfTree >> treeDistance;
	for (int i = 0; i < numOfTree; i++) {
		int t; cin >> t;
		tree.push_back(t);
	}
	sort(tree.begin(), tree.end(), cmp);
	long long answer = 0;
	long long first = 0, end = tree[0];
	while (first <= end) {
		long long middle = (first + end) / 2;
		if (binarySearch(middle)) {
			first = middle + 1;
			if (answer <= middle) {
				answer = middle;
			}
		}
		else {
			end = middle - 1;
		}
	}
	cout << answer << "\n";
}