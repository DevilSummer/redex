/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "Pass.h"

class AccessMarkingPass : public Pass {
 public:
  AccessMarkingPass() : Pass("AccessMarkingPass") {}

  virtual void configure_pass(const PassConfig& pc) override {
    pc.get("finalize_classes", true, m_finalize_classes);
    pc.get("finalize_methods", true, m_finalize_methods);
    pc.get("privatize_methods", true, m_privatize_methods);
  }

  virtual void run_pass(DexStoresVector&, ConfigFiles&, PassManager&) override;

 private:
  bool m_finalize_classes;
  bool m_finalize_methods;
  bool m_privatize_methods;
};
