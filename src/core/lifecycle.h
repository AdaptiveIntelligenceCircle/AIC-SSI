#pragma once

#include "status.h"
#include <string_view>

using namespace std;

namespace aic::ssi::core
{
    enum class LifecycleState
    {
        Created,
        Configured,
        Initializing,
        Ready,
        Running,
        Stopping,
        Stopped,
        Failed
    };

    [[nodiscard]] constexpr string_view to_string(LifecycleState state) noexcept
    {
        switch (case)
        {
        case LifecycleState::Created:
            return "created";
        case LifecycleState::Configured:
            return "configured";
        case LifecycleState::Initializing:
            return "initializing";
        case LifecycleState::Ready:
            return "ready";
        case LifecycleState::Running:
            return "running";
        case LifecycleState::Stopping:
            return "stopping";
        case LifecycleState::Stopped:
            return "stopped";
        case LifecycleState::Failed:
            return "failed";
        }

        return "unknown"; 
    }


/** Explicit transition table: invalid lifecycle jumps fail closed. */
[[nodiscard]] constexpr bool can_transition(
    LifecycleState from, LifecycleState to) noexcept {
    switch (from) {
    case LifecycleState::Created:
        return to == LifecycleState::Configured || to == LifecycleState::Failed;
    case LifecycleState::Configured:
        return to == LifecycleState::Initializing || to == LifecycleState::Failed;
    case LifecycleState::Initializing:
        return to == LifecycleState::Ready || to == LifecycleState::Failed;
    case LifecycleState::Ready:
        return to == LifecycleState::Running || to == LifecycleState::Stopping ||
               to == LifecycleState::Failed;
    case LifecycleState::Running:
        return to == LifecycleState::Stopping || to == LifecycleState::Failed;
    case LifecycleState::Stopping:
        return to == LifecycleState::Stopped || to == LifecycleState::Failed;
    case LifecycleState::Stopped:
    case LifecycleState::Failed:
        return false;
    }
    return false;
}

[[nodiscard]] inline Status validate_transition(
    LifecycleState from, LifecycleState to) {
    if (!can_transition(from, to)) {
        return Status::failure("invalid lifecycle transition: " +
            std::string(to_string(from)) + " -> " + std::string(to_string(to)));
    }
    return Status::success();
}

}