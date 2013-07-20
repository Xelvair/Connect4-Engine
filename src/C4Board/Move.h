#pragma once

#include <ostream>

#include "Player.h"

namespace C4{
	class Move final{
	public:
						Move();
						Move(Player player, const int column);
						Move(Move const& rhs);
						~Move();

		Move& 			operator=(Move const& rhs);
		
		const Player	getPlayer() const;
		const int		getColumn() const;
		
	private:
		Player 	m_player = Player::None;
		int 	m_column = -1;
		
	friend std::ostream& operator<< (std::ostream&, Move const&);
	};

	std::ostream& operator<< (std::ostream& lhs, C4::Move const& rhs);
}