#include <iostream>



using namespace std;


class SniperCommander :public Sniper {

public:
	SniperCommander(int num_p) {
		this->damage = 100;
		this->hp = 120;
		this->fullHealt = 120;
		this->player_number = num_p;

	}
	void specialAttack(std::vector<std::vector<Soldier*>>& b, std::pair<int, int> location) override {

		Sniper::specialAttack(b, location);

		for (int i = 0; i < b.size(); i++) {
			for (int j = 0; j < b[0].size(); j++) {
				if (b[i][j] != nullptr && this->getPlayerNum() == b[i][j]->getPlayerNum()) {
					if (Sniper * fs = dynamic_cast<Sniper*>(b[i][j])) {
						if (SniperCommander * fc = dynamic_cast<SniperCommander*>(b[i][j])) {

						}
						else {
							b[i][j]->specialAttack(b, { i,j });

						}
					}
				}


			}
		}






	}
	

};