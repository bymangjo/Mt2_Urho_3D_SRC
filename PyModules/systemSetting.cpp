/*
	File: systemSetting.cpp

	Implemention of Python game settings module
*/
#include <pybind11/embed.h>

static unsigned int GetWidth()
{
	return 800;
}

static unsigned int GetHeight()
{
	return 600;
}

static bool IsSoftwareCursor()
{
	return false;
}

PYBIND11_EMBEDDED_MODULE(systemSetting, m)
{
	m.def("GetWidth", GetWidth);
	m.def("GetHeight", GetHeight);
	m.def("IsSoftwareCursor", IsSoftwareCursor);
}
