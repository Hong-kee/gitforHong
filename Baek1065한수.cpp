/*
°£´ÜÇÑ Brute-Force Problem
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int num, cnt = 99;
	string temp;

	cin >> num;

	if (num <= 99) {
		cout << num << '\n';
		return 0;
	}
	else {
		while (num > 100) {
			temp = to_string(num);

			int diff = temp[0] - '0' - (temp[1] - '0');

			if (temp[1] - '0' - (temp[2] - '0') == diff) {
				cnt++;
			}
			num--;
		}
	}
	cout << cnt << '\n';
	return 0;
}