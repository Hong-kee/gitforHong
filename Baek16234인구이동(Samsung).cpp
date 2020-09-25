#include <iostream>
#include <queue>
using namespace std;

int map[51][51];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//ºÏ,µ¿,³²,¼­
int numbering[51][51];
bool check[51][51];
int N, L, R, cnt = 0, nation_num = 0;

struct pos {
	int y;
	int x;
};
queue<pos>nation;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void numbering_init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			numbering[i][j] = 0;
		}
	}
}

void borderline(int y, int x) {
	int ans = map[y][x], nation_cnt = 1;
	check[y][x] = true;
	nation_num++;
	nation.push({ y, x });
	numbering[y][x] = nation_num;

	while (!nation.empty()) {
		int size_of_nation = nation.size();

		for (int i = 0; i < size_of_nation; i++) {
			int y = nation.front().y;
			int x = nation.front().x;

			nation.pop();
			
			for (int j = 0; j < 4; j++) {
				int my = y + dir[j][0];
				int mx = x + dir[j][1];

				if (Inbound(my, mx)) {
					if (numbering[my][mx] == 0) {
						if (abs(map[my][mx] - map[y][x]) >= L
							&& abs(map[my][mx] - map[y][x]) <= R) {

							nation.push({ my,mx });
							numbering[my][mx] = nation_num;
							ans += map[my][mx];
							nation_cnt++;
						}
					}
				}
			}
		}
	}
	if (nation_cnt > 1) {
		ans /= nation_cnt;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (numbering[i][j] == nation_num) {
					map[i][j] = ans;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];//¸Ê ÀÔ·Â
		}
	}
	while (numbering[N][N] != N * N) {
		nation_num = 0;
		numbering_init();

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (numbering[i][j] == 0) {
					borderline(i,j);
				}
			}
		}

		if (numbering[N][N] != N * N) {
			cnt++;
		}
	}
	cout << cnt << '\n';

	return 0;
}