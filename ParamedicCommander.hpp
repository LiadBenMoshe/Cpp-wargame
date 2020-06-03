#include <iostream>



using namespace std;


class ParamedicCommander :public Paramedic {

public:
	ParamedicCommander(int num_p) {
		this->damage = 0;
		this->hp = 200;
		this->fullHealt = 200;
		this->player_number = num_p;

	}
	void specialAttack(std::vector<std::vector<Soldier*>>& b, std::pair<int, int> location) override {

		Paramedic::specialAttack(b, location);

		for (int i = 0; i < b.size(); i++) {
			for (int j = 0; j < b[0].size(); j++) {
				if (b[i][j] != nullptr && this->getPlayerNum() == b[i][j]->getPlayerNum()) {
					if (Paramedic * fs = dynamic_cast<Paramedic*>(b[i][j])) {
						if (ParamedicCommander * fc = dynamic_cast<ParamedicCommander*>(b[i][j])) {

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