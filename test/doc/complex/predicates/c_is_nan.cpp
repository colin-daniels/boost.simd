//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [is_nan]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/is_nan.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using cp_t = bs::complex<p_t>;

int main() {
  cp_t pf{p_t{1.0f, 2.0f, -1.0f, bs::Nan<float>()}, p_t{0.0, bs::Nan<float>(), -1.0, 3.0}};

  std::cout << "---- simd" << '\n'
            << "<- pf =                " << pf << '\n'
            << "-> bs::is_nan(pf) = " << bs::is_nan(pf) << '\n';

  bs::complex<float> xf{1, bs::Nan<float>()};

  std::cout << "---- scalar" << '\n'
            << "<- xf =                " << xf << '\n'
            << "-> bs::is_nan(xf) = " << bs::is_nan(xf) << '\n';
  return 0;
}
//! [is_nan]