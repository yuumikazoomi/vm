# vm
Simple byte code based vm


A very simple byte code vm which supports five registers: r0,r1,r2,r3,rax and an instruction pointer rip

And 6 instructions: add registers, subtract registers, move registers, add constant, subtract constant, move constant

Semantics are intel syntax:
instruction, destination, source
Sample 
```
bytecode {
    kMovConst,  kR0,    10,
    kAddConst,  kR0,    5,
    kMovConst,  kR1,    3,
    kSubReg,    kR0,    kR1,
    kMovConst,  kR1,    4,
    kAddReg,    kR0,    kR1,
    kMovReg,    kR1,    kR0,
    kSubConst,  kR1,    7,
    kMovReg,    kRax,   kR1,
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
add reg const
mov reg const
sub reg reg
mov reg const
add reg reg
mov reg reg
sub reg const
mov reg reg
9
```
