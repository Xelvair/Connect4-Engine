#pragma once

#include <exception>
#include <stdexcept>

#include "Vec2.h"

namespace C4{
	template<class T, int TWidth, int THeight>
	class Array2 final{
	
	using type = Array2<T, TWidth, THeight>;
	
	public:
					Array2();
		explicit 	Array2(T const& val);
					Array2(type const& rhs);
					Array2(type&& rhs);
					~Array2();
				
		type&		operator=(type const& rhs);
		type&		operator=(type&& rhs);
		
		T&			operator()(const int x, const int y);
		T const&	operator()(const int x, const int y) const;
		T&			operator()(Vec2s const& pos);
		T const&	operator()(Vec2s const& pos) const;
		
		void		fill(T const& val);
		
		const Vec2s	size() const;
		
	private:
		T* 			m_data = nullptr;
	};
	
	#include "Array2.inl"
}