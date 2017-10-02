
template<class _Ty>
shared_ptr<_Ty>::shared_ptr() noexcept { _sharedPtr=new std::shared_ptr<_Ty>(); }

template<class _Ty>
shared_ptr<_Ty>::shared_ptr(_Ty *ptr) { _sharedPtr=new std::shared_ptr<_Ty>(ptr); }

template<class _Ty>
template<class _Ptr>
shared_ptr<_Ty>::shared_ptr(_Ptr *ptr){ _sharedPtr=new std::shared_ptr<_Ty>(ptr); }

template<class _Ty>
template<class _Ptr, class _Deleter>
shared_ptr<_Ty>::shared_ptr(_Ptr *ptr, _Deleter deleter) { _sharedPtr=new std::shared_ptr<_Ty>(ptr, deleter); }

//template<class _Ty>
//constexpr shared_ptr<_Ty>::shared_ptr(std::nullptr_t) noexcept { _sharedPtr=new std::shared_ptr<_Ty>(std::nullptr_t); }
//
//template<class _Ty>
//template<class _Deleter>
//shared_ptr<_Ty>::shared_ptr(std::nullptr_t, _Deleter deleter) { _sharedPtr=new std::shared_ptr<_Ty>(std::nullptr_t, deleter); }
//
//template<class _Ty>
//template<class _Deleter, class _Alloc>
//shared_ptr<_Ty>::shared_ptr(std::nullptr_t, _Deleter deleter, _Alloc alloc) { _sharedPtr=new std::shared_ptr<_Ty>(std::nullptr_t, delter, alloc); }

template<class _Ty>
template<class _Ptr, class _Deleter, class _Alloc>
shared_ptr<_Ty>::shared_ptr(_Ptr *ptr, _Deleter deleter, _Alloc alloc) { _sharedPtr=new std::shared_ptr<_Ty>(ptr, deleter, alloc); }

template<class _Ty>
template<class _Ty2>
shared_ptr<_Ty>::shared_ptr(const shared_ptr<_Ty2> &right, _Ty *ptr) noexcept { _sharedPtr=new std::shared_ptr<_Ty>(right._shared_ptr, ptr); }

template<class _Ty>
shared_ptr<_Ty>::shared_ptr(const _Myt &right) noexcept { _sharedPtr=new std::shared_ptr<_Ty>(*right._sharedPtr); }

template<class _Ty>
template<class _Ty2, class=typename std::enable_if<std::is_convertible<_Ty2 *, _Ty *>::value, void>::type>
shared_ptr<_Ty>::shared_ptr(const shared_ptr<_Ty2> &right) noexcept { _sharedPtr=new std::shared_ptr<_Ty>(*right._sharedPtr); }

template<class _Ty>
template<class _Ty2>
shared_ptr<_Ty>::shared_ptr(const std::weak_ptr<_Ty2>& right, bool shouldThrow) { _sharedPtr=new std::shared_ptr<_Ty>(right, shouldThrow); }

#if _HAS_AUTO_PTR_ETC
template<class _Ty>
template<class _Ty2>
shared_ptr<_Ty>::shared_ptr(std::auto_ptr<_Ty2> &&right) { _sharedPtr=new std::shared_ptr<_Ty>(*right._sharedPtr); }
#endif /* _HAS_AUTO_PTR_ETC */

template<class _Ty>
shared_ptr<_Ty>::shared_ptr(_Myt &&right) noexcept { _sharedPtr=new std::shared_ptr<_Ty>(*right._sharedPtr); }

template<class _Ty>
template<class _Ty2, class=typename std::enable_if<std::is_convertible<_Ty2 *, _Ty *>::value, void>::type>
shared_ptr<_Ty>::shared_ptr(shared_ptr<_Ty2> &&right) noexcept { _sharedPtr=new std::shared_ptr<_Ty>(*right._sharedPtr); }

template<class _Ty>
template<class _Ptr, class _Deleter, class=typename std::enable_if<std::is_convertible<typename unique_ptr<_Ptr, _Deleter>::pointer, _Ty *>::value, void>::type>
shared_ptr<_Ty>::shared_ptr(std::unique_ptr<_Ptr, _Deleter> &&right) { _sharedPtr=new std::shared_ptr<_Ty>(right); }

template<class _Ty>
template<class _Ptr, class _Deleter>
typename shared_ptr<_Ty>::_Myt &shared_ptr<_Ty>::operator=(std::unique_ptr<_Ptr, _Deleter> &&right) { _sharedPtr->operator=(right); return *this; }

template<class _Ty>
typename shared_ptr<_Ty>::_Myt &shared_ptr<_Ty>::operator=(_Myt &&right) noexcept { _sharedPtr->operator=(*right._sharedPtr); return *this; }

template<class _Ty>
template<class _Ty2>
typename shared_ptr<_Ty>::_Myt &shared_ptr<_Ty>::operator=(shared_ptr<_Ty2>&& right) noexcept { _sharedPtr->operator=(r*ight._sharedPtr); return *this; }

template<class _Ty>
shared_ptr<_Ty>::~shared_ptr() noexcept { delete _sharedPtr; }

template<class _Ty>
typename shared_ptr<_Ty>::_Myt &shared_ptr<_Ty>::operator=(const _Myt &right) noexcept { _sharedPtr->operator=(*right._sharedPtr); return *this; }

template<class _Ty>
template<class _Ty2>
typename shared_ptr<_Ty>::_Myt &shared_ptr<_Ty>::operator=(const shared_ptr<_Ty2> &right) noexcept { _sharedPtr->operator=(right); return *this; }

#if _HAS_AUTO_PTR_ETC
template<class _Ty>
template<class _Ty2>
typename shared_ptr<_Ty>::_Myt &shared_ptr<_Ty>::operator=(std::auto_ptr<_Ty2> &&right) { _sharedPtr->operator=(right); return *this; }
#endif /* _HAS_AUTO_PTR_ETC */

template<class _Ty>
void shared_ptr<_Ty>::reset() noexcept { _sharedPtr->reset(); }

template<class _Ty>
template<class _Ptr>
void shared_ptr<_Ty>::reset(_Ptr *ptr) { _sharedPtr->reset(ptr); }

template<class _Ty>
template<class _Ptr, class _Deleter>
void shared_ptr<_Ty>::reset(_Ptr *ptr, _Deleter deleter) { _sharedPtr->reset(ptr, deleter); }

template<class _Ty>
template<class _Ptr, class _Deleter, class _Alloc>
void shared_ptr<_Ty>::reset(_Ptr *ptr, _Deleter deleter, _Alloc alloc) { _sharedPtr->reset(ptr, deleter, alloc); }

template<class _Ty>
void shared_ptr<_Ty>::swap(_Myt &right) noexcept { _sharedPtr->swap(*right._sharedPtr); }

template<class _Ty>
_Ty *shared_ptr<_Ty>::get() const noexcept { return _sharedPtr->get(); }

template<class _Ty>
typename std::add_lvalue_reference<_Ty>::type shared_ptr<_Ty>::operator*() const noexcept { return _sharedPtr->operator*(); }

template<class _Ty>
_Ty *shared_ptr<_Ty>::operator->() const noexcept { return _sharedPtr->operator->(); }

template<class _Ty>
bool shared_ptr<_Ty>::unique() const noexcept { return _sharedPtr->unique(); }

template<class _Ty>
shared_ptr<_Ty>::operator bool() const noexcept { return _sharedPtr->operator bool(); }
