# 2. Iterator Facade

Date: 2023-10-06

## Status

Accepted

## Context

Writing stl complain iterators is a troublesome adventure. The introduction of 
a facade will minimize the needed effort to write iterators and would avoid 
hard-to-detect errors in the long run. A variety of implementations for such a 
facade are already available:

* [Proposal: `std::iterator_interface`](https://wg21.link/p2727r1)
* [Code: `boost::iterator_interface`](https://github.com/boostorg/stl_interfaces)
* [Code: `boost::iterator_facade`](https://github.com/boostorg/iterator)
* [Blog: An `iterator_facade` in C++20](https://vector-of-bool.github.io/2020/06/13/cpp20-iter-facade.html)

## Decision

Introduce an iterator facade before implementing any containers to reduce the 
implementation and maintenance effort in the long run.

## Consequences

Using an iterator facade would create a dependency between most 
iterators and algorithms. Also, the compile time will suffer 
because of the additional template instances needed.
