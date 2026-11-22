# AIC-SSI Core foundation

**Implementation scope:** C++23 lifecycle/orchestration foundation  
**Maturity:** Prototype implementation with passing local unit tests  
**Not a production SSI stack.**

## Components

| Component | Responsibility |
|---|---|
| `status.h` | Dependency-free success/failure result for operational calls |
| `config.h/.cpp` | Validate engine name, version, and module capacity |
| `context.h/.cpp` | Thread-safe, process-local runtime key/value context |
| `lifecycle.h` | Explicit allowed lifecycle transitions |
| `module_engine.h` | Module interface (`id`, `version`, `initialize`, `shutdown`) |
| `module_registry.h/.cpp` | Own modules, reject duplicate IDs, initialize in registration order, shut down in reverse order |
| `ssi_engine.h/.cpp` | Coordinate registration, initialization, start, and stop |

## Lifecycle

```text
Created -> Configured -> Initializing -> Ready -> Running
                                      |       |        |
                                      v       v        v
                                    Failed  Stopping <-+
                                              |
                                              v
                                            Stopped
```

`Failed` and `Stopped` are terminal in this first implementation. There is no restart or recovery transition. A failed module initialization triggers best-effort shutdown of the failing module and all previously initialized modules in reverse order.

## Module contract

- Module IDs and versions must be non-empty; IDs must be unique within an engine.
- Registration is only allowed before initialization.
- Initialization order follows registration order.
- Shutdown order is the reverse of initialization order.
- `shutdown()` must be safe after partial initialization because `initialize()` can acquire resources and then return failure or throw.
- A module must return a failed `Status` for expected operational errors; exceptions are caught at the registry boundary.
- Module implementations are responsible for documenting external side effects and their cleanup limits.

## Build and test

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Or use the repository scripts:

```bash
./scripts/src/build.sh
./scripts/src/run_tests.sh
```

## Explicit limitations

This is an orchestration foundation, not a complete SSI implementation. It does not implement DID parsing/resolution, VC issuance or verification, wallet/key storage, cryptographic operations, persistence, secure erasure, distributed consensus, or recovery after failed shutdown. The context is an in-memory runtime key/value store and **must not be used to store secrets, private keys, or credentials**.

The tests exercise configuration validation, context access, lifecycle transitions, duplicate registration, normal startup/shutdown, and cleanup after initialization failure using in-process test doubles. They do not establish cryptographic security, production readiness, hardware isolation, formal verification, or compliance with an SSI standard.
