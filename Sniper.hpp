#include <iostream>
#include<limits.h>



using namespace std;


class Sniper :public Soldier {


public:
	Sniper() {}
	Sniper(int num_p) {
		this->damage = 50;
		this->hp = 100;
		this->fullHealt = 100;
		this->player_number = num_p;

	}
	void specialAttack(std::vector<std::vector<Soldier*>>& b, std::pair<int, int> location) override {

		int numPlayer = b[location.first][location.second]->getPlayerNum();
		Soldier* s1 = nullptr;
		int ii, jj;
		int max = 0;

		for (int i = 0; i < b.size(); i++) {
			for (int j = 0; j < b[0].size(); j++) {
				if (b[i][j] != nullptr && b[i][j]->getPlayerNum() != numPlayer) {
					if (b[i][j]->hp > max) {
						max=b[i][j]->hp;
						s1 = b[i][j];
						ii = i;
						jj = j;
					}

				}
			}
		}
		
		s1->hp = s1->hp - this->damage;
		if (s1->hp <= 0) {
			delete s1;
			b[ii][jj] = nullptr;


		}

	}

	~Sniper() {

	}
};
