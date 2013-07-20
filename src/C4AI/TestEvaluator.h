#pragma once

#include <C4Board/Board.h>
#include <C4Board/Player.h>

#include "IEvaluator.h"

namespace C4{
	class TestEvaluator final : public IEvaluator{
	public:
		virtual int evaluate(Board const& board) const override final;
	private:
		static int valueOfStreak(int streak);
	};
};