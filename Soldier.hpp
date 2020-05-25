
#include <iostream>



using namespace std;

class Soldier {

protected:
	
	int player_number;

public:

	int hp;
	int damage;
	int healthDamage;

	Soldier() {}


	virtual void specialAttack(std::vector<std::vector<Soldier*>> b, std::pair<int, int> location) = 0;

	int getPlayerNum() {
		return this->player_number;
	}
	 virtual ~Soldier() {
		cout << "delete soldier" << endl;
	}


};


