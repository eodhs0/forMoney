#include <iostream>

using namespace std;

int main() {
	int arr[8] = {};
	int checkSorting = 0; // 1=ascending, 2=descending, 3=mixed
	string answer;
	

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	if (arr[0] < arr[1]) {
		checkSorting = 1;
	}
	else {
		checkSorting = 2;
	}

	for (int i = 1; i < 7; i++) {
		if (arr[i] < arr[i + 1]) {
			if (checkSorting != 1) {
				checkSorting = 3;
				break;
			}
		}
		else {
			if (checkSorting != 2) {
				checkSorting = 3;
				break;
			}
		}
	}

	if (checkSorting == 1) {
		answer = "ascending";
	}
	else if(checkSorting == 2) {
		answer = "descending";
	}
	else {
		answer = "mixed";
	}

	cout << answer << endl;
}