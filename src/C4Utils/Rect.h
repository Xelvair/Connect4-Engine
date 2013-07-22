#pragma once

#include <ostream>

#include "Vec2.h"

namespace C4{
	template<class T>
	class Rect final{
	public:
		T left		= 0;
		T top		= 0;
		T width		= 0;
		T height 	= 0;
	
		Rect();
		Rect(T left, T top, T width, T height);
		Rect(Rect<T> const& rhs);
		
		template<class T2>
		bool	contains(Vec2<T2> const& vec);
		
	template<class TVal>
	friend std::ostream& operator<<(std::ostream&, Rect<T> const&);
	};

	using Recti = Rect<int>;
	using Rectf = Rect<float>;
	using Rectd = Rect<double>;
	using Rectl = Rect<long>;
	using Rectc = Rect<char>;
	
	template<class TVal>
	std::ostream& operator << (std::ostream& lhs, Rect<TVal> const& rhs);
}

#include "Rect.inl"