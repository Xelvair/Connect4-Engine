#include "GameNode.h"

using namespace C4;

////////////////////////////
// CONSTRUCTOR/DESTRUCTOR //
////////////////////////////

GameNode::GameNode(Move const& move, int value)
	: m_move(move)
	, m_value(value)
{}

GameNode::~GameNode(){
	delete m_subNodes.back();
	m_subNodes.pop_back();
}

////////////////////
// MEMBER METHODS //
////////////////////

void GameNode::setMove(Move const& move){
	m_move = move;
}

void GameNode::setValue(int value){
	m_value = value;
}

Move const& GameNode::getMove() const{
	return m_move;
}

int GameNode::getValue() const{
	return m_value;
}

void GameNode::addSubnode(GameNode* node){
	m_subNodes.push_back(node);
}

void GameNode::removeSubnode(GameNode* node){
	for(auto it : m_subNodes){
		if(it == node){
			std::swap(it, m_subNodes.back());
			delete m_subNodes.back();
			m_subNodes.pop_back();
		}
	}
}

GameNode::NodeListIterator GameNode::getNodeListBegin(){
	return m_subNodes.begin();
}

GameNode::NodeListIterator GameNode::getNodeListEnd(){
	return m_subNodes.end();
}

///////////////
// OPERATORS //
///////////////

std::ostream& C4::operator<< (std::ostream& lhs, GameNode const& rhs){
	return lhs << "(move:" << rhs.m_move << " value:" << rhs.m_value << " subnodes:" << rhs.m_subNodes.size() << ")";
}

