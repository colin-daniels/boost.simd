//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <simd_test.hpp>

namespace ba = boost::alignment;
namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  std::size_t alg = p_t::alignment;

  T* a1 = static_cast<T*>(ba::aligned_alloc(alg, (sizeof(T)) * N));
  T* a2 = static_cast<T*>(ba::aligned_alloc(alg, (sizeof(T)) * N));

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = T(27);
    a2[i] = T(i+1);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  bs::aligned_store(aa1, &a2[0]);

  for(std::size_t i=0; i <N ; ++i) STF_EQUAL(a1[i], a2[i]);

  ba::aligned_free(a1);
  ba::aligned_free(a2);
}

STF_CASE_TPL( "Check aligned_store behavior with all types", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
