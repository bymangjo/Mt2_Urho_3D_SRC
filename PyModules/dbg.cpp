/*
	File: dbg.cpp

	Implemention of Python debug module
*/
#include "../BuildConfig.h"

#include <pybind11/embed.h>
#include <Urho3D/IO/Log.h>
#include <SDL/SDL.h>

static void dbgLogBox(std::string message)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, DEFAULT_NAME, message.c_str(), nullptr);
}

static void dbgTrace(std::string message)
{
	URHO3D_LOGINFOF("dbg.Trace: %s\n", message.c_str());
}

static void dbgTracen(std::string message)
{
	URHO3D_LOGINFOF("dbg.Tracen: %s\n", message.c_str());
}

static void dbgTraceError(std::string message)
{
	URHO3D_LOGERROR(message.c_str());
}

PYBIND11_EMBEDDED_MODULE(dbg, m)
{
	m.def("LogBox", dbgLogBox);
	m.def("Trace", dbgTrace);
	m.def("Tracen", dbgTracen);
	m.def("TraceError", dbgTraceError);
}
