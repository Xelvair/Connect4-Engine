#include "Move.h"

using namespace C4;

////////////////////
// MEMBER METHODS //
////////////////////

Move::Move(){}

Move::Move(Player player, const int column)
	: m_player(player)
	, m_column(column)
{}

Move::Move(Move const& rhs)
	: m_player(rhs.m_player)
	, m_column(rhs.m_column)
{}

Move::~Move(){}

Move& Move::operator=(Move const& rhs){
	this->m_player = rhs.m_player;
	this->m_column = rhs.m_column;
}

const Player Move::getPlayer() const{
	return m_player;
}

const int Move::getColumn() const{
	return m_column;
}

///////////////
// OPERATORS //
///////////////

std::ostream& C4::operator<< (std::ostream& lhs, Move const& rhs){
	return lhs << "(player:" << rhs.m_player << " column:" << rhs.m_column << ")";
}