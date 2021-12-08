#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end()); // 오름차순 정렬
    long long first = 1;
    long long end = (long long)times[times.size() - 1] * n; // 최대 걸리는 시간 : 입국 심사 대기자 * 가장 긴 
    while (first <= end) {
        long long middle = (first + end) / 2;
        long long count = 0;
        for (int i = 0; i < times.size(); i++) {
            count += middle / times[i];
        }
        if (count < n) {
            first = middle + 1;
        }
        else {
            if (middle <= end) {
                answer = middle;
            }
            end = middle - 1;
        }
    }
    return answer;
}