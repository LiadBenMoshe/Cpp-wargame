/*

AUTHORS: liad ben moshe

*/
#include"Board.hpp"
#include <iostream>
#include "doctest.h"
#include <stdexcept>
#include <cassert>

#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"


using namespace std;
using namespace WarGame;


TEST_CASE("Foot soldiers") {
	Board board(8, 1);

	CHECK(!board.has_soldiers(1));
	board[{0, 0}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{7, 0}] = new FootSoldier(2);
	CHECK(board.has_soldiers(2));

	CHECK_NOTHROW(board.move(1, { 0,0 }, Board::MoveDIR::Up));
	CHECK_NOTHROW(board.move(1, { 1,0 }, Board::MoveDIR::Down));
	CHECK_NOTHROW(board.move(1, { 0,0 }, Board::MoveDIR::Up));
	CHECK_NOTHROW(board.move(1, { 1,0 }, Board::MoveDIR::Down));
	CHECK_NOTHROW(board.move(1, { 0,0 }, Board::MoveDIR::Up));
	CHECK_NOTHROW(board.move(1, { 1,0 }, Board::MoveDIR::Down));
	CHECK_NOTHROW(board.move(1, { 0,0 }, Board::MoveDIR::Up));
	CHECK_NOTHROW(board.move(1, { 1,0 }, Board::MoveDIR::Down));
	CHECK_NOTHROW(board.move(1, { 0,0 }, Board::MoveDIR::Up));
	CHECK_NOTHROW(board.move(1, { 1,0 }, Board::MoveDIR::Down));

	CHECK(!board.has_soldiers(2));
	board.deleteall();

	
}
	
	
TEST_CASE("SniperCommander") {

	Board board(8, 8);

	board[{0, 1}] = new FootSoldier(1);
	board[{0, 3}] = new SniperCommander(1);
	board[{0, 5}] = new FootSoldier(1);

	board[{7, 1}] = new FootSoldier(2);
	board[{7, 3}] = new FootCommander(2);
	board[{7, 5}] = new FootSoldier(2);

	CHECK_NOTHROW(board.move(1, { 0,1 }, Board::MoveDIR::Up));
	CHECK_NOTHROW(board.move(2, { 7,1 }, Board::MoveDIR::Down));
	CHECK_NOTHROW(board.move(1, { 0,3 }, Board::MoveDIR::Up));
	CHECK_NOTHROW(board.move(2, { 7,3 }, Board::MoveDIR::Left));
	CHECK_NOTHROW(board.move(1, { 1,3 }, Board::MoveDIR::Left));
	CHECK_NOTHROW(board.move(1, { 1,2 }, Board::MoveDIR::Up));
	CHECK_NOTHROW(board.move(1, { 2,2 }, Board::MoveDIR::Up));

	CHECK(!board.has_soldiers(2));
	board.deleteall();
	
	
}

TEST_CASE("Paramedic"){

	Board board(8, 2);

	board[{0, 0}] = new Sniper(1);
	board[{6, 0}] = new SniperCommander(2);
	board[{7, 1}] = new Paramedic(2);
	
	CHECK_NOTHROW(board.move(1, { 0,0 }, Board::MoveDIR::Up));
	CHECK(board[{6, 0}]->hp==70);
	CHECK_NOTHROW(board.move(1, { 1,0 }, Board::MoveDIR::Down));
	CHECK(board[{7, 1}]->hp==50);
	CHECK_NOTHROW(board.move(2, { 7,1 }, Board::MoveDIR::Down));
	CHECK(board[{6, 0}]->hp==120);

	board.deleteall();
	

}

TEST_CASE("FootCommander") {

	Board board(8, 8);

	board[{0, 1}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{0, 2}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{0, 3}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{0, 4}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{0, 5}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{0, 6}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{0, 7}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{0, 0}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{1, 0}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
	board[{1, 1}] = new FootCommander(1);
	CHECK(board.has_soldiers(1));
	CHECK(!board.has_soldiers(2));
	board[{7, 1}] = new Paramedic(2);
	CHECK(board.has_soldiers(2));
	CHECK_NOTHROW(board.move(1, { 1,1 }, Board::MoveDIR::Up));
	CHECK(!board.has_soldiers(2));

	board.deleteall();





}
TEST_CASE("ParamedicCommander"){

	Board board(8, 2);

	board[{0, 0}] = new Sniper(1);
	board[{7, 0}] = new ParamedicCommander(2);
	board[{7, 1}] = new Paramedic(2);
	
	CHECK_NOTHROW(board.move(1, { 0,0 }, Board::MoveDIR::Right));
	CHECK_NOTHROW(board.move(2, { 7,0 }, Board::MoveDIR::Down));
	CHECK_NOTHROW(board.move(1, { 0,1 }, Board::MoveDIR::Left));
	CHECK_NOTHROW(board.move(2, { 6,0 }, Board::MoveDIR::Up));
	CHECK(board[{7, 0}]->hp==200);
	CHECK(board[{7, 1}]->hp==100);
	CHECK(board[{0, 0}]->hp==100);
	board.deleteall();
}
TEST_CASE("Exepsion"){
	

	Board board(8, 8);

	board[{0, 0}] = new Sniper(1);
	board[{7, 0}] = new ParamedicCommander(2);
	board[{7, 1}] = new Paramedic(2);
	

	CHECK_THROWS(board.move(2, { 5,5 }, Board::MoveDIR::Up));
	CHECK_THROWS(board.move(1, { 6,5 }, Board::MoveDIR::Up));
	
	CHECK_THROWS(board.move(2, { 0,0 }, Board::MoveDIR::Up));
	CHECK_THROWS(board.move(1, { 7,1 }, Board::MoveDIR::Down));
	
	CHECK_THROWS(board.move(1, { 7,0 }, Board::MoveDIR::Up));

	CHECK_THROWS(board.move(1, { 0,0 }, Board::MoveDIR::Down));
	CHECK_THROWS(board.move(2, { 7,0 }, Board::MoveDIR::Up));
	CHECK_THROWS(board.move(2, { 7,1 }, Board::MoveDIR::Up));



	board.deleteall();

}
TEST_CASE("has soldier"){

	Board board(8, 8);

	board[{0, 0}] = new Sniper(1);
	board[{7, 0}] = new ParamedicCommander(2);
	board[{7, 1}] = new Paramedic(2);

	CHECK(board.has_soldiers(1));
	CHECK(board.has_soldiers(2));

	CHECK(board.has_soldiers(1));
	CHECK(board.has_soldiers(2));

	CHECK(board.has_soldiers(1));
	CHECK(board.has_soldiers(2));
	

}