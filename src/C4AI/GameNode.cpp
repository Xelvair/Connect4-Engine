#include "GameNode.h"

#include <iostream>
#include <cstdlib>

using namespace C4;

////////////////////////////
// CONSTRUCTOR/DESTRUCTOR //
////////////////////////////

GameNode::GameNode(Move const& move, int value)
	: m_move(move)
	, m_value(value)
{}

GameNode::~GameNode(){
	if(m_subNodes.size() > 0){
		delete m_subNodes.back();
		m_subNodes.pop_back();
	}
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

Move GameNode::getBestMove(const Player player) const{
	if(m_subNodes.size() == 0){
		return Move(player, -1);
	}

	std::vector<GameNode*> nodes;
	int best_value = m_subNodes[0]->getValue();
	for(auto node : m_subNodes){
		if(player == Player::Red){
			if (node->getValue() > best_value){
				best_value = node->getValue();
				nodes.clear();
				nodes.push_back(node);
			} else if(node->getValue() == best_value){
				nodes.push_back(node);
			}
		} else {
			if (node->getValue() < best_value){
				best_value = node->getValue();
				nodes.clear();
				nodes.push_back(node);
			} else if(node->getValue() == best_value){
				nodes.push_back(node);
			}
		}
	}
	return (nodes[rand() % nodes.size()])->getMove();
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

