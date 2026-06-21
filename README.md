## CPU Emulator

This Repository is about a simple 8-bit CPU emulator written in C++23. It simulates the fundamental fetch → decode → execute cycle of a processor. It has four registers (A-D), a program counter and a 256-byte adress space implemented as an Array (can store 256x 0-255 numbers; 256 Slots * 1 Byte). 


## Instruction Set
| Instruction | Pseudocode | Explanation |
| --- | --- | --- |
| LOAD a imm | a = imm | Loads an immediate in a Register |
| LOAD a [addr] | Reg a = mem[addr] | Loads the value from memory in Register |
| STORE [addr] a | mem[addr] = a | Writes Register Value in Memory |
| ADD a b | a = a+b | Adds two registers |
| SUB a b | a = a-b | Subtracts two registers |
| PRINT a | console: a | prints value in console
| STOP | stop | Stop CPU |


## 3-byte Format for instructions
| Byte 0 | Byte 1 | Byte 2 |
| --- | --- | --- |
| Opcode | Operand 1 | Operand 2 |


## Register Encoding
- A = 0, B = 1, C = 2, D = 3
- enum class Register: u8

## Example Flow
1. Read .txt File and store instructions in Memory
2. CPU starts at PC=0
3. Each step:
  - Read 3 bytes from Memory
  - print instruction in console
  - execute
  - print cpu status + show ram (only adresses with a stored value)
4. pc += 3
5. Stop

## Example Console View
FETCH [PC=0x06]   ADD A B
DECODE Opcode=0x04 Op1=A (0x00) Op2=B (0x01)
EXECUTE A = 10 + 5 = 15
CPU A=15   B=5   C=0   D=0    PC=0x09
RAM (empty)
