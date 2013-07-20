#pragma once

#include <ostream>

namespace C4{
	enum class Player{
		Red,
		Blue,
		None
	};
	
	static const Player STARTING_PLAYER = Player::Red;
	
	/*Might want to put this in a .cpp file in the future*/
	inline Player nextPlayer(const Player player){
		return player == Player::Red ? Player::Blue : Player::Red;
	}
	
	inline std::ostream& operator<< (std::ostream& lhs, C4::Player const& rhs){
		switch(rhs){
			case C4::Player::Red:
				lhs << "X";
				break;
			case C4::Player::Blue:
				lhs << "O";
				break;
			default:
				lhs << " ";
				break;
		}
		return lhs;
	}
}