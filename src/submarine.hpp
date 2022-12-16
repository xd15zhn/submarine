#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "simucpp.hpp"
using namespace simucpp;
using namespace zhnmat;
using namespace std;

class SubmarineXZ: public PackModule {
public:
    SubmarineXZ(Simulator *sim, std::string name);
    ~SubmarineXZ() {};
    virtual PUnitModule Get_InputPort(int n=0) const;
    virtual PUnitModule Get_OutputPort(int n=0) const;
    UGain *ganEa=nullptr;
    UGain *ganEe=nullptr;
    UGain *ganFi=nullptr;
    UIntegrator *intEy=nullptr;
    UIntegrator *intWy=nullptr;
    UIntegrator *intVx=nullptr;
    UIntegrator *intVz=nullptr;
    USum *sumS1=nullptr;
    USum *sumS2=nullptr;
    USum *sumS3=nullptr;
    USum *sumAx=nullptr;
    USum *sumAy=nullptr;
    USum *sumAz=nullptr;
};

#endif // SUBMARINE_H
