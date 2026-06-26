#pragma once
#include "../sor/core.hpp"
#include <optional>

namespace MiniCPU {
    using namespace JanSordid::Core;

    [[nodiscard]] std::optional<DynArray<u8>> assemble(const String& filepath);
}