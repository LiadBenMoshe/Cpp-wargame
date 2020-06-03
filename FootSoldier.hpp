#include <iostream>
#include<limits.h>



using namespace std;


class FootSoldier :public Soldier {


public:
	FootSoldier() {}
	FootSoldier(int num_p) {
		this->damage = 10;
		this->hp = 100;
		this->fullHealt = 100;
		this->player_number = num_p;

	}
	void specialAttack(std::vector<std::vector<Soldier*>> &b, std::pair<int, int> location) override {
		
		int numPlayer = b[location.first][location.second]->getPlayerNum();
		Soldier* s1 = nullptr;
		int ii, jj;
		int dist = INT_MAX;
		for (int i = 0; i < b.size(); i++) {
			for (int j = 0; j < b[0].size(); j++) {
				if (b[i][j] != nullptr && b[i][j]->getPlayerNum() != numPlayer) {
					if (abs(i - location.first) + abs(j - location.second) < dist && 
						abs(i - location.first) + abs(j - location.second)>0) {
						dist=abs(i - location.first) + abs(j - location.second);	
						s1 = b[i][j];
						ii = i;
						jj = j;
					}
				}
			}
		}
		
		if (s1 != nullptr) {
			
			s1->hp = s1->hp - this->damage;
			if (s1->hp <= 0) {
				delete s1;
				b[ii][jj] = nullptr;
				
			
			}
		}
		
		
		
		
		
		



	}
	~FootSoldier(){
		//cout << "delete footSoldier" << endl;
	}

};