/**
 * eDSP, A cross-platform Digital Signal Processing library written in modern C++.
 * Copyright (c) 2018 All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * File: spectral_entropy.hpp
 * Created by: Mohammed Boujemaoui Boulaghmoudi
 * Created at: 14/10/18
 */

#ifndef EDSP_SPECTRAL_ENTROPY_HPP
#define EDSP_SPECTRAL_ENTROPY_HPP

#include <edsp/statistics/entropy.hpp>
#include <functional>
#include <algorithm>

namespace edsp { namespace feature { inline namespace spectral {

    /**
     * @brief Computes the spectral entropy of the of the power spectral density represented by the elements in the range [first, last)
     *
     * Spectral Entropy describes the complexity of a system. The PSD of a audio signal can be computed
     * as the normalized version of the Power Spectral Density:
     *
     * \f[
     *  p_i=\dfrac{P(\omega_i)}{\sum_iP(\omega_i)}
     * \f]
     *
     * The Power Spectral entropy can be now calculated using a standard formula for an entropy calculation.
     *
     * @warning This function normalize/modifies the input range.
     * @param first Forward iterator defining the begin of the magnitude spectrum.
     * @param last Forward iterator defining the end of the magnitude spectrum.
     * @param first2 Forward iterator defining the begin of the center frequencies range.
     * @return Estimated spectral entropy.
     * @see entropy
     */
    template <typename ForwardIt>
    constexpr auto spectral_centroid(ForwardIt first, ForwardIt last) {
        using value_type = typename std::iterator_traits<ForwardIt>::value_type ;
        const auto acc = std::accumulate(first, last, static_cast<value_type >(0));
        std::for_each(first, last, std::bind(std::multiplies<value_type>(), std::placeholders::_1, acc));
        return statistics::entropy(first, last);
    }

}}}
#endif //EDSP_SPECTRAL_ENTROPY_HPP
