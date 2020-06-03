#include <string>
#include <vector>
#include <stdexcept>
#include"Board.hpp"


namespace WarGame {

	
		// operator for putting soldiers on the game-board during initialization.
		Soldier*& Board::operator[](std::pair<int, int> location) {
			
			return this->board[location.first][location.second];
		}

		// operator for reading which soldiers are on the game-board.
		Soldier* Board::operator[](std::pair<int, int> location) const {
			return this->board[location.first][location.second];
		}

		void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
			if (this->board[source.first][source.second]==nullptr || 
				this->board[source.first][source.second]->getPlayerNum() != player_number) {
				throw std::invalid_argument("Worng Move!");
			}
			if (direction == MoveDIR::Down ) {
				
				if (source.first-1 >=0 && source.first-1 < this->board.size() && 
					this->board[source.first - 1][source.second]==nullptr)
				{

					this->board[source.first - 1][source.second] = this->board[source.first][source.second];
					this->board[source.first][source.second] = nullptr;
					this->board[source.first - 1][source.second]->specialAttack(this->board, { source.first - 1 ,source.second });
				}
				else {
					throw std::invalid_argument("Worng Move!");
				}
			}
			else if (direction == MoveDIR::Up) {

				if (source.first + 1 >= 0 && source.first + 1 < this->board.size() &&
					this->board[source.first + 1][source.second] == nullptr)
				{

					this->board[source.first + 1][source.second] = this->board[source.first][source.second];
					this->board[source.first][source.second] = nullptr;
					this->board[source.first + 1][source.second]->specialAttack(this->board, { source.first + 1 ,source.second });
				}
				else {
					throw std::invalid_argument("Worng Move!");
				}
			}
			else if (direction == MoveDIR::Right) {

				if (source.second + 1 >= 0 && source.second + 1 < this->board[source.first].size() &&
					this->board[source.first][source.second+1] == nullptr)
				{

					this->board[source.first][source.second+1] = this->board[source.first][source.second];
					this->board[source.first][source.second] = nullptr;
					this->board[source.first][source.second+1]->specialAttack(this->board, { source.first ,source.second +1});
				}
				else {
					throw std::invalid_argument("Worng Move!");
				}
			}
			else if (direction == MoveDIR::Left) {

				if (source.second - 1 >= 0 && source.second - 1 < this->board[source.first].size() &&
					this->board[source.first][source.second - 1] == nullptr)
				{

					this->board[source.first][source.second - 1] = this->board[source.first][source.second];
					this->board[source.first][source.second] = nullptr;
					this->board[source.first][source.second-1]->specialAttack(this->board, { source.first ,source.second-1 });
				}
				else {
					throw std::invalid_argument("Worng Move!");
				}
			}
			else {
					throw std::invalid_argument("Worng Move!");
				}
			

		

		}

		// returns true iff the board contains one or more soldiers of the given player.
		bool Board::has_soldiers(uint player_number) const {

			for (int i = 0; i < this->board.size(); i++) {
				for (int j = 0; j < this->board[0].size(); j++) {
					if (this->board[i][j] != nullptr && this->board[i][j]->getPlayerNum() == player_number)
						return true;
				}
			}

			return false;
		}

		void Board::deleteall() {
			for (int i = 0; i < this->board.size(); i++) {
				for (int j = 0; j < this->board.front().size(); j++) {
					if (this->board[i][j] != nullptr)
						delete board[i][j];
				}
			}
		}
	}