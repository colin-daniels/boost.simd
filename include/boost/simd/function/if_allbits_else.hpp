//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If a0 is true returns allbits else returns a1

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T1 r = if_allbits_else(a0,a1);
    @endcode

    is similar to:

    @code
    T r = a0 ? Allbits : a1;
    @endcode

    @par Alias:
    @c if_allbits_else,
    @c ifallbitselse,
    @c ifnot_else_allbits,
    @c ifnotelseallbits,
    @c if_nan_else,
    @c ifnanelse,
    @c ifnot_else_nan,
    @c ifnotelsenan

    @see genmask


    @return a value of the same type as the second parameter

**/
  template<typename T> auto if_allbits_else(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::if_allbits_else

      @see simd::if_allbits_else
    **/
    const boost::dispatch::functor<tag::if_allbits_else_> if_allbits_else = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_allbits_else.hpp>
#include <boost/simd/arch/common/scalar/function/if_allbits_else.hpp>
//#include <boost/simd/arch/common/function/simd/if_allbits_else.hpp>

#endif
