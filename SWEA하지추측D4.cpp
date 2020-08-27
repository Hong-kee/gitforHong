#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	long long Num, i = 0;

	cin >> T;

	while (T--) {
		cin >> Num;
		if (Num == 1) {
			cout << '#' << ++i << ' ' << "NO" << '\n';
			continue;
		}
		while (Num > 1) {
			if (Num % 2 == 0) {
				Num /= 2;
			}
			else {
				cout << '#' << ++i << ' ' << "NO" << '\n';
				break;
			}
		}
		if (Num == 1) {
			cout << '#' << ++i << ' ' << "YES" << '\n';
		}
	}
}