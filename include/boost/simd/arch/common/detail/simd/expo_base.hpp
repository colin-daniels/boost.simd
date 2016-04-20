//==================================================================================================
/*!
  @file

  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_DETAIL_SIMD_EXPO_BASE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_DETAIL_SIMD_EXPO_BASE_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/simd/if_allbits_else.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#endif

#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/if_zero_else.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/arch/common/detail/scalar/expo_reduction.hpp>
#include <boost/simd/arch/common/detail/scalar/expo_scale.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    namespace bs = boost::simd;
    template < class A0, class Tag>
    struct exponential < A0, Tag, tag::simd_type, double>
    {
      typedef exp_reduction<A0,Tag>                        reduc_t;
      // compute exp(ax)
      static inline A0 expa(const A0& a0)
      {
        A0 hi, lo, x;
        A0 k = reduc_t::reduce(a0, hi, lo, x);
        A0 c = reduc_t::approx(x);
        c = reduc_t::finalize(x, c, hi, lo);
        c = bs::if_zero_else(reduc_t::isleminlog(a0), scale(c, k));
        c = bs::if_else(reduc_t::isgemaxlog(a0), bs::Inf<A0>(), c);
#ifdef BOOST_SIMD_NO_INVALIDS
        return c;
#else
        return if_allbits_else(is_nan(a0), c);
#endif
      }
    };

    template < class A0, class Tag >
    struct exponential < A0, Tag, tag::simd_type, float>
    {
      typedef exp_reduction<A0,Tag>                        reduc_t;
      // compute exp(ax)
      static inline A0 expa(const A0& a0)
      {
        A0 x;
        A0 k = reduc_t::reduce(a0, x);
        x = reduc_t::approx(x);
        x = bs::if_zero_else(reduc_t::isleminlog(a0), scale(x, k));
        x = bs::if_else(reduc_t::isgemaxlog(a0), bs::Inf<A0>(), x);
#ifdef BOOST_SIMD_NO_INVALIDS
        return x;
#else
        return if_allbits_else(is_nan(a0), x);
#endif
      }
    };

  }
} }


#endif
