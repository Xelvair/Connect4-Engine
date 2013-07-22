#include "EvaluatorV2.h"

#include <cstdlib>

#include "CheckArea.h"

using namespace C4;

int EvaluatorV2::evaluate(Board const& board) const{
	CheckAreaList check_list = CheckArea<Board::WIDTH, Board::HEIGHT>::list;
	
	int value = 0;
	for(auto check_area : check_list){
		std::list<Vec2i> path_list = Vec2i::allInbetween(check_area.first.first, check_area.first.second);
		Vec2i step = check_area.second;
		for(auto path : path_list){
			int redCount = 0;
			int blueCount = 0;
			Vec2i pos = path;
			for(int i = 0; i < 4; ++i){
				if(board(static_cast<Vec2s>(pos)) == Player::Red){
					redCount++;
				} else if(board(static_cast<Vec2s>(pos)) == Player::Blue){
					blueCount++;
				}
				pos += step;
			}
			if(redCount == 0 || blueCount == 0){
				if(std::max(redCount, blueCount) == redCount){
					value += valueOfStreak(redCount);
				} else {
					value -= valueOfStreak(blueCount);
				}
			}
		}
	}
	return value;
}

int EvaluatorV2::valueOfStreak(int streak) const{
	if(streak <= 0){
		return 0;
	} else if(streak == 1){
		return 1;
	} else if(streak == 2){
		return 16;
	} else if(streak == 3){
		return 64;
	} else {
		return 9999;
	}
}