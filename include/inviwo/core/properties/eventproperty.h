/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 * Version 0.6b
 *
 * Copyright (c) 2013-2014 Inviwo Foundation
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
 * Contact: Sathish Kottravel
 *
 *********************************************************************************/

#ifndef IVW_EVENTPROPERTY_H
#define IVW_EVENTPROPERTY_H

#include <inviwo/core/interaction/action.h>
#include <inviwo/core/interaction/events/interactionevent.h>
#include <inviwo/core/properties/property.h>

namespace inviwo {

/** class EventProperty
 *
 * Property which contains one event and one action to represent the current key binding for the
 *contained action.
 * @see EventPropertyWidgetQt
 */
class IVW_CORE_API EventProperty : public Property {
public:
    InviwoPropertyInfo();
    /**
     * \brief Constructor used to create a new action-key binding.
     *
     * The constructor creates a new binding between a specified action and event.
     *
     * @param std::string identifier
     * @param std::string displayName
     * @param Event e The key or mouse event to bind to an action
     * @param Action action The action to be bound to an event
     * @param PropertySemantics semantics
     */
    EventProperty(
        std::string identifier, std::string displayName, InteractionEvent* e, Action* action,
        PropertyOwner::InvalidationLevel invalidationLevel = PropertyOwner::INVALID_OUTPUT,
        PropertySemantics semantics = PropertySemantics::Default);

    EventProperty(const EventProperty& rhs);
    EventProperty& operator=(const EventProperty& that);
    virtual EventProperty* clone() const;
    virtual ~EventProperty();

    /**
     * \brief Maps action to new event.
     * Changes the current action-to-key binding by replacing the old event with a new
     */
    void setEvent(InteractionEvent* e);
    InteractionEvent* getEvent() const;
    
    void setAction(Action* action);
    Action* getAction() const;
    
    virtual void setCurrentStateAsDefault();
    virtual void resetToDefaultState();

    virtual void serialize(IvwSerializer& s) const;
    virtual void deserialize(IvwDeserializer& d);

private:
    InteractionEvent* event_;           //< owning reference
    InteractionEvent* defaultEvent_;    //< owning reference
    Action* action_;                    //< owning reference
};

}  // namespace

#endif  // IVW_EVENTPROPERTY_H
