//
//  vm.c
//  vm
//
//  Created by Irelia on 2/17/22.
//

#include <vm.h>

struct vm_context* initvm(void){
    struct vm_context* ctx = malloc(sizeof(struct vm_context));
    assert(ctx);
    memset(ctx,0,sizeof(struct vm_context));
    return ctx;
}
void destroyvm(struct vm_context* ctx){
    assert(ctx);
    free(ctx);
}
int64_t* vm_getregister(struct vm_context* ctx, uint8_t op){
    int64_t* reg = NULL;
    switch (op) {
        case kR0:
            reg = &ctx->registers.r0;
            break;
        case kR1:
            reg = &ctx->registers.r1;
            break;
        case kRax:
            reg = &ctx->registers.rax;
            break;
        case kRdx:
            reg = &ctx->registers.rdx;
        default:
            break;
    }
    return reg;
}
void vm(struct vm_context* ctx){
    do{
        switch(ctx->instructions[ctx->registers.rip]){
            case kMovReg:{//mov reg reg
                printf("mov reg reg\n");
                int64_t* rf = vm_getregister(ctx, ctx->instructions[ctx->registers.rip+1]);
                int64_t* rs = vm_getregister(ctx, ctx->instructions[ctx->registers.rip+2]);
                assert(rf&&rs);
                *rf = *rs;
                ctx->registers.rip+=3;
            }
                break;
            case kMovConst:{//mov reg const
                printf("mov reg const\n");
                int64_t* reg = vm_getregister(ctx,ctx->instructions[ctx->registers.rip+1]);
                assert(reg);
                *reg = ctx->instructions[ctx->registers.rip+2];
                ctx->registers.rip+=3;
            }
                break;
            case kAddReg:{//add reg reg
                printf("add reg reg\n");
                int64_t* rf = vm_getregister(ctx, ctx->instructions[ctx->registers.rip+1]);
                int64_t* rs = vm_getregister(ctx, ctx->instructions[ctx->registers.rip+2]);
                assert(rf&&rs);
                *rf+=*rs;
                ctx->registers.rip+=3;
            }
                break;
            case kAddConst:{//add reg const
                printf("add reg const\n");
                int64_t* reg = vm_getregister(ctx,ctx->instructions[ctx->registers.rip+1]);
                assert(reg);
                *reg += ctx->instructions[ctx->registers.rip+2];
                ctx->registers.rip+=3;
            }
                break;
            case kSubReg:{//sub reg reg
                printf("sub reg reg\n");
                int64_t* rf = vm_getregister(ctx, ctx->instructions[ctx->registers.rip+1]);
                int64_t* rs = vm_getregister(ctx, ctx->instructions[ctx->registers.rip+2]);
                assert(rf&&rs);
                ctx->registers.rip+=3;
                *rf-=*rs;
            }
                break;
            case kSubConst:{//sub reg const
                printf("sub reg const\n");
                int64_t* reg = vm_getregister(ctx,ctx->instructions[ctx->registers.rip+1]);
                assert(reg);
                *reg -= ctx->instructions[ctx->registers.rip+2];
                ctx->registers.rip+=3;
            }
                break;
        }
    }while(ctx->instructions[ctx->registers.rip]!=kHalt);
    
}
