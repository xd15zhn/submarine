#include "submarine.hpp"

SubmarineXZ::SubmarineXZ(Simulator *sim, std::string name) {
    SUGain(ganEa, sim);
    SUGain(ganEe, sim);
    SUGain(ganFi, sim);
    SUIntegrator(intEy, sim);
    SUIntegrator(intWy, sim);
    SUIntegrator(intVx, sim);
    SUIntegrator(intVz, sim);
    SUSum(sumS1, sim);
    SUSum(sumS2, sim);
    SUSum(sumS3, sim);
    SUSum(sumAx, sim);
    SUSum(sumAy, sim);
    SUSum(sumAz, sim);
    sim->connectU(intVx, sumS1);
    sim->connectU(intVz, sumS1);
    sim->connectU(intEy, sumS1);
    sumS1->Set_InputGain(-10.1, 0);
    sumS1->Set_InputGain(-37.8, 1);
    sumS1->Set_InputGain(37.5, 2);
    sim->connectU(intVz, sumS2);
    sim->connectU(intWy, sumS2);
    sim->connectU(ganEa, sumS2);
    sim->connectU(ganEe, sumS2);
    sumS2->Set_InputGain(-1047.5, 0);
    sumS2->Set_InputGain(-569.9, 1);
    sumS2->Set_InputGain(-189.97, 2);
    sumS2->Set_InputGain(-379.943, 3);
    sim->connectU(intVz, sumS3);
    sim->connectU(intWy, sumS3);
    sim->connectU(ganEa, sumS3);
    sim->connectU(ganEe, sumS3);
    sumS3->Set_InputGain(-210.9, 0);
    sumS3->Set_InputGain(-239.4, 1);
    sumS3->Set_InputGain(171, 2);
    sumS3->Set_InputGain(-228, 3);
    sim->connectU(sumS1, sumAx);
    sim->connectU(sumS2, sumAx);
    sim->connectU(sumS3, sumAx);
    sumAx->Set_InputGain(165.987525236596, 0);
    sumAx->Set_InputGain(3.81203748021033, 1);
    sumAx->Set_InputGain(-1.82515701785262, 2);
    sim->connectU(sumS1, sumAy);
    sim->connectU(sumS2, sumAy);
    sim->connectU(sumS3, sumAy);
    sumAy->Set_InputGain(-8.5400764866803, 0);
    sumAy->Set_InputGain(-202.803573702547, 1);
    sumAy->Set_InputGain(97.099875777814, 2);
    sim->connectU(sumS1, sumAz);
    sim->connectU(sumS2, sumAz);
    sim->connectU(sumS3, sumAz);
    sumAz->Set_InputGain(2.3583876502109, 0);
    sumAz->Set_InputGain(266.832288053883, 1);
    sumAz->Set_InputGain(-26.8146483498798, 2);
    sim->connectU(intWy, intEy);
    sim->connectU(sumAy, intWy);
    sim->connectU(sumAx, intVx);
    sim->connectU(sumAz, intVz);
}
PUnitModule SubmarineXZ::Get_InputPort(int n) const {
    if (n==0) return ganEa;
    if (n==1) return ganEe;
    if (n==2) return ganFi;
    return nullptr;
}
PUnitModule SubmarineXZ::Get_OutputPort(int n) const {
    if (n==0) return intEy;
    if (n==1) return intWy;
    if (n==2) return intVx;
    if (n==3) return intVz;
    return nullptr;
}
