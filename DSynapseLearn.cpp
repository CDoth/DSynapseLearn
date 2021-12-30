#include "DSynapseLearn.h"


DSynapseNetAdapter::DSynapseNetAdapter() : net(nullptr), created(false), error(0)
{
}
DSynapseNetAdapter::~DSynapseNetAdapter()
{
    if(created)
        DSynapse::net_free(net);
    net = nullptr;
    error = 0;

//    std::cout << __func__ << " adapter: " << this << " net: " << net << " created: " << created << std::endl;
}
void DSynapseNetAdapter::set(DSynapse::NET_P n)
{
    if(created)
        DSynapse::net_free(net);
    created = false;
    net = n;

//    std::cout << __func__ << " adapter: " << this << " net: " << net << " created: " << created << std::endl;

}
void DSynapseNetAdapter::set(DSynapseNetAdapter &a)
{
    set(a.net);
}
DSynapse::NET_P DSynapseNetAdapter::get()
{
    return net;
}
void DSynapseNetAdapter::create()
{
    net = DSynapse::alloc_net();
    error = net ? 0 : -1;
    created = net ? true : false;

//    std::cout << __func__ << " adapter: " << this << " net: " << net << " created: " << created << std::endl;

}
void DSynapseNetAdapter::addLayer(int size, DSynapse::ACTIVATION a)
{
    if( DSynapse::net_add_layer(net, size, 0) == nullptr)
        error = -1;
    if( DSynapse::layer_set_actf(net->output_l, a) < 0 )
        error = -1;
}
//void DSynapseNetAdapter::addLayer(int size, int activationIndex, double learnRate, bool actout)
//{
//    if(size <= 0)
//        return;
//    if( DSynapse::net_add_layer(net, size, 0) == nullptr)
//        error = -1;
//    else
//    {
//        auto last = DSynapse::net_get_output_layer(net);
//        if(last)
//        {
//            if( DSynapse::layer_set_actf(last, DSynapse::actt_get_lable_by_index(activationIndex)) < 0 )
//                error = -1;
//            if( DSynapse::layer_set_lr(last, learnRate) < 0 )
//                error = -1;
//            if( DSynapse::layer_use_act_out(last, int(actout)) < 0)
//                error = -1;
//        }
//        else
//            error = -1;
//    }
//}
void DSynapseNetAdapter::setRandWeights()
{
    error = DSynapse::net_set_randw(net);
}
void DSynapseNetAdapter::setOptimizedWeights()
{

}
void DSynapseNetAdapter::setZeroWeights()
{

}
void DSynapseNetAdapter::setActivation(DSynapse::ACTIVATION a)
{
    error = DSynapse::net_set_actf(net, a);
}
void DSynapseNetAdapter::setLearnRate(DSynapse::nvt learn_rate)
{
    error = DSynapse::net_set_lr(net, learn_rate);
}
void DSynapseNetAdapter::setInputQRate(DSynapse::nvt qrate)
{
    error = DSynapse::net_fill_input_qrate(net, qrate);
}
void DSynapseNetAdapter::setInputQRate(DSynapse::data_line qrate)
{
    error = DSynapse::net_set_input_qrate(net, qrate);
}
void DSynapseNetAdapter::setOutputQRate(DSynapse::nvt qrate)
{
    error = DSynapse::net_fill_output_qrate(net, qrate);
}
void DSynapseNetAdapter::setOutputQRate(DSynapse::data_line qrate)
{
    error = DSynapse::net_set_output_qrate(net, qrate);
}
void DSynapseNetAdapter::setEpocSize(int n)
{
    error = DSynapse::net_set_epoc_size(net, n);
}
void DSynapseNetAdapter::setBackprop(DSynapse::BACKPROP_FUNCTION f)
{
    error = DSynapse::net_set_bpf(net, f);
}
void DSynapseNetAdapter::setUsingActivatedOutput(bool state)
{
    error = DSynapse::net_use_act_out(net, state);
}
void DSynapseNetAdapter::setLayerActivation(int layer_index, DSynapse::ACTIVATION a)
{
    DSynapse::LAYER_P l = DSynapse::net_get_layer(net, layer_index);
    error = DSynapse::layer_set_actf(l, a);
}
void DSynapseNetAdapter::setLayerLearnRate(int layer_index, DSynapse::nvt learn_rate)
{
    DSynapse::LAYER_P l = DSynapse::net_get_layer(net, layer_index);
    error = DSynapse::layer_set_lr(l, learn_rate);
}
void DSynapseNetAdapter::removeLayer(int layerIndex)
{
    error = DSynapse::net_remove_layer(net, layerIndex, 0);
}
void DSynapseNetAdapter::modifyLayer(int layerIndex, int size)
{
    error = DSynapse::net_modify_layer(net, layerIndex, size);
}
void DSynapseNetAdapter::insertLayer(int pos, int size, int activationIndex, double learnRate, bool actout)
{
    DSynapse::LAYER_P l = DSynapse::net_insert_layer(net, size, pos, 0);
    if(l == nullptr)
        error = -1;
    else
    {
        if( DSynapse::layer_set_actf(l, DSynapse::actt_get_lable_by_index(activationIndex)) < 0 )
            error = -1;
        if( DSynapse::layer_set_lr(l, learnRate) < 0 )
            error = -1;
        if( DSynapse::layer_use_act_out(l, int(actout)) < 0)
            error = -1;
    }
}
void DSynapseNetAdapter::applyLayerProperty(int layerIndex, const DSynapseLayerProperty &p)
{
    DSynapse::LAYER_P l = DSynapse::net_get_layer(net, layerIndex);
    if(l)
    {
        if( DSynapse::layer_set_actf(l, DSynapse::actt_get_lable_by_index(p.activation)) < 0 )
            error = -1;
        if( DSynapse::layer_set_lr(l, p.learnRate) < 0 )
            error = -1;
        if( DSynapse::layer_use_act_out(l, int(p.actout)) < 0)
            error = -1;
    }
    else
        error = -1;
}
DSynapse::LAYER_P DSynapseNetAdapter::getLayer(int layerIndex) const
{
    return DSynapse::net_get_layer(net, layerIndex);
}
DSynapseLayerProperty DSynapseNetAdapter::getLayerProperty(int layerIndex) const
{
    DSynapseLayerProperty p;
    auto l = DSynapse::net_get_layer(net, layerIndex);
    p.size = l->size;
    p.actout = l->use_act_out;
    p.learnRate = l->learn_rate;
    p.activation = DSynapse::actt_get_index_by_callback(l->act);
    return p;
}
int DSynapseNetAdapter::size() const
{
    return DSynapse::net_get_size(net);
}
int DSynapseNetAdapter::outLayerSize() const
{
    return DSynapse::layer_get_size(DSynapse::net_get_output_layer(net));
}
int DSynapseNetAdapter::layerSize(int layer) const
{
    return DSynapse::net_get_layer_size(net, layer);
}
int DSynapseNetAdapter::getErrorCode() const
{
    return error;
}
DLogs::DLogsContext *DSynapseNetAdapter::getGlobalLogsContext() const
{
    return DSynapse::DSynapseGetLogContext();
}
void DSynapseNetAdapter::setGlobalLogsContext(DLogs::DLogsContext *c)
{
    if(c)
        DSynapse::DSynapseSetLogContext(*c);
    else
        error = -1;
}

void printLayerProperty(const DSynapseLayerProperty &p)
{
    std::cout << "Layer Property: " << " size: " << p.size << " actout: " << p.actout <<  " lr: " << p.learnRate << " activation: " << p.activation << std::endl;
}
