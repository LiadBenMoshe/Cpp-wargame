/*

AUTHORS: liad ben moshe

*/#include"Board.hpp"#include <iostream>#include "doctest.h"#include <stdexcept>
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
using namespace WarGame;


TEST_CASE("Foot soldiers") {
	Board board(8, 1);

	CHECK(!board.has_soldiers(1));
	board[{0, 0}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{7, 0}] = new FootSoldier(2);
	CHECK(board.has_soldiers(2));

	for (int i = 0; i < 101; i++) {
		CHECK(board.has_soldiers(2));
	}
	
	
	
	
	
}