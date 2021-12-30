#ifndef DSL_FUNC_APPROXIMATION_H
#define DSL_FUNC_APPROXIMATION_H

#include <DSynapse.h>
namespace DSL_func_approximation
{
typedef float func_value_type, fv_t;

typedef void (*FUNC_COMMON)(fv_t &X, fv_t &Y, fv_t T, void *opaque);

//default:
void FuncBase_sin(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_cos(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_line(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_par(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_exp(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_cubic_par(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_sqr(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_back(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_ln(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_tan(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBase_spec1(fv_t &X, fv_t &Y, fv_t T, void *opaque);

//parametrics:
void FuncBivar_circle(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_spiral(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_deltoid(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_astroid(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_heart(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_butterfly(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_hypocycloid1(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_hypocycloid2(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_hypocycloid3(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_cardioid(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_epicycloid(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_lissajous1(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_lissajous2(fv_t &X, fv_t &Y, fv_t T, void *opaque);
void FuncBivar_lissajous3(fv_t &X, fv_t &Y, fv_t T, void *opaque);


void FuncBase_net(fv_t &X, fv_t &Y, fv_t T, void *opaque);

struct FuncDescriptor
{
    FUNC_COMMON f;
    const char *name;
};
extern FuncDescriptor funcs[];
bool is_parametric(FUNC_COMMON f);





struct TaskDescriptor
{
    FUNC_COMMON base;
    fv_t x_low;
    fv_t x_high;
    fv_t step;
};
int getSample_func_approx(DSynapse::data_line input, DSynapse::data_line target, const void *opaque, int index);
int getSample_func_approx_parametric(DSynapse::data_line input, DSynapse::data_line target, const void *opaque, int index);
}


#endif // DSL_FUNC_APPROXIMATION_H
