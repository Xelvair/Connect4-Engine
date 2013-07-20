#pragma once

#include <C4Board/Board.h>

#include "GameNode.h"

namespace C4{
	class GameTree final{
	public:
		GameTree();
		GameTree(GameNode* root, Board const& board);
		GameTree(GameTree const& rhs);
		GameTree(GameTree&& rhs);
		~GameTree();
		
		GameNode*		getRootNode() const;
		void 			setRootNode(GameNode* root);
		const Board&	getBoard() const;
		void			setBoard(Board const& board);
	
		GameTree&		operator=(GameTree const& rhs);
		GameTree&		operator=(GameTree&& rhs);
				
	private:	
		GameNode* 		mp_root;
		Board			m_board;
	};
}