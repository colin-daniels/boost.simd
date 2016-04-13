//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/popcnt.hpp>
#include <boost/simd/meta/cardinal_of.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( inbtrue_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::integer_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE std::size_t operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
       using i8type = pack<int8_t, 16>;
       i8type tmp = bitwise_cast<i8type>(genmask(a0));
       return  bs::popcnt(_mm_movemask_epi8(tmp)) * bs::cardinal_of<A0>::value >> 4;
//      return 0;
    }
  };
  BOOST_DISPATCH_OVERLOAD ( inbtrue_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bs::logical_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE std::size_t operator() ( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      using i8type = pack<int8_t, 16>;
      i8type tmp = bitwise_cast<i8type>(genmask(a0));
      return  bs::popcnt(_mm_movemask_epi8(tmp)) * bs::cardinal_of<A0>::value >> 4;
    }
  };
  BOOST_DISPATCH_OVERLOAD ( inbtrue_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE std::size_t operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      int32_t  r = _mm_movemask_pd(genmask(a0));
      return   (r&1)+(r>>1);
    }
  };

} } }

#endif
