#pragma once
#include "systemc.h"
#include "s1_unit.h"

SC_MODULE(s2_unit)
{
	sc_in<int> pow_in, f1_in;
	sc_out<int> r1, r2, r8;

	void OutR1()
	{
		int result = pow_in.read() & f1_in.read();
		r1.write(result);
	}

	void OutR2()
	{
		OutR1();
		r2.write((!(pow_in.read() & f1_in.read())));
	}
	void OutR8()
	{
		
		r8.write(88);
	}
	SC_CTOR(s2_unit)
	{
		SC_METHOD(OutR8);

		sensitive << pow_in << f1_in;
	}
};
