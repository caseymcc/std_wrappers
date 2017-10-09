template<class _Myvec, class _IterTy, class _ConstIterTy>
class map_iterator;

template<class _Kty, class _Ty, class _Pr, class _Alloc>
class map;

template<class _Mymap, class _IterTy, class _ConstIterTy>
class map_const_iterator
{
public:
    typedef map_const_iterator<_Mymap, _IterTy, _ConstIterTy> _Myiter;
    typedef map_iterator<_Mymap, _IterTy, _ConstIterTy> _Iter;
    typedef _ConstIterTy _Mybase;

    typedef std::bidirectional_iterator_tag iterator_category;
    typedef typename _Mybase::value_type value_type;
    typedef typename _Mybase::difference_type difference_type;
    typedef typename _Mybase::pointer pointer;
    typedef typename _Mybase::reference reference;

#ifdef STD_WRAPPER_EXPORT
    map_const_iterator(const typename _ConstIterTy &iter);
#endif//STD_WRAPPER_EXPORT
    map_const_iterator(const _Myiter &right);
    map_const_iterator(_Myiter &&right);
    map_const_iterator(const _Iter &right);

    reference operator*() const;
    pointer operator->() const;
    _Myiter &operator++();
    _Myiter operator++(int);
    _Myiter &operator--();
    _Myiter operator--(int);
    bool operator==(const _Myiter &right) const;
    bool operator!=(const _Myiter &right) const;

    friend map_iterator<_Mymap, _IterTy, _ConstIterTy>;
    friend map<typename _Mymap::key_type, typename _Mymap::mapped_type, typename _Mymap::key_compare, typename _Mymap::allocator_type>;

private:
    _Mybase *_iter;
};


template<class _Mymap, class _IterTy, class _ConstIterTy>
class map_iterator
{
public:
    typedef map_iterator<_Mymap, _IterTy, _ConstIterTy> _Myiter;
    typedef _IterTy _Mybase;

    typedef std::bidirectional_iterator_tag iterator_category;
    typedef typename _Mybase::value_type value_type;
    typedef typename _Mybase::difference_type difference_type;
    typedef typename _Mybase::pointer pointer;
    typedef typename _Mybase::reference reference;

#ifdef STD_WRAPPER_EXPORT
    map_iterator(const typename _IterTy &iter);
#endif//STD_WRAPPER_EXPORT
    map_iterator(const _Myiter &right);
    map_iterator(_Myiter &&right);

    reference operator*() const;
    pointer operator->() const;
    _Myiter &operator++();
    _Myiter operator++(int);
    _Myiter &operator--();
    _Myiter operator--(int);
    bool operator==(const _Myiter &right) const;
    bool operator!=(const _Myiter &right) const;

    friend map_const_iterator<_Mymap, _IterTy, _ConstIterTy>;
    friend map<typename _Mymap::key_type, typename _Mymap::mapped_type, typename _Mymap::key_compare, typename _Mymap::allocator_type>;

private:
    _Mybase *_iter;
};


template<class _Kty, class _Ty, class _Pr=std::less<_Kty>, class _Alloc=std::allocator<std::pair<const _Kty, _Ty> > >
class map
{
public:
    typedef map<_Kty, _Ty, _Pr, _Alloc> _Myt;
    typedef std::map<_Kty, _Ty, _Pr, _Alloc> _Mybase;

    typedef _Kty key_type;
    typedef _Ty mapped_type;
    typedef _Pr key_compare;
    
    typedef typename _Mybase::value_compare value_compare;
    typedef typename _Mybase::allocator_type allocator_type;
    typedef typename _Mybase::size_type size_type;
    typedef typename _Mybase::difference_type difference_type;
    typedef typename _Mybase::pointer pointer;
    typedef typename _Mybase::const_pointer const_pointer;
    typedef typename _Mybase::reference reference;
    typedef typename _Mybase::const_reference const_reference;
    typedef typename map_iterator<_Mybase, typename _Mybase::iterator, typename _Mybase::const_iterator> iterator;
    typedef typename map_const_iterator<_Mybase, typename _Mybase::iterator, typename _Mybase::const_iterator> const_iterator;
    typedef typename map_iterator<_Mybase, typename _Mybase::reverse_iterator, typename _Mybase::const_reverse_iterator> reverse_iterator;
    typedef typename map_const_iterator<_Mybase, typename _Mybase::reverse_iterator, typename _Mybase::const_reverse_iterator> const_reverse_iterator;
    typedef typename _Mybase::value_type value_type;

    typedef typename _Mybase::_Alty _Alty;
    typedef typename _Mybase::_Pairib _Pairib;
    typedef typename _Mybase::_Pairii _Pairii;
    typedef typename _Mybase::_Paircc _Paircc;

    map();
    explicit map(const allocator_type &alloc);
    map(const _Myt &right);
    map(const _Myt &right, const allocator_type &alloc);
    explicit map(const key_compare &pred);
    map(const key_compare &pred, const allocator_type &alloc);

#ifdef STD_WRAPPER_EXPORT
    map(const _Mybase &right);
    map(const _Mybase &&right);

    template<class _Iter>
    map(_Iter first, _Iter last);
    template<class _Iter>
    map(_Iter first, _Iter last, const key_compare &pred);
    template<class _Iter>
    map(_Iter first, _Iter last, const key_compare &pred, const allocator_type &alloc);
#endif//STD_WRAPPER_EXPORT
    
    _Myt &operator=(const _Myt &right);
    map(_Myt&& right);
    map(_Myt&& right, const allocator_type &alloc);
    _Myt &operator=(_Myt&& right) noexcept;
#ifdef STD_WRAPPER_EXPORT
    _Myt &operator=(const _Mybase &right);
    _Myt &operator=(const _Mybase &&right);
#endif//STD_WRAPPER_EXPORT
    mapped_type& operator[](key_type &&keyVal);
    void swap(_Myt &right);

#ifdef STD_WRAPPER_EXPORT
    template<class _Valty, class=enable_if_t<is_constructible<value_type, _Valty>::value> >
    _Pairib insert(_Valty &&val);
    template<class _Valty, class=enable_if_t<is_constructible<value_type, _Valty>::value> >
    iterator insert(const_iterator where, _Valty &&val);

    template<class... _Mappedty>
    _Pairib try_emplace(const key_type &keyVal, _Mappedty&&... mapVal);
    template<class... _Mappedty>
    iterator try_emplace(const_iterator, const key_type &keyVal, _Mappedty&&... mapVal);
    template<class... _Mappedty>
    _Pairib try_emplace(key_type &&keyVal, _Mappedty&&... mapVal);
    template<class... _Mappedty>
    iterator try_emplace(const_iterator, key_type &&keyVal, _Mappedty&&... mapVal);

    template<class _Mappedty>
    _Pairib insert_or_assign(const key_type &keyVal, _Mappedty &&mapVal);
    template<class _Mappedty>
    iterator insert_or_assign(const_iterator, const key_type &keyVal, _Mappedty &&mapVal);
    template<class _Mappedty>
    _Pairib insert_or_assign(key_type &&keyVal, _Mappedty &&mapVal);
    template<class _Mappedty>
    iterator insert_or_assign(const_iterator, key_type &&keyVal, _Mappedty &&mapVal);
#endif//STD_WRAPPER_EXPORT    

    map(std::initializer_list<value_type> ilist);
    map(std::initializer_list<value_type> ilist, const key_compare &pred);
    map(std::initializer_list<value_type> ilist, const key_compare &pred, const allocator_type &alloc);

    _Myt &operator=(std::initializer_list<value_type> ilist);
    mapped_type& operator[](const key_type &keyVal);
    mapped_type& at(const key_type &keyVal);
    const mapped_type& at(const key_type &keyVal) const;

//tree
#ifdef STD_WRAPPER_EXPORT
    template<class... _Valty>
    _Pairib emplace(_Valty&&... val);
    template<class... _Valty>
    iterator emplace_hint(const_iterator where, _Valty&&... val);
#endif//STD_WRAPPER_EXPORT
    
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

    size_type size() const noexcept;
    size_type max_size() const noexcept;
    bool empty() const noexcept;
    
    allocator_type get_allocator() const noexcept;
    key_compare key_comp() const;
    value_compare value_comp() const;
    
    _Pairib insert(const value_type &val);
    _Pairib insert(value_type&& val);
    iterator insert(const_iterator where, const value_type &val);
    iterator insert(const_iterator where, value_type&& val);
#ifdef STD_WRAPPER_EXPORT
    template<class _Iter>
    void insert(_Iter first, _Iter last);
#endif//STD_WRAPPER_EXPORT
    void insert(std::initializer_list<value_type> ilist);
    
    iterator erase(const_iterator where);
    iterator erase(const_iterator first, const_iterator last);
    size_type erase(const key_type &keyVal);
    
    void clear() noexcept;
    
    iterator find(const key_type &keyVal);
    const_iterator find(const key_type &keyVal) const;
#ifdef STD_WRAPPER_EXPORT
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
    iterator find(const _Other &keyVal);
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
    const_iterator find(const _Other &keyVal) const;
#endif//STD_WRAPPER_EXPORT

    size_type count(const key_type &keyVal) const;
#ifdef STD_WRAPPER_EXPORT
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent> 
    size_type count(const _Other &keyVal) const;
#endif//STD_WRAPPER_EXPORT

    iterator lower_bound(const key_type &keyVal);
    const_iterator lower_bound(const key_type &keyVal) const;
#ifdef STD_WRAPPER_EXPORT
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
    iterator lower_bound(const _Other &keyVal);
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
    const_iterator lower_bound(const _Other &keyVal) const;
#endif//STD_WRAPPER_EXPORT
    
    iterator upper_bound(const key_type &keyVal);
    const_iterator upper_bound(const key_type &keyVal) const;
#ifdef STD_WRAPPER_EXPORT
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
    iterator upper_bound(const _Other &keyVal);
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
    const_iterator upper_bound(const _Other &keyVal) const;
#endif//STD_WRAPPER_EXPORT
    
    _Pairii equal_range(const key_type &keyVal);
    _Paircc equal_range(const key_type &keyVal) const;
#ifdef STD_WRAPPER_EXPORT
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent> 
    _Pairii equal_range(const _Other &keyVal);
    template<class _Other, class _Mycomp=key_compare, class=typename _Mycomp::is_transparent>
    _Paircc equal_range(const _Other &keyVal) const;
#endif//STD_WRAPPER_EXPORT

private:
    _Mybase *_map;
};
