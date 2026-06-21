#pragma once
#include "../sor/core.hpp"

namespace MiniCPU {
    using namespace JanSordid::Core;

    class Memory {
        Array<u8, 256> _data{};

    public:
        [[nodiscard]] u8 read(u8 addr) const noexcept;
        void write(u8 addr, u8 value) noexcept;
        void load(const DynArray<u8>& bytes) noexcept;
    };
}