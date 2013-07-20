#include <iostream>
#include <cstdlib>
#include <time.h>

#include <C4Utils/Vec2.h>
#include <C4Board/Board.h>
#include <C4Utils/Array2.h>
#include <C4AI/CheckPath.h>
#include <C4AI/TestEvaluator.h>
#include <C4AI/GameNode.h>
#include <C4AI/TestTreeGenerator.h>

int main(int argc, char* argv[]){
	srand(time(NULL));
	
	C4::Board b;
	C4::TestTreeGenerator g;
	C4::GameTree t;
	
	b.print();
	while(true){
		/*
		int column = -1;
		do{
			std::cin >> column;
		} while(!b.isOpen(column));
		b.apply(C4::Move(C4::Player::Red, column));
		b.print();
		t = g.generate(b, 4);
		b.apply(t.getRootNode()->getBestMove(C4::Player::Blue));
		b.print();*/
		
		t = g.generate(b, 6);
		b.apply(C4::Move(t.getRootNode()->getBestMove(C4::Player::Red)));
		b.print();
		t = g.generate(b, 6);
		b.apply(C4::Move(t.getRootNode()->getBestMove(C4::Player::Blue)));
		b.print();
	}
	
	return 0;
}