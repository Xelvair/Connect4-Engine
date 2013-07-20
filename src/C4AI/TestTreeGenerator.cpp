#include "TestTreeGenerator.h"

#include <Windows.h>

#include <C4Board/Player.h>

using namespace C4;

GameTree TestTreeGenerator::generate(Board board, int depth) const{
	GameNode* root;
	if(board.getLastMove().getPlayer() == Player::None){ //If no move has been made, start with the initial player
		root = new GameNode(Move(nextPlayer(STARTING_PLAYER), -1), 0);
	} else {
		root = new GameNode(board.getLastMove(), m_evaluator.evaluate(board));
	}
	
	generateRecursiveTree(root, board, depth);
	
	return GameTree(root, board);
}

void TestTreeGenerator::generateRecursiveTree(GameNode*& node, Board& board, int depth) const{	
	//Evaluate node score
	node->setValue(m_evaluator.evaluate(board));
	
	/*
	std::cout << "Evaluated board: " << std::endl;
	board.print();
	std::cout << "score: " << node->getValue() << " depth: " << depth << std::endl;
	Sleep(250);
	*/
	
	//If we're at the specified depth, GTFO
	if(depth <= 0)
		return;
	
	//Calculate all possible moves
	Player current_player = nextPlayer(node->getMove().getPlayer());
	std::list<Move>	possible_moves;
	for(int column = 0; column < Board::WIDTH; ++column){
		if(board.isOpen(column)){
			possible_moves.push_back(Move(current_player, column));
		}
	}
	
	//Recurse on each subnode/move
	for(auto move : possible_moves){
		GameNode* subnode = new GameNode(move);
		node->addSubnode(subnode);
		board.apply(move);
		generateRecursiveTree(subnode, board, depth - 1);
		board.revert();
	}
}