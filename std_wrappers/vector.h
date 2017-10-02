template<class _Myvec, class _IterTy, class _ConstIterTy>
class vector_iterator;

template<class _Ty, class _Alloc>
class vector;

template<class _Myvec, class _IterTy, class _ConstIterTy>
class vector_const_iterator
{
public:
    typedef vector_const_iterator<_Myvec, _IterTy, _ConstIterTy> _Myiter;
    typedef vector_iterator<_Myvec, _IterTy, _ConstIterTy> _Iter;

    typedef std::random_access_iterator_tag iterator_category;
    typedef typename _Myvec::value_type value_type;
    typedef typename _Myvec::difference_type difference_type;
    typedef typename _Myvec::const_pointer pointer;
    typedef typename _Myvec::const_reference reference;

#ifdef STD_WRAPPER_EXPORT
    vector_const_iterator(const typename _ConstIterTy &iter);
#endif//STD_WRAPPER_EXPORT
    vector_const_iterator(const _Myiter &right);
    vector_const_iterator(_Myiter &&right);
    vector_const_iterator(const _Iter &right);

//    vector_const_iterator(typename _ConstIterTy &&iter);
    ~vector_const_iterator();

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

    friend vector_iterator<_Myvec, _IterTy, _ConstIterTy>;
    friend vector<typename _Myvec::value_type, typename _Myvec::allocator_type>;

private:
    typename _ConstIterTy *_constIter;
};


template<class _Myvec, class _IterTy, class _ConstIterTy>
class vector_iterator//:public vector_const_iterator<_Myvec, _IterTy, _ConstIterTy>
{
public:
    typedef vector_iterator<_Myvec, _IterTy, _ConstIterTy> _Myiter;
    typedef vector_const_iterator<_Myvec, _IterTy, _ConstIterTy> _ConstIter;

    typedef std::random_access_iterator_tag iterator_category;
    typedef typename _Myvec::value_type value_type;
    typedef typename _Myvec::difference_type difference_type;
    typedef typename _Myvec::pointer pointer;
    typedef typename _Myvec::reference reference;

#ifdef STD_WRAPPER_EXPORT
    vector_iterator(const typename _IterTy &iter);
#endif//STD_WRAPPER_EXPORT
    vector_iterator(const _Myiter &right);
    vector_iterator(_Myiter &&right);
//    vector_iterator(typename _IterTy &&iter);

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

    friend vector_const_iterator<_Myvec, _IterTy, _ConstIterTy>;

private:
    typename _IterTy *_iter;
};

template<class _Ty, class _Alloc=std::allocator<_Ty> >
class vector
{
public:
    typedef vector<_Ty, _Alloc> _Myt;
    typedef std::vector<_Ty, _Alloc> _StdTy;

    typedef typename std::vector<_Ty, _Alloc>::value_type value_type;
    typedef typename std::vector<_Ty, _Alloc>::allocator_type allocator_type;
    typedef typename std::vector<_Ty, _Alloc>::size_type size_type;
    typedef typename std::vector<_Ty, _Alloc>::difference_type difference_type;

    typedef typename std::vector<_Ty, _Alloc>::reference reference;
    typedef typename std::vector<_Ty, _Alloc>::const_reference const_reference;
    typedef typename std::vector<_Ty, _Alloc>::pointer pointer;
    typedef typename std::vector<_Ty, _Alloc>::const_pointer const_pointer;

    typedef vector_iterator<_StdTy, typename _StdTy::iterator, typename _StdTy::const_iterator> iterator;
    typedef vector_const_iterator<_StdTy, typename _StdTy::iterator, typename _StdTy::const_iterator> const_iterator;
    typedef vector_iterator<_StdTy, typename _StdTy::reverse_iterator, typename _StdTy::const_reverse_iterator> reverse_iterator;
    typedef vector_const_iterator<_StdTy, typename _StdTy::reverse_iterator, typename _StdTy::const_reverse_iterator> const_reverse_iterator;

public:
    vector() noexcept;
#ifdef STD_WRAPPER_EXPORT
    explicit vector(const _Alloc &alloc) noexcept;
#endif//STD_WRAPPER_EXPORT
    explicit vector(size_type count);
    vector(size_type count, const value_type &value);
#ifdef STD_WRAPPER_EXPORT
    vector(size_type count, const value_type &value, const _Alloc &alloc=std::allocator<_Ty>);
    template<class InputIt> vector(InputIt first, InputIt last, const _Alloc &alloc=std::allocator<_Ty>)
    { _vector=new std::vector<_Ty, _Alloc>(first, last, alloc); }
#endif//STD_WRAPPER_EXPORT
    vector(const _Myt &right);
#ifdef STD_WRAPPER_EXPORT
    vector(const _Myt &right, const _Alloc &alloc);
#endif//STD_WRAPPER_EXPORT
    vector(_Myt &&right) noexcept;
#ifdef STD_WRAPPER_EXPORT
    vector(_Myt &&right, const _Alloc &alloc);
    vector(const _StdTy &right);
    vector(const _StdTy &right, const _Alloc &alloc);
    vector(_StdTy &&right) noexcept;
    vector(_StdTy &&right, const _Alloc &alloc);
#endif//STD_WRAPPER_EXPORT

    ~vector();

    vector &operator=(const _Myt &other);
    vector &operator=(_Myt &&other);
#ifdef STD_WRAPPER_EXPORT
    vector &operator=(const _StdTy &other);
    vector &operator=(_StdTy &&other);
#endif//STD_WRAPPER_EXPORT
    vector &operator=(std::initializer_list<_Ty> ilist);

    void assign(size_type count, const _Ty &value);
#ifdef STD_WRAPPER_EXPORT
    template< class InputIt> void assign(InputIt first, InputIt last) { _vector->assign(first, last); }
#endif//STD_WRAPPER_EXPORT
    void assign(std::initializer_list<_Ty> ilist);

    reference at(size_type pos);
    const_reference at(size_type pos) const;

    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

    reference front();
    const_reference front() const;

    reference back();
    const_reference back() const;

    _Ty *data() noexcept;
    const _Ty *data() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;

    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;

    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const;
    const_reverse_iterator crbegin() const noexcept;

    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;

    bool empty() const noexcept;
    size_type size() const noexcept;
    void reserve(size_type new_cap);
    void clear() noexcept;

    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);

    void push_back(const _Ty &value);
    void push_back(_Ty &&value);

    void resize(size_type count);
    void resize(size_type count, const value_type& value);

private:
    std::vector<_Ty, _Alloc> *_vector;
};

