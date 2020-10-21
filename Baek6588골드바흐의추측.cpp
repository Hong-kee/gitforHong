#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool eratos[1000001];
int min_num, max_num;

bool check_the_number(int Testcase) {
	for (int first = 3; first <= Testcase / 2; first++) {
		if (eratos[first] && eratos[Testcase - first]) {
			min_num = first;
			max_num = Testcase - first;
			return true;
		}
	}
	return false;
}

void determine_the_number() {
	eratos[3] = true;
	eratos[5] = true;
	eratos[7] = true;

	for (int i = 11; i <= 1000000; i += 2) {
		eratos[i] = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i%j == 0) {
				eratos[i] = false;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Testcase;
	determine_the_number();

	while (1) {
		cin >> Testcase;
		if (Testcase == 0) {
			break;
		}

		if (check_the_number(Testcase)) {
			cout << Testcase << " = " << min_num << " + " << max_num<<'\n';
		}
		else {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}
}