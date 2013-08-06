#include "GameTree.h"

using namespace C4;

//////////////////////////////
// CONSTRUCTORS/DESTRUCTORS //
//////////////////////////////

GameTree::GameTree()
	: mp_root(nullptr)
	, m_board(Board())
{}

GameTree::GameTree(GameNode* root, Board const& board)
	: mp_root(root)
	, m_board(board)
{}

GameTree::GameTree(GameTree const& rhs){
	std::cout << "copying a game tree makes me sad :(" << std::endl;
}

GameTree::GameTree(GameTree&& rhs)
	: m_board(rhs.m_board)
{
	delete mp_root;
	mp_root = rhs.mp_root;
	rhs.mp_root = nullptr;
}

GameTree::~GameTree(){
	if(mp_root){
		delete mp_root;
		mp_root = nullptr;
	}
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

///////////////
// OPERATORS //
///////////////

GameTree& GameTree::operator=(GameTree const& rhs){
	std::cout << "copying a game tree makes me sad :(" << std::endl;
	return *this;
}

GameTree& GameTree::operator=(GameTree&& rhs){
	m_board = rhs.m_board;
	delete mp_root;
	mp_root = rhs.mp_root;
	rhs.mp_root = nullptr;
	return *this;
}