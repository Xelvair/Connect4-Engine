#include "GameTree.h"

using namespace C4;

//////////////////////////////
// CONSTRUCTORS/DESTRUCTORS //
//////////////////////////////

GameTree::GameTree(GameNode* root, Board const& board)
	: mp_root(root)
	, m_board(board)
{}

GameTree::~GameTree(){
	delete mp_root;
	mp_root = nullptr;
}

////////////////////
// MEMBER METHODS //
////////////////////

GameNode* GameTree::getRootNode() const{
	return mp_root;
}

void GameTree::setRootNode(GameNode* root){
	mp_root = root;
}

const Board& GameTree::getBoard() const{
	return m_board;
}

void GameTree::setBoard(Board const& board){
	m_board = board;
}