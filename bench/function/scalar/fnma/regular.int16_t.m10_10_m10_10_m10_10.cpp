// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor fnma in scalar mode for std::int16_t type with pedantic_.
#include <simd_bench.hpp>
#include <boost/simd/function/fnma.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_fnma, bs::pedantic_(bs::fnma));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_fnma, std::int16_t>(-10, 10, -10, 10, -10, 10);
}

