#include <iostream>
#include<limits.h>
#define FS 100
#define FC 150
#define S 100
#define SC 120
#define P 100
#define PC 200




using namespace std;


class Paramedic :public Soldier {


public:
	Paramedic() {}
	Paramedic(int num_p) {
		this->damage = 0;
		this->hp = 100;
		this->fullHealt = 100;
		this->player_number = num_p;

	}
	void specialAttack(std::vector<std::vector<Soldier*>>& b, std::pair<int, int> location) override {

		int numPlayer = b[location.first][location.second]->getPlayerNum();
		Soldier* s1 = nullptr;
		for(int i=location.first-1;i<=location.first+1;i++){
			for(int j=location.second-1;j<=location.second+1;j++){
				if(i>=0 && i<b.size() && j>=0 && j<b[0].size()){
		
					if(i!=location.first || j!=location.second){
						
						if(b[i][j]!=nullptr && b[i][j]->getPlayerNum()==numPlayer){
						
						b[i][j]->hp=b[i][j]->fullHealt;
						}
					}
				}
			}
		}

		

		

	}

	~Paramedic() {

	}
};
