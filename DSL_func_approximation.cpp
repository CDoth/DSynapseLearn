#include "DSL_func_approximation.h"
#include <cmath>
#include <net.h>

DSL_func_approximation::FuncDescriptor DSL_func_approximation::funcs[]
= {
    {FuncBase_sin, "sin"}
    ,{FuncBase_cos, "cos"}
    ,{FuncBase_line, "line"}
    ,{FuncBase_par, "par"}
    ,{FuncBase_cubic_par, "cubic par"}
    ,{FuncBase_sqr, "sqr"}
    ,{FuncBase_back, "back"}
    ,{FuncBase_ln, "ln"}
    ,{FuncBase_tan, "tan"}
    ,{FuncBase_spec1, "spec1"}

    ,{FuncBivar_circle, "b_circle"}
    ,{FuncBivar_spiral, "b_spiral"}
    ,{FuncBivar_deltoid, "b_deltoid"}
    ,{FuncBivar_astroid, "b_astroid"}
    ,{FuncBivar_heart, "b_heart"}
    ,{FuncBivar_butterfly, "b_butterfly"}
    ,{FuncBivar_hypocycloid1, "b_hypocycloid1"}
    ,{FuncBivar_hypocycloid2, "b_hypocycloid2"}
    ,{FuncBivar_hypocycloid3, "b_hypocycloid3"}
    ,{FuncBivar_cardioid, "b_cardioid"}
    ,{FuncBivar_epicycloid, "b_epicycloid"}
    ,{FuncBivar_lissajous1, "b_lissajous1"}
    ,{FuncBivar_lissajous2, "b_lissajous2"}
    ,{FuncBivar_lissajous3, "b_lissajous3"}

    ,{NULL, ""}
};


void DSL_func_approximation::FuncBase_sin(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = sin(X);
}
void DSL_func_approximation::FuncBase_cos(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = cos(X);
}
void DSL_func_approximation::FuncBase_line(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = X;
}
void DSL_func_approximation::FuncBase_par(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = X*X;
}
void DSL_func_approximation::FuncBase_exp(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = exp(X);
}
void DSL_func_approximation::FuncBase_cubic_par(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = X*X*X;
}
void DSL_func_approximation::FuncBase_sqr(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = sqrt(X);
}
void DSL_func_approximation::FuncBase_back(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    if(X)
        Y = 1.0/X;
    else
        Y = 0.0;
}
void DSL_func_approximation::FuncBase_ln(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = log(X);
}
void DSL_func_approximation::FuncBase_tan(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = tan(X);
}
void DSL_func_approximation::FuncBase_spec1(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    Y = X*X*(X-2.0)*(X-2.0);
}

void DSL_func_approximation::FuncBivar_circle(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    X = sin(T);
    Y = cos(T);
}
void DSL_func_approximation::FuncBivar_spiral(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = T * sin(T);
    Y = T * cos(T);
}
void DSL_func_approximation::FuncBivar_deltoid(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = 2.0 * cos(T) + cos(2*T);
    Y = 2.0 * sin(T) - sin(2*T);
}
void DSL_func_approximation::FuncBivar_astroid(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    auto tsin = sin(T);
    auto tcos = cos(T);
    X = 2.0 * tsin * tsin * tsin;
    Y = 2.0 * tcos * tcos * tcos;
}
void DSL_func_approximation::FuncBivar_heart(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    auto tsin = sin(T);
    auto tcos = cos(T);
    X = 16.0 * pow(tsin, 3.0);
    Y = (13.0 * tcos) - (5.0 * cos(2.0*T)) - (2.0 * cos(3.0*T)) - cos(4.0*T);
}
void DSL_func_approximation::FuncBivar_butterfly(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = sin(T) *
            (
                exp(cos(T)) -
                2.0 * cos(4*T) +
                pow(sin((T/12.0)), 5.0)
                );
    Y = cos(T) *
            (
                exp(cos(T)) -
                2.0 * cos(4.0*T) +
                pow(sin((T/12.0)), 5)
                );
}
void DSL_func_approximation::FuncBivar_hypocycloid1(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = 20.0 *
            (
                cos(T) +
                cos(5.0*T)/5.0
                );
    Y = 20.0 *
            (
                sin(T) -
                sin(5.0*T)/5.0
                );
}
void DSL_func_approximation::FuncBivar_hypocycloid2(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = 4.4 *
            (
                cos(T) +
                cos(1.1 * T)/1.1
                );
    Y = 4.4 *
            (
                sin(T) -
                sin(1.1*T) / 1.1
                );
}
void DSL_func_approximation::FuncBivar_hypocycloid3(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = 24.8 *
            (
                cos(T) +
                cos(6.2 * T) / 6.2
                );
    Y = 24.8 *
            (
                sin(T) -
                sin(6.2 * T) / 6.2
                );
}
void DSL_func_approximation::FuncBivar_cardioid(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = (1.0 + cos(T)) * cos(T);
    Y = (1.0 + cos(T)) * sin(T);
}
void DSL_func_approximation::FuncBivar_epicycloid(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = 6.2 *
            (
                cos(T) -
                cos(3.1 * T) / 3.1
                );
    Y = 6.2 *
            (
                sin(T) -
                sin(3.1 * T) / 3.1
                );
}
void DSL_func_approximation::FuncBivar_lissajous1(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = sin(T + M_PI / 2.0);
    Y = sin(2.0*T);
}
void DSL_func_approximation::FuncBivar_lissajous2(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = sin(3.0*T + M_PI / 2.0);
    Y = sin(2.0*T);
}
void DSL_func_approximation::FuncBivar_lissajous3(fv_t &X, DSL_func_approximation::fv_t &Y, DSL_func_approximation::fv_t T, void *opaque)
{
    X = sin(5.0*T + M_PI / 2.0);
    Y = sin(6.0*T);
}
int DSL_func_approximation::getSample_func_approx(DSynapse::data_line input, DSynapse::data_line target, const void *opaque, int index)
{
    std::cout << "getSample_func_approx" << std::endl;

    const TaskDescriptor *desc = reinterpret_cast<const TaskDescriptor*>(opaque);
    if(!desc->base)
        return -1;
    fv_t x = desc->x_low + desc->step * (fv_t)index;
    if(x > desc->x_high)
        return -1;
    input[0] = x;
    desc->base(x, target[0], 0, nullptr);

    return 0;
}
int DSL_func_approximation::getSample_func_approx_parametric(DSynapse::data_line input, DSynapse::data_line target, const void *opaque, int index)
{
    std::cout << "getSample_func_approx_parametric" << std::endl;

    const TaskDescriptor *desc = reinterpret_cast<const TaskDescriptor*>(opaque);
    if(!desc->base)
        return -1;
    fv_t t = desc->x_low + desc->step * (fv_t)index;
    if(t > desc->x_high)
        return -1;
    input[0] = t;
    desc->base(target[0], target[1], t, nullptr);

    return 0;
}

void DSL_func_approximation::FuncBase_net(fv_t &X, fv_t &Y, fv_t T, void *opaque)
{
    DSynapse::NET_P net = reinterpret_cast<DSynapse::NET_P>(opaque);
    if( DSynapse::net_set_input(net, X, 0) < 0 )
    {
        std::cout << "FuncBase_net error: net_set_input" << std::endl;
        //err
    }
//    net->input_l->raw[0] = X;
//    net->input_l->input[0] = X;

    DSynapse::forward_prop(net);
    if( DSynapse::net_get_output(net, &Y, 0))
    {
        std::cout << "FuncBase_net error: net_get_output" << std::endl;
        //err
    }
//    std::cout << "CALL: FuncBase_net" << " X: " << X << " Y: " << Y << " net: " << net << std::endl;

}


bool DSL_func_approximation::is_parametric(DSL_func_approximation::FUNC_COMMON f)
{
    auto func = funcs;
    while(func->f)
    {
        if(f == func->f && func->name[0] == 'b' && func->name[1] == '_')
            return true;
        ++func;
    }
    return false;
}
