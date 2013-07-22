template<class T>
C4::Rect<T>::Rect(){}

template<class T>
C4::Rect<T>::Rect(T left, T top, T width, T height)
	: left(left)
	, top(top)
	, width(width)
	, height(height)
{}

template<class T>
C4::Rect<T>::Rect(C4::Rect<T> const& rhs)
	: left(rhs.left)
	, top(rhs.top)
	, width(rhs.width)
	, height(rhs.height)
{}

template<class T>
template<class T2>
bool C4::Rect<T>::contains(C4::Vec2<T2> const& vec){
	return vec.x >= left &&
		   vec.x <= left + width &&
		   vec.y >= top &&
		   vec.y <= top + height;
}

template<class TVal>
std::ostream& operator<<(std::ostream& lhs, C4::Rect<TVal> const& rhs){
	return lhs << "(" <<  rhs.left << "," << rhs.top << ":" << rhs.width << "," << rhs.height << ")";
}