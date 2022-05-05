#pragma once
#include "systemc.h"

SC_MODULE(s1_unit)
{
	sc_in<int> x_in, y_in;
	sc_out<int> pow_out, f1_out;

	void outPOW()
	{
		pow_out.write(x_in.read() - y_in.read());
	}

	void outF1()
	{
		f1_out.write(x_in.read() * ((y_in.read() * (y_in.read() + 1)) / 2));

	}

	SC_CTOR(s1_unit)
	{
		SC_METHOD(outF1);

		sensitive << x_in << y_in;
	}
};
