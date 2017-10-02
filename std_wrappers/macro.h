#ifndef _stl_wrappers_macro_h_
#define _stl_wrappers_macro_h_

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
 EXTERN template class EXPORT vector_iterator<std::vector<TYPE, ALLOC>, typename std::vector<TYPE>::iterator, typename std::vector<TYPE>::const_iterator>; \
 EXTERN template class EXPORT vector_const_iterator<std::vector<TYPE, ALLOC>, typename std::vector<TYPE>::iterator, typename std::vector<TYPE>::const_iterator>; \
 EXTERN template class EXPORT vector_iterator<std::vector<TYPE, ALLOC>, typename std::vector<TYPE>::reverse_iterator, typename std::vector<TYPE>::const_reverse_iterator>; \
 EXTERN template class EXPORT vector_const_iterator<std::vector<TYPE, ALLOC>, typename std::vector<TYPE>::reverse_iterator, typename std::vector<TYPE>::const_reverse_iterator>;

#endif //_stl_wrappers_macro_h_
