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
	C4::TestEvaluator e;
	C4::TestTreeGenerator g;
	
	C4::GameTree t = g.generate(b, 6);
	
	int num = 0;
	bool isRedTurn = false;
	do{
		isRedTurn = !isRedTurn;
		b.print();
		std::cout << "Evaluation: " << e.evaluate(b) << std::endl;
		std::cin >> num;
	} while (b.apply(C4::Move(isRedTurn ? C4::Player::Red : C4::Player::Blue, num)));
	return 0;
}