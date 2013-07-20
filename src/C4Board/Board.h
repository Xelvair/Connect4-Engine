#pragma once

#include <list>

#include <C4Utils/Array2.h>

#include "Move.h"
#include "Player.h"

namespace C4{
	class Board final{	
	public:
		static const int WIDTH = 7;
		static const int HEIGHT = 6;
		typedef Array2<Player, WIDTH, HEIGHT> 	BoardArray;
	
		Vec2s				size() const;
		Player const&		operator()(int x, int y) const;
		Player const&		operator()(Vec2s const&) const;
		Move 				getLastMove() const;
		bool				isOpen(int column) const;
		void 				print();
		bool 				apply(Move const& move);
		void 				revert();
	
	private:
		typedef std::list<Move>	MoveList;
	
		MoveList				m_moves;
		mutable BoardArray 		m_boardCache = BoardArray(Player::None);
		
		void					cacheBoard() const;
	};
}