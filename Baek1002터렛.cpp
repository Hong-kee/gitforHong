#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double Testcase, x_1, y_1, r_1, x_2, y_2, r_2;

	cin >> Testcase;

	while (Testcase--) {
		cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		
		double center_distance = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));

		if (x_1 == x_2 && y_1 == y_2) {//�߽��� ���� ��
			if (r_1 == r_2) {
				cout << -1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (center_distance == r_1 + r_2) { // ������ ��
			cout << 1 << '\n';
		}
		else if (center_distance > max(r_1, r_2)) { // �߽��� �ٱ� ��
			if (center_distance - min(r_1, r_2) > max(r_1, r_2)) {
				cout << 0 << '\n';
			}
			if (center_distance - min(r_1, r_2) == max(r_1, r_2)) {
				cout << 1 << '\n';
			}
			if (center_distance - min(r_1, r_2) < max(r_1, r_2)) {
				cout << 2 << '\n';
			}
		}
		else if (center_distance == max(r_1, r_2)) { // �߽��� ���� ��ĥ ��
			if (center_distance - min(r_1, r_2) < max(r_1, r_2)) {
				cout << 2 << '\n';
			}
		}
		else if (center_distance < max(r_1, r_2)) { // �߽��� �� ��
			if (center_distance + min(r_1, r_2) == max(r_1, r_2)) {
				cout << 1 << '\n';
			}
			if (center_distance + min(r_1, r_2) < max(r_1, r_2)){
				cout << 0 << '\n';
			}
			if (center_distance + min(r_1, r_2) > max(r_1, r_2)) {
				cout << 2 << '\n';
			}
		}
	}
	return 0;
}