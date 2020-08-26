/* ans = 청소하는 칸의 갯수
1. 1은 벽, 0은 빈 칸
2. 현재 위치를 청소하고 왼쪽이 방문하지 않고, 0이라면 들어가서 청소
3. 만일 4곳 다 청소 못하면 처음 방향을 기준으로 뒤로 가서 또 왼쪽회전탐색
4. 만일 뒤로 갈 수 없다면 종료
*/

#include<iostream>
#include<queue>
using namespace std;

struct pos {
	int y;
	int x;
	int c_dir;
};
int map[50][50];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//북,동,남,서
int r, c, f_y, f_x, f_dir, ans = 1;
bool visit[50][50];
queue<pos>Q;

bool Inbound(int y, int x) {
	if (y >= 0 && x >= 0 && y < r && x < c) {
		return true;
	}
	return false;
}

int change_the_dir(int n_dir) { //현 기준 왼쪽 방향으로 전환
	if (n_dir == 0) {
		return 3;
	}
	else if (n_dir == 1) {
		return 0;
	}
	else if (n_dir == 2) {
		return 1;
	}
	else if (n_dir == 3) {
		return 2;
	}
}

void clean_the_room(){
	Q.push({ f_y, f_x, f_dir});
	visit[f_y][f_x] = true; //첫 번째 방문 처리

	while(!Q.empty()) {
		int ny = Q.front().y;
		int nx = Q.front().x;
		int n_dir = Q.front().c_dir;
		Q.pop();

		for (int i = 0; i < 4; i++) { //방향 바꾸면서 넣을 수 있는지 확인
			n_dir = change_the_dir(n_dir);

			int my = ny + dir[n_dir][0];
			int mx = nx + dir[n_dir][1];

			if (Inbound(my, mx) && !visit[my][mx] && map[my][mx] == 0) {
				Q.push({ my,mx,n_dir });
				ans++;
				visit[my][mx] = true;
				break;
			}
		}

		if (Q.empty()) { //비었으면 더 이상 청소 불가능->뒤로가기
			ny -= dir[n_dir][0];
			nx -= dir[n_dir][1];
			
			if (Inbound(ny, nx) && map[ny][nx] != 1) {
				Q.push({ ny,nx,n_dir});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	cin >> f_y >> f_x >> f_dir;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	clean_the_room();
	cout << ans << '\n';
	return 0;
}