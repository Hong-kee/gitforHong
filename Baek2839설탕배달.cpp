#include <iostream>
using namespace std;

int main() {
	int can_num, num_3 = 0, num_5 = -1;

	cin >> can_num;

	for (int i = 0; i <= 5000; i += 3) {
		for (int j = 0; j <= 5000; j += 5) {
			num_5++;

			if (i + j == can_num) {
				cout << num_3 + num_5 << '\n';
				return 0;
			}
		}
		num_5 = -1;
		num_3++;
	}
	cout << -1 << '\n';
	return 0;
}