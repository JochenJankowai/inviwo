/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2015-2017 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/

#ifndef IVW_VOLUMESEQUENCEUTILS_H
#define IVW_VOLUMESEQUENCEUTILS_H

#include <inviwo/core/common/inviwocoredefine.h>
#include <inviwo/core/common/inviwo.h>

namespace inviwo {

    class Volume;
    using SharedVolume = std::shared_ptr<Volume>;
    using VoumeSequence = std::vector<SharedVolume>;

    namespace util {

        bool IVW_CORE_API hasTimestamps(const VoumeSequence &seq,bool checkfirstonly = true);


        std::pair<double, double> IVW_CORE_API getTimestampRange(const VoumeSequence &seq, bool sorted = true);

        bool IVW_CORE_API isSorted(const VoumeSequence &seq);
        VoumeSequence IVW_CORE_API sortSequence(const VoumeSequence &seq);

        std::pair<SharedVolume, SharedVolume> IVW_CORE_API getVolumesForTimestep(const VoumeSequence &seq, double t, bool sorted = true);


        bool IVW_CORE_API hasTimestamp(SharedVolume vol);
        double IVW_CORE_API getTimestamp(SharedVolume vol);
    }

} // namespace

#endif // IVW_VOLUMESEQUENCEUTILS_H

