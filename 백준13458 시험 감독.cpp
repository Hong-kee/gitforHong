#include <iostream>
using namespace std;

long long N, grandmaster, master;
long long ans = 0;
int classroom[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> classroom[i];
	}

	cin >> grandmaster >> master;

	for (int i = 1; i <= N; i++) {
		if (classroom[i] - grandmaster <= 0) {
			classroom[i] = 0;
		}
		else {
			classroom[i] -= grandmaster;
		}
		ans++;
	}

	for (int i = 1; i <= N; i++) {
		if (classroom[i] == 0) {
			continue;
		}
		else if (classroom[i] != 0 && classroom[i] / master >= 1
			&& classroom[i] % master != 0) {
			ans += (classroom[i] / master) + 1;
		}
		else if (classroom[i] != 0 && classroom[i] / master >= 1
			&& classroom[i] % master == 0) {
			ans += classroom[i] / master;
		}
		else if (classroom[i] != 0 && classroom[i] / master < 1){
			ans += 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
