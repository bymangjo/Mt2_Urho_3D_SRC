/*
	File: grp.cpp

	Implemention of Python graphic module
*/
#include <pybind11/embed.h>

uint32_t grpGenerateColor(float r, float g, float b, float a)
{
	return 0x0; // todo
}

PYBIND11_EMBEDDED_MODULE(grp, m)
{
	m.def("GenerateColor", grpGenerateColor);
}
