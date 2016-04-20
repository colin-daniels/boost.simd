//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/div.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/two.hpp>


STF_CASE_TPL (" div real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(div(bs::Inf<T>(), bs::Inf<T>(), bs::ceil), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::Minf<T>(), bs::Minf<T>(), bs::ceil), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::Nan<T>(), bs::Nan<T>(), bs::ceil), bs::Nan<r_t>());
#endif
  STF_EQUAL(div(T(4),T(0), bs::ceil), bs::Inf<r_t>());
  STF_EQUAL(div(T(4),T(3), bs::ceil), 2);
  STF_EQUAL(div(bs::Mone<T>(), bs::Mone<T>(), bs::ceil), bs::One<r_t>());
  STF_EQUAL(div(bs::Mone<T>(),bs::Zero<T>(), bs::ceil), bs::Minf<r_t>());
  STF_EQUAL(div(bs::One<T>(), bs::One<T>(), bs::ceil), bs::One<r_t>());
  STF_EQUAL(div(bs::One<T>(),bs::Zero<T>(), bs::ceil), bs::Inf<r_t>());
  STF_IEEE_EQUAL(div(bs::Zero<T>(),bs::Zero<T>(), bs::ceil), bs::Nan<r_t>());
} // end of test for floating_

STF_CASE_TPL (" div unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));

  STF_EQUAL(div(T(4),T(0), bs::ceil), bs::Valmax<r_t>());
  STF_EQUAL(div(T(4),T(3), bs::ceil), T(2));
  STF_EQUAL(div(bs::One<T>(), bs::One<T>(), bs::ceil), bs::One<r_t>());
  STF_EQUAL(div(bs::Valmax<T>(),  bs::Two<T>(), bs::ceil), bs::Valmax<r_t>()/bs::Two<T>()+bs::One<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" div signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));

  STF_EQUAL(div(T(-4),T(0), bs::ceil), bs::Valmin<r_t>());
  STF_EQUAL(div(T(4),T(0), bs::ceil), bs::Valmax<r_t>());
  STF_EQUAL(div(T(4),T(3), bs::ceil), T(2));
  STF_EQUAL(div(T(-4),T(-3), bs::ceil), T(2));
  STF_EQUAL(div(T(4),T(-3), bs::ceil), T(-1));
  STF_EQUAL(div(T(-4),T(3), bs::ceil), T(-1));
  STF_EQUAL(div(bs::Mone<T>(), bs::Mone<T>(), bs::ceil), bs::One<r_t>());
  STF_EQUAL(div(bs::One<T>(), bs::One<T>(), bs::ceil), bs::One<r_t>());
} // end of test for signed_int_


