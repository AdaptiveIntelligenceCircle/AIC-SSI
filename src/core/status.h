#pragma once

#include <string>
#include <utility>

using namespace std;

namespace aic::ssi::core
{
    // A small, dependency free result type for expected operational failures.. //
    class Status final
    {
    public:
        static Status success() { return Status(true, {}); }
        static Status failure(string message)
        {
            return Status(false, move(message));
        }

        [[nodiscard]] bool ok() const noexcept { return ok_; }
        [[nodiscard]] const string &message() const noexcept { return message_; }
        explicit operator bool() const noexcept { return ok_; }

    private:
        Status(bool ok, string message)
            : ok_(ok), message_(move(message)) {}

        bool ok_;
        string message_;
    };
}