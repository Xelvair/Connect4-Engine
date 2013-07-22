#pragma once

#include "IEvaluator.h"

namespace C4{
	class EvaluatorV2 final : public IEvaluator{
	public:
		virtual int evaluate(Board const& board) const override final;
	private:
		int valueOfStreak(int streak) const;
	};
}