/**
 * Copyright (c) 2014 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#ifndef VEC_H
#define VEC_H

#include <stdlib.h>
#include <string.h>

#define VEC_VERSION "0.2.1"


#define ICE_ArrayUnpack_(v)\
  (char**)&(v)->data, &(v)->length, &(v)->capacity, sizeof(*(v)->data)


#define ICE_Array(T)\
  struct { T *data; int length, capacity; }


#define ICE_Array_init(v)\
  memset((v), 0, sizeof(*(v)))


#define ICE_Array_deinit(v)\
  ( free((v)->data),\
	vec_init(v) ) 


#define ICE_Array_push(v, val)\
  ( vec_expand_(vec_unpack_(v)) ? -1 :\
	((v)->data[(v)->length++] = (val), 0), 0 )


#define ICE_Array_pop(v)\
  (v)->data[--(v)->length]


#define ICE_Array_splice(v, start, count)\
  ( vec_splice_(vec_unpack_(v), start, count),\
	(v)->length -= (count) )


#define ICE_Array_swapsplice(v, start, count)\
  ( vec_swapsplice_(vec_unpack_(v), start, count),\
	(v)->length -= (count) )


#define ICE_Array_insert(v, idx, val)\
  ( vec_insert_(vec_unpack_(v), idx) ? -1 :\
	((v)->data[idx] = (val), 0), (v)->length++, 0 )


#define ICE_Array_sort(v, fn)\
  qsort((v)->data, (v)->length, sizeof(*(v)->data), fn)


#define ICE_Array_swap(v, idx1, idx2)\
  vec_swap_(vec_unpack_(v), idx1, idx2)


#define ICE_Array_truncate(v, len)\
  ((v)->length = (len) < (v)->length ? (len) : (v)->length)


#define ICE_Array_clear(v)\
  ((v)->length = 0)


#define ICE_Array_first(v)\
  (v)->data[0]


#define ICE_Array_last(v)\
  (v)->data[(v)->length - 1]


#define ICE_Array_reserve(v, n)\
  vec_reserve_(vec_unpack_(v), n)


#define ICE_Array_compact(v)\
  vec_compact_(vec_unpack_(v))


#define ICE_Array_pusharr(v, arr, count)\
  do {\
	int i__, n__ = (count);\
	if (vec_reserve_po2_(vec_unpack_(v), (v)->length + n__) != 0) break;\
	for (i__ = 0; i__ < n__; i__++) {\
	  (v)->data[(v)->length++] = (arr)[i__];\
	}\
  } while (0)


#define ICE_Array_extend(v, v2)\
  vec_pusharr((v), (v2)->data, (v2)->length)


#define ICE_Array_find(v, val, idx)\
  do {\
	for ((idx) = 0; (idx) < (v)->length; (idx)++) {\
	  if ((v)->data[(idx)] == (val)) break;\
	}\
	if ((idx) == (v)->length) (idx) = -1;\
  } while (0)


#define ICE_Array_remove(v, val)\
  do {\
	int idx__;\
	vec_find(v, val, idx__);\
	if (idx__ != -1) vec_splice(v, idx__, 1);\
  } while (0)


#define ICE_Array_reverse(v)\
  do {\
	int i__ = (v)->length / 2;\
	while (i__--) {\
	  vec_swap((v), i__, (v)->length - (i__ + 1));\
	}\
  } while (0)


#define ICE_Array_foreach(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = 0;\
		(iter) < (v)->length && (((var) = (v)->data[(iter)]), 1);\
		++(iter))


#define ICE_Array_foreach_rev(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = (v)->length - 1;\
		(iter) >= 0 && (((var) = (v)->data[(iter)]), 1);\
		--(iter))


#define ICE_Array_foreach_ptr(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = 0;\
		(iter) < (v)->length && (((var) = &(v)->data[(iter)]), 1);\
		++(iter))


#define ICE_Array_foreach_ptr_rev(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = (v)->length - 1;\
		(iter) >= 0 && (((var) = &(v)->data[(iter)]), 1);\
		--(iter))



int vec_expand_(char **data, int *length, int *capacity, int memsz);
int vec_reserve_(char **data, int *length, int *capacity, int memsz, int n);
int vec_reserve_po2_(char **data, int *length, int *capacity, int memsz,
	int n);
int vec_compact_(char **data, int *length, int *capacity, int memsz);
int vec_insert_(char **data, int *length, int *capacity, int memsz,
	int idx);
void vec_splice_(char **data, int *length, int *capacity, int memsz,
	int start, int count);
void vec_swapsplice_(char **data, int *length, int *capacity, int memsz,
	int start, int count);
void vec_swap_(char **data, int *length, int *capacity, int memsz,
	int idx1, int idx2);


typedef ICE_Array(void*) vec_void_t;
typedef ICE_Array(char*) vec_str_t;
typedef ICE_Array(int) vec_int_t;
typedef ICE_Array(char) vec_char_t;
typedef ICE_Array(float) vec_float_t;
typedef ICE_Array(double) vec_double_t;

#endif
