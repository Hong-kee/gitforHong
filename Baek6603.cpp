#include <iostream>
using namespace std;

int N, num;
int arr[50];
bool visit[50];

void dfs(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 1; i <= N; i++) {
			if (visit[i]) {
				cout << arr[i] << ' ';
			}
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = idx; i <= N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				dfs(i, cnt + 1);
				visit[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		arr[i] = num;
	}
	dfs(1,0);

	return 0;
}