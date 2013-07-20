#pragma once

#include "ITreeGenerator.h"
#include "GameTree.h"
#include "TestEvaluator.h"

namespace C4{
	class TestTreeGenerator final : public ITreeGenerator{
	public:
		virtual GameTree 	generate(Board board, int depth) const final override;
	
	private:
		TestEvaluator	m_evaluator;
	
		void			generateRecursiveTree(GameNode*& node, Board& board, int depth) const;
	};
}