template<class _Mylist, class _IterTy, class _ConstIterTy>
class list_iterator;

template<class _Ty, class _Alloc>
class list;

template<class _Mylist, class _IterTy, class _ConstIterTy>
class list_const_iterator
{
public:
    typedef list_const_iterator<_Mylist, _IterTy, _ConstIterTy> _Myiter;
    typedef list_iterator<_Mylist, _IterTy, _ConstIterTy> _Iter;
    typedef std::bidirectional_iterator_tag iterator_category;

    typedef typename _Mylist::_Nodeptr _Nodeptr;
    typedef typename _Mylist::value_type value_type;
    typedef typename _Mylist::difference_type difference_type;
    typedef typename _Mylist::const_pointer pointer;
    typedef typename _Mylist::const_reference reference;

    list_const_iterator();
//    list_const_iterator(_Nodeptr node, const _Mylist *list);
    list_const_iterator(_Myiter &right);
    list_const_iterator(_Myiter &&right);
    list_const_iterator(_Iter &right);
#ifdef STD_WRAPPER_EXPORT
    list_const_iterator(_ConstIterTy &right);
    list_const_iterator(_IterTy &right);
#endif//STD_WRAPPER_EXPORT
    ~list_const_iterator();

    _Myiter &operator=(const _Myiter &right);
    _Myiter &operator=(_Myiter &&right);
    _Myiter &operator=(const _Iter &right);

    reference operator*() const;
    pointer operator->() const;
    
    _Myiter &operator++();
    _Myiter operator++(int);
    _Myiter &operator--();
    _Myiter operator--(int);

    bool operator==(const _Myiter &right) const;
    bool operator!=(const _Myiter &right) const;

    friend list_iterator<_Mylist, _IterTy, _ConstIterTy>;
    friend list<typename _Mylist::value_type, typename _Mylist::allocator_type>;

private:
    _ConstIterTy *_iter;
};


template<class _Mylist, class _IterTy, class _ConstIterTy>
class list_iterator
{
public:
    typedef list_iterator<_Mylist, _IterTy, _ConstIterTy> _Myiter;
    typedef std::bidirectional_iterator_tag iterator_category;

    typedef typename _Mylist::_Nodeptr _Nodeptr;
    typedef typename _Mylist::value_type value_type;
    typedef typename _Mylist::difference_type difference_type;
    typedef typename _Mylist::const_pointer pointer;
    typedef typename _Mylist::const_reference reference;

    list_iterator();
//    list_iterator(_Nodeptr node, const _Mylist *list);
    list_iterator(_Myiter &right);
    list_iterator(_Myiter &&right);
#ifdef STD_WRAPPER_EXPORT
    list_iterator(_IterTy &right);
#endif//STD_WRAPPER_EXPORT
    ~list_iterator();

    _Myiter &operator=(const _Myiter &right);
    _Myiter &operator=(_Myiter &&right);

    reference operator*() const;
    pointer operator->() const;

    _Myiter &operator++();
    _Myiter operator++(int);
    _Myiter &operator--();
    _Myiter operator--(int);

    bool operator==(const _Myiter &right) const;
    bool operator!=(const _Myiter &right) const;

    friend list_const_iterator<_Mylist, _IterTy, _ConstIterTy>;
    friend list<typename _Mylist::value_type, typename _Mylist::allocator_type>;

private:
    _IterTy *_iter;
};



template<class _Ty, class _Alloc=std::allocator<_Ty> >
class list
{
public:
    typedef list<_Ty, _Alloc> _Myt;
    typedef std::list<_Ty, _Alloc> _Mybase;

    typedef typename _Mybase::_Node _Node;
    typedef typename _Mybase::_Nodeptr _Nodeptr;
    typedef typename _Mybase::_Alty _Alty;

    typedef _Alloc allocator_type;
    typedef typename _Mybase::size_type size_type;
    typedef typename _Mybase::difference_type difference_type;
    typedef typename _Mybase::pointer pointer;
    typedef typename _Mybase::const_pointer const_pointer;
    typedef typename _Mybase::reference reference;
    typedef typename _Mybase::const_reference const_reference;
    typedef typename _Mybase::value_type value_type;

    typedef typename list_const_iterator<_Mybase, typename _Mybase::iterator, typename _Mybase::const_iterator> const_iterator;
    typedef typename list_iterator<_Mybase, typename _Mybase::iterator, typename _Mybase::const_iterator> iterator;
    typedef typename list_const_iterator<_Mybase, typename _Mybase::reverse_iterator, typename _Mybase::const_reverse_iterator> const_reverse_iterator;
    typedef typename list_iterator<_Mybase, typename _Mybase::reverse_iterator, typename _Mybase::const_reverse_iterator> reverse_iterator;

    list();
    explicit list(const _Alloc &alloc);
    explicit list(size_type count);
    list(size_type count, const _Ty &val);
    list(size_type count, const _Ty &val, const _Alloc &alloc);
    list(const _Myt &right);
    list(const _Myt &right, const _Alloc &alloc);
//    template<class _Iter, class=typename enable_if<_Is_iterator<_Iter>::value, void>::type>
//    list(_Iter first, _Iter last);
//    template<class _Iter, class=typename enable_if<_Is_iterator<_Iter>::value, void>::type>
//    list(_Iter first, _Iter last, const _Alloc &alloc);
    list(_Myt &&right);
    list(_Myt &&right, const _Alloc &alloc);
    list(std::initializer_list<_Ty> ilist, const _Alloc &alloc=allocator_type());
#ifdef STD_WRAPPER_EXPORT
    list(_Mybase &right);
    list(_Mybase &&right);
#endif//STD_WRAPPER_EXPORT

    ~list() noexcept;

    _Myt &operator=(_Myt &&right) noexcept;
    _Myt &operator=(std::initializer_list<_Ty> ilist);
    _Myt &operator=(const _Myt &right);
#ifdef STD_WRAPPER_EXPORT
    _Myt &operator=(_Mybase &right) noexcept;
    _Myt &operator=(const _Mybase &right);
    _Myt &operator=(_Mybase &&right) noexcept;
#endif//STD_WRAPPER_EXPORT

    void push_front(_Ty &&val);
    void push_back(_Ty &&val);
    iterator insert(const_iterator where, _Ty &&val);
#ifdef STD_WRAPPER_EXPORT
    template<class... _Valty>
    void emplace_front(_Valty &&... val);
    template<class... _Valty>
    void emplace_back(_Valty &&... val);
    template<class... _Valty>
    iterator emplace(const_iterator where, _Valty &&... val);
#endif//STD_WRAPPER_EXPORT
    void assign(std::initializer_list<_Ty> ilist);
    iterator insert(const_iterator where, std::initializer_list<_Ty> ilist);

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

    void resize(size_type newSize);
    void resize(size_type newSize, const _Ty &val);
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    bool empty() const noexcept;
    allocator_type get_allocator() const noexcept;

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    void push_front(const _Ty &val);
    void pop_front();
    void push_back(const _Ty &val);
    void pop_back();

//    template<class _Iter>
//    typename std::enable_if<_Is_iterator<_Iter>::value, void>::type assign(_Iter first, _Iter last);
    void assign(size_type count, const _Ty &val);
    iterator insert(const_iterator where, const _Ty &val);
    iterator insert(const_iterator where, size_type count, const _Ty &val);
//    template<class _Iter>
//    typename std::enable_if<_Is_iterator<_Iter>::value, iterator>::type insert(const_iterator where, _Iter first, _Iter last);
    iterator erase(const_iterator where);
    iterator erase(const_iterator first, const_iterator last);
    void clear() noexcept;
    void swap(_Myt &right) noexcept;
    void splice(const_iterator where, _Myt &right);
    void splice(const_iterator where, _Myt &&right);
    void splice(const_iterator where, _Myt &right, const_iterator first);
    void splice(const_iterator where, _Myt &&right, const_iterator first);
    void splice(const_iterator where, _Myt &right, const_iterator first, const_iterator last);
    void splice(const_iterator where, _Myt &&right, const_iterator first, const_iterator last);

    void remove(const _Ty &val);
    template<class _Pr1>
    void remove_if(_Pr1 pred);
    void unique();
    template<class _Pr2>
    void unique(_Pr2 pred);

    void merge(_Myt &right);
    void merge(_Myt &&right);
    template<class _Pr2>
    void merge(_Myt &right, _Pr2 pred);
    template<class _Pr2>
    void merge(_Myt &&right, _Pr2 pred);
    
    void sort();
    template<class _Pr2>
    void sort(_Pr2 pred);
    void reverse() noexcept;

    private:
        _Mybase *_list;
};