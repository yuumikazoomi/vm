#ifndef vm_h
#define vm_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
enum vm_op : uint8_t{
    kR0,
    kR1,
    kR2,
    kR3,
    kRax,
    kHalt,
    kMovReg,
    kMovConst,
    kAddReg,
    kAddConst,
    kSubReg,
    kSubConst,
};
/*
 *Calling convention - TO BE ADDED LATER
 *Four registers, r0,r1,r2,r3
 *Four available arguments all passed through r0-r3 in respective order
 *r0,r1,r2,r3,rax are volatile registers , do not need to be preserved, callee can modfiy
 *rsp is non volatile and needs to be preserved
 *no arguments are passed on the stack
 *return address is stored on the stack
 *stack size is 256 bytes allowing for 32 'stack-frames'
 *return value is in rax
 *call instruction is 9 bytes
 *call address
 */
struct vm_reg{
    int64_t r0;
    int64_t r1;
    int64_t r2;
    int64_t r3;
    int64_t rax;
    int64_t rip;
    
};
struct vm_context{
    struct vm_reg registers;
    uint8_t* instructions;
};
struct vm_context* initvm(void);
void destroyvm(struct vm_context* ctx);
void vm(struct vm_context* ctx);

#endif /* vm_h */
