//#include <iostream>
//#include <string>
//using namespace std;
//
//char UP[3][3] = { {'w','w','w'},{'w','w','w'},{'w','w','w'} };
//char DOWN[3][3] = { {'y','y','y'},{'y','y','y'},{'y','y','y'} };
//char RIGHT[3][3] = { {'b','b','b'},{'b','b','b'},{'b','b','b'} };
//char LEFT[3][3] = { {'g','g','g'},{'g','g','g'},{'g','g','g'} };
//char FRONT[3][3] = { {'r','r','r'},{'r','r','r'},{'r','r','r'} };
//char BACK[3][3] = { {'o','o','o'},{'o','o','o'},{'o','o','o'} };
//
//void Left_clock()////
//{
//	char a = UP[0][0], b = UP[1][0], c = UP[2][0];
//
//	UP[0][0] = BACK[2][2];//�޸��� ��������
//	UP[1][0] = BACK[1][2];
//	UP[2][0] = BACK[0][2];
//
//	BACK[2][2] = DOWN[0][0];//�ظ��� �޸�����
//	BACK[1][2] = DOWN[1][0];
//	BACK[0][2] = DOWN[2][0];
//
//	DOWN[0][0] = FRONT[0][0];
//	DOWN[1][0] = FRONT[1][0];
//	DOWN[2][0] = FRONT[2][0];
//
//	FRONT[0][0] = a;
//	FRONT[1][0] = b;
//	FRONT[2][0] = c;//
//
//	a = LEFT[0][0];
//	b = LEFT[0][1];
//	c = LEFT[0][2];
//
//	LEFT[0][2] = LEFT[0][0];
//	LEFT[0][1] = LEFT[1][0];
//	LEFT[0][0] = LEFT[2][0];
//
//	LEFT[1][0] = LEFT[2][1];
//	LEFT[2][0] = LEFT[2][2];
//
//	LEFT[2][1] = LEFT[1][2];
//	LEFT[2][2] = c;
//	LEFT[1][2] = b;
//}
//void Left_reverse_clock()//
//{
//	char a = UP[0][0], b = UP[1][0], c = UP[2][0];
//	UP[0][0] = FRONT[0][0];//������ �ո�����
//	UP[1][0] = FRONT[1][0];
//	UP[2][0] = FRONT[2][0];
//
//	FRONT[0][0] = DOWN[0][0];//�ո��� �ظ�����
//	FRONT[1][0] = DOWN[1][0];
//	FRONT[2][0] = DOWN[2][0];
//
//	DOWN[0][0] = BACK[2][2];//�ظ��� �޸�����
//	DOWN[1][0] = BACK[1][2];
//	DOWN[2][0] = BACK[0][2];
//
//	BACK[0][2] = c;//�޸��� �ո�����
//	BACK[1][2] = b;
//	BACK[2][2] = a;
//
//	a = LEFT[0][0];
//	b = LEFT[0][1];
//
//	LEFT[0][0] = LEFT[0][2];//�������� ��������
//	LEFT[0][1] = LEFT[1][2];
//	LEFT[0][2] = LEFT[2][2];
//
//	LEFT[1][2] = LEFT[2][1];//�Ʒ����� ����������
//	LEFT[2][2] = LEFT[2][0];
//
//	LEFT[2][1] = LEFT[1][0];
//	LEFT[2][0] = a;
//	LEFT[1][0] = b;
//}
//void Right_clock()////
//{
//	char a = UP[0][2], b = UP[1][2], c = UP[2][2];
//
//	UP[0][2] = FRONT[0][2];//�޸��� ��������
//	UP[1][2] = FRONT[1][2];
//	UP[2][2] = FRONT[2][2];
//
//	FRONT[2][2] = DOWN[2][2];//�ظ��� �޸�����
//	FRONT[1][2] = DOWN[1][2];
//	FRONT[0][2] = DOWN[0][2];
//
//	DOWN[0][2] = BACK[2][0];
//	DOWN[1][2] = BACK[1][0];
//	DOWN[2][2] = BACK[0][0];
//
//	BACK[0][0] = c;
//	BACK[1][0] = b;
//	BACK[2][0] = a;
//
//	a = RIGHT[0][0];
//	b = RIGHT[0][1];
//	c = RIGHT[0][2];
//
//	RIGHT[0][2] = RIGHT[0][0];
//	RIGHT[0][1] = RIGHT[1][0];
//	RIGHT[0][0] = RIGHT[2][0];
//
//	RIGHT[1][0] = RIGHT[2][1];
//	RIGHT[2][0] = RIGHT[2][2];
//
//	RIGHT[2][1] = RIGHT[1][2];
//	RIGHT[2][2] = c;
//	RIGHT[1][2] = b;
//}
//void Right_reverse_clock()////
//{
//	char a = UP[0][2], b = UP[1][2], c = UP[2][2];
//	UP[0][2] = BACK[2][0];//�޸��� ��������
//	UP[1][2] = BACK[1][0];
//	UP[2][2] = BACK[0][0];
//
//	BACK[2][0] = DOWN[0][2];//�ظ��� �޸�����
//	BACK[1][0] = DOWN[1][2];
//	BACK[0][0] = DOWN[2][2];
//
//	DOWN[2][2] = FRONT[2][2];//�ظ��� �޸�����
//	DOWN[1][2] = FRONT[1][2];
//	DOWN[0][2] = FRONT[0][2];
//
//	FRONT[0][2] = a;//�޸��� �ո�����
//	FRONT[1][2] = b;
//	FRONT[2][2] = c;
//
//	a = RIGHT[0][0];
//	b = RIGHT[0][1];
//
//	RIGHT[0][0] = RIGHT[0][2];//�������� ��������
//	RIGHT[0][1] = RIGHT[1][2];
//	RIGHT[0][2] = RIGHT[2][2];
//
//	RIGHT[1][2] = RIGHT[2][1];//�Ʒ����� ����������
//	RIGHT[2][2] = RIGHT[2][0];
//
//	RIGHT[2][1] = RIGHT[1][0];
//	RIGHT[2][0] = a;
//	RIGHT[1][0] = b;
//}
//void Front_clock()//
//{
//	char a = UP[2][0], b = UP[2][1], c = UP[2][2];
//
//	UP[2][0] = LEFT[2][2];//�޸��� ��������
//	UP[2][1] = LEFT[1][2];
//	UP[2][2] = LEFT[0][2];
//
//	LEFT[2][2] = DOWN[0][2];//�ظ��� �޸�����
//	LEFT[1][2] = DOWN[0][1];
//	LEFT[0][2] = DOWN[0][0];
//
//	DOWN[0][2] = RIGHT[0][0];
//	DOWN[0][1] = RIGHT[1][0];
//	DOWN[0][0] = RIGHT[2][0];
//
//	RIGHT[0][0] = a;
//	RIGHT[1][0] = b;
//	RIGHT[2][0] = c;
//
//	a = FRONT[0][0];
//	b = FRONT[0][1];
//	c = FRONT[0][2];
//
//	FRONT[0][2] = FRONT[0][0];
//	FRONT[0][1] = FRONT[1][0];
//	FRONT[0][0] = FRONT[2][0];
//
//	FRONT[1][0] = FRONT[2][1];
//	FRONT[2][0] = FRONT[2][2];
//
//	FRONT[2][1] = FRONT[1][2];
//	FRONT[2][2] = c;
//	FRONT[1][2] = b;
//}
//void Front_reverse_clock()//
//{
//	char a = UP[2][0], b = UP[2][1], c = UP[2][2];
//	UP[2][0] = RIGHT[0][0];//�޸��� ��������
//	UP[2][1] = RIGHT[1][0];
//	UP[2][2] = RIGHT[2][0];
//
//	RIGHT[0][0] = DOWN[0][2];//�ظ��� �޸�����
//	RIGHT[1][0] = DOWN[0][1];
//	RIGHT[2][0] = DOWN[0][0];
//
//	DOWN[0][0] = LEFT[0][2];//�ظ��� �޸�����
//	DOWN[0][1] = LEFT[1][2];
//	DOWN[0][2] = LEFT[2][2];
//
//	LEFT[0][2] = c;//�޸��� �ո�����
//	LEFT[1][2] = b;
//	LEFT[2][2] = a;
//
//	a = FRONT[0][0];
//	b = FRONT[0][1];
//
//	FRONT[0][0] = FRONT[0][2];//�������� ��������
//	FRONT[0][1] = FRONT[1][2];
//	FRONT[0][2] = FRONT[2][2];
//
//	FRONT[1][2] = FRONT[2][1];//�Ʒ����� ����������
//	FRONT[2][2] = FRONT[2][0];
//
//	FRONT[2][1] = FRONT[1][0];
//	FRONT[2][0] = a;
//	FRONT[1][0] = b;
//}
//
//void Back_clock()//
//{
//	char a = UP[0][0], b = UP[0][1], c = UP[0][2];
//
//	UP[0][0] = RIGHT[0][2];//�޸��� ��������
//	UP[0][1] = RIGHT[1][2];
//	UP[0][2] = RIGHT[2][2];
//
//	RIGHT[0][2] = DOWN[2][2];//�ظ��� �޸�����
//	RIGHT[1][2] = DOWN[2][1];
//	RIGHT[2][2] = DOWN[2][0];
//
//	DOWN[2][2] = LEFT[2][0];
//	DOWN[2][1] = LEFT[1][0];
//	DOWN[2][0] = LEFT[0][0];
//
//	LEFT[2][0] = a;
//	LEFT[1][0] = b;
//	LEFT[0][0] = c;
//
//	a = BACK[0][0];
//	b = BACK[0][1];
//	c = BACK[0][2];
//
//	BACK[0][2] = BACK[0][0];
//	BACK[0][1] = BACK[1][0];
//	BACK[0][0] = BACK[2][0];
//
//	BACK[1][0] = BACK[2][1];
//	BACK[2][0] = BACK[2][2];
//
//	BACK[2][1] = BACK[1][2];
//	BACK[2][2] = c;
//	BACK[1][2] = b;
//}
//void Back_reverse_clock()//
//{
//	char a = UP[0][0], b = UP[0][1], c = UP[0][2];
//
//	UP[0][0] = LEFT[2][0];//�޸��� ��������
//	UP[0][1] = LEFT[1][0];
//	UP[0][2] = LEFT[0][0];
//
//	LEFT[2][0] = DOWN[2][2];//�ظ��� �޸�����
//	LEFT[1][0] = DOWN[2][1];
//	LEFT[0][0] = DOWN[2][0];
//
//	DOWN[2][2] = RIGHT[0][2];//�ظ��� �޸�����
//	DOWN[2][1] = RIGHT[1][2];
//	DOWN[2][0] = RIGHT[2][2];
//
//	RIGHT[0][2] = a;//�޸��� �ո�����
//	RIGHT[1][2] = b;
//	RIGHT[2][2] = c;
//
//	a = BACK[0][0];
//	b = BACK[0][1];
//
//	BACK[0][0] = BACK[0][2];//�������� ��������
//	BACK[0][1] = BACK[1][2];
//	BACK[0][2] = BACK[2][2];
//
//	BACK[1][2] = BACK[2][1];//�Ʒ����� ����������
//	BACK[2][2] = BACK[2][0];
//
//	BACK[2][1] = BACK[1][0];
//	BACK[2][0] = a;
//	BACK[1][0] = b;
//}
//void Up_clock()//
//{
//	char a = BACK[0][0], b = BACK[0][1], c = BACK[0][2];
//
//	BACK[0][0] = LEFT[0][0];//�޸��� ��������
//	BACK[0][1] = LEFT[0][1];
//	BACK[0][2] = LEFT[0][2];
//
//	LEFT[0][0] = FRONT[0][0];//�ظ��� �޸�����
//	LEFT[0][1] = FRONT[0][1];
//	LEFT[0][2] = FRONT[0][2];
//
//	FRONT[0][0] = RIGHT[0][0];
//	FRONT[0][1] = RIGHT[0][1];
//	FRONT[0][2] = RIGHT[0][2];
//
//	RIGHT[0][0] = a;
//	RIGHT[0][1] = b;
//	RIGHT[0][2] = c;
//
//	a = UP[0][0];
//	b = UP[0][1];
//	c = UP[0][2];
//
//	UP[0][2] = UP[0][0];
//	UP[0][1] = UP[1][0];
//	UP[0][0] = UP[2][0];
//
//	UP[1][0] = UP[2][1];
//	UP[2][0] = UP[2][2];
//
//	UP[2][1] = UP[1][2];
//	UP[2][2] = c;
//	UP[1][2] = b;
//}
//void Up_reverse_clock()//
//{
//	char a = BACK[0][0], b = BACK[0][1], c = BACK[0][2];
//
//	BACK[0][0] = RIGHT[0][0];//�޸��� ��������
//	BACK[0][1] = RIGHT[0][1];
//	BACK[0][2] = RIGHT[0][2];
//
//	RIGHT[0][0] = FRONT[0][0];//�ظ��� �޸�����
//	RIGHT[0][1] = FRONT[0][1];
//	RIGHT[0][2] = FRONT[0][2];
//
//	FRONT[0][0] = LEFT[0][0];
//	FRONT[0][1] = LEFT[0][1];
//	FRONT[0][2] = LEFT[0][2];
//
//	LEFT[0][0] = a;
//	LEFT[0][1] = b;
//	LEFT[0][2] = c;
//
//	a = UP[0][0];
//	b = UP[0][1];
//
//	UP[0][0] = UP[0][2];//�������� ��������
//	UP[0][1] = UP[1][2];
//	UP[0][2] = UP[2][2];
//
//	UP[1][2] = UP[2][1];//�Ʒ����� ����������
//	UP[2][2] = UP[2][0];
//
//	UP[2][1] = UP[1][0];
//	UP[2][0] = a;
//	UP[1][0] = b;
//}
//void Down_clock()//��ġ��
//{
//	char a = FRONT[2][0], b = FRONT[2][1], c = FRONT[2][2];
//
//	FRONT[2][0] = LEFT[2][0];//�޸��� ��������
//	FRONT[2][1] = LEFT[2][1];
//	FRONT[2][2] = LEFT[2][2];
//
//	LEFT[2][0] = BACK[2][0];//�ظ��� �޸�����
//	LEFT[2][1] = BACK[2][1];
//	LEFT[2][2] = BACK[2][2];
//
//	BACK[2][0] = RIGHT[2][0];
//	BACK[2][1] = RIGHT[2][1];
//	BACK[2][2] = RIGHT[2][2];
//
//	RIGHT[2][0] = a;
//	RIGHT[2][1] = b;
//	RIGHT[2][2] = c;
//
//	a = DOWN[0][0];
//	b = DOWN[0][1];
//	c = DOWN[0][2];
//
//	DOWN[0][2] = DOWN[0][0];
//	DOWN[0][1] = DOWN[1][0];
//	DOWN[0][0] = DOWN[2][0];
//
//	DOWN[1][0] = DOWN[2][1];
//	DOWN[2][0] = DOWN[2][2];
//
//	DOWN[2][1] = DOWN[1][2];
//	DOWN[2][2] = c;
//	DOWN[1][2] = b;
//}
//void Down_reverse_clock()//
//{
//	char a = FRONT[2][0], b = FRONT[2][1], c = FRONT[2][2];
//
//	FRONT[2][0] = RIGHT[2][0];//�޸��� ��������
//	FRONT[2][1] = RIGHT[2][1];
//	FRONT[2][2] = RIGHT[2][2];
//
//	RIGHT[2][0] = BACK[2][0];//�ظ��� �޸�����
//	RIGHT[2][1] = BACK[2][1];
//	RIGHT[2][2] = BACK[2][2];
//
//	BACK[2][0] = LEFT[2][0];
//	BACK[2][1] = LEFT[2][1];
//	BACK[2][2] = LEFT[2][2];
//
//	LEFT[2][0] = a;
//	LEFT[2][1] = b;
//	LEFT[2][2] = c;
//
//	a = DOWN[0][0];
//	b = DOWN[0][1];
//
//	DOWN[0][0] = DOWN[0][2];//�������� ��������
//	DOWN[0][1] = DOWN[1][2];
//	DOWN[0][2] = DOWN[2][2];
//
//	DOWN[1][2] = DOWN[2][1];//�Ʒ����� ����������
//	DOWN[2][2] = DOWN[2][0];
//
//	DOWN[2][1] = DOWN[1][0];
//	DOWN[2][0] = a;
//	DOWN[1][0] = b;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int Total_turn_num, turn_num;
//	string what_turn;
//
//	cin >> Total_turn_num;
//
//	while (Total_turn_num--)
//	{
//		cin >> turn_num;
//
//		for (int i = 0; i < turn_num; i++)
//		{
//			cin >> what_turn;
//
//			if (what_turn == "L-")//���ʸ� �ݽð�
//			{
//				Left_reverse_clock();
//			}
//			if (what_turn == "L+")//���ʸ� �ð�
//			{
//				Left_clock();
//			}
//			if (what_turn == "R-")//������ �ݽð�
//			{
//				Right_reverse_clock();
//			}
//			if (what_turn == "R+")//������ �ð�
//			{
//				Right_clock();
//			}
//			if (what_turn == "F-")//�ո� �ݽð�
//			{
//				Front_reverse_clock();
//			}
//			if (what_turn == "F+")//�ո� �ð�
//			{
//				Front_clock();
//			}
//			if (what_turn == "B-")//�޸� �ݽð�
//			{
//				Back_reverse_clock();
//			}
//			if (what_turn == "B+")//�޸� �ð�
//			{
//				Back_clock();
//			}
//			if (what_turn == "U-")//���� �ݽð�
//			{
//				Up_reverse_clock();
//			}
//			if (what_turn == "U+")//���� �ð�
//			{
//				Up_clock();
//			}
//			if (what_turn == "D-")//�Ʒ��� �ݽð�
//			{
//				Down_reverse_clock();
//			}
//			if (what_turn == "D+")//�Ʒ��� �ð�
//			{
//				Down_clock();
//			}
//		}
//
//		for (int i = 0; i < 3; i++)//���� ���
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				cout << UP[i][j];
//			}
//			cout << '\n';
//		}
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				UP[i][j] = 'w';
//				DOWN[i][j] = 'y';
//				FRONT[i][j] = 'r';
//				BACK[i][j] = 'o';
//				LEFT[i][j] = 'g';
//				RIGHT[i][j] = 'b';
//			}
//		}
//	}
//	return 0;
//}