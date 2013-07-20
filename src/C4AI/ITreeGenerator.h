#pragma once

#include "GameNode.h"
#include "GameTree.h"

namespace C4{
	class ITreeGenerator{
	public:
		virtual GameTree	generate(Board board, int depth) const = 0;
	};
}