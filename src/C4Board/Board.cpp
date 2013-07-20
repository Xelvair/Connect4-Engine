#include "Board.h"

#include <iostream>

using namespace C4;

////////////////////
// MEMBER METHODS //
////////////////////

Vec2s Board::size() const{
	return m_boardCache.size();
}

Player const& Board::operator()(int x, int y) const{
	return m_boardCache(x, y);
}

Player const& Board::operator()(Vec2s const& pos) const{
	return m_boardCache(pos);
}

Move const& Board::getLastMove() const{
	m_moves.size() > 0 ? m_moves.back() : Move();
}

bool Board::isOpen(int column) const{
	if(column < 0 || column >= WIDTH){
		return false;
	} else if(m_boardCache(column, 0) != Player::None){
		return false;
	} else {
		return true;
	}
}

void Board::print(){
	std::cout << "Red Player: X" << std::endl;
	std::cout << "Blue Player: O" << std::endl;
	
	for(int i = 0; i < m_boardCache.size().x * 4; ++i){
		if(i % 4 == 1)
			std::cout << i / 4;
		else
			std::cout << " ";
	}
	std::cout << std::endl;
	
	for(int y = 0; y < m_boardCache.size().y * 2 + 1; ++y){
		for(int x = 0; x < m_boardCache.size().x * 4; x++){
			if(y % 2 == 0){
				std::cout << "-";
			} else {
				if(x % 4 == 3)
					std::cout << "|";
				else if(x % 4 == 1){
					std::cout << m_boardCache(x / 4, y / 2);
				}
				else
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

bool Board::apply(Move const& move){
	if(!isOpen(move.getColumn())){
		return false;
	} else {
		m_moves.push_back(move);
		cacheBoard();
		return true;
	}
}

void Board::revert(){
	m_moves.pop_back();
	cacheBoard();
}

void Board::cacheBoard() const{
	m_boardCache.fill(Player::None);
	
	for(auto it = m_moves.begin(); it != m_moves.end(); ++it){
		int column = it->getColumn();
		int row = m_boardCache.size().y - 1;
		while(row > 0){
			if(m_boardCache(column, row) == Player::None)
				break;
			else{
				--row;
			}
		}
		if(row < m_boardCache.size().y){
			m_boardCache(column, row) = it->getPlayer();
		} else {
			std::cout << "wat." << std::endl;
		}
	}
}