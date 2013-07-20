#pragma once

#include <exception>

#inlude "Move.h"

namespace C4{
	class MoveException final : public std::runtime_error{	
	public:	
		explicit MoveException(std::string const& msg)
			: std::runtime_error(msg)
		{}
	};
}