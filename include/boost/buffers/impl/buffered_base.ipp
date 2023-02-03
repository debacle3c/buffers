//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/http_proto
//

#include <boost/buffers/buffered_base.hpp>

namespace boost {
namespace buffers {

buffered_base::
~buffered_base() = default;

void
buffered_base::
init(allocator&)
{
    // do nothing
}

void
buffered_base::
init(
    allocator& a,
    std::size_t max_size)
{
    // max_size exceeds limit
    if(max_size > a.max_size())
        detail::throw_invalid_argument();

    auto const n =
        a.max_size() - max_size;
    a.remove(n);
    a.restore(n);
}

void*
buffered_base::
allocator::
allocate(
    std::size_t n)
{
    // n exceeds available space
    if(n > size_)
        detail::throw_invalid_argument();

    size_used_ += n;
    if(down_)
    {
        auto p = base_ + size_ - n;
        size_ -= n;
        return p;
    }
    auto p = base_;
    base_ += n;
    size_ -= n;
    return p;
}

} // buffers
} // boost