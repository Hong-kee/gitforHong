#include <iostream>
#include <vector>
using namespace std;

vector<int>progresses, speeds, answer;

int main() {
	int temp, idx = 0;

	for (int i = 0; i < 3; i++) { //progress 입력
		cin >> temp;
		progresses.push_back(temp);
	}


	for (int i = 0; i < 3; i++) { //speed 입력
		cin >> temp;
		speeds.push_back(temp);
	}

	while (1) {
		for (int i = idx; i < progresses.size(); i++) {//더한다.
			progresses[i] += speeds[i];
		}
		int cnt = 0;//갯수 초기화

		for (int i = idx; i < progresses.size(); i++) {
			if (progresses[idx] >= 100) { //검사
				idx = i+1;
				cnt++;
			}
			else {
				break;
			}
		}
		if (cnt > 0) {//갯수 넣기
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