/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 23:30:13 by zkasmi            #+#    #+#             */
/*   Updated: 2023/01/03 23:19:41 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COMMON_HPP
#define COMMON_HPP

#define BLACK 0
#define RED 1


#include <memory>
#include <limits>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <cstddef>
#include <math.h>


// std utils

#include <equal.hpp>
#include <lexicographical_compare.hpp>
#include <is_integral.hpp>
#include <pair.hpp>
#include <enable_if.hpp>
#include <iterator_traits.hpp>
#include <reverse_iterator.hpp>

#include <rd_node.hpp>

#include <red_black_tree.hpp>
#include <map_iterator.hpp>

#include <set_rbtree.hpp>


using std::allocator;
using std::cout;
using std::endl;
using std::ostream;

#endif