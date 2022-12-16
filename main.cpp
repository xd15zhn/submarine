#include "submarine.hpp"

int main(void) {
    Simulator sim1;
    FUInput(inF, &sim1);
    FUConstant(inEa, &sim1);
    FUConstant(inEe, &sim1);
    FUOutput(outVx, &sim1);
    SubmarineXZ *tf = new SubmarineXZ(&sim1, "tf");
    sim1.connectU(inEa, tf, 0);
    sim1.connectU(inEe, tf, 1);
    sim1.connectU(inF, tf, 2);
    sim1.connectU(tf, 2, outVx);
    inF->Set_Function([](double t){return 1e-3;});
    sim1.Initialize();
    sim1.Simulate();
    sim1.Plot();
    return 0;
}
