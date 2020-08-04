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
//	UP[0][0] = BACK[2][2];//µÞ¸éÀ» À­¸éÀ¸·Î
//	UP[1][0] = BACK[1][2];
//	UP[2][0] = BACK[0][2];
//
//	BACK[2][2] = DOWN[0][0];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
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
//	UP[0][0] = FRONT[0][0];//À­¸éÀ» ¾Õ¸éÀ¸·Î
//	UP[1][0] = FRONT[1][0];
//	UP[2][0] = FRONT[2][0];
//
//	FRONT[0][0] = DOWN[0][0];//¾Õ¸éÀ» ¹Ø¸éÀ¸·Î
//	FRONT[1][0] = DOWN[1][0];
//	FRONT[2][0] = DOWN[2][0];
//
//	DOWN[0][0] = BACK[2][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
//	DOWN[1][0] = BACK[1][2];
//	DOWN[2][0] = BACK[0][2];
//
//	BACK[0][2] = c;//µÞ¸éÀ» ¾Õ¸éÀ¸·Î
//	BACK[1][2] = b;
//	BACK[2][2] = a;
//
//	a = LEFT[0][0];
//	b = LEFT[0][1];
//
//	LEFT[0][0] = LEFT[0][2];//¿À¸¥ÂÊÀ» À­ÂÊÀ¸·Î
//	LEFT[0][1] = LEFT[1][2];
//	LEFT[0][2] = LEFT[2][2];
//
//	LEFT[1][2] = LEFT[2][1];//¾Æ·§ÂÊÀ» ¿À¸¥ÂÊÀ¸·Î
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
//	UP[0][2] = FRONT[0][2];//µÞ¸éÀ» À­¸éÀ¸·Î
//	UP[1][2] = FRONT[1][2];
//	UP[2][2] = FRONT[2][2];
//
//	FRONT[2][2] = DOWN[2][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
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
//	UP[0][2] = BACK[2][0];//µÞ¸éÀ» À­¸éÀ¸·Î
//	UP[1][2] = BACK[1][0];
//	UP[2][2] = BACK[0][0];
//
//	BACK[2][0] = DOWN[0][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
//	BACK[1][0] = DOWN[1][2];
//	BACK[0][0] = DOWN[2][2];
//
//	DOWN[2][2] = FRONT[2][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
//	DOWN[1][2] = FRONT[1][2];
//	DOWN[0][2] = FRONT[0][2];
//
//	FRONT[0][2] = a;//µÞ¸éÀ» ¾Õ¸éÀ¸·Î
//	FRONT[1][2] = b;
//	FRONT[2][2] = c;
//
//	a = RIGHT[0][0];
//	b = RIGHT[0][1];
//
//	RIGHT[0][0] = RIGHT[0][2];//¿À¸¥ÂÊÀ» À­ÂÊÀ¸·Î
//	RIGHT[0][1] = RIGHT[1][2];
//	RIGHT[0][2] = RIGHT[2][2];
//
//	RIGHT[1][2] = RIGHT[2][1];//¾Æ·§ÂÊÀ» ¿À¸¥ÂÊÀ¸·Î
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
//	UP[2][0] = LEFT[2][2];//µÞ¸éÀ» À­¸éÀ¸·Î
//	UP[2][1] = LEFT[1][2];
//	UP[2][2] = LEFT[0][2];
//
//	LEFT[2][2] = DOWN[0][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
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
//	UP[2][0] = RIGHT[0][0];//µÞ¸éÀ» À­¸éÀ¸·Î
//	UP[2][1] = RIGHT[1][0];
//	UP[2][2] = RIGHT[2][0];
//
//	RIGHT[0][0] = DOWN[0][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
//	RIGHT[1][0] = DOWN[0][1];
//	RIGHT[2][0] = DOWN[0][0];
//
//	DOWN[0][0] = LEFT[0][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
//	DOWN[0][1] = LEFT[1][2];
//	DOWN[0][2] = LEFT[2][2];
//
//	LEFT[0][2] = c;//µÞ¸éÀ» ¾Õ¸éÀ¸·Î
//	LEFT[1][2] = b;
//	LEFT[2][2] = a;
//
//	a = FRONT[0][0];
//	b = FRONT[0][1];
//
//	FRONT[0][0] = FRONT[0][2];//¿À¸¥ÂÊÀ» À­ÂÊÀ¸·Î
//	FRONT[0][1] = FRONT[1][2];
//	FRONT[0][2] = FRONT[2][2];
//
//	FRONT[1][2] = FRONT[2][1];//¾Æ·§ÂÊÀ» ¿À¸¥ÂÊÀ¸·Î
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
//	UP[0][0] = RIGHT[0][2];//µÞ¸éÀ» À­¸éÀ¸·Î
//	UP[0][1] = RIGHT[1][2];
//	UP[0][2] = RIGHT[2][2];
//
//	RIGHT[0][2] = DOWN[2][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
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
//	UP[0][0] = LEFT[2][0];//µÞ¸éÀ» À­¸éÀ¸·Î
//	UP[0][1] = LEFT[1][0];
//	UP[0][2] = LEFT[0][0];
//
//	LEFT[2][0] = DOWN[2][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
//	LEFT[1][0] = DOWN[2][1];
//	LEFT[0][0] = DOWN[2][0];
//
//	DOWN[2][2] = RIGHT[0][2];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
//	DOWN[2][1] = RIGHT[1][2];
//	DOWN[2][0] = RIGHT[2][2];
//
//	RIGHT[0][2] = a;//µÞ¸éÀ» ¾Õ¸éÀ¸·Î
//	RIGHT[1][2] = b;
//	RIGHT[2][2] = c;
//
//	a = BACK[0][0];
//	b = BACK[0][1];
//
//	BACK[0][0] = BACK[0][2];//¿À¸¥ÂÊÀ» À­ÂÊÀ¸·Î
//	BACK[0][1] = BACK[1][2];
//	BACK[0][2] = BACK[2][2];
//
//	BACK[1][2] = BACK[2][1];//¾Æ·§ÂÊÀ» ¿À¸¥ÂÊÀ¸·Î
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
//	BACK[0][0] = LEFT[0][0];//µÞ¸éÀ» À­¸éÀ¸·Î
//	BACK[0][1] = LEFT[0][1];
//	BACK[0][2] = LEFT[0][2];
//
//	LEFT[0][0] = FRONT[0][0];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
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
//	BACK[0][0] = RIGHT[0][0];//µÞ¸éÀ» À­¸éÀ¸·Î
//	BACK[0][1] = RIGHT[0][1];
//	BACK[0][2] = RIGHT[0][2];
//
//	RIGHT[0][0] = FRONT[0][0];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
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
//	UP[0][0] = UP[0][2];//¿À¸¥ÂÊÀ» À­ÂÊÀ¸·Î
//	UP[0][1] = UP[1][2];
//	UP[0][2] = UP[2][2];
//
//	UP[1][2] = UP[2][1];//¾Æ·§ÂÊÀ» ¿À¸¥ÂÊÀ¸·Î
//	UP[2][2] = UP[2][0];
//
//	UP[2][1] = UP[1][0];
//	UP[2][0] = a;
//	UP[1][0] = b;
//}
//void Down_clock()//°íÄ¡±â
//{
//	char a = FRONT[2][0], b = FRONT[2][1], c = FRONT[2][2];
//
//	FRONT[2][0] = LEFT[2][0];//µÞ¸éÀ» À­¸éÀ¸·Î
//	FRONT[2][1] = LEFT[2][1];
//	FRONT[2][2] = LEFT[2][2];
//
//	LEFT[2][0] = BACK[2][0];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
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
//	FRONT[2][0] = RIGHT[2][0];//µÞ¸éÀ» À­¸éÀ¸·Î
//	FRONT[2][1] = RIGHT[2][1];
//	FRONT[2][2] = RIGHT[2][2];
//
//	RIGHT[2][0] = BACK[2][0];//¹Ø¸éÀ» µÞ¸éÀ¸·Î
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
//	DOWN[0][0] = DOWN[0][2];//¿À¸¥ÂÊÀ» À­ÂÊÀ¸·Î
//	DOWN[0][1] = DOWN[1][2];
//	DOWN[0][2] = DOWN[2][2];
//
//	DOWN[1][2] = DOWN[2][1];//¾Æ·§ÂÊÀ» ¿À¸¥ÂÊÀ¸·Î
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
//			if (what_turn == "L-")//¿ÞÂÊ¸é ¹Ý½Ã°è
//			{
//				Left_reverse_clock();
//			}
//			if (what_turn == "L+")//¿ÞÂÊ¸é ½Ã°è
//			{
//				Left_clock();
//			}
//			if (what_turn == "R-")//¿À¸¥¸é ¹Ý½Ã°è
//			{
//				Right_reverse_clock();
//			}
//			if (what_turn == "R+")//¿À¸¥¸é ½Ã°è
//			{
//				Right_clock();
//			}
//			if (what_turn == "F-")//¾Õ¸é ¹Ý½Ã°è
//			{
//				Front_reverse_clock();
//			}
//			if (what_turn == "F+")//¾Õ¸é ½Ã°è
//			{
//				Front_clock();
//			}
//			if (what_turn == "B-")//µÞ¸é ¹Ý½Ã°è
//			{
//				Back_reverse_clock();
//			}
//			if (what_turn == "B+")//µÞ¸é ½Ã°è
//			{
//				Back_clock();
//			}
//			if (what_turn == "U-")//À­¸é ¹Ý½Ã°è
//			{
//				Up_reverse_clock();
//			}
//			if (what_turn == "U+")//À­¸é ½Ã°è
//			{
//				Up_clock();
//			}
//			if (what_turn == "D-")//¾Æ·§¸é ¹Ý½Ã°è
//			{
//				Down_reverse_clock();
//			}
//			if (what_turn == "D+")//¾Æ·§¸é ½Ã°è
//			{
//				Down_clock();
//			}
//		}
//
//		for (int i = 0; i < 3; i++)//À­¸é Ãâ·Â
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