#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1]][puddles[i][0]] = -1; // �������� �ִ� ���� -1�� �ʱ�ȭ
    }
    dp[1][1] = 1; // ���� ��ġ 

    for (int i = 1; i <= n; i++) { // ��
        for (int j = 1; j <= m; j++) { // ��
            if (dp[i][j] == -1) // ������ ������ �н�
                continue;
            else {
                // ����, ���� �� �����ָ� �ִܰŸ� ����.
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