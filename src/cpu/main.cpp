#include "assembler.hpp"
#include "memory.hpp"
#include "cpu.hpp"
#include "../sor/core.hpp"

using namespace JanSordid::Core;
using namespace MiniCPU;

int main (const int argc, const char* const argv[]) {
    if(argc < 2) {
        print("Aufruf per: CPU <Pfad/program.txt>\n" );
        return EXIT_FAILURE;
    }

    const auto bytes = assemble(argv[1]);
    if (!bytes) {
        print( "Error: Konnte nicht laden oder parsen: '{}'\n", argv[1] );
        return EXIT_FAILURE;
    }

    Memory memory;
    memory.load(*bytes);

    CPU cpu;
    cpu.run(memory);

    return EXIT_SUCCESS;
}