#ifndef _std_wrappers_macro_h_
#define _std_wrappers_macro_h_

#define STD_WRAP_SHARED_PTR(EXTERN, EXPORT, TYPE) \
 EXTERN template class EXPORT shared_ptr<TYPE>;

#define STD_WRAP_STRING(EXTERN, EXPORT) STD_WRAP_BASIC_STRING(EXTERN, EXPORT, char)

#define STD_WRAP_BASIC_STRING(EXTERN, EXPORT, TYPE) \
 EXTERN template class EXPORT basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >; \
 EXTERN template class EXPORT basic_string_iterator<std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >, typename std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >::iterator, typename std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >::const_iterator>; \
 EXTERN template class EXPORT basic_string_const_iterator<std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >, typename std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >::iterator, typename std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >::const_iterator>; \
 EXTERN template class EXPORT basic_string_iterator<std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >, typename std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >::reverse_iterator, typename std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >::const_reverse_iterator>; \
 EXTERN template class EXPORT basic_string_const_iterator<std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >, typename std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >::reverse_iterator, typename std::basic_string<TYPE, std::char_traits<TYPE>, std::allocator<TYPE> >::const_reverse_iterator>;


#define STD_WRAP_VECTOR(EXTERN, EXPORT, TYPE) \
 EXTERN template class EXPORT vector<TYPE>; \
 EXTERN template class EXPORT vector_iterator<std::vector<TYPE>, typename std::vector<TYPE>::iterator, typename std::vector<TYPE>::const_iterator>; \
 EXTERN template class EXPORT vector_const_iterator<std::vector<TYPE>, typename std::vector<TYPE>::iterator, typename std::vector<TYPE>::const_iterator>; \
 EXTERN template class EXPORT vector_iterator<std::vector<TYPE>, typename std::vector<TYPE>::reverse_iterator, typename std::vector<TYPE>::const_reverse_iterator>; \
 EXTERN template class EXPORT vector_const_iterator<std::vector<TYPE>, typename std::vector<TYPE>::reverse_iterator, typename std::vector<TYPE>::const_reverse_iterator>;

#define STD_WRAP_VECTOR_ALLOC(EXTERN, EXPORT, TYPE, ALLOC) \
 EXTERN template class EXPORT vector<TYPE, ALLOC>; \
 EXTERN template class EXPORT vector_iterator<std::vector<TYPE, ALLOC>, typename std::vector<TYPE, ALLOC>::iterator, typename std::vector<TYPE, ALLOC>::const_iterator>; \
 EXTERN template class EXPORT vector_const_iterator<std::vector<TYPE, ALLOC>, typename std::vector<TYPE, ALLOC>::iterator, typename std::vector<TYPE, ALLOC>::const_iterator>; \
 EXTERN template class EXPORT vector_iterator<std::vector<TYPE, ALLOC>, typename std::vector<TYPE, ALLOC>::reverse_iterator, typename std::vector<TYPE, ALLOC>::const_reverse_iterator>; \
 EXTERN template class EXPORT vector_const_iterator<std::vector<TYPE, ALLOC>, typename std::vector<TYPE, ALLOC>::reverse_iterator, typename std::vector<TYPE, ALLOC>::const_reverse_iterator>;


#define STD_WRAP_LIST(EXTERN, EXPORT, TYPE) \
 EXTERN template class EXPORT list<TYPE>; \
 EXTERN template class EXPORT list_iterator<std::list<TYPE>, typename std::list<TYPE>::iterator, typename std::list<TYPE>::const_iterator>; \
 EXTERN template class EXPORT list_const_iterator<std::list<TYPE>, typename std::list<TYPE>::iterator, typename std::list<TYPE>::const_iterator>; \
 EXTERN template class EXPORT list_iterator<std::list<TYPE>, typename std::list<TYPE>::reverse_iterator, typename std::list<TYPE>::const_reverse_iterator>; \
 EXTERN template class EXPORT list_const_iterator<std::list<TYPE>, typename std::list<TYPE>::reverse_iterator, typename std::list<TYPE>::const_reverse_iterator>;

#define STD_WRAP_LIST_ALLOC(EXTERN, EXPORT, TYPE, ALLOC) \
 EXTERN template class EXPORT list<TYPE, ALLOC>; \
 EXTERN template class EXPORT list_iterator<std::list<TYPE, ALLOC>, typename std::list<TYPE, ALLOC>::iterator, typename std::list<TYPE, ALLOC>::const_iterator>; \
 EXTERN template class EXPORT list_const_iterator<std::list<TYPE, ALLOC>, typename std::list<TYPE, ALLOC>::iterator, typename std::list<TYPE, ALLOC>::const_iterator>; \
 EXTERN template class EXPORT list_iterator<std::list<TYPE, ALLOC>, typename std::list<TYPE, ALLOC>::reverse_iterator, typename std::list<TYPE, ALLOC>::const_reverse_iterator>; \
 EXTERN template class EXPORT list_const_iterator<std::list<TYPE, ALLOC>, typename std::list<TYPE, ALLOC>::reverse_iterator, typename std::list<TYPE, ALLOC>::const_reverse_iterator>;


#define STD_WRAP_MAP(EXTERN, EXPORT, TYPE1, TYPE2) \
 EXTERN template class EXPORT map<TYPE1, TYPE2>; \
 EXTERN template class EXPORT map_iterator<std::map<TYPE1, TYPE2>, typename std::map<TYPE1, TYPE2>::iterator, typename std::map<TYPE1, TYPE2>::const_iterator>; \
 EXTERN template class EXPORT map_const_iterator<std::map<TYPE1, TYPE2>, typename std::map<TYPE1, TYPE2>::iterator, typename std::map<TYPE1, TYPE2>::const_iterator>; \
 EXTERN template class EXPORT map_iterator<std::map<TYPE1, TYPE2>, typename std::map<TYPE1, TYPE2>::reverse_iterator, typename std::map<TYPE1, TYPE2>::const_reverse_iterator>; \
 EXTERN template class EXPORT map_const_iterator<std::map<TYPE1, TYPE2>, typename std::map<TYPE1, TYPE2>::reverse_iterator, typename std::map<TYPE1, TYPE2>::const_reverse_iterator>;

#endif //_std_wrappers_macro_h_
