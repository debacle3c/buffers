//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/http_proto
//

#ifndef BOOST_BUFFERS_MUTABLE_BUFFER_SPAN_HPP
#define BOOST_BUFFERS_MUTABLE_BUFFER_SPAN_HPP

#include <boost/buffers/detail/config.hpp>
#include <boost/buffers/mutable_buffer.hpp>
#include <iterator>

namespace boost {
namespace buffers {

/** Holds a span of buffers that are modifiable.

    Objects of this type meet the requirements
    of <em>MutableBufferSequence</em>.
*/
class mutable_buffer_span
{
    mutable_buffer const* p_ = nullptr;
    std::size_t n_ = 0;

public:
    /** The type of buffer.
    */
    using value_type = mutable_buffer;

    /** The type of iterators returned.
    */
    using mutable_iterator = value_type const*;

    /** Constructor.
    */
    mutable_buffer_span() = default;

    /** Constructor.
    */
    mutable_buffer_span(
        mutable_buffer const* p,
        std::size_t n) noexcept
        : p_(p)
        , n_(n)
    {
    }

    /** Constructor.
    */
    mutable_buffer_span(
        mutable_buffer_span const&) = default;

    /** Assignment.
    */
    mutable_buffer_span& operator=(
        mutable_buffer_span const&) = default;

    /** Return an iterator to the beginning.
    */
    mutable_iterator
    begin() const noexcept
    {
        return p_;
    }

    /** Return an iterator to the end.
    */
    mutable_iterator
    end() const noexcept
    {
        return p_ + n_;
    }
};

} // buffers
} // boost

#endif
