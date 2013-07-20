////////////////////////////
// CONSTRUCTOR/DESTRUCTOR //
////////////////////////////

template<class T, int TWidth, int THeight>
Array2<T, TWidth, THeight>::Array2()
	: m_data(new T[TWidth * THeight])
{}

template<class T, int TWidth, int THeight>
Array2<T, TWidth, THeight>::Array2(T const& val)
	: m_data(new T[TWidth * THeight])
{
	fill(val);
}

template<class T, int TWidth, int THeight>
Array2<T, TWidth, THeight>::Array2(Array2<T, TWidth, THeight> const& rhs)
	: m_data(new T[TWidth * THeight])
{
	for(int i = 0; i < TWidth * THeight; ++i){
		m_data[i] = rhs.m_data[i];
	}
}

template<class T, int TWidth, int THeight>
Array2<T, TWidth, THeight>::Array2(Array2<T, TWidth, THeight>&& rhs){
	m_data = rhs.m_data;
	rhs.m_data = nullptr;
}

template<class T, int TWidth, int THeight>
Array2<T, TWidth, THeight>::~Array2(){
	if(m_data){
		delete [] m_data;
		m_data = nullptr;
	}
}

////////////////////
// MEMBER METHODS //
////////////////////

template<class T, int TWidth, int THeight>
void Array2<T, TWidth, THeight>::fill(T const& val){
	for(int i = 0; i < TWidth * THeight; ++i){
		m_data[i] = val;
	}
}

template<class T, int TWidth, int THeight>
const Vec2s Array2<T, TWidth, THeight>::size() const{
	return Vec2s(TWidth, THeight);
}

///////////////
// OPERATORS //
///////////////

template<class T, int TWidth, int THeight>
Array2<T, TWidth, THeight>& Array2<T, TWidth, THeight>::operator=(Array2<T, TWidth, THeight> const& rhs){
	for(int i = 0; i < TWidth * THeight; ++i){
		m_data[i] = rhs.m_data[i];
	}
}

template<class T, int TWidth, int THeight>
Array2<T, TWidth, THeight>& Array2<T, TWidth, THeight>::operator=(Array2<T, TWidth, THeight> && rhs){
	delete [] m_data;
	m_data = rhs.m_data;
	rhs.m_data = nullptr;
}

template<class T, int TWidth, int THeight>
T& Array2<T, TWidth, THeight>::operator()(const int x, const int y){
	if(x < 0 || y < 0 || x >= TWidth || y >= THeight){
		throw std::out_of_range(__func__);
	}

	return m_data[y * TWidth + x];
}

template<class T, int TWidth, int THeight>
T const& Array2<T, TWidth, THeight>::operator()(const int x, const int y) const{
	if(x < 0 || y < 0 || x >= TWidth || y >= THeight){
		throw std::out_of_range(__func__);
	}

	return m_data[y * TWidth + x];
}

template<class T, int TWidth, int THeight>
T& Array2<T, TWidth, THeight>::operator()(Vec2s const& pos){
	return this->operator()(pos.x, pos.y);
}

template<class T, int TWidth, int THeight>
T const& Array2<T, TWidth, THeight>::operator()(Vec2s const& pos) const{
	return this->operator()(pos.x, pos.y);
}