#ifndef IVW_COMPOSITEPROPERTY_H
#define IVW_COMPOSITEPROPERTY_H

#include <inviwo/core/inviwocoredefine.h>
#include <inviwo/core/inviwo.h>
#include <inviwo/core/properties/property.h>
#include <inviwo/core/util/observer.h>

namespace inviwo {

class IVW_CORE_API CompositeProperty : public Property, public VoidObserver {

public:
    CompositeProperty(std::string identifier, std::string displayName, PropertySemantics::Type semantics = PropertySemantics::Default);
    virtual ~CompositeProperty();

    void addProperty(Property* property);
    void addProperty(Property& property);
    std::vector<Property*> getSubProperties() { return subProperties_; }
    void setOwner(PropertyOwner* owner);
    void notify();

private:
    std::vector<Property*> subProperties_;
    
};

} // namespace

#endif // IVW_COMPOSITEPROPERTY_H