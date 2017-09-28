/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//vector_const_iterator
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _Myvec, class _IterTy>
vector_const_iterator<_Myvec, _IterTy>::vector_const_iterator(const typename _IterTy &iter) { _iter=new _IterTy(iter); }

template<class _Myvec, class _IterTy>
vector_const_iterator<_Myvec, _IterTy>::vector_const_iterator(const _Myiter &right) { _iter=new _IterTy(*(right._iter)); }

template<class _Myvec, class _IterTy>
vector_const_iterator<_Myvec, _IterTy>::vector_const_iterator(_Myiter &&right) { _iter=right._iter; right._iter=nullptr; }

//template<class _Myvec, class _IterTy>
//vector_const_iterator<_Myvec, _IterTy>::vector_const_iterator(typename _IterTy &&iter):_iter(iter) {}

template<class _Myvec, class _IterTy>
vector_const_iterator<_Myvec, _IterTy>::~vector_const_iterator(){ delete _iter; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter &vector_const_iterator<_Myvec, _IterTy>::operator=(const _Myiter &right) { if(_iter==nullptr) _iter=new _IterTy(*(right._iter)); else _iter->operator=(*(right._iter)); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter &vector_const_iterator<_Myvec, _IterTy>::operator=(_Myiter &&right) { if(_iter!=nullptr) delete _iter;  _iter=right._iter; right._iter=nullptr; return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::reference vector_const_iterator<_Myvec, _IterTy>::operator*() const { return _iter->operator*(); }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::pointer vector_const_iterator<_Myvec, _IterTy>::operator->() const { return _iter->operator->(); }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter &vector_const_iterator<_Myvec, _IterTy>::operator++() { _iter->operator++(); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter vector_const_iterator<_Myvec, _IterTy>::operator++(int) { _iter->operator++(); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter &vector_const_iterator<_Myvec, _IterTy>::operator--() { _iter->operator--(); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter vector_const_iterator<_Myvec, _IterTy>::operator--(int) { _iter->operator--(); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter &vector_const_iterator<_Myvec, _IterTy>::operator+=(difference_type offset) { _iter->operator+=(offset); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter vector_const_iterator<_Myvec, _IterTy>::operator+(difference_type offset) const { _iter->operator+(offset); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter &vector_const_iterator<_Myvec, _IterTy>::operator-=(difference_type offset) { _iter->operator-=(offset); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::_Myiter vector_const_iterator<_Myvec, _IterTy>::operator-(difference_type offset) const { _iter->operator-(offset); return *this; }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::difference_type vector_const_iterator<_Myvec, _IterTy>::operator-(const _Myiter &right) const { return _iter->operator-(*right._iter); }

template<class _Myvec, class _IterTy>
typename vector_const_iterator<_Myvec, _IterTy>::reference vector_const_iterator<_Myvec, _IterTy>::operator[](difference_type offset) const { return _iter->operator[](offset); }

template<class _Myvec, class _IterTy>
bool vector_const_iterator<_Myvec, _IterTy>::operator==(const _Myiter &right) const { return _iter->operator==(*right._iter); }

template<class _Myvec, class _IterTy>
bool vector_const_iterator<_Myvec, _IterTy>::operator!=(const _Myiter &right) const { return _iter->operator!=(*right._iter); }

template<class _Myvec, class _IterTy>
bool vector_const_iterator<_Myvec, _IterTy>::operator<(const _Myiter &right) const { return _iter->operator<(*right._iter); }

template<class _Myvec, class _IterTy>
bool vector_const_iterator<_Myvec, _IterTy>::operator>(const _Myiter &right) const { return _iter->operator>(*right._iter); }

template<class _Myvec, class _IterTy>
bool vector_const_iterator<_Myvec, _IterTy>::operator<=(const _Myiter &right) const { return _iter->operator<=(*right._iter); }

template<class _Myvec, class _IterTy>
bool vector_const_iterator<_Myvec, _IterTy>::operator>=(const _Myiter &right) const { return _iter->operator>=(*right._iter); }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//vector_iterator
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _Myvec, class _IterTy>
vector_iterator<_Myvec, _IterTy>::vector_iterator(const typename _IterTy &iter):vector_const_iterator(iter) {}

template<class _Myvec, class _IterTy>
vector_iterator<_Myvec, _IterTy>::vector_iterator(const _Myiter &right):vector_const_iterator(right) {}

template<class _Myvec, class _IterTy>
vector_iterator<_Myvec, _IterTy>::vector_iterator(_Myiter &&right):vector_const_iterator(right) {}

//template<class _Myvec, class _IterTy>
//vector_iterator<_Myvec, _IterTy>::vector_iterator(typename _IterTy &&iter):vector_const_iterator(iter) {}

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter &vector_iterator<_Myvec, _IterTy>::operator=(const _Myiter &right) { if(_iter==nullptr) _iter=new _IterTy(*(right._iter)); else _iter->operator=(*(right._iter)); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter &vector_iterator<_Myvec, _IterTy>::operator=(_Myiter &&right) { if(_iter!=nullptr) delete _iter;  _iter=right._iter; right._iter=nullptr; return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::reference vector_iterator<_Myvec, _IterTy>::operator*() const { return _iter->operator*(); }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::pointer vector_iterator<_Myvec, _IterTy>::operator->() const { return _iter->operator->(); }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter &vector_iterator<_Myvec, _IterTy>::operator++() { _iter->operator++(); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter vector_iterator<_Myvec, _IterTy>::operator++(int) { _iter->operator++(); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter &vector_iterator<_Myvec, _IterTy>::operator--() { _iter->operator--(); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter vector_iterator<_Myvec, _IterTy>::operator--(int) { _iter->operator--(); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter &vector_iterator<_Myvec, _IterTy>::operator+=(difference_type offset) { _iter->operator+=(offset); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter vector_iterator<_Myvec, _IterTy>::operator+(difference_type offset) const { _iter->operator+(offset); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter &vector_iterator<_Myvec, _IterTy>::operator-=(difference_type offset) { _iter->operator-=(offset); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::_Myiter vector_iterator<_Myvec, _IterTy>::operator-(difference_type offset) const { _iter->operator-(offset); return *this; }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::difference_type vector_iterator<_Myvec, _IterTy>::operator-(const _Mybase &right) const { return _iter->operator-(*right._iter); }

template<class _Myvec, class _IterTy>
typename vector_iterator<_Myvec, _IterTy>::reference vector_iterator<_Myvec, _IterTy>::operator[](difference_type offset) const { return _iter->operator[](offset); }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//vector
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector() noexcept { _vector=new std::vector<_Ty, _Alloc>(); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(const _Alloc &alloc) noexcept { _vector=new std::vector<_Ty, _Alloc>(alloc); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(size_type count) { _vector=new std::vector<_Ty, _Alloc>(count); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(size_type count, const value_type &value) { _vector=new std::vector<_Ty, _Alloc>(count, value); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(size_type count, const value_type& value, const _Alloc &alloc) { _vector=new std::vector<_Ty, _Alloc>(count, value, alloc); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(const _Myt &right) { _vector=new std::vector<_Ty, _Alloc>(*(right._vector)); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(const _Myt &right, const _Alloc &alloc) { _vector=new std::vector<_Ty, _Alloc>(*(right._vector), alloc); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(_Myt &&right) noexcept { _vector=right._vector; right._vector=new std::vector<_Ty, _Alloc>();  }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(_Myt &&right, const _Alloc &alloc) { _vector=right._vector; right._vector=new std::vector<_Ty, _Alloc>(alloc); }

#ifdef STD_WRAPPER_EXPORT
template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(const _StdTy &right) { _vector=new std::vector<_Ty, _Alloc>(right); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(const _StdTy &right, const _Alloc &alloc) { _vector=new std::vector<_Ty, _Alloc>(right, alloc); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(_StdTy &&right) noexcept { _vector=new std::vector<_Ty, _Alloc>(right); }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::vector(_StdTy &&right, const _Alloc &alloc) { _vector=new std::vector<_Ty, _Alloc>(right, alloc); }
#endif//STD_WRAPPER_EXPORT

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc>::~vector() { delete _vector; }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc> &vector<_Ty, _Alloc>::operator=(const _Myt &other) { _vector->operator=(*(other._vector)); return *this;}

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc> &vector<_Ty, _Alloc>::operator=(_Myt &&other) { delete _vector; _vector=other._vector; other._vector=new std::vector<_Ty, _Alloc>(); return *this; }

#ifdef STD_WRAPPER_EXPORT
template<class _Ty, class _Alloc>
vector<_Ty, _Alloc> &vector<_Ty, _Alloc>::operator=(const _StdTy &other) { _vector->operator=(other); return *this; }

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc> &vector<_Ty, _Alloc>::operator=(_StdTy &&other) { _vector->operator=(other); return *this; }
#endif//STD_WRAPPER_EXPORT

template<class _Ty, class _Alloc>
vector<_Ty, _Alloc> &vector<_Ty, _Alloc>::operator=(std::initializer_list<_Ty> ilist) { _vector->operator=(ilist); return *this; }

template<class _Ty, class _Alloc>
void vector<_Ty, _Alloc>::assign(size_type count, const _Ty &value) { _vector->assign(count, value); }

template<class _Ty, class _Alloc>
void vector<_Ty, _Alloc>::assign(std::initializer_list<_Ty> ilist) { _vector->assign(ilist); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::reference vector<_Ty, _Alloc>::at(size_type pos) { return _vector->at(pos); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_reference vector<_Ty, _Alloc>::at(size_type pos) const { return _vector->at(pos); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::reference vector<_Ty, _Alloc>::operator[](size_type pos) { return _vector->operator[](pos); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_reference vector<_Ty, _Alloc>::operator[](size_type pos) const { return _vector->operator[](pos); };

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::reference vector<_Ty, _Alloc>::front() { return _vector->front(); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_reference vector<_Ty, _Alloc>::front() const { return _vector->front(); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::reference vector<_Ty, _Alloc>::back() { return _vector->back(); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_reference vector<_Ty, _Alloc>::back() const { return _vector->back(); }

template<class _Ty, class _Alloc>
_Ty *vector<_Ty, _Alloc>::data() noexcept { return _vector->data(); }

template<class _Ty, class _Alloc>
const _Ty *vector<_Ty, _Alloc>::data() const noexcept { return _vector->data(); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::begin() noexcept { return iterator(_vector->begin()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_iterator vector<_Ty, _Alloc>::begin() const noexcept { return const_iterator(_vector->cbegin()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_iterator vector<_Ty, _Alloc>::cbegin() const noexcept { return const_iterator(_vector->cbegin()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::end() noexcept { return iterator(_vector->end()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_iterator vector<_Ty, _Alloc>::end() const noexcept { return const_iterator(_vector->cend()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_iterator vector<_Ty, _Alloc>::cend() const noexcept { return const_iterator(_vector->cend()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::reverse_iterator vector<_Ty, _Alloc>::rbegin() noexcept { return reverse_iterator(_vector->rbegin()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_reverse_iterator vector<_Ty, _Alloc>::rbegin() const { return const_reverse_iterator(_vector->crbegin()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_reverse_iterator vector<_Ty, _Alloc>::crbegin() const noexcept { return const_reverse_iterator(_vector->crbegin()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::reverse_iterator vector<_Ty, _Alloc>::rend() noexcept { return reverse_iterator(_vector->rend()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_reverse_iterator vector<_Ty, _Alloc>::rend() const noexcept { return const_reverse_iterator(_vector->crend()); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::const_reverse_iterator vector<_Ty, _Alloc>::crend() const noexcept { return const_reverse_iterator(_vector->crend()); }

template<class _Ty, class _Alloc>
bool vector<_Ty, _Alloc>::empty() const noexcept { return _vector->empty(); }

template<class _Ty, class _Alloc>
typename vector<_Ty, _Alloc>::size_type vector<_Ty, _Alloc>::size() const noexcept { return _vector->size(); }

template<class _Ty, class _Alloc>
void vector<_Ty, _Alloc>::reserve(size_type new_cap) { _vector->reserve(new_cap); }

template<class _Ty, class _Alloc>
void vector<_Ty, _Alloc>::clear() noexcept { _vector->clear(); }

template<class _Ty, class _Alloc>
void vector<_Ty, _Alloc>::push_back(const _Ty &value) { _vector->push_back(value); }

template<class _Ty, class _Alloc>
void vector<_Ty, _Alloc>::push_back(_Ty &&value) { _vector->push_back(value); }

template<class _Ty, class _Alloc>
void vector<_Ty, _Alloc>::resize(size_type count) { _vector->resize(count); }

template<class _Ty, class _Alloc>
void vector<_Ty, _Alloc>::resize(size_type count, const value_type& value) { _vector->resize(count, value); }
