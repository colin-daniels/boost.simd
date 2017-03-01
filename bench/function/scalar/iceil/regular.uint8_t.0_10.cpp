// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor iceil in scalar mode for std::uint8_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/iceil.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_iceil, bs::iceil);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_iceil, std::uint8_t>(0, 10);
}

