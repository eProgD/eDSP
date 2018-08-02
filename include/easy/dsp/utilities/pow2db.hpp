/*
 * EasyDSP, A cross-platform Digital Signal Processing library written in modern C++.
 * Copyright (C) 2018 Mohammed Boujemaoui Boulaghmoudi
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
 * You should have received a copy of the GNU General Public License along withº
 * this program.  If not, see <http://www.gnu.org/licenses/>
 *
 * Filename: pow2db.hpp
 * Author: Mohammed Boujemaoui
 * Date: 2/8/2018
 */
#ifndef EASYDSP_POW2DB_HPP
#define EASYDSP_POW2DB_HPP

#include <easy/meta/expects.hpp>
#include <cmath>

namespace easy { namespace dsp {

    template <typename T>
    constexpr T pow2db(T value) noexcept {
        meta::expects(value >= 0, "Expected non negative value");
        return 10 * std::log10(value);
    }
}}

#endif // EASYDSP_POW2DB_HPP