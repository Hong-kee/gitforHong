#include <iostream>
#include <string>
#include <vector>
using namespace std;
int ans = 0;

void learn_the_skill(string skill, vector<string> skill_trees) {

	for (int m = 0; m < skill_trees.size(); m++) {
		int idx = -1;
		bool possible = true, exit = false;
		for (int i = 0; i < skill.size(); i++) {
			for (int j = 0; j < skill_trees[m].size(); j++) {
				if (skill[i] == skill_trees[m][j]) {
					if (possible) {
						if (idx < j) {
							idx = j;
							possible = true;
							break;
						}
						else {
							exit = true;
							break;
						}
					}
					else {
						exit = true;
						break;
					}
				}
				if (j == skill_trees[m].size() - 1 && skill[i] != skill_trees[m][j]) {
					possible = false;
				}
			}
			if (exit == true) {
				break;
			}
		}
		if (exit == false) {
			ans++;
		}
	}
}

int main() {
	string skill,a;

	vector<string>skill_trees;
	cin >> skill;

	for (int i = 0; i < 4; i++) {
		cin >> a;
		skill_trees.push_back(a);
		
	}
	learn_the_skill(skill, skill_trees);
	cout << ans << '\n';

	return 0;
}