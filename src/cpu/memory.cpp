#include "memory.hpp"
using namespace MiniCPU;

u8 Memory::read(u8 addr) const noexcept {
    return _data[addr];
}

void Memory::write(u8 addr, u8 value) noexcept {
    _data[addr] = value;
}

void Memory::load(const DynArray<u8>& bytes) noexcept {
    Assert(bytes.size() <= _data.size());
    for (usize i = 0; i < bytes.size(); ++i)
        _data[i] = bytes[i];
}