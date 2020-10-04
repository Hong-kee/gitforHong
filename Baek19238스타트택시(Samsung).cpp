/*
1. ���� ���� ����� �°��� �� �� �¿��.
2. ���� ����� �°��� ���ٸ� ���� ���� ���� �°�, ���� ���� ���� �°��¿�
3. �ýÿ� �°��� ���� ���̶�� �ִܰŸ��� 0
4. ����� �� ĭ �̵��� ������ 1��ŭ �Ҹ�
5. �������� �̵���Ű�� �Ҹ��� ���� ���� 2�� ����.
6. �̵����� ���ᰡ �ٴڳ��� �̵� ���� -> �� ��.
   ��, �������� �̵���Ų ���ÿ� ���ᰡ �ٴڳ��� ��� ������
7. Result=> ��� �մ��� �̵���Ű�� ���Ḧ �������� �� ���� ���� �� ���
			��, ��� �մ��� �̵���Ű�� ���ϰų�, ���ᰡ �ٴڳ��� -1���.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, person, fuel, des_y, des_x, taxi_y, taxi_x, a, b, c, d;
bool possible = true;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };//�ϼ�����
int map[21][21];
bool visit[21][21];
struct pos {
	int y;
	int x;
};

vector<pair<int, int>>person_info[21][21];
vector<pair<int, int>>V;
queue<pos>Q;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void visit_init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
		}
	}
}

void go_to_the_destination() {
	int go_fuel = 0;

	while (!Q.empty()) {
		Q.pop();
	}
	Q.push({ taxi_y, taxi_x });

	while (!Q.empty()) {
		int size = Q.size();
		go_fuel++;

		for (int i = 0; i < size; i++) {
			int y = Q.front().y;
			int x = Q.front().x;

			Q.pop();

			for (int j = 0; j < 4; j++) {
				int my = y + dir[j][0];
				int mx = x + dir[j][1];

				if (Inbound(my, mx)) {
					if (map[my][mx] == 0 && !visit[my][mx]) {
						if (des_y == my && des_x == mx) {
							fuel += go_fuel;
							taxi_y = my;
							taxi_x = mx;
							return;
						}
						else {
							Q.push({ my,mx });
							visit[my][mx] = true;
						}
					}
				}
			}
		}
		if (fuel - go_fuel <= 0) {
			possible = false;
			return;
		}
	}
	possible = false;
}

void find_the_person() {
	int find_fuel = 0;

	while (!Q.empty()) {
		Q.pop();
	}
	while (V.size() > 0) {
		V.pop_back();
	}

	Q.push({ taxi_y, taxi_x });

	if (person_info[taxi_y][taxi_x].size() > 0) {
		V.push_back(make_pair(taxi_y, taxi_x));
		taxi_y = V[0].first;
		taxi_x = V[0].second;
		des_y = person_info[taxi_y][taxi_x].front().first;
		des_x = person_info[taxi_y][taxi_x].front().second;
		person_info[taxi_y][taxi_x].pop_back();
		return;
	}

	while (!Q.empty()) {
		int size = Q.size();
		find_fuel++;

		for (int i = 0; i < size; i++) {
			int y = Q.front().y;
			int x = Q.front().x;

			Q.pop();

			for (int j = 0; j < 4; j++) {
				int my = y + dir[j][0];
				int mx = x + dir[j][1];

				if (Inbound(my, mx)) {
					if (map[my][mx] == 0 && !visit[my][mx]) {
						if (person_info[my][mx].size() > 0) {
							V.push_back(make_pair(my, mx));
						}
						else {
							Q.push({ my,mx });
						}
						visit[my][mx] = true;
					}
				}
			}
		}
		if (fuel - find_fuel <= 0) {
			possible = false;
			return;
		}
		if (V.size() > 0) {
			fuel -= find_fuel;
			sort(V.begin(), V.end());
			taxi_y = V[0].first;
			taxi_x = V[0].second;
			des_y = person_info[taxi_y][taxi_x].front().first;
			des_x = person_info[taxi_y][taxi_x].front().second;
			person_info[taxi_y][taxi_x].pop_back();
			return;
		}
	}
	possible = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> person >> fuel;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> taxi_y >> taxi_x;

	for (int i = 1; i <= person; i++) {
		cin >> a >> b >> c >> d;
		person_info[a][b].push_back(make_pair(c,d));
	}
	while (person > 0) {

		possible = true;
		find_the_person();
		if (!possible) {
			break;
		}
		visit_init();
		go_to_the_destination();
		if (!possible) {
			break;
		}
		visit_init();
		person--;
	}
	if (!possible) {
		cout << -1 << '\n';
	}
	else {
		cout << fuel << '\n';
	}
	return 0;
}