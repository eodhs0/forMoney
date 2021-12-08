#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++) {
        if (phone_book[0] == phone_book[1].substr(0, phone_book[i].size())) {
            answer = false;
            break;
        }
    }
    return answer;
}