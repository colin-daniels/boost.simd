//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLATTED_SUM_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLATTED_SUM_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
//#include <boost/simd/function/simd/all_reduce.hpp>
#include <boost/simd/function/simd/plus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(splatted_sum_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
   {
     BOOST_FORCEINLINE A0 operator()(A0 const& a0) const
      {
        return a0; //TODO all_reduce<bs::plus_>(a0);
      }
   };

} } }

#endif

