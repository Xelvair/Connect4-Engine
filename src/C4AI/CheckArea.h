#pragma once

#include <forward_list>

#include <C4Utils/Rect.h>
#include <C4Utils/Vec2.h>
#include <C4Board/Board.h>

namespace C4{
	using CheckAreaList = std::forward_list<std::pair<std::pair<Vec2i, Vec2i>, Vec2i> >;

	template<int TWidth, int THeight>
	class CheckArea final{
	public:
		CheckArea() = delete;
		CheckArea(CheckArea const&) = delete;
	
		static const CheckAreaList list;
	private:
		static const CheckAreaList generate(){
			CheckAreaList list;
			
			//Vertical check area
			list.push_front(
				std::make_pair(
					std::make_pair(
						Vec2i(0, 0), 
						Vec2i(TWidth - Board::WINSTREAK, THeight - 1)
					),
					Vec2i(1, 0)
				)
			);
			
			//Horizontal check area
			list.push_front(
				std::make_pair(
					std::make_pair(
						Vec2i(0, 0), 
						Vec2i(TWidth - 1, THeight - Board::WINSTREAK)
					),
					Vec2i(0, 1)
				)
			);
										  
			//Diagonally descending check area
			list.push_front(
				std::make_pair(
					std::make_pair(
						Vec2i(0, 0), 
						Vec2i(TWidth - Board::WINSTREAK, THeight - Board::WINSTREAK)
					),
					Vec2i(1, 1)
				)
			);
										  
			//Diagonally ascending check area
			list.push_front(
				std::make_pair(
					std::make_pair(
						Vec2i(0, Board::WINSTREAK - 1), 
						Vec2i(TWidth - Board::WINSTREAK, THeight - 1)
					),
					Vec2i(1, -1)
				)
			);
										  
			return list;
		}
	};
	
}

template<int TWidth, int THeight>
const C4::CheckAreaList C4::CheckArea<TWidth, THeight>::list = C4::CheckArea<TWidth, THeight>::generate();