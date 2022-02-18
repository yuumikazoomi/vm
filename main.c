#include "vm.h"

uint8_t bytecode[] = {
    kMovConst,  kR0,    10,
    kAddConst,  kR0,    5,
    kMovConst,  kR1,    3,
    kSubReg,    kR0,    kR1,
    kMovConst,  kR1,    4,
    kAddReg,    kR0,    kR1,
    kMovReg,    kR1,    kR0,
    kSubConst,  kR1,    7,
    kMovReg,    kRax,   kR1,
    kCall,      0x00,   0x00,
    kHalt
};

int main(int argc, const char * argv[]) {
    
    struct vm_context* ctx = initvm();
    ctx->instructions = bytecode;
    vm(ctx);
    printf("%llu\n",ctx->registers.rax);
    destroyvm(ctx);
    return 0;
}
