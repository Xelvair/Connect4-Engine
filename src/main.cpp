#include <iostream>
#include <cstdlib>
#include <time.h>
#include <Windows.h>

#include <C4Utils/Vec2.h>
#include <C4Board/Board.h>
#include <C4Utils/Array2.h>
#include <C4AI/CheckPath.h>
#include <C4AI/TestEvaluator.h>
#include <C4AI/GameNode.h>
#include <C4AI/TestTreeGenerator.h>
#include <C4Utils/Rect.h>
#include <C4AI/CheckArea.h>

int main(int argc, char* argv[]){
	srand(time(NULL));
	
	C4::Board b;
	C4::TestTreeGenerator g;
	C4::GameTree t;
	C4::EvaluatorV2 e;

	C4::Player current_player = C4::Player::Red;
	
	b.print();
	while(true){
		/*int column = -1;
		do{
			std::cin >> column;
		} while(!b.isOpen(column));
		b.apply(C4::Move(C4::Player::Red, column));
		b.print();
		std::cout << "Eval: " << e.evaluate(b) << std::endl;
		t = g.generate(b, 6);
		b.apply(t.getRootNode()->getBestMove(C4::Player::Blue));
		b.print();
		std::cout << "Eval: " << e.evaluate(b) << std::endl;
		*/
		t = g.generate(b, 6);
		b.apply(C4::Move(t.getRootNode()->getBestMove(C4::Player::Red)));
		b.print();
		std::cout << "Eval: " << e.evaluate(b) << std::endl;
		Sleep(1000);
		t = g.generate(b, 6);
		b.apply(C4::Move(t.getRootNode()->getBestMove(C4::Player::Blue)));
		b.print();
		std::cout << "Eval: " << e.evaluate(b) << std::endl;
		Sleep(1000);
	}
	return 0;
}