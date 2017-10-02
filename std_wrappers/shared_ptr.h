
template<class _Ty>
class shared_ptr
{
public:
    typedef shared_ptr<_Ty> _Myt;

    shared_ptr() noexcept; 
    shared_ptr(_Ty *ptr);
#ifdef STD_WRAPPER_EXPORT
    template<class _Ptr>
    explicit shared_ptr(_Ptr *ptr);
    template<class _Ptr,class _Deleter>
    shared_ptr(_Ptr *ptr, _Deleter deleter);
#endif//STD_WRAPPER_EXPORT
//    constexpr shared_ptr(std::nullptr_t) noexcept;
#ifdef STD_WRAPPER_EXPORT
//    template<class _Deleter>
//    shared_ptr(std::nullptr_t, _Deleter deleter);
//    template<class _Deleter, class _Alloc>
//    shared_ptr(std::nullptr_t, _Deleter deleter, _Alloc alloc);
    template<class _Ptr, class _Deleter, class _Alloc>
    shared_ptr(_Ptr *ptr, _Deleter deleter, _Alloc alloc);
    template<class _Ty2>
    shared_ptr(const shared_ptr<_Ty2> &right, _Ty *ptr) noexcept;
#endif//STD_WRAPPER_EXPORT
    shared_ptr(const _Myt &right) noexcept;
#ifdef STD_WRAPPER_EXPORT
    template<class _Ty2, class=typename std::enable_if<std::is_convertible<_Ty2 *, _Ty *>::value, void>::type>
    shared_ptr(const shared_ptr<_Ty2> &right) noexcept;
    template<class _Ty2>
    explicit shared_ptr(const std::weak_ptr<_Ty2> &right, bool shouldThrow=true);
#endif//STD_WRAPPER_EXPORT
#if _HAS_AUTO_PTR_ETC
    template<class _Ty2>
    shared_ptr(std::auto_ptr<_Ty2> &&right);
#endif /* _HAS_AUTO_PTR_ETC */
    shared_ptr(_Myt &&right) noexcept;
#ifdef STD_WRAPPER_EXPORT
    template<class _Ty2, class=typename std::enable_if<std::is_convertible<_Ty2 *, _Ty *>::value, void>::type>
    shared_ptr(shared_ptr<_Ty2> &&right) noexcept;
    template<class _Ptr,class _Deleter, class=typename std::enable_if<std::is_convertible<typename std::unique_ptr<_Ptr, _Deleter>::pointer, _Ty *>::value, void>::type>
    shared_ptr(std::unique_ptr<_Ptr, _Deleter> &&right);
#endif//STD_WRAPPER_EXPORT

#ifdef STD_WRAPPER_EXPORT
    template<class _Ptr, class _Deleter>
    _Myt &operator=(std::unique_ptr<_Ptr, _Deleter> &&right);
#endif//STD_WRAPPER_EXPORT
    _Myt &operator=(_Myt &&right) noexcept;
#ifdef STD_WRAPPER_EXPORT
    template<class _Ty2>
    _Myt &operator=(shared_ptr<_Ty2> &&right) noexcept;
#endif//STD_WRAPPER_EXPORT

    ~shared_ptr() noexcept;

    _Myt &operator=(const _Myt &right) noexcept;
#ifdef STD_WRAPPER_EXPORT
    template<class _Ty2>
    _Myt &operator=(const shared_ptr<_Ty2> &right) noexcept;
#endif//STD_WRAPPER_EXPORT
#if _HAS_AUTO_PTR_ETC
    template<class _Ty2>
    _Myt &operator=(std::auto_ptr<_Ty2> &&right);
#endif//_HAS_AUTO_PTR_ETC

    void reset() noexcept;
#ifdef STD_WRAPPER_EXPORT
    template<class _Ptr>
    void reset(_Ptr *ptr);
    template<class _Ptr, class _Deleter>
    void reset(_Ptr *ptr, _Deleter deleter);
    template<class _Ptr, class _Deleter, class _Alloc>
    void reset(_Ptr *ptr, _Deleter deleter, _Alloc alloc);
#endif//STD_WRAPPER_EXPORT

    void swap(_Myt &right) noexcept;

    _Ty *get() const noexcept;

    typename std::add_lvalue_reference<_Ty>::type operator*() const noexcept;

    _Ty *operator->() const noexcept;

    bool unique() const noexcept;

    explicit operator bool() const noexcept;

private:
    std::shared_ptr<_Ty> *_sharedPtr;
};