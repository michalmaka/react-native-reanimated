#pragma once

#ifdef RCT_NEW_ARCH_ENABLED &&REACT_NATIVE_MINOR_VERSION >= 73

#include "PropsRegistry.h"

#include <react/renderer/uimanager/UIManagerMountHook.h>

#include <memory>

namespace reanimated {

using namespace facebook::react;

class ReanimatedMountHook : public UIManagerMountHook {
 public:
  ReanimatedMountHook(
      const std::shared_ptr<PropsRegistry> &propsRegistry,
      const std::shared_ptr<UIManager> &uiManager);
  ~ReanimatedMountHook() noexcept override;

  void shadowTreeDidMount(
      RootShadowNode::Shared const &rootShadowNode,
      double mountTime) noexcept override;

 private:
  std::shared_ptr<PropsRegistry> propsRegistry_;

  std::shared_ptr<UIManager> uiManager_;
};

} // namespace reanimated

#endif // RCT_NEW_ARCH_ENABLED && REACT_NATIVE_MINOR_VERSION >= 73
