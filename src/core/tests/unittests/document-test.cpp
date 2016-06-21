/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2014-2016 Inviwo Foundation
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

#include <warn/push>
#include <warn/ignore/all>
#include <gtest/gtest.h>
#include <warn/pop>

#include <inviwo/core/common/inviwo.h>
#include <inviwo/core/util/document.h>

#include <iostream>

namespace inviwo {

TEST(DocumentTest, Minimal) {
    Document doc;
    
    using P = Document::Path;
    
    auto w = doc.addElementIn({}, "body", "body").addElementIn("table", "t1").addElementIn("tr", "r1");
    Document d2(doc);
    d2.addElementAfter({P("body"),P("t1")}, "table", "d2");
    Document d3 = doc;
    d3.addElementAfter({P("body"),P("t1")}, "table", "d3");
    
    doc.addElementIn({P("body"), P("t1")}, "tr", "r1");
    doc.addElementIn({P("body"), P("t1")}, "tr", "r1");
    
    doc.addElementIn({P("body"), P("t1"), P::first()}, "td", "nil");
    doc.addElementIn({P("body"), P("t1"), P(-2)}, "td", "-2").setContent("bla bla").addAttribute("key", "balue");
    doc.addElementIn({P("body"), P("t1"), P::last()}, "td", "end");
    
    doc.addElementAfter({P("body"),P("t1")}, "table", "t2");
    
    std::string test = doc;
    
    std::cout << test << std::endl;
    
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    
    EXPECT_STREQ("test", "test");
}



} // namespace

