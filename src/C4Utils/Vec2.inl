#include <iostream>
#include <cmath>

////////////////////
// MEMBER METHODS //
////////////////////

template<class T>
C4::Vec2<T>::Vec2(){}

template<class T>
C4::Vec2<T>::Vec2(T x, T y)
	: x(x)
	, y(y)
{}

template<class T>
C4::Vec2<T>::Vec2(Vec2<T> const& rhs)
	: x(rhs.x)
	, y(rhs.y)
{}

template<class T>
C4::Vec2<T>::~Vec2(){}

template<class T>
template<class T2>
C4::Vec2<T>::operator C4::Vec2<T2>() const{
	return Vec2<T2>(static_cast<T2>(this->x),
					static_cast<T2>(this->y));
}

template<class T>
C4::Vec2<T>& C4::Vec2<T>::operator=(C4::Vec2<T> const& rhs){
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

template<class T>
bool C4::Vec2<T>::isInbetween(C4::Vec2<T> const& first, C4::Vec2<T> const& second) const{
	return(this->x >= std::min(first.x, second.x) &&
		   this->x <= std::max(first.x, second.x) &&
		   this->y >= std::min(first.y, second.y) &&
		   this->y <= std::max(first.y, second.y));
}

///////////////////////////
// STATIC MEMBER METHODS //
///////////////////////////

template<class T>
std::list<C4::Vec2<T> > C4::Vec2<T>::allInbetween(C4::Vec2<T> const& v1, C4::Vec2<T> const& v2){
	static_assert(std::is_integral<T>::value, "Vec2<T>::allInbetween() must only be used with integral types");
	std::list<C4::Vec2<T> > list;
	for(int y = std::min(v1.y, v2.y); y <= std::max(v1.y, v2.y); ++y){
		for(int x = std::min(v1.x, v1.x); x <= std::max(v1.x, v2.x); ++x){
			list.push_back(C4::Vec2<T>(x, y));
		}
	}
	return list;
}

//////////////////////
// GLOBAL OPERATORS //
//////////////////////

//Vector-by-Vector operators
template<class T>
C4::Vec2<T> operator+(C4::Vec2<T> const& lhs, C4::Vec2<T> const& rhs){
	return C4::Vec2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template<class T>
C4::Vec2<T> operator-(C4::Vec2<T> const& lhs, C4::Vec2<T> const& rhs){
	return C4::Vec2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<class T>
C4::Vec2<T> operator*(C4::Vec2<T> const& lhs, C4::Vec2<T> const& rhs){
	return C4::Vec2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
}

template<class T>
C4::Vec2<T> operator/(C4::Vec2<T> const& lhs, C4::Vec2<T> const& rhs){
	return C4::Vec2<T>(lhs.x / rhs.x, lhs.y / rhs.y);
}

template<class T>
C4::Vec2<T>& operator+=(C4::Vec2<T>& lhs, C4::Vec2<T> const& rhs){
	lhs = lhs + rhs;
	return lhs;
}

template<class T>
C4::Vec2<T>& operator-=(C4::Vec2<T>& lhs, C4::Vec2<T> const& rhs){
	lhs = lhs - rhs;
	return lhs;
}

template<class T>
C4::Vec2<T>& operator*=(C4::Vec2<T>& lhs, C4::Vec2<T> const& rhs){
	lhs = lhs * rhs;
	return lhs;
}

template<class T>
C4::Vec2<T>& operator/=(C4::Vec2<T>& lhs, C4::Vec2<T> const& rhs){
	lhs = lhs / rhs;
	return lhs;
}

//Vector-by-Number operators
template<class T>
C4::Vec2<T> operator*(C4::Vec2<T> const& lhs, const T rhs){
	return C4::Vec2<T>(lhs.x * rhs, lhs.y * rhs);
}

template<class T>
C4::Vec2<T> operator/(C4::Vec2<T> const& lhs, const T rhs){
	return C4::Vec2<T>(lhs.x / rhs, lhs.y / rhs);
}

//std::ostream operators
template<class T>
std::ostream& operator<<(std::ostream& lhs, C4::Vec2<T> const& rhs){
	return lhs << "(" << rhs.x << "," << rhs.y << ")";
}