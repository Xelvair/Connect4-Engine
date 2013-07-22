#pragma once

#include <forward_list>

namespace C4{
	typedef std::forward_list<std::pair<Vec2s, Vec2s> > CheckPathList;
	
	template<int TWidth, int THeight>	
	class CheckPath final{	
	public:
		CheckPath() = delete;
		CheckPath(CheckPath const&) = delete;
	
		static const CheckPathList list;
	private:	
		static const CheckPathList generate(){
			CheckPathList 	cpl; //List of all positions + directions to be checked
			Vec2s 			step;//Determines in which way we go
			
			//Vertical check paths
			step = Vec2s(1, 0);
			
			for(int i = 0; i < THeight; ++i){
				cpl.push_front(std::make_pair(Vec2s(0, i), step));
			}
			
			//Horizontal check paths
			step = Vec2s(0, 1);
			
			for(int i = 0; i < TWidth; ++i){
				cpl.push_front(std::make_pair(Vec2s(i, 0), step));
			}
			
			//Diagonal descending paths
			step = Vec2s(1, 1);
			
			for(int i = 0; i < TWidth + THeight - 1; ++i){
				if(i < THeight){ //If we're going up
					cpl.push_front(std::make_pair(Vec2s(0, (THeight - 1) - i), step));
				} else {         //..or to the right
					cpl.push_front(std::make_pair(Vec2s(i - (THeight - 1), 0), step));
				}
			}
			
			//Diagonal ascending paths
			step = Vec2s(1, -1);
			
			for(int i = 0; i < TWidth + THeight - 1; ++i){
				if(i < THeight){ //If we're going down
					cpl.push_front(std::make_pair(Vec2s(0, i), step));
				} else {         //..or to the right
					cpl.push_front(std::make_pair(Vec2s(i - (THeight - 1), THeight - 1), step));
				}
			}
			
			//FYI, the list is later accessed in reverse order, that is due to me being a memory whore
			//and using std::forward_list instead of a conventional std::list ;)
			
			//And reurn the list!
			return cpl;
		}
	};
}

template<int TWidth, int THeight>
const C4::CheckPathList C4::CheckPath<TWidth, THeight>::list = C4::CheckPath<TWidth, THeight>::generate();