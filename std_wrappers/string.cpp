
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//basic_string_const_iterator
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _MyStr, class _IterTy, class _ConstIterTy>
basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::basic_string_const_iterator(const typename _ConstIterTy &iter) { _constIter=new _ConstIterTy(iter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::basic_string_const_iterator(const _Myiter &right) { _constIter=new _ConstIterTy(*(right._constIter)); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::basic_string_const_iterator(_Myiter &&right) { _constIter=right._constIter; right._constIter=nullptr; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::basic_string_const_iterator(const _Iter &right) { _constIter=new _ConstIterTy(*(right._iter)); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::~basic_string_const_iterator() { delete _constIter; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator=(const _Myiter &right) { if(_constIter==nullptr) _constIter=new _ConstIterTy(*(right._constIter)); else _constIter->operator=(*(right._constIter)); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator=(_Myiter &&right) { if(_constIter!=nullptr) delete _constIter;  _constIter=right._constIter; right._constIter=nullptr; return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator=(const _Iter &right) { if(_constIter==nullptr) _constIter=new _ConstIterTy(*(right._iter)); else _constIter->operator=(*(right._iter)); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::reference basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator*() const { return _constIter->operator*(); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::pointer basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator->() const { return _constIter->operator->(); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator++() { _constIter->operator++(); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator++(int) { _constIter->operator++(); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator--() { _constIter->operator--(); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator--(int) { _constIter->operator--(); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator+=(difference_type offset) { _constIter->operator+=(offset); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator+(difference_type offset) const { _constIter->operator+(offset); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator-=(difference_type offset) { _constIter->operator-=(offset); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator-(difference_type offset) const { _constIter->operator-(offset); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy> //reverse iterator does not have operator-(const reverse_iterator &right) so this is allowing the compiler to search for nonmembers as well
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::difference_type basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator-(const _Myiter &right) const { return (*_constIter)-(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::reference basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator[](difference_type offset) const { return _constIter->operator[](offset); }

//reverse iterator does not have any bool operator member functions, this is allowing the compiler to search for nonmembers as well
template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator==(const _Myiter &right) const { return (*_constIter)==(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator!=(const _Myiter &right) const { return (*_constIter)!=(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator<(const _Myiter &right) const { return (*_constIter)<(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator>(const _Myiter &right) const { return (*_constIter)>(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator<=(const _Myiter &right) const { return (*_constIter)<=(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>::operator>=(const _Myiter &right) const { return (*_constIter)>=(*right._constIter); }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//basic_string_iterator
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _MyStr, class _IterTy, class _ConstIterTy>
basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::basic_string_iterator(const typename _IterTy &iter) { _iter=new _IterTy(iter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::basic_string_iterator(const _Myiter &right) { _iter=new _IterTy(*(right._iter)); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::basic_string_iterator(_Myiter &&right) { _iter=right._iter; right._iter=nullptr; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator=(const _Myiter &right) { if(_iter==nullptr) _iter=new _IterTy(*(right._iter)); else _iter->operator=(*(right._iter)); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator=(_Myiter &&right) { if(_iter!=nullptr) delete _iter;  _iter=right._iter; right._iter=nullptr; return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::reference basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator*() const { return _iter->operator*(); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::pointer basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator->() const { return _iter->operator->(); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator++() { _iter->operator++(); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator++(int) { _iter->operator++(); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator--() { _iter->operator--(); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator--(int) { _iter->operator--(); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator+=(difference_type offset) { _iter->operator+=(offset); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator+(difference_type offset) const { _iter->operator+(offset); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter &basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator-=(difference_type offset) { _iter->operator-=(offset); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::_Myiter basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator-(difference_type offset) const { _iter->operator-(offset); return *this; }

template<class _MyStr, class _IterTy, class _ConstIterTy> //reverse iterator does not have operator-(const reverse_iterator &right) so this is allowing the compiler to search for nonmembers as well
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::difference_type basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator-(const _ConstIter &right) const { return (*_iter)-(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
typename basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::reference basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator[](difference_type offset) const { return _iter->operator[](offset); }

//reverse iterator does not have any bool operator member functions, this is allowing the compiler to search for nonmembers as well
template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator==(const _Myiter &right) const { return (*_iter)==(*right._iter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator!=(const _Myiter &right) const { return (*_iter)!=(*right._iter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator<(const _Myiter &right) const { return (*_iter)<(*right._iter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator>(const _Myiter &right) const { return (*_iter)>(*right._iter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator<=(const _Myiter &right) const { return (*_iter)<=(*right._iter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator>=(const _Myiter &right) const { return (*_iter)>=(*right._iter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator==(const _ConstIter &right) const { return (*_iter)==(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator!=(const _ConstIter &right) const { return (*_iter)!=(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator<(const _ConstIter &right) const { return (*_iter)<(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator>(const _ConstIter &right) const { return (*_iter)>(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator<=(const _ConstIter &right) const { return (*_iter)<=(*right._constIter); }

template<class _MyStr, class _IterTy, class _ConstIterTy>
bool basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>::operator>=(const _ConstIter &right) const { return (*_iter)>=(*right._constIter); }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//basic_string
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _Elem, class _Traits, class _Alloc>
const typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::npos=std::basic_string<_Elem, _Traits, _Alloc>::npos;

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Myt &right) { _string=new std::string(*right._string); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Myt &right, const _Alloc &alloc) { _string=new std::string(*right._string, alloc); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Mybase &right) { _string=new std::string(right); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string() noexcept{ _string=new std::string(); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Alloc &alloc) noexcept { _string=new std::string(alloc); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Myt &right, size_type roffset, size_type count) { _string=new std::string(*right._string, roffset, count); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Myt &right, size_type roffset, size_type count, const _Alloc &alloc) { _string=new std::string(*right._string, roffset, count, alloc); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Mybase &right, size_type roffset, size_type count) { _string=new std::string(right, roffset, count); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Elem *ptr, size_type count) { _string=new std::string(ptr, count); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Elem *ptr, size_type count, const _Alloc &alloc) { _string=new std::string(ptr, count, alloc); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Elem *ptr) { _string=new std::string(ptr); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(const _Elem *ptr, const _Alloc &alloc) { _string=new std::string(ptr, alloc); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(size_type count, _Elem ch) { _string=new std::string(count, ch); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(size_type count, _Elem ch, const _Alloc &alloc) { _string=new std::string(count, ch, alloc); }

template<class _Elem, class _Traits, class _Alloc>
template<class _Iter>
basic_string<_Elem, _Traits, _Alloc>::basic_string(_Iter first, _Iter last, const _Alloc &alloc) { _string=new std::string(first, last, alloc); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(_Myt &&right) noexcept { _string=new std::string(*right._string); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(_Myt &&right, const _Alloc &alloc) { _string=new std::string(*right._string, alloc); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator=(_Myt &&right) noexcept{ _string->operator=(*right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(_Myt &&right) noexcept { _string->assign(*right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(_Mybase &&right) noexcept { _string=new std::string(right); }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(_Mybase &&right, const _Alloc &alloc) { _string=new std::string(right, alloc); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator=(_Mybase &&right) noexcept { _string->operator=(right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(_Mybase &&right) noexcept { _string->assign(right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::basic_string(std::initializer_list<_Elem> ilist, const _Alloc &alloc){ _string=new std::string(ilist, alloc); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator=(std::initializer_list<_Elem> ilist) { _string->operator=(ilist); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator+=(std::initializer_list<_Elem> ilist){ _string->operator+=(ilist); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(std::initializer_list<_Elem> ilist) { _string->assign(ilist); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(std::initializer_list<_Elem> ilist) { _string->append(ilist); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::insert(const_iterator where, std::initializer_list<_Elem> ilist) { return iterator(_string->insert(*where._constIter, ilist)); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, std::initializer_list<_Elem> ilist) { _string->replace(*first._constIter, *last._constIter, ilist); return *this; }

template<class _Elem, class _Traits, class _Alloc>
basic_string<_Elem, _Traits, _Alloc>::~basic_string() noexcept { delete _string; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::basic_string<_Elem, _Traits, _Alloc>::operator=(const _Myt &right) { _string->operator=(*right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::basic_string<_Elem, _Traits, _Alloc>::operator=(const _Mybase &right) { _string->operator=(right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator=(const _Elem *ptr) { _string->operator=(ptr); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator=(_Elem ch) { _string->operator=(ch); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator+=(const _Myt &right) { _string->operator+=(*right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator+=(const _Mybase &right) { _string->operator+=(right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator+=(const _Elem *ptr) { _string->operator+=(ptr); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::operator+=(_Elem ch) { _string->operator+=(ch); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(const _Myt &right) { _string->append(*right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(const _Myt &right, size_type roffset, size_type count){ _string->append(*right._string, roffset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(const _Mybase &right) { _string->append(right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(const _Mybase &right, size_type roffset, size_type count) { _string->append(right, roffset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(const _Elem *ptr, size_type count) { _string->append(ptr, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(const _Elem *ptr) { _string->append(ptr); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(size_type count, _Elem ch) { _string->append(count, ch); return *this; }

template<class _Elem, class _Traits, class _Alloc>
template<class _Iter>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(_Iter first, _Iter last) { _string->append(first, last); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(const_pointer first, const_pointer last) { _string->append(first, last); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::append(const_iterator first, const_iterator last) { _string->append(first, last); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(const _Myt &right) { _string->assign(*right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(const _Myt &right, size_type roffset, size_type count) { _string->assign(*right._string, roffset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(const _Mybase &right) { _string->assign(right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(const _Mybase &right, size_type roffset, size_type count) { _string->assign(right, roffset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(const _Elem *ptr, size_type count) { _string->assign(ptr, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(const _Elem *ptr) { _string->assign(ptr); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(size_type count, _Elem ch) { _string->assign(count, ch); return *this; }

template<class _Elem, class _Traits, class _Alloc>
template<class _Iter>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(_Iter first, _Iter last) { _string->assign(first, last); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(const_pointer first, const_pointer last) { _string->assign(first, last); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::assign(const_iterator first, const_iterator last) { _string->assign(first, last); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::insert(size_type offset, const _Myt &right) { _string->insert(offset, *right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::insert(size_type offset, const _Myt &right, size_type roffset, size_type count) { _string->insert(offset, *right._string, roffset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::insert(size_type offset, const _Mybase &right) { _string->insert(offset, right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::insert(size_type offset, const _Mybase &right, size_type roffset, size_type count) { _string->insert(offset, right, roffset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::insert(size_type offset, const _Elem *ptr, size_type count) { _string->insert(offset, ptr, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::insert(size_type offset, const _Elem *ptr) { _string->insert(offset, ptr); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::insert(size_type offset, size_type count, _Elem ch) { _string->insert(offset, count, ch); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::insert(const_iterator where) { return iterator(_string->insert(*where._constIter)); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::insert(const_iterator where, _Elem ch) { return iterator(_string->insert(*where._constIter, ch)); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::insert(const_iterator where, size_type count, _Elem ch) { return iterator(_string->insert(*where._constIter, count, ch)); }

template<class _Elem, class _Traits, class _Alloc>
template<class _Iter>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::insert(const_iterator where, _Iter first, _Iter last) { return iterator(_string->insert(*where._constIter, *first._constIter, *last._constIter)); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::insert(const_iterator where, const_pointer first, const_pointer last) { return iterator(_string->insert(*where._constIter, first, last)); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::insert(const_iterator where, const_iterator first, const_iterator last) { return iterator(_string->insert(*where._constIter, *first._constIter, *last._constIter)); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::erase(size_type offset) { _string->erase(offset); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::erase(size_type offset, size_type count) { _string->erase(offset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::erase(const_iterator where) { return iterator(_string->erase(*where._constIter)); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::erase(const_iterator first, const_iterator last) { return iterator(_string->erase(*first._constIter, *last._constIter));}

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::clear() noexcept { _string->clear(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(size_type offset, size_type n0, const _Myt &right) { _string->replace(offset, n0, *right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(size_type offset, size_type n0, const _Myt &right, size_type roffset, size_type count) { _string->replace(offset, n0, *right._string, roffset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(size_type offset, size_type n0, const _Mybase &right) { _string->replace(offset, n0, right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(size_type offset, size_type n0, const _Mybase &right, size_type roffset, size_type count) { _string->replace(offset, n0, right, roffset, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(size_type offset, size_type n0, const _Elem *ptr, size_type count) { _string->replace(offset, n0, ptr, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(size_type offset, size_type n0, const _Elem *ptr) { _string->replace(offset, n0, ptr); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(size_type offset, size_type n0, size_type count, _Elem ch) { _string->replace(offset, n0, count, ch); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, const _Myt &right) { _string->replace(*first._constIter, *last._constIter, *right._string); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, const _Mybase &right) { _string->replace(*first._constIter, *last._constIter, right); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, const _Elem *ptr, size_type count) { _string->replace(*first._constIter, *last._constIter, ptr, count); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, const _Elem *ptr) { _string->replace(*first._constIter, *last._constIter, ptr); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, size_type count, _Elem ch) { _string->replace(*first._constIter, *last._constIter, count, ch); return *this; }

template<class _Elem, class _Traits, class _Alloc>
template<class _Iter>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, _Iter first2, _Iter last2) { _string->replace(*first._constIter, *last._constIter, first2, last2); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, const_pointer first2, const_pointer last2){ _string->replace(*first._constIter, *last._constIter, first2, last2); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, pointer first2, pointer last2) { _string->replace(*first._constIter, *last._constIter, first2, last2); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, const_iterator first2, const_iterator last2) { _string->replace(*first._constIter, *last._constIter, *first2._constIter, *last2._constIter); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt &basic_string<_Elem, _Traits, _Alloc>::replace(const_iterator first, const_iterator last, iterator first2, iterator last2) { _string->replace(*first._constIter, *last._constIter, *first2._iter, *last2._iter); return *this; }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::begin() noexcept { return iterator(_string->begin()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_iterator basic_string<_Elem, _Traits, _Alloc>::begin() const noexcept { return const_iterator(_string->cbegin()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::iterator basic_string<_Elem, _Traits, _Alloc>::end() noexcept { return iterator(_string->end()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_iterator basic_string<_Elem, _Traits, _Alloc>::end() const noexcept { return const_iterator(_string->cend()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::reverse_iterator basic_string<_Elem, _Traits, _Alloc>::rbegin() noexcept { return reverse_iterator(_string->rbegin()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_reverse_iterator basic_string<_Elem, _Traits, _Alloc>::rbegin() const noexcept { return const_reverse_iterator(_string->crbegin()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::reverse_iterator basic_string<_Elem, _Traits, _Alloc>::rend() noexcept { return reverse_iterator(_string->rend()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_reverse_iterator basic_string<_Elem, _Traits, _Alloc>::rend() const noexcept { return const_reverse_iterator(_string->crend()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_iterator basic_string<_Elem, _Traits, _Alloc>::cbegin() const noexcept { return const_iterator(_string->cbegin()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_iterator basic_string<_Elem, _Traits, _Alloc>::cend() const noexcept { return const_iterator(_string->cend()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_reverse_iterator basic_string<_Elem, _Traits, _Alloc>::crbegin() const noexcept { return const_reverse_iterator(_string->crbegin()); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_reverse_iterator basic_string<_Elem, _Traits, _Alloc>::crend() const noexcept { return const_reverse_iterator(_string->crend()); }

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::shrink_to_fit() { _string->shrink_to_fit(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::reference basic_string<_Elem, _Traits, _Alloc>::at(size_type offset) { return _string->at(offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_reference basic_string<_Elem, _Traits, _Alloc>::at(size_type offset) const { return _string->at(offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::reference basic_string<_Elem, _Traits, _Alloc>::operator[](size_type offset) { return _string->operator[](offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_reference basic_string<_Elem, _Traits, _Alloc>::operator[](size_type offset) const { return _string->operator[](offset); }

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::push_back(_Elem ch) { _string->push_back(ch); }

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::pop_back() { _string->pop_back(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::reference basic_string<_Elem, _Traits, _Alloc>::front() { return _string->front(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_reference basic_string<_Elem, _Traits, _Alloc>::front() const { return _string->front(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::reference basic_string<_Elem, _Traits, _Alloc>::back() { return _string->back(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::const_reference basic_string<_Elem, _Traits, _Alloc>::back() const { return _string->back(); }

template<class _Elem, class _Traits, class _Alloc>
const _Elem *basic_string<_Elem, _Traits, _Alloc>::c_str() const noexcept { return _string->c_str(); }

template<class _Elem, class _Traits, class _Alloc>
const _Elem *basic_string<_Elem, _Traits, _Alloc>::data() const noexcept { return _string->data(); }

#if _HAS_CXX17
template<class _Elem, class _Traits, class _Alloc>
_Elem *basic_string<_Elem, _Traits, _Alloc>::data() noexcept { return _string->data(); }
#endif /* _HAS_CXX17 */

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::length() const noexcept { return _string->length(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::size() const noexcept { return _string->size(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::max_size() const noexcept { return _string->max_size(); }

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::resize(size_type newsize) { _string->resize(newsize); }

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::resize(size_type newsize, _Elem ch) { _string->resize(newsize, ch); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::capacity() const noexcept { return _string->capacity(); }

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::reserve(size_type newcap) { _string->resize(newcap); }

template<class _Elem, class _Traits, class _Alloc>
bool basic_string<_Elem, _Traits, _Alloc>::empty() const noexcept { return _string->empty(); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::copy(_Elem *ptr, size_type count, size_type offset) const { return _string->copy(ptr, count, offset); }

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::swap(_Myt &right) noexcept { _string->swap(*right._string); }

template<class _Elem, class _Traits, class _Alloc>
void basic_string<_Elem, _Traits, _Alloc>::swap(_Mybase &right) noexcept { _string->swap(right); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find(const _Myt &right, size_type offset) const noexcept { return _string->find(*right._string, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find(const _Mybase &right, size_type offset) const noexcept { return _string->find(right, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find(const _Elem *ptr, size_type offset, size_type count) const { return _string->find(ptr, offset, count); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find(const _Elem *ptr, size_type offset) const { return _string->find(ptr, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find(_Elem ch, size_type offset) const{ return _string->find(ch, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::rfind(const _Myt &right, size_type offset) const noexcept { return _string->rfind(*right._string, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::rfind(const _Mybase &right, size_type offset) const noexcept { return _string->rfind(right, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::rfind(const _Elem *ptr, size_type offset, size_type count) const { return _string->rfind(ptr, offset, count); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::rfind(const _Elem *ptr, size_type offset) const{ return _string->rfind(ptr, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::rfind(_Elem ch, size_type offset) const { return _string->rfind(ch, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_of(const _Myt &right, size_type offset) const noexcept { return _string->find_first_of(*right._string, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_of(const _Mybase &right, size_type offset) const noexcept { return _string->find_first_of(right, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_of(const _Elem *ptr, size_type offset, size_type count) const { return _string->find_first_of(ptr, offset, count); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_of(const _Elem *ptr, size_type offset) const { return _string->find_first_of(ptr, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_of(_Elem ch, size_type offset) const { return _string->find_first_of(ch, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_of(const _Myt &right, size_type offset) const noexcept { return _string->find_last_of(*right._string, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_of(const _Mybase &right, size_type offset) const noexcept { return _string->find_last_of(right, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_of(const _Elem *ptr, size_type offset, size_type count) const { return _string->find_last_of(ptr, offset, count); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_of(const _Elem *ptr, size_type offset) const { return _string->find_last_of(ptr, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_of(_Elem ch, size_type offset) const { return _string->find_last_of(ch, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_not_of(const _Myt &right, size_type offset) const noexcept { return _string->find_first_not_of(*right._string, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_not_of(const _Mybase &right, size_type offset) const noexcept { return _string->find_first_not_of(right, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_not_of(const _Elem *ptr, size_type offset, size_type count) const { return _string->find_first_not_of(ptr, offset, count); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_not_of(const _Elem *ptr, size_type offset) const { return _string->find_first_not_of(ptr, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_first_not_of(_Elem ch, size_type offset) const { return _string->find_first_not_of(ch, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_not_of(const _Myt &right, size_type offset) const noexcept { return _string->find_last_not_of(*right._string, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_not_of(const _Mybase &right, size_type offset) const noexcept { return _string->find_last_not_of(right, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_not_of(const _Elem *ptr, size_type offset, size_type count) const { return _string->find_last_not_of(ptr, offset, count); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_not_of(const _Elem *ptr, size_type offset) const { return _string->find_last_not_of(ptr, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::size_type basic_string<_Elem, _Traits, _Alloc>::find_last_not_of(_Elem ch, size_type offset) const { return _string->find_last_not_of(ch, offset); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::_Myt basic_string<_Elem, _Traits, _Alloc>::substr(size_type offset, size_type count) const { return _string->substr(offset, count); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(const _Myt &right) const noexcept { return _string->compare(*right._string); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(size_type offset, size_type n0, const _Myt &right) const { return _string->compare(offset, n0, *right._string); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(size_type offset, size_type n0, const _Myt &right, size_type roffset, size_type count) const { return _string->compare(offset, n0, *right._string, count); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(const _Mybase &right) const noexcept { return _string->compare(right); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(size_type offset, size_type n0, const _Mybase &right) const { return _string->compare(offset, n0, right); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(size_type offset, size_type n0, const _Mybase &right, size_type roffset, size_type count) const { return _string->compare(offset, n0, right, count); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(const _Elem *ptr) const { return _string->compare(ptr); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(size_type offset, size_type n0, const _Elem *ptr) const { return _string->compare(offset, n0, ptr); }

template<class _Elem, class _Traits, class _Alloc>
int basic_string<_Elem, _Traits, _Alloc>::compare(size_type offset, size_type n0, const _Elem *ptr, size_type count) const { return _string->compare(offset, n0, ptr, count); }

template<class _Elem, class _Traits, class _Alloc>
typename basic_string<_Elem, _Traits, _Alloc>::allocator_type basic_string<_Elem, _Traits, _Alloc>::get_allocator() const noexcept { return _string->get_allocator(); }