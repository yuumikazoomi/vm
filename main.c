//
//  main.c
//  vm
//
//  Created by Irelia on 2/17/22.
//

#include <vm.h>


uint8_t addtwodigits[] = {
    kMovConst,  kR0,    02,
    kMovConst,  kR1,    04,
    kAddReg,    kR0,    kR1,
    kMovReg,    kRax,   kR0,
    kSubConst,  kRax,   03,
    kHalt
};
int main(int argc, const char * argv[]) {
    struct vm_context* ctx = initvm();
    ctx->instructions = addtwodigits;
    vm(ctx);
    printf("%llu\n",ctx->registers.rax);
    destroyvm(ctx);
    return 0;
}
