/*
1. 기사는 가장 가까운 승객을 고른 후 태운다.
2. 만일 가까운 승객이 많다면 가장 작은 행의 승객, 가장 작은 열의 승객태움
3. 택시와 승객이 같은 곳이라면 최단거리는 0
4. 연료는 한 칸 이동할 때마다 1만큼 소모
5. 목적지로 이동시키면 소모한 연료 양의 2배 충전.
6. 이동도중 연료가 바닥나면 이동 실패 -> 일 끝.
   단, 목적지로 이동시킨 동시에 연료가 바닥나는 경우 성공임
7. Result=> 모든 손님을 이동시키고 연료를 충전했을 때 남은 연료 양 출력
			단, 모든 손님을 이동시키지 못하거나, 연료가 바닥나면 -1출력.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, person, fuel, des_y, des_x, taxi_y, taxi_x, a, b, c, d;
bool possible = true;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };//북서남동
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