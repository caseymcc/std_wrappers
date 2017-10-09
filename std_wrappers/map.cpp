/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//map_const_iterator
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _Mymap, class _IterTy, class _ConstIterTy>
map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::map_const_iterator(const typename _ConstIterTy &iter) { _iter=new _Mybase(iter); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::map_const_iterator(const _Myiter &right) { _iter=new _Mybase(*right._iter); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::map_const_iterator(_Myiter &&right) { _iter=new _Mybase(std::move(*right._iter)); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::map_const_iterator(const _Iter &right) { _iter=new _Mybase(*right._iter); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::reference map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::operator*() const { return _iter->operator*(); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::pointer map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::operator->() const { return _iter->operator->(); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::_Myiter &map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::operator++() { _iter->operator++(); return *this; }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::_Myiter map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::operator++(int) { _iter->operator++(); return *this; }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::_Myiter &map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::operator--() { _iter->operator--(); return *this; }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::_Myiter map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::operator--(int) { _iter->operator--(); return *this; }

template<class _Mymap, class _IterTy, class _ConstIterTy>
bool map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::operator==(const _Myiter &right) const { return((*_iter)==(*right._iter)); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
bool map_const_iterator<_Mymap, _IterTy, _ConstIterTy>::operator!=(const _Myiter &right) const { return((*_iter)!=(*right._iter)); }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//map_iterator
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class _Mymap, class _IterTy, class _ConstIterTy>
map_iterator<_Mymap, _IterTy, _ConstIterTy>::map_iterator(const typename _IterTy &iter) { _iter=new _Mybase(iter); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
map_iterator<_Mymap, _IterTy, _ConstIterTy>::map_iterator(const _Myiter &right) { _iter=new _Mybase(*right._iter); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
map_iterator<_Mymap, _IterTy, _ConstIterTy>::map_iterator(_Myiter &&right) { _iter=new _Mybase(std::move(*right._iter)); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_iterator<_Mymap, _IterTy, _ConstIterTy>::reference map_iterator<_Mymap, _IterTy, _ConstIterTy>::operator*() const { return _iter->operator*(); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_iterator<_Mymap, _IterTy, _ConstIterTy>::pointer map_iterator<_Mymap, _IterTy, _ConstIterTy>::operator->() const { return _iter->operator->(); }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_iterator<_Mymap, _IterTy, _ConstIterTy>::_Myiter &map_iterator<_Mymap, _IterTy, _ConstIterTy>::operator++() { _iter->operator++(); return *this; }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_iterator<_Mymap, _IterTy, _ConstIterTy>::_Myiter map_iterator<_Mymap, _IterTy, _ConstIterTy>::operator++(int) { _iter->operator++(); return *this; }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_iterator<_Mymap, _IterTy, _ConstIterTy>::_Myiter &map_iterator<_Mymap, _IterTy, _ConstIterTy>::operator--() { _iter->operator--(); return *this; }

template<class _Mymap, class _IterTy, class _ConstIterTy>
typename map_iterator<_Mymap, _IterTy, _ConstIterTy>::_Myiter map_iterator<_Mymap, _IterTy, _ConstIterTy>::operator--(int) { _iter->operator--(); return *this; }

template<class _Mymap, class _IterTy, class _ConstIterTy>
bool map_iterator<_Mymap, _IterTy, _ConstIterTy>::operator==(const _Myiter &right) const { return (*_iter)==(*right._iter);}

template<class _Mymap, class _IterTy, class _ConstIterTy>
bool map_iterator<_Mymap, _IterTy, _ConstIterTy>::operator!=(const _Myiter &right) const { return (*_iter)!=(*right._iter);}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//map
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map() { _map=new _Mybase(); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(const allocator_type &alloc) { _map=new _Mybase(alloc); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(const _Myt &right) { _map=new _Mybase(*right._map); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(const _Myt &right, const allocator_type &alloc) { _map=new _Mybase(*right._map, alloc); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(const key_compare &pred) { _map=new _Mybase(pred); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(const key_compare &pred, const allocator_type &alloc) { _map=new _Mybase(pred, alloc); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(const _Mybase &right) { _map=new _Mybase(right); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(const _Mybase &&right) { _map=new _Mybase(right); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Iter>
map<_Kty, _Ty, _Pr, _Alloc>::map(_Iter first, _Iter last) { _map=new _Mybase(*first._iter, *last._iter); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Iter>
map<_Kty, _Ty, _Pr, _Alloc>::map(_Iter first, _Iter last, const key_compare &pred) { _map=new _Mybase(*first._iter, *last._iter, pred); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Iter>
map<_Kty, _Ty, _Pr, _Alloc>::map(_Iter first, _Iter last, const key_compare &pred, const allocator_type &alloc) { _map=new _Mybase(*first._iter, *last._iter, pred, alloc); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Myt &map<_Kty, _Ty, _Pr, _Alloc>::operator=(const _Myt &right) { _map->operator=(*right._map); return *this; }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(_Myt &&right) { _map=new _Mybase(std::move(*right._map)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(_Myt &&right, const allocator_type &alloc) { _map=new _Mybase(std::move(*right._map), alloc); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Myt &map<_Kty, _Ty, _Pr, _Alloc>::operator=(_Myt &&right) noexcept { _map->operator=(std::move(*right._map)); return *this; }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Myt &map<_Kty, _Ty, _Pr, _Alloc>::operator=(const _Mybase &right) { _map->operator=(right); return *this; }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Myt &map<_Kty, _Ty, _Pr, _Alloc>::operator=(const _Mybase &&right) { _map->operator=(right); return *this; }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::mapped_type &map<_Kty, _Ty, _Pr, _Alloc>::operator[](key_type &&keyVal) { return _map->operator[](keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
void map<_Kty, _Ty, _Pr, _Alloc>::swap(_Myt &right) { _map->swap(*right._map); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Valty, class=enable_if_t<is_constructible<value_type, _Valty>::value> >
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairib map<_Kty, _Ty, _Pr, _Alloc>::insert(_Valty &&val) { return _map->insert(val); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Valty, class=enable_if_t<is_constructible<value_type, _Valty>::value> >
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::insert(const_iterator where, _Valty &&val) { return iterator(_map->insert(*where._iter, val)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class... _Mappedty>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairib map<_Kty, _Ty, _Pr, _Alloc>::try_emplace(const key_type &keyVal, _Mappedty&&... mapVal) { return _map->try_emplace(keyVal, val); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class... _Mappedty>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::try_emplace(const_iterator where, const key_type &keyVal, _Mappedty&&... mapVal) { return iterator(_map->try_emplace(*where._iter, keyVal, mapVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class... _Mappedty>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairib map<_Kty, _Ty, _Pr, _Alloc>::try_emplace(key_type &&keyVal, _Mappedty&&... mapVal) { return _map->try_emplace(keyVal, mapVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class... _Mappedty>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::try_emplace(const_iterator where, key_type &&keyVal, _Mappedty&&... mapVal) { return iterator(_map->try_emplace(*where._iter, keyVal, mapVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Mappedty>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairib map<_Kty, _Ty, _Pr, _Alloc>::insert_or_assign(const key_type &keyVal, _Mappedty &&mapVal) { return _map->insert_or_assign(keyVal, mapVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Mappedty>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::insert_or_assign(const_iterator where, const key_type &keyVal, _Mappedty &&mapVal) { return iterator(_map->insert_or_assign(*where._iter, keyVal, mapVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Mappedty>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairib map<_Kty, _Ty, _Pr, _Alloc>::insert_or_assign(key_type &&keyVal, _Mappedty &&mapVal) { return _map->insert_or_assign( keyVal, mapVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Mappedty>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::insert_or_assign(const_iterator where, key_type &&keyVal, _Mappedty &&mapVal) { return iterator(_map->insert_or_assign(*where._iter, keyVal, mapVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(_XSTD initializer_list<value_type> ilist) { _map=new _Mybase(ilist); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(_XSTD initializer_list<value_type> ilist, const key_compare &pred) { _map=new _Mybase(ilist, pred); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
map<_Kty, _Ty, _Pr, _Alloc>::map(_XSTD initializer_list<value_type> ilist, const key_compare &pred, const allocator_type &alloc) { _map=new _Mybase(ilist, pred, alloc); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Myt &map<_Kty, _Ty, _Pr, _Alloc>::operator=(std::initializer_list<value_type> ilist) { _map->operator=(ilist); return *this; }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::mapped_type &map<_Kty, _Ty, _Pr, _Alloc>::operator[](const key_type &keyVal) { return _map->operator[](keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::mapped_type &map<_Kty, _Ty, _Pr, _Alloc>::at(const key_type &keyVal) { return _map->at(keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
const typename map<_Kty, _Ty, _Pr, _Alloc>::mapped_type &map<_Kty, _Ty, _Pr, _Alloc>::at(const key_type &keyVal) const { return _map->at(keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class... _Valty>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairib map<_Kty, _Ty, _Pr, _Alloc>::emplace(_Valty&&... val) { return _map->emplace(val); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class... _Valty>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::emplace_hint(const_iterator where, _Valty&&... val) { return iterator(_map->emplace_hint(*where._iter, val)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::begin() noexcept { return iterator(_map->begin()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::begin() const noexcept { return const_iterator(_map->begin()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::end() noexcept { return iterator(_map->end()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::end() const noexcept { return iterator(_map->end()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::reverse_iterator map<_Kty, _Ty, _Pr, _Alloc>::rbegin() noexcept { return reverse_iterator(_map->rbegin()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_reverse_iterator map<_Kty, _Ty, _Pr, _Alloc>::rbegin() const noexcept { return const_reverse_iterator(_map->crbegin()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::reverse_iterator map<_Kty, _Ty, _Pr, _Alloc>::rend() noexcept { return reverse_iterator(_map->rend()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_reverse_iterator map<_Kty, _Ty, _Pr, _Alloc>::rend() const noexcept { return const_reverse_iterator(_map->crend()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::cbegin() const noexcept { return const_iterator(_map->cbegin()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::cend() const noexcept { return const_iterator(_map->cend()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_reverse_iterator map<_Kty, _Ty, _Pr, _Alloc>::crbegin() const noexcept { return const_reverse_iterator(_map->crbegin()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_reverse_iterator map<_Kty, _Ty, _Pr, _Alloc>::crend() const noexcept { return const_reverse_iterator(_map->crend()); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::size_type map<_Kty, _Ty, _Pr, _Alloc>::size() const noexcept { return _map->size(); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::size_type map<_Kty, _Ty, _Pr, _Alloc>::max_size() const noexcept { return _map->max_size(); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
bool map<_Kty, _Ty, _Pr, _Alloc>::empty() const noexcept { return _map->empty(); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::allocator_type map<_Kty, _Ty, _Pr, _Alloc>::get_allocator() const noexcept { return _map->get_allocator(); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::key_compare map<_Kty, _Ty, _Pr, _Alloc>::key_comp() const { return _map->key_comp(); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::value_compare map<_Kty, _Ty, _Pr, _Alloc>::value_comp() const { return _map->value_comp(); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairib map<_Kty, _Ty, _Pr, _Alloc>::insert(const value_type &val) { return _map->insert(val); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairib map<_Kty, _Ty, _Pr, _Alloc>::insert(value_type&& val) { return _map->insert(val); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::insert(const_iterator where, const value_type &val) { return iterator(_map->insert(*where._iter, val)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::insert(const_iterator where, value_type&& val) { return iterator(_map->insert(*where._iter, val)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Iter>
void map<_Kty, _Ty, _Pr, _Alloc>::insert(_Iter first, _Iter last) { return iterator(_map->insert(*first._iter, *last._iter)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
void map<_Kty, _Ty, _Pr, _Alloc>::insert(std::initializer_list<value_type> ilist) { _map->insert(ilist); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::erase(const_iterator where) { return iterator(_map->erase(*where._iter)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::erase(const_iterator first, const_iterator last) { return iterator(_map->erase(*first._iter, *last._iter)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::size_type map<_Kty, _Ty, _Pr, _Alloc>::erase(const key_type &keyVal) { return _map->erase(keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
void map<_Kty, _Ty, _Pr, _Alloc>::clear() noexcept { return _map->clear(); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::find(const key_type &keyVal) { return iterator(_map->find(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::find(const key_type &keyVal) const { return const_iterator(_map->find(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::find(const _Other &keyVal) { return iterator(_map->find(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::find(const _Other &keyVal) const { return const_iterator(_map->find(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::size_type map<_Kty, _Ty, _Pr, _Alloc>::count(const key_type &keyVal) const { return _map->count(keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::size_type map<_Kty, _Ty, _Pr, _Alloc>::count(const _Other &keyVal) const { return _map->count(keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::lower_bound(const key_type &keyVal) { return iterator(_map->lower_bound(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::lower_bound(const key_type &keyVal) const { return const_iterator(_map->lower_bound(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::lower_bound(const _Other &keyVal) { return iterator(_map->lower_bound(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::lower_bound(const _Other &keyVal) const { return const_iterator(_map->lower_bound(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::upper_bound(const key_type &keyVal) { return iterator(_map->upper_bound(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::upper_bound(const key_type &keyVal) const { return const_iterator(_map->upper_bound(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::iterator map<_Kty, _Ty, _Pr, _Alloc>::upper_bound(const _Other &keyVal) { return iterator(_map->upper_bound(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::const_iterator map<_Kty, _Ty, _Pr, _Alloc>::upper_bound(const _Other &keyVal) const { return const_iterator(_map->upper_bound(keyVal)); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairii map<_Kty, _Ty, _Pr, _Alloc>::equal_range(const key_type &keyVal) { return _map->equal_range(keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Paircc map<_Kty, _Ty, _Pr, _Alloc>::equal_range(const key_type &keyVal) const { return _map->equal_range(keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Pairii map<_Kty, _Ty, _Pr, _Alloc>::equal_range(const _Other &keyVal) { return _map->equal_range(keyVal); }

template<class _Kty, class _Ty, class _Pr, class _Alloc>
template<class _Other, class _Mycomp, class=typename _Mycomp::is_transparent>
typename map<_Kty, _Ty, _Pr, _Alloc>::_Paircc map<_Kty, _Ty, _Pr, _Alloc>::equal_range(const _Other &keyVal) const { return _map->equal_range(keyVal); }
