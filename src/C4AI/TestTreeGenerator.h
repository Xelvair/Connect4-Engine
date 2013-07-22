#pragma once

#include "ITreeGenerator.h"
#include "GameTree.h"
#include "EvaluatorV2.h"

namespace C4{
	class TestTreeGenerator final : public ITreeGenerator{
	public:
		virtual GameTree 	generate(Board board, int depth) const final override;
	
	private:
		EvaluatorV2		m_evaluator;
	
		void			generateRecursiveTree(GameNode*& node, Board& board, int depth) const;
	};
}