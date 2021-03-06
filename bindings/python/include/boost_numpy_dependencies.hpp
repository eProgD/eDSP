/*
* eDSP, A cross-platform Digital Signal Processing library written in modern C++.
* Copyright (C) 2019 Mohammed Boujemaoui Boulaghmoudi, All rights reserved.
*
* This program is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along width
* this program.  If not, see <http://www.gnu.org/licenses/>
*
* Filename: algorithm.hpp
* Author: Mohammed Boujemaoui
* Date: 30/03/19
*/

#ifndef EDSP_BOOST_NUMPY_DEPENDENCIES_HPP
#define EDSP_BOOST_NUMPY_DEPENDENCIES_HPP

#ifdef USE_BOOST_NUMPY_DEPRECATED
#    include <boost/python.hpp>
#    include <boost/numpy.hpp>
#include <boost/python/def.hpp>

namespace bp = boost::python;
namespace bn = boost::numpy;
#else
#    include <boost/python.hpp>
#    include <boost/python/numpy.hpp>
#include <boost/python/def.hpp>


namespace bp = boost::python;
namespace bn = boost::python::numpy;
#endif

#endif //EDSP_BOOST_NUMPY_DEPENDENCIES_HPP
