//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/simd/mask2logical.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD_IF( logical_and_
                             , (typename A0,typename A1,typename X)
                             , (detail::same_size<A0,A1>)
                             , bd::cpu_
                             , bs::pack_<bd::fundamental_<A0>,X>
                             , bs::pack_<bd::fundamental_<A1>,X>
                             )

   {
     using result = bs::as_logical_t<A0>;
     BOOST_FORCEINLINE result operator()(const A0& a0, const A1& a1) const BOOST_NOEXCEPT
     {
       return mask2logical(bitwise_and(genmask(a0), genmask(a1)));
     }
   };
} } }

#endif
