#include <iostream>
#include <algorithm>
using namespace std;

int testcase, N;
int arr[2][100001], dp[2][100001];

void init_the_dp(int N) {
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] = 0;
			arr[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> testcase;

	while (testcase--) {
		cin >> N;
		init_the_dp(N);

		for (int i = 0; i <= 1; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		for (int i = 2; i <= N; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}
		cout << max(dp[0][N], dp[1][N]) << '\n';
	}
	return 0;
}