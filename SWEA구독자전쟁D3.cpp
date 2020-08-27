#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Testcase, Total, P, T, Min_sub, Max_sub, i = 0;

	cin >> Testcase;

	while (Testcase--) {
		cin >> Total >> P >> T;

		Max_sub = min(P, T);

		if (Total >= P + T) {
			Min_sub = 0;
		}
		else if (Total < P + T) {
			Min_sub = P + T - Total;
		}
		cout << '#' << ++i << ' ' << Max_sub << ' ' << Min_sub << '\n';
	}
}