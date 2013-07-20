#pragma once

#include <vector>

#include <C4Board/Move.h>
#include <C4Board/Player.h>

namespace C4{
	class GameNode final{	
	public:
		typedef std::vector<GameNode*> 	NodeList;
		typedef NodeList::iterator		NodeListIterator;
	
		GameNode(Move const& move = Move(), int value = 0);
		~GameNode();
		
		void				setMove(Move const& move);
		void				setValue(int value);
		Move const&			getMove() const;
		int					getValue() const;
		void				addSubnode(GameNode* node);
		void				removeSubnode(GameNode* node);
		Move				getBestMove(const Player player) const;
		NodeListIterator	getNodeListBegin();
		NodeListIterator	getNodeListEnd();
		
	private:
		Move				m_move;
		int					m_value;
		NodeList			m_subNodes;
	
		GameNode(GameNode const&);
	
	friend std::ostream& operator<<(std::ostream&, GameNode const&);
	};
	
	std::ostream& operator<< (std::ostream& lhs, GameNode const& rhs);
}