#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1]][puddles[i][0]] = -1; // 물웅덩이 있는 곳을 -1로 초기화
    }
    dp[1][1] = 1; // 시작 위치 

    for (int i = 1; i <= n; i++) { // 열
        for (int j = 1; j <= m; j++) { // 행
            if (dp[i][j] == -1) // 웅덩이 있으면 패스
                continue;
            else {
                // 왼쪽, 위쪽 값 더해주면 최단거리 갯수.
                if (dp[i - 1][j] > 0)
                    dp[i][j] += dp[i - 1][j];
                if (dp[i][j - 1] > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
    }
    answer = dp[n][m] % 1000000007;

    return answer;
}