#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int N, x, y, z;
int parent[100001];
int ans;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<tuple<int, int, int>> planet;

int find(int u)
{
	if (parent[u] == u) return u;
	else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v)
{
	u = find(u);
	v = find(v);

	// �θ� ��尡 ���ٸ� ����Ŭ�� ����Ƿ� �ǳʶ�
	if (u == v) return false;
	else
	{
		parent[u] = v; // �θ� ��� ����
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	// �ڱ� �ڽ��� �θ�� ����
	for (int i = 0; i < N; i++)
		parent[i] = i;

	// �༺ ��ǥ �Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> z;
		X.push_back({ x,i });
		Y.push_back({ y,i });
		Z.push_back({ z,i });
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++)
	{
		planet.push_back({ X[i + 1].first - X[i].first,X[i].second,X[i + 1].second });
		planet.push_back({ Y[i + 1].first - Y[i].first,Y[i].second,Y[i + 1].second });
		planet.push_back({ Z[i + 1].first - Z[i].first,Z[i].second,Z[i + 1].second });
	}

	sort(planet.begin(), planet.end());

	for (int i = 0; i < planet.size(); i++)
	{
		int d = get<0>(planet[i]);
		int u = get<1>(planet[i]);
		int v = get<2>(planet[i]);

		if (union_node(u, v)) ans += d;
	}

	cout << ans;
}