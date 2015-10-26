//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVROUND2EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the round2even of the division.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = divround2even(x, y);
    @endcode

    The code is similar to:

    @code
    T r = round2even(x/y);
    @endcode

    for integral types, if y is null, it returns Valmax or Valmin
    if x is positive (resp. negative) and 0 if x is null.
    Take also care that dividing Valmin by -1 for signed integral types has
    undefined behaviour.

    @see  divides, rec, divs, divfloor,
    divceil, divround, divfix

    @return      a value of the same type as the input.


**/
  template<typename T> auto divround2even(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::divround2even

      @see simd::divround2even
    **/
    const boost::dispatch::functor<tag::divround2even_> divround2even = {};
  }
} }
#endif

#include <boost/simd/function/definition/divround2even.hpp>
#include <boost/simd/arch/common/scalar/function/divround2even.hpp>
//#include <boost/simd/arch/common/function/simd/divround2even.hpp>

#endif
