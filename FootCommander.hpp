#include <iostream>



using namespace std;


class FootCommander :public FootSoldier {

public:
	FootCommander(int num_p) {
		this->damage = 20;
		this->hp = 150;
		this->healthDamage = 0;
		this->player_number = num_p;

	}
	void specialAttack(std::vector<std::vector<Soldier*>> b, std::pair<int, int> location) override {
		
		FootSoldier::specialAttack(b, location);

		for (int i = 0; i < b.size(); i++) {
			for (int j = 0; j < b[0].size(); j++) {
				if (b[i][j]!=nullptr && this->getPlayerNum() == b[i][j]->getPlayerNum()) {
					if (FootSoldier * fs = dynamic_cast<FootSoldier*>(b[i][j])) {
						if (FootCommander * fc = dynamic_cast<FootCommander*>(b[i][j])) {

						}
						else {
							b[i][j]->specialAttack(b, { i,j });
							
							

						}
					}
				}
					

			}
		}

		
		
		
		
		
	}
	~FootCommander(){
		cout << "delete footCommander" << endl;
	}

};