template<class _MyStr, class _IterTy, class _ConstIterTy>
class basic_string_iterator;

template<class _Elem, class _Traits, class _Alloc>
class basic_string;

template<class _MyStr, class _IterTy, class _ConstIterTy>
class basic_string_const_iterator
{
public:
    typedef basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy> _Myiter;
    typedef basic_string_iterator<_MyStr, _IterTy, _ConstIterTy> _Iter;

    typedef std::random_access_iterator_tag iterator_category;
    typedef typename _MyStr::value_type value_type;
    typedef typename _MyStr::difference_type difference_type;
    typedef typename _MyStr::const_pointer pointer;
    typedef typename _MyStr::const_reference reference;

#ifdef STD_WRAPPER_EXPORT
    basic_string_const_iterator(const typename _ConstIterTy &iter);
#endif//STD_WRAPPER_EXPORT
    basic_string_const_iterator(const _Myiter &right);
    basic_string_const_iterator(_Myiter &&right);
    basic_string_const_iterator(const _Iter &right);

    ~basic_string_const_iterator();

    _Myiter &operator=(const _Myiter &right);
    _Myiter &operator=(_Myiter &&right);
    _Myiter &operator=(const _Iter &right);

    reference operator*() const;
    pointer operator->() const;
    _Myiter &operator++();
    _Myiter operator++(int);
    _Myiter &operator--();
    _Myiter operator--(int);
    _Myiter &operator+=(difference_type offset);
    _Myiter operator+(difference_type offset) const;
    _Myiter &operator-=(difference_type offset);
    _Myiter operator-(difference_type offset) const;
    difference_type operator-(const _Myiter &right) const;
    reference operator[](difference_type offset) const;
    bool operator==(const _Myiter &right) const;
    bool operator!=(const _Myiter &right) const;
    bool operator<(const _Myiter &right) const;
    bool operator>(const _Myiter &right) const;
    bool operator<=(const _Myiter &right) const;
    bool operator>=(const _Myiter &right) const;

    friend basic_string_iterator<_MyStr, _IterTy, _ConstIterTy>;
    friend basic_string<typename _MyStr::value_type, typename _MyStr::traits_type, typename _MyStr::allocator_type>;

private:
    typename _ConstIterTy *_constIter;
};


template<class _MyStr, class _IterTy, class _ConstIterTy>
class basic_string_iterator
{
public:
    typedef basic_string_iterator<_MyStr, _IterTy, _ConstIterTy> _Myiter;
    typedef basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy> _ConstIter;

    typedef std::random_access_iterator_tag iterator_category;
    typedef typename _MyStr::value_type value_type;
    typedef typename _MyStr::difference_type difference_type;
    typedef typename _MyStr::pointer pointer;
    typedef typename _MyStr::reference reference;

#ifdef STD_WRAPPER_EXPORT
    basic_string_iterator(const typename _IterTy &iter);
#endif//STD_WRAPPER_EXPORT
    basic_string_iterator(const _Myiter &right);
    basic_string_iterator(_Myiter &&right);

    _Myiter &operator=(const _Myiter &right);
    _Myiter &operator=(_Myiter &&right);

    reference operator*() const;
    pointer operator->() const;
    _Myiter &operator++();
    _Myiter operator++(int);
    _Myiter &operator--();
    _Myiter operator--(int);
    _Myiter &operator+=(difference_type offset);
    _Myiter operator+(difference_type offset) const;
    _Myiter &operator-=(difference_type offset);
    _Myiter operator-(difference_type offset) const;
    difference_type operator-(const _ConstIter &right) const;
    reference operator[](difference_type offset) const;

    bool operator==(const _Myiter &right) const;
    bool operator!=(const _Myiter &right) const;
    bool operator<(const _Myiter &right) const;
    bool operator>(const _Myiter &right) const;
    bool operator<=(const _Myiter &right) const;
    bool operator>=(const _Myiter &right) const;

    bool operator==(const _ConstIter &right) const;
    bool operator!=(const _ConstIter &right) const;
    bool operator<(const _ConstIter &right) const;
    bool operator>(const _ConstIter &right) const;
    bool operator<=(const _ConstIter &right) const;
    bool operator>=(const _ConstIter &right) const;

    friend basic_string_const_iterator<_MyStr, _IterTy, _ConstIterTy>;
    friend basic_string<typename _MyStr::value_type, typename _MyStr::traits_type, typename _MyStr::allocator_type>;

private:
    typename _IterTy *_iter;
};

template<class _Elem, class _Traits, class _Alloc>
class basic_string
{
public:
    typedef basic_string<_Elem, _Traits, _Alloc> _Myt;
    typedef std::basic_string<_Elem, _Traits, _Alloc> _Mybase;
    typedef _Traits traits_type;
    typedef _Alloc allocator_type;

    typedef typename _Mybase::_Alty _Alty;

    typedef typename _Mybase::value_type value_type;
    typedef typename _Mybase::size_type size_type;
    typedef typename _Mybase::difference_type difference_type;
    typedef typename _Mybase::pointer pointer;
    typedef typename _Mybase::const_pointer const_pointer;
    typedef typename _Mybase::reference reference;
    typedef typename _Mybase::const_reference const_reference;

    typedef basic_string_iterator<typename _Mybase, typename _Mybase::iterator, typename _Mybase::const_iterator> iterator;
    typedef basic_string_const_iterator<typename _Mybase, typename _Mybase::iterator, typename _Mybase::const_iterator> const_iterator;
    typedef basic_string_iterator<typename _Mybase, typename _Mybase::reverse_iterator, typename _Mybase::const_reverse_iterator> reverse_iterator;
    typedef basic_string_const_iterator<typename _Mybase, typename _Mybase::reverse_iterator, typename _Mybase::const_reverse_iterator> const_reverse_iterator;

    basic_string(const _Myt &right);
    basic_string(const _Myt &right, const _Alloc &alloc);
#ifdef STD_WRAPPER_EXPORT
    basic_string(const _Mybase &right);
#endif//STD_WRAPPER_EXPORT
    basic_string() noexcept;
    explicit basic_string(const _Alloc &alloc) noexcept;
    basic_string(const _Myt &right, size_type roffset, size_type count=npos);
    basic_string(const _Myt &right, size_type roffset, size_type count, const _Alloc &alloc);
#ifdef STD_WRAPPER_EXPORT
    basic_string(const _Mybase &right, size_type roffset, size_type count=npos);
#endif//STD_WRAPPER_EXPORT
    basic_string(const _Elem *ptr, size_type count);
    basic_string(const _Elem *ptr, size_type count, const _Alloc &alloc);
    basic_string(const _Elem *ptr);
    basic_string(const _Elem *ptr, const _Alloc &alloc);
    basic_string(size_type count, _Elem ch);
    basic_string(size_type count, _Elem ch, const _Alloc &alloc);
#ifdef STD_WRAPPER_EXPORT
    template<class _Iter> 
    basic_string(_Iter first, _Iter last, const _Alloc &alloc=_Alloc());
#endif//STD_WRAPPER_EXPORT

    basic_string(_Myt &&right) noexcept;
    basic_string(_Myt &&right, const _Alloc &alloc);
    _Myt &operator=(_Myt &&right) noexcept;
    _Myt &assign(_Myt &&right) noexcept;
#ifdef STD_WRAPPER_EXPORT
    basic_string(_Mybase &&right) noexcept;
    basic_string(_Mybase &&right, const _Alloc &alloc);
    _Myt &operator=(_Mybase &&right) noexcept;
    _Myt &assign(_Mybase &&right) noexcept;
#endif// STD_WRAPPER_EXPORT

    basic_string(std::initializer_list<_Elem> ilist, const _Alloc &alloc=allocator_type());

    _Myt &operator=(std::initializer_list<_Elem> ilist);
    _Myt &operator+=(std::initializer_list<_Elem> ilist);
    _Myt &assign(std::initializer_list<_Elem> ilist);
    _Myt &append(std::initializer_list<_Elem> ilist);
    iterator insert(const_iterator where, std::initializer_list<_Elem> ilist);
    _Myt &replace(const_iterator first, const_iterator last, std::initializer_list<_Elem> ilist);

    ~basic_string() noexcept;

    static const size_type npos;	// bad/missing length/position

    _Myt &operator=(const _Myt &right);
#ifdef STD_WRAPPER_EXPORT
    _Myt &operator=(const _Mybase &right);
#endif//STD_WRAPPER_EXPORT
    _Myt &operator=(const _Elem *ptr);
    _Myt &operator=(_Elem ch);
    _Myt &operator+=(const _Myt &right);
#ifdef STD_WRAPPER_EXPORT
    _Myt &operator+=(const _Mybase &right);
#endif//STD_WRAPPER_EXPORT
    _Myt &operator+=(const _Elem *ptr);
    _Myt &operator+=(_Elem ch);

    _Myt &append(const _Myt &right);
    _Myt &append(const _Myt &right, size_type roffset, size_type count=npos);
#ifdef STD_WRAPPER_EXPORT
    _Myt &append(const _Mybase &right);
    _Myt &append(const _Mybase &right, size_type roffset, size_type count=npos);
#endif//STD_WRAPPER_EXPORT
    _Myt &append(const _Elem *ptr, size_type count);
    _Myt &append(const _Elem *ptr);
    _Myt &append(size_type count, _Elem ch);
#ifdef STD_WRAPPER_EXPORT
    template<class _Iter>
    _Myt &append(_Iter first, _Iter last);
#endif//STD_WRAPPER_EXPORT
    _Myt &append(const_pointer first, const_pointer last);
    _Myt &append(const_iterator first, const_iterator last);

    _Myt &assign(const _Myt &right);
    _Myt &assign(const _Myt &right, size_type roffset, size_type count=npos);
#ifdef STD_WRAPPER_EXPORT
    _Myt &assign(const _Mybase &right);
    _Myt &assign(const _Mybase &right, size_type roffset, size_type count=npos);
#endif//STD_WRAPPER_EXPORT
    _Myt &assign(const _Elem *ptr, size_type count);
    _Myt &assign(const _Elem *ptr);
    _Myt &assign(size_type count, _Elem ch);
#ifdef STD_WRAPPER_EXPORT
    template<class _Iter>
    _Myt &assign(_Iter first, _Iter last);
#endif//STD_WRAPPER_EXPORT
    _Myt &assign(const_pointer first, const_pointer last);
    _Myt &assign(const_iterator first, const_iterator last);

    _Myt &insert(size_type offset, const _Myt &right);
    _Myt &insert(size_type offset, const _Myt &right, size_type roffset, size_type count=npos);
#ifdef STD_WRAPPER_EXPORT
    _Myt &insert(size_type offset, const _Mybase &right);
    _Myt &insert(size_type offset, const _Mybase &right, size_type roffset, size_type count=npos);
#endif//STD_WRAPPER_EXPORT
    _Myt &insert(size_type offset, const _Elem *ptr, size_type count);
    _Myt &insert(size_type offset, const _Elem *ptr);
    _Myt &insert(size_type offset, size_type count, _Elem ch);
    iterator insert(const_iterator where);
    iterator insert(const_iterator where, _Elem ch);
    iterator insert(const_iterator where, size_type count, _Elem ch);
#ifdef STD_WRAPPER_EXPORT
    template<class _Iter>
    iterator insert(const_iterator where, _Iter first, _Iter last);
#endif//STD_WRAPPER_EXPORT
    iterator insert(const_iterator where, const_pointer first, const_pointer last);
    iterator insert(const_iterator where, const_iterator first, const_iterator last);

    _Myt &erase(size_type offset=0);
    _Myt &erase(size_type offset, size_type count);
    iterator erase(const_iterator where);
    iterator erase(const_iterator first, const_iterator last);
    void clear() noexcept;

    _Myt &replace(size_type offset, size_type n0, const _Myt &right);
    _Myt &replace(size_type offset, size_type n0, const _Myt &right, size_type roffset, size_type count=npos);
#ifdef STD_WRAPPER_EXPORT
    _Myt &replace(size_type offset, size_type n0, const _Mybase &right);
    _Myt &replace(size_type offset, size_type n0, const _Mybase &right, size_type roffset, size_type count=npos);
#endif//STD_WRAPPER_EXPORT
    _Myt &replace(size_type offset, size_type n0, const _Elem *ptr, size_type count);
    _Myt &replace(size_type offset, size_type n0, const _Elem *ptr);
    _Myt &replace(size_type offset, size_type n0, size_type count, _Elem ch);
    _Myt &replace(const_iterator first, const_iterator last, const _Myt &right);
#ifdef STD_WRAPPER_EXPORT
    _Myt &replace(const_iterator first, const_iterator last, const _Mybase &right);
#endif//STD_WRAPPER_EXPORT
    _Myt &replace(const_iterator first, const_iterator last, const _Elem *ptr, size_type count);
    _Myt &replace(const_iterator first, const_iterator last, const _Elem *ptr);
    _Myt &replace(const_iterator first, const_iterator last, size_type count, _Elem ch);
#ifdef STD_WRAPPER_EXPORT
    template<class _Iter>
    _Myt &replace(const_iterator first, const_iterator last, _Iter first2, _Iter last2);
#endif//STD_WRAPPER_EXPORT
    _Myt &replace(const_iterator first, const_iterator last, const_pointer first2, const_pointer last2);
    _Myt &replace(const_iterator first, const_iterator last, pointer first2, pointer last2);
    _Myt &replace(const_iterator first, const_iterator last, const_iterator first2, const_iterator last2);
    _Myt &replace(const_iterator first, const_iterator last, iterator first2, iterator last2);

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;
    void shrink_to_fit();

    reference at(size_type offset);
    const_reference at(size_type offset) const;
    reference operator[](size_type offset);
    const_reference operator[](size_type offset) const;
    void push_back(_Elem ch);
    void pop_back();
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    const _Elem *c_str() const noexcept;
    const _Elem *data() const noexcept;
    
#if _HAS_CXX17
    _Elem *data() noexcept;
#endif /* _HAS_CXX17 */

    size_type length() const noexcept;
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    void resize(size_type newsize);
    void resize(size_type newsize, _Elem ch);
    size_type capacity() const noexcept;
    void reserve(size_type newcap=0);

    bool empty() const noexcept;
    
    size_type copy(_Elem *ptr, size_type count, size_type offset=0) const;
    void swap(_Myt &right) noexcept;
#ifdef STD_WRAPPER_EXPORT
    void swap(_Mybase &right) noexcept;
#endif//STD_WRAPPER_EXPORT

    size_type find(const _Myt &right, size_type offset=0) const noexcept;
#ifdef STD_WRAPPER_EXPORT
    size_type find(const _Mybase &right, size_type offset=0) const noexcept;
#endif//STD_WRAPPER_EXPORT
    size_type find(const _Elem *ptr, size_type offset, size_type count) const;
    size_type find(const _Elem *ptr, size_type offset=0) const;
    size_type find(_Elem ch, size_type offset=0) const;

    size_type rfind(const _Myt &right, size_type offset=npos) const noexcept;
#ifdef STD_WRAPPER_EXPORT
    size_type rfind(const _Mybase &right, size_type offset=npos) const noexcept;
#endif//STD_WRAPPER_EXPORT
    size_type rfind(const _Elem *ptr, size_type offset, size_type count) const;
    size_type rfind(const _Elem *ptr, size_type offset=npos) const;
    size_type rfind(_Elem ch, size_type offset=npos) const;

    size_type find_first_of(const _Myt &right, size_type offset=0) const noexcept;
#ifdef STD_WRAPPER_EXPORT
    size_type find_first_of(const _Mybase &right, size_type offset=0) const noexcept;
#endif//STD_WRAPPER_EXPORT
    size_type find_first_of(const _Elem *ptr, size_type offset, size_type count) const;
    size_type find_first_of(const _Elem *ptr, size_type offset=0) const;
    size_type find_first_of(_Elem ch, size_type offset=0) const;

    size_type find_last_of(const _Myt &right, size_type offset=npos) const noexcept;
#ifdef STD_WRAPPER_EXPORT
    size_type find_last_of(const _Mybase &right, size_type offset=npos) const noexcept;
#endif//STD_WRAPPER_EXPORT
    size_type find_last_of(const _Elem *ptr, size_type offset, size_type count) const;
    size_type find_last_of(const _Elem *ptr, size_type offset=npos) const;
    size_type find_last_of(_Elem ch, size_type offset=npos) const;

    size_type find_first_not_of(const _Myt &right, size_type offset=0) const noexcept;
#ifdef STD_WRAPPER_EXPORT
    size_type find_first_not_of(const _Mybase &right, size_type offset=0) const noexcept;
#endif//STD_WRAPPER_EXPORT
    size_type find_first_not_of(const _Elem *ptr, size_type offset, size_type count) const;
    size_type find_first_not_of(const _Elem *ptr, size_type offset=0) const;
    size_type find_first_not_of(_Elem ch, size_type offset=0) const;

    size_type find_last_not_of(const _Myt &right, size_type offset=npos) const noexcept;
#ifdef STD_WRAPPER_EXPORT
    size_type find_last_not_of(const _Mybase &right, size_type offset=npos) const noexcept;
#endif//STD_WRAPPER_EXPORT
    size_type find_last_not_of(const _Elem *ptr, size_type offset, size_type count) const;
    size_type find_last_not_of(const _Elem *ptr, size_type offset=npos) const;
    size_type find_last_not_of(_Elem ch, size_type offset=npos) const;

    _Myt substr(size_type offset=0, size_type count=npos) const;
    
    int compare(const _Myt &right) const noexcept;
    int compare(size_type offset, size_type n0, const _Myt &right) const;
    int compare(size_type offset, size_type n0, const _Myt &right, size_type roffset, size_type count=npos) const;
#ifdef STD_WRAPPER_EXPORT
    int compare(const _Mybase &right) const noexcept;
    int compare(size_type offset, size_type n0, const _Mybase &right) const;
    int compare(size_type offset, size_type n0, const _Mybase &right, size_type roffset, size_type count=npos) const;
#endif//STD_WRAPPER_EXPORT
    int compare(const _Elem *ptr) const;
    int compare(size_type offset, size_type n0, const _Elem *ptr) const;
    int compare(size_type offset, size_type n0, const _Elem *ptr, size_type count) const;

    allocator_type get_allocator() const noexcept;

private:
    std::basic_string<_Elem, _Traits, _Alloc> *_string;
};

typedef basic_string<char, std::char_traits<char>, std::allocator<char> > string;
typedef basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstring;
