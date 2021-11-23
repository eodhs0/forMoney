#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int testCase; cin >> testCase;
	
	multimap<int, string> people; // 중복 key 사용을 위한 multimap 사용.
	for (int i = 0; i < testCase; i++) {
		int age; cin >> age;
		string name; cin >> name;
		people.insert({ age, name });
	}

	for (auto iter : people) {
		cout << iter.first << " " << iter.second << "\n";
	}
}