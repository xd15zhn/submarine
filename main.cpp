#include <iostream>
#include <cmath>
#include "submarine.hpp"

int main(void) {
    Simulator sim1(0.01);
    FUInput(inF, &sim1);
    FUConstant(inEa, &sim1);
    FUConstant(inEe, &sim1);
    FUOutput(outVx, &sim1);
    SubmarineXZ *tf = new SubmarineXZ(&sim1, "tf");
    sim1.connectU(inEa, tf, 0);
    sim1.connectU(inEe, tf, 1);
    sim1.connectU(inF, tf, 2);
    sim1.connectU(tf, 2, outVx);
    inEa->Set_OutValue(0);
    inEe->Set_OutValue(0);
    inF->Set_Function([](double t){return 0.001*sin(1000*t);});
    // sim1.Set_DivergenceCheckMode(2);
    sim1.Initialize();
    for (size_t i = 0; i < 10; i++) {
        sim1.Simulate_OneStep();
        cout << tf->intVz->Get_OutValue() << endl;
    }
    // sim1.Simulate();
    // sim1.Plot();
    return 0;
}
