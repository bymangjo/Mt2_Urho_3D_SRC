/*
	File: wndMgr.cpp

	Implemention of Python window manager module
*/
#include "../Game.h"

#include <Urho3D/UI/UI.h>

static void wndMgrSetAttachingFlag(bool flag)
{

}

static void wndMgrSetMouseHandler(pybind11::object handler)
{

}

static void wndMgrSetScreenSize(unsigned int width, unsigned int height)
{

}

static void wndMgrRegisterNumberLine(pybind11::object obj, std::string layer)
{
	auto ui = Game::Instance()->GetSubsystem<Urho3D::UI>();

//	ui->Window
}

PYBIND11_EMBEDDED_MODULE(wndMgr, m)
{
	m.def("SetAttachingFlag", wndMgrSetAttachingFlag);
	m.def("SetMouseHandler", wndMgrSetMouseHandler);
	m.def("SetScreenSize", wndMgrSetScreenSize);
}
