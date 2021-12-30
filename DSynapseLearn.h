#ifndef DSYNAPSELEARN_H
#define DSYNAPSELEARN_H
/*
 DSynapseLearn task ~ DSLT
*/



#include <DSynapse.h>
#include <net.h>


// 1. rand w
// 2. rand w options (full rand/smart rand)
// 3. actf
// 4. lr
// 5. qrate
// 6. epocsize
// 7. bpf
// 8. use act out
struct DSynapseLayerProperty
{
    DSynapseLayerProperty() : size(0), activation(0), learnRate(0.0), actout(false)
    {}
    int size;
    int activation;
    double learnRate;
    bool actout;
};
class DSynapseNetAdapter
{
public:
    DSynapseNetAdapter();
    ~DSynapseNetAdapter();
    void set(DSynapse::NET_P n);
    void set(DSynapseNetAdapter &a);
    DSynapse::NET_P get();
    void create();


    void addLayer(int size, DSynapse::ACTIVATION a = DSynapse::ACT_SIGMOID);
//    void addLayer(int size, int activationIndex = 0, double learnRate = 0.1, bool actout = false);

    void setRandWeights();
    void setOptimizedWeights();
    void setZeroWeights();

    void setActivation(DSynapse::ACTIVATION a);
    void setLearnRate(DSynapse::nvt learn_rate);
    void setInputQRate(DSynapse::nvt qrate);
    void setInputQRate(DSynapse::data_line qrate);
    void setOutputQRate(DSynapse::nvt qrate);
    void setOutputQRate(DSynapse::data_line qrate);
    void setEpocSize(int n);
    void setBackprop(DSynapse::BACKPROP_FUNCTION f);
    void setUsingActivatedOutput(bool state);
    void setLayerActivation(int layer_index, DSynapse::ACTIVATION a);
    void setLayerLearnRate(int layer_index, DSynapse::nvt learn_rate);

    void removeLayer(int layerIndex);
    void modifyLayer(int layerIndex, int size);
    void insertLayer(int pos, int size, int activationIndex = 0, double learnRate = 0.1, bool actout = false);
    void applyLayerProperty(int layerIndex, const DSynapseLayerProperty &p);

    DSynapse::LAYER_P getLayer(int layerIndex) const;
    DSynapseLayerProperty getLayerProperty(int layerIndex) const;

    int size() const;
    int outLayerSize() const;
    int layerSize(int layer) const;



    int getErrorCode() const;
    DLogs::DLogsContext* getGlobalLogsContext() const;
    void setGlobalLogsContext(DLogs::DLogsContext *c);
private:
    DSynapse::NET_P net;
    bool created;
    int error;
};
void printLayerProperty(const DSynapseLayerProperty &p);
#endif // DSYNAPSELEARN_H
