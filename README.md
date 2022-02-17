# vm
Simple byte code based vm


A very simple byte code vm which supports four registers: r0, r1, rax, rdx, and instruction pointer rip

And 6 instructions: add registers, subtract registers, move registers, add constant, subtract constant, move constant

Sample 
```
bytecode {

    kMovConst,  kR0,    02,
    kMovConst,  kR1,    04,
    kAddReg,    kR0,    kR1,
    kMovReg,    kRax,   kR0,
    kSubConst,  kRax,   03,
    kHalt
};
``` 
Result == 3


example:

make

./vm

expected output: ```
mov reg const
mov reg const
add reg reg
mov reg reg
sub reg const
3
```
