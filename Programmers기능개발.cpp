#include <iostream>
#include <vector>
using namespace std;

vector<int>progresses, speeds, answer;

int main() {
	int temp, idx = 0;

	for (int i = 0; i < 3; i++) { //progress �Է�
		cin >> temp;
		progresses.push_back(temp);
	}


	for (int i = 0; i < 3; i++) { //speed �Է�
		cin >> temp;
		speeds.push_back(temp);
	}

	while (1) {
		for (int i = idx; i < progresses.size(); i++) {//���Ѵ�.
			progresses[i] += speeds[i];
		}
		int cnt = 0;//���� �ʱ�ȭ

		for (int i = idx; i < progresses.size(); i++) {
			if (progresses[idx] >= 100) { //�˻�
				idx = i+1;
				cnt++;
			}
			else {
				break;
			}
		}
		if (cnt > 0) {//���� �ֱ�
			answer.push_back(cnt);
			if (idx == progresses.size()) {
				break;
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
}