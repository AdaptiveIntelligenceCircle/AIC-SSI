#pragma once

#include "module_engine.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace aic::ssi::core {

/** Owns modules and initializes/shuts them down in deterministic order. */
class ModuleRegistry final {
public:
    explicit ModuleRegistry(std::size_t capacity);
    ModuleRegistry(const ModuleRegistry&) = delete;
    ModuleRegistry& operator=(const ModuleRegistry&) = delete;

    Status add(std::unique_ptr<IModule> module);
    Status initialize_all(EngineContext& context);
    Status shutdown_all(EngineContext& context);

    [[nodiscard]] std::size_t size() const noexcept;
    [[nodiscard]] bool initialized() const noexcept;
    [[nodiscard]] std::vector<std::string> module_ids() const;

private:
    std::size_t capacity_;
    bool initialized_{false};
    std::unordered_map<std::string, std::unique_ptr<IModule>> modules_;
    std::vector<std::string> registration_order_;
    std::vector<std::string> initialized_order_;
};

} // namespace aic::ssi::core
