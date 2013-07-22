#pragma once

#include <ostream>
#include <list>

namespace C4{
	template<class T>
	class Vec2 final{
	public:
		T x = 0;
		T y = 0;
	
		Vec2();
		Vec2(T x, T y);
		Vec2(Vec2<T> const&);
		~Vec2();
		
		template<class T2>
		explicit operator Vec2<T2>() const;
		
		Vec2<T>& operator=(Vec2<T> const& rhs);

		//Returns whether this vector is in between two others.
		//Think of it as an intersection check between a point and a rectangle
		bool	isInbetween(Vec2<T> const& first, Vec2<T> const& second) const;
	
		static std::list<Vec2<T> > allInbetween(Vec2<T> const& v1, Vec2<T> const& v2);
	};
	
	typedef Vec2<int> Vec2i;
	typedef Vec2<float> Vec2f;
	typedef Vec2<double> Vec2d;
	typedef Vec2<short> Vec2s;
	typedef Vec2<char> Vec2c;
	typedef Vec2<long> Vec2l;
}

//Vector-by-Vector operators
template<class T>
C4::Vec2<T> operator+(C4::Vec2<T> const& lhs, C4::Vec2<T> const& rhs);
template<class T>
C4::Vec2<T> operator-(C4::Vec2<T> const& lhs, C4::Vec2<T> const& rhs);
template<class T>
C4::Vec2<T> operator*(C4::Vec2<T> const& lhs, C4::Vec2<T> const& rhs);
template<class T>
C4::Vec2<T> operator/(C4::Vec2<T> const& lhs, C4::Vec2<T> const& rhs);

template<class T>
C4::Vec2<T>& operator+=(C4::Vec2<T>& lhs, C4::Vec2<T> const& rhs);
template<class T>
C4::Vec2<T>& operator-=(C4::Vec2<T>& lhs, C4::Vec2<T> const& rhs);
template<class T>
C4::Vec2<T>& operator*=(C4::Vec2<T>& lhs, C4::Vec2<T> const& rhs);
template<class T>
C4::Vec2<T>& operator/=(C4::Vec2<T>& lhs, C4::Vec2<T> const& rhs);

//Vector-by-Number operators
template<class T>
C4::Vec2<T> operator*(C4::Vec2<T> const& lhs, const T rhs);
template<class T>
C4::Vec2<T> operator/(C4::Vec2<T> const& lhs, const T rhs);

//std::ostream operators
template<class T>
std::ostream& operator<<(std::ostream& lhs, C4::Vec2<T> const& rhs);

#include "Vec2.inl"