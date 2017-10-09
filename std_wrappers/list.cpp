/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//list_const_iterator
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _Mylist, class _IterTy, class _ConstIterTy>
list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::list_const_iterator() { _iter=new _ConstIterTy(); }

//template<class _Mylist, class _IterTy, class _ConstIterTy>
//list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::list_const_iterator(_Nodeptr node, const _Mylist *list) { _iter=new _ConstIterTy(node, list); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::list_const_iterator(_Myiter &right) { _iter=new _ConstIterTy(*right._iter); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::list_const_iterator(_Myiter &&right) { _iter=new _ConstIterTy(std::move(*right._iter)); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::list_const_iterator(_Iter &right) { _iter=new _ConstIterTy(*right._iter); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::list_const_iterator(_ConstIterTy &right) { _iter=new _ConstIterTy(right); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::list_const_iterator(_IterTy &right) { _iter=new _ConstIterTy(right); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::~list_const_iterator() { delete _iter; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator=(const _Myiter &right) { _iter->operator=(*right._iter); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator=(_Myiter &&right) { _iter->operator=(std::move(*right._iter)); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator=(const _Iter &right) { _iter->operator=(*right._iter); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::reference list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator*() const { return _iter->operator*(); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::pointer list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator->() const { return _iter->operator->(); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator++() { _iter->operator++(); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator++(int) { _iter->operator++(); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator--() { _iter->operator--(); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator--(int) { _iter->operator--(); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
bool list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator==(const _Myiter &right) const { return ((*_iter)==(*right._iter)); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
bool list_const_iterator<_Mylist, _IterTy, _ConstIterTy>::operator!=(const _Myiter &right) const { return ((*_iter)!=(*right._iter)); }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//list_iterator
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _Mylist, class _IterTy, class _ConstIterTy>
list_iterator<_Mylist, _IterTy, _ConstIterTy>::list_iterator() { _iter=new _IterTy(); }

//template<class _Mylist, class _IterTy, class _ConstIterTy>
//list_iterator<_Mylist, _IterTy, _ConstIterTy>::list_iterator(_Nodeptr node, const _Mylist *list) { _iter=new _IterTy(node, list); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_iterator<_Mylist, _IterTy, _ConstIterTy>::list_iterator(_Myiter &right) { _iter=new _IterTy(*right._iter); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_iterator<_Mylist, _IterTy, _ConstIterTy>::list_iterator(_Myiter &&right) { _iter=new _IterTy(std::move(*right._iter)); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_iterator<_Mylist, _IterTy, _ConstIterTy>::list_iterator(_IterTy &right) { _iter=new _IterTy(right); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
list_iterator<_Mylist, _IterTy, _ConstIterTy>::~list_iterator() { delete _iter; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator=(const _Myiter &right) { _iter->operator=(*right._iter); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator=(_Myiter &&right) { _iter->operator=(std::move(*right._iter)); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_iterator<_Mylist, _IterTy, _ConstIterTy>::reference list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator*() const { return _iter->operator*(); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_iterator<_Mylist, _IterTy, _ConstIterTy>::pointer list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator->() const { return _iter->operator->(); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator++() { _iter->operator++(); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator++(int) { _iter->operator++(); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter &list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator--() { _iter->operator--(); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
typename list_iterator<_Mylist, _IterTy, _ConstIterTy>::_Myiter list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator--(int) { _iter->operator--(); return *this; }

template<class _Mylist, class _IterTy, class _ConstIterTy>
bool list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator==(const _Myiter &right) const { return ((*_iter)==(*right._iter)); }

template<class _Mylist, class _IterTy, class _ConstIterTy>
bool list_iterator<_Mylist, _IterTy, _ConstIterTy>::operator!=(const _Myiter &right) const { return ((*_iter)!=(*right._iter)); }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//list
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list() { _list=new _Mybase(); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(const _Alloc &alloc) { _list=new _Mybase(alloc); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(size_type count) { _list=new _Mybase(count); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(size_type count, const _Ty &val) { _list=new _Mybase(count, val); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(size_type count, const _Ty &val, const _Alloc &alloc) { _list=new _Mybase(count, val, alloc); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(const _Myt &right) { _list=new _Mybase(*right._list); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(const _Myt &right, const _Alloc &alloc) { _list=new _Mybase(*right._list, alloc); }

//template<class _Ty, class _Alloc>
//template<class _Iter, class=typename enable_if<_Is_iterator<_Iter>::value, void>::type>
//list<_Ty, _Alloc>::list(_Iter first, _Iter last) { _list=new _Mybase(*first.iter, *last._iter); }

//template<class _Ty, class _Alloc>
//template<class _Iter, class=typename enable_if<_Is_iterator<_Iter>::value, void>::type>
//list<_Ty, _Alloc>::list(_Iter first, _Iter last, const _Alloc &alloc) { _list=new _Mybase(*first._iter, *last._iter, alloc); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(_Myt &&right) { _list=right._list; right._list=nullptr; }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(_Myt &&right, const _Alloc &alloc) { _list=new _Mybase(std::move(*right._list), alloc); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(std::initializer_list<_Ty> ilist, const _Alloc &alloc) { _list=new _Mybase(ilist, alloc); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(_Mybase &right) { _list=new _Mybase(right); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::list(_Mybase &&right) { _list=new _Mybase(right); }

template<class _Ty, class _Alloc>
list<_Ty, _Alloc>::~list() noexcept { if(_list != nullptr) delete _list; }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::_Myt &list<_Ty, _Alloc>::operator=(_Myt &&right) noexcept { if(_list!=nullptr) delete _list; _list=right._list; right._list=nullptr; return *this; }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::_Myt &list<_Ty, _Alloc>::operator=(std::initializer_list<_Ty> ilist) { if(_list==nullptr) new _Mybase(ilist); else _list->operator=(ilist); return *this; }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::_Myt &list<_Ty, _Alloc>::operator=(const _Myt &right) { if(_list==nullptr) new _Mybase(*right._list); else _list->operator=(*right._list); return *this; }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::_Myt &list<_Ty, _Alloc>::operator=(_Mybase &right) noexcept { if(_list==nullptr) new _Mybase(right); else _list->operator=(right); return *this; }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::_Myt &list<_Ty, _Alloc>::operator=(const _Mybase &right) { if(_list==nullptr) new _Mybase(right); else _list->operator=(right); return *this; }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::_Myt &list<_Ty, _Alloc>::operator=(_Mybase &&right) noexcept { if(_list==nullptr) new _Mybase(right); else _list->operator=(right); return *this; }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::push_front(_Ty &&val) { _list->push_front(val);}

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::push_back(_Ty &&val) { _list->push_back(val); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::insert(const_iterator where, _Ty &&val) { return iterator(_list->insert(*where._iter, val)); }

template<class _Ty, class _Alloc>
template<class... _Valty>
void list<_Ty, _Alloc>::emplace_front(_Valty &&... val) { _list->emplace_front(val); }

template<class _Ty, class _Alloc>
template<class... _Valty>
void list<_Ty, _Alloc>::emplace_back(_Valty &&... val) { _list->emplace_back(val); }

template<class _Ty, class _Alloc>
template<class... _Valty>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::emplace(const_iterator where, _Valty &&... val) { return iterator(_list->emplace(*where._iter, val)); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::assign(std::initializer_list<_Ty> ilist) { _list->assign(ilist); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::insert(const_iterator where, std::initializer_list<_Ty> ilist) { return iterator(_list->insert(*where._iter, ilist)); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::begin() noexcept { return iterator(_list->begin()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_iterator list<_Ty, _Alloc>::begin() const noexcept { return const_iterator(_list->cbegin()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::end() noexcept { return iterator(_list->end()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_iterator list<_Ty, _Alloc>::end() const noexcept { return const_iterator(_list->cend()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::reverse_iterator list<_Ty, _Alloc>::rbegin() noexcept { return reverse_iterator(_list->rbegin()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_reverse_iterator list<_Ty, _Alloc>::rbegin() const noexcept { return const_reverse_iterator(_list->crbegin()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::reverse_iterator list<_Ty, _Alloc>::rend() noexcept { return reverse_iterator(_list->rend()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_reverse_iterator list<_Ty, _Alloc>::rend() const noexcept { return const_reverse_iterator(_list->crend()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_iterator list<_Ty, _Alloc>::cbegin() const noexcept { return const_iterator(_list->cbegin()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_iterator list<_Ty, _Alloc>::cend() const noexcept { return const_iterator(_list->cend()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_reverse_iterator list<_Ty, _Alloc>::crbegin() const noexcept { return const_reverse_iterator(_list->crbegin()); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_reverse_iterator list<_Ty, _Alloc>::crend() const noexcept { return const_reverse_iterator(_list->crend()); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::resize(size_type newSize) { _list->resize(newSize); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::resize(size_type newSize, const _Ty &val) { _list->resize(newSize, val); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::size_type list<_Ty, _Alloc>::size() const noexcept { return _list->size(); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::size_type list<_Ty, _Alloc>::max_size() const noexcept { return _list->max_size(); }

template<class _Ty, class _Alloc>
bool list<_Ty, _Alloc>::empty() const noexcept { return _list->empty(); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::allocator_type list<_Ty, _Alloc>::get_allocator() const noexcept { return _list->get_allocator(); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::reference list<_Ty, _Alloc>::front() { return _list->front(); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_reference list<_Ty, _Alloc>::front() const{ return _list->front(); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::reference list<_Ty, _Alloc>::back() { return _list->back(); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::const_reference list<_Ty, _Alloc>::back() const { return _list->back(); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::push_front(const _Ty &val) { _list->push_front(val); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::pop_front() { _list->pop_front(); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::push_back(const _Ty &val) { _list->push_back(val); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::pop_back() { _list->pop_back(); }

//template<class _Ty, class _Alloc>
//template<class _Iter>
//typename enable_if<_Is_iterator<_Iter>::value, void>::type
//list<_Ty, _Alloc>::assign(_Iter first, _Iter last) { _list->assign(*first._iter, *last._iter); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::assign(size_type count, const _Ty &val) { _list->assign(count, val); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::insert(const_iterator where, const _Ty &val) { return iterator(_list->insert(*where._iter, val)); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::insert(const_iterator where, size_type count, const _Ty &val) { return iterator(_list->insert(*where._iter, count, val)); }

//template<class _Ty, class _Alloc>
//template<class _Iter>
//typename enable_if<_Is_iterator<_Iter>::value, typename list<_Ty, _Alloc>::iterator>::type
//list<_Ty, _Alloc>::insert(const_iterator where, _Iter first, _Iter last) { return iterator(_list->insert(*where._iter, *first._iter, *last._iter)); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::erase(const_iterator where) { return iterator(_list->erase(*where._iter)); }

template<class _Ty, class _Alloc>
typename list<_Ty, _Alloc>::iterator list<_Ty, _Alloc>::erase(const_iterator first, const_iterator last) { return iterator(_list->erase(*first._iter, *last._iter)); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::clear() noexcept { _list->clear(); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::swap(_Myt &right) noexcept { _list->swap(*right._list); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::splice(const_iterator where, _Myt &right) { _list->splice(*where._iter, *right._list); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::splice(const_iterator where, _Myt &&right) { _list->splice(*where._iter, std::move(*right._list)); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::splice(const_iterator where, _Myt &right, const_iterator first) { _list->splice(*where._iter, *right._list, *first._iter); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::splice(const_iterator where, _Myt &&right, const_iterator first) { _list->splice(*where._iter, std::move(*right._list), *first._iter); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::splice(const_iterator where, _Myt &right, const_iterator first, const_iterator last) { _list->splice(*where._iter, *right._list, *first._iter, *last._iter); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::splice(const_iterator where, _Myt &&right, const_iterator first, const_iterator last) { _list->splice(*where._iter, std::move(*right._list), *first._iter, *last._iter); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::remove(const _Ty &val) { _list->remove(val); }

template<class _Ty, class _Alloc>
template<class _Pr1>
void list<_Ty, _Alloc>::remove_if(_Pr1 pred) { _list->remove_if(pred); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::unique() { _list->unique(); }

template<class _Ty, class _Alloc>
template<class _Pr2>
void list<_Ty, _Alloc>::unique(_Pr2 pred) { _list->unique(pred); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::merge(_Myt &right) { _list->merge(*right._list); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::merge(_Myt &&right) { _list->merge(std::move(*right._list)); }

template<class _Ty, class _Alloc>
template<class _Pr2>
void list<_Ty, _Alloc>::merge(_Myt &right, _Pr2 pred) { _list->merge(*right._list, pred); }

template<class _Ty, class _Alloc>
template<class _Pr2>
void list<_Ty, _Alloc>::merge(_Myt &&right, _Pr2 pred) { _list->merge(std::move(*right._list), pred); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::sort() { _list->sort(); }

template<class _Ty, class _Alloc>
template<class _Pr2>
void list<_Ty, _Alloc>::sort(_Pr2 pred) { _list->sort(pred); }

template<class _Ty, class _Alloc>
void list<_Ty, _Alloc>::reverse() noexcept { _list->reverse(); }