#include "systemc.h"
#include "Stimulator.h"
#include "Monitor.h"
#include "s1_unit.h"
#include "s2_unit.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<int> XSig, YSig;
	sc_signal<int> POWSig, F1Sig;
	sc_signal<int> R1Sig, R2Sig, R8Sig;

	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);

	Stimulator Stim1("stim");
	Stim1.X(XSig);
	Stim1.Y(YSig);
	Stim1.CLK(TestClk);

	s1_unit first_part("s1_unit");
	first_part.x_in(XSig);
	first_part.y_in(YSig);
	first_part.pow_out(POWSig);
	first_part.f1_out(F1Sig);

	s2_unit second_part("s2_unit");
	second_part.pow_in(POWSig);
	second_part.f1_in(F1Sig);
	second_part.r1(R1Sig);
	second_part.r2(R2Sig);
	second_part.r8(R8Sig);
	

	Monitor Monitor1("monitor");
	Monitor1.X(XSig);
	Monitor1.Y(YSig);
	Monitor1.POW(POWSig);
	Monitor1.F1(F1Sig);
	Monitor1.R1(R1Sig);
	Monitor1.R2(R2Sig);
	Monitor1.R8(R8Sig);
	Monitor1.CLK(TestClk);

	sc_start();

	return 0;
}
