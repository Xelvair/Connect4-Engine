#include "TestEvaluator.h"

#include "CheckPath.h"

using namespace C4;

////////////////////
// MEMBER METHODS //
////////////////////

int TestEvaluator::evaluate(Board const& board) const{
	int value = 0;
	
	for(auto it : CheckPath<Board::WIDTH, Board::HEIGHT>::list){
		Vec2s pos = it.first; //initial position
		int redStreak = 0;
		int blueStreak = 0;
		static int i;
		while(pos.isInbetween(Vec2s(0, 0), Vec2s(Board::WIDTH - 1, Board::HEIGHT - 1))){
			switch(board(pos)){
				case Player::None:
					value += valueOfStreak(redStreak);
					value -= valueOfStreak(blueStreak);
					redStreak = 0;
					blueStreak = 0;
					break;
				case Player::Red:
					value -= valueOfStreak(blueStreak);
					blueStreak = 0;
					redStreak++;
					break;
				case Player::Blue:
					value += valueOfStreak(redStreak);
					redStreak = 0;
					blueStreak++;
					break;
			}
			pos += it.second; //step
		}
		value += valueOfStreak(redStreak);
		value -= valueOfStreak(blueStreak);
	}
	return value;
}

////////////////////
// STATIC METHODS //
////////////////////

int TestEvaluator::valueOfStreak(int streak){
	if(streak <= 1){
		return 0;
	} else if(streak == 2){
		return 4;
	} else if(streak == 3){
		return 9;
	} else if(streak >= 4){
		return 999;
	}
	throw std::logic_error(__func__);
}