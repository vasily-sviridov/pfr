// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_POSSIBLE_REFLECTABLE_HPP
#define BOOST_PFR_DETAIL_POSSIBLE_REFLECTABLE_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>
#include <boost/pfr/traits_fwd.hpp>

#include <type_traits> // for std::is_aggregate

namespace boost { namespace pfr { namespace detail {

///////////////////// Returns false when the type exactly wasn't be reflectable
template <class T, class WhatFor>
constexpr decltype(is_reflectable<T, WhatFor>::value) possible_reflectable(long) noexcept {
    return is_reflectable<T, WhatFor>::value;
}

template <class T, class WhatFor>
constexpr bool possible_reflectable(int) noexcept {
    using type = std::remove_cv_t<T>;
    // TODO: it should work in C++14
    return std::is_aggregate<type>();
}

}}}

#endif // BOOST_PFR_DETAIL_POSSIBLE_REFLECTABLE_HPP