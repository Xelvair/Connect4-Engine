#pragma once

#include <C4Utils/Array2.h>
#include <C4Board/Board.h>

namespace C4{
	class IEvaluator{
	public:
		virtual ~IEvaluator(){}
		virtual int evaluate(Board const& board) const = 0;
	};
}