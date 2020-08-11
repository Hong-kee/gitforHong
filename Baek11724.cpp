#include <iostream>
#include <vector>

using namespace std;

vector<int>map[1001];
bool visit[1001];
int N, M, ans = 0;
int Apex_1, Apex_2;

void dfs(int Apex){
	visit[Apex] = true;

	for (int i = 0; i < map[Apex].size(); i++) {
		int next = map[Apex][i];
		if (!visit[next]) {
			dfs(next);
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> Apex_1 >> Apex_2;

		map[Apex_1].push_back(Apex_2);
		map[Apex_2].push_back(Apex_1);
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}