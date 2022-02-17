//
//  vm.h
//  vm
//
//  Created by Irelia on 2/17/22.
//

#ifndef vm_h
#define vm_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
enum vm_op : uint8_t{
    kR0,
    kR1,
    kRax,
    kRdx,
    kHalt,
    kMovReg,
    kMovConst,
    kAddReg,
    kAddConst,
    kSubReg,
    kSubConst,
};
struct vm_reg{
    int64_t r0;
    int64_t r1;
    int64_t rax;
    int64_t rdx;
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
