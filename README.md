# vm
Simple byte code based vm


A very simple byte code vm which supports four registers: r0, r1, rax, rdx, and instruction pointer rip

And 6 instructions: add registers, subtract registers, move registers, add constant, subtract constant, move constant

Sample 
```
bytecode {
    kMovConst,  kR0,    10,
    kAddConst,  kR0,    5,
    kMovConst,  kRax,   3,
    kSubReg,    kR0,    kRax,
    kMovConst,  kRax,   4,
    kAddReg,    kR0,    kRax,
    kMovReg,    kRax,  kR0,
    kSubConst,  kRax,   7,
    kHalt
};
``` 
Result == 9


example:

make

./vm

expected output: 
```
mov reg const
mov reg const
add reg reg
mov reg reg
sub reg const
3
```
