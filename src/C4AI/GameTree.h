#pragma once

#include <C4Board/Board.h>

#include "GameNode.h"

namespace C4{
	class GameTree final{
	public:
		GameTree(GameNode* root = nullptr, Board const& board = Board());
		~GameTree();
		
		GameNode*		getRootNode() const;
		void 			setRootNode(GameNode* root);
		const Board&	getBoard() const;
		void			setBoard(Board const& board);
		
	private:
		GameNode* 	mp_root;
		Board		m_board;
	};
}