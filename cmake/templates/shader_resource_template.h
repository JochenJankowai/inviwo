// clang-format off
#ifndef @U_MODULE@_SHADER_RESOURCE
#define @U_MODULE@_SHADER_RESOURCE

#include <modules/opengl/shader/shadermanager.h>

@ADD_INCLUDES@

namespace inviwo {

namespace @L_MODULE@ {

inline void addGeneratedShaderResources([[maybe_unused]] ShaderManager* manager) {
@ADD_RESOURCES@
}

inline void addShaderResources(ShaderManager* manager, std::vector<std::string> includePaths) {
#ifdef @U_MODULE@_INCLUDE_SHADER_RESOURCES
    addGeneratedShaderResources(manager);
#else
    for (auto& includePath : includePaths) {
        manager->addShaderSearchPath(includePath);
    }
#endif
}
// clang-format on
}  // namespace

}  // namespace

#endif
