/* ans = û���ϴ� ĭ�� ����
1. 1�� ��, 0�� �� ĭ
2. ���� ��ġ�� û���ϰ� ������ �湮���� �ʰ�, 0�̶�� ���� û��
3. ���� 4�� �� û�� ���ϸ� ó�� ������ �������� �ڷ� ���� �� ����ȸ��Ž��
4. ���� �ڷ� �� �� ���ٸ� ����
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
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//��,��,��,��
int r, c, f_y, f_x, f_dir, ans = 1;
bool visit[50][50];
queue<pos>Q;

bool Inbound(int y, int x) {
	if (y >= 0 && x >= 0 && y < r && x < c) {
		return true;
	}
	return false;
}

int change_the_dir(int n_dir) { //�� ���� ���� �������� ��ȯ
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
	visit[f_y][f_x] = true; //ù ��° �湮 ó��

	while(!Q.empty()) {
		int ny = Q.front().y;
		int nx = Q.front().x;
		int n_dir = Q.front().c_dir;
		Q.pop();

		for (int i = 0; i < 4; i++) { //���� �ٲٸ鼭 ���� �� �ִ��� Ȯ��
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

		if (Q.empty()) { //������� �� �̻� û�� �Ұ���->�ڷΰ���
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