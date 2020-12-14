/*
	File: app.cpp
	
	Implemention of Python application module
*/
#include "../Game.h"

#include <Urho3D/IO/Log.h>
#include <Urho3D/Graphics/Graphics.h>

using namespace Urho3D;

enum class CursorImages
{
	Normal,
	Attack,
	Target,
	Talk,
	Cant_Go,
	Pick,
	Door,
	Chair,
	Magic,
	Buy,
	Sell,
	Camera_Rotate,
	HSize,
	VSize,
	HVSize,
};

static void appAbort()
{
	URHO3D_LOGINFO("app.Abort");
	Game::Instance()->GetSubsystem<Engine>()->Exit();
}

static std::string appGetLocalePath()
{
	return "locale/it";
}

static std::string appGetLocaleServiceName()
{
	return "ITALY";
}

static int appGetDefaultCodepage()
{
	return 1152;
}

static void appSetDefaultFontName(std::string fontName)
{
	URHO3D_LOGINFOF("app.SetDefaultFontName: %s\n", fontName.c_str());
}

static void appSetMouseHandler(pybind11::object handler)
{

}

static void appSetHairColorEnable(bool enable)
{

}

static void appCreate(std::string windowTitle, unsigned int width, unsigned int height, bool windowed)
{
	Graphics* graphics = Game::Instance()->GetSubsystem<Graphics>();

	graphics->SetWindowTitle(windowTitle.c_str());
	graphics->SetMode(width, height);

	// @todo: fullscreen
}

static void appSetCursor(int id)
{

}

PYBIND11_EMBEDDED_MODULE(app, m)
{
	m.def("Abort", appAbort);
	m.def("GetLocalePath", appGetLocalePath);
	m.def("GetLocaleServiceName", appGetLocaleServiceName);
	m.def("GetDefaultCodePage", appGetDefaultCodepage);
	m.def("SetDefaultFontName", appSetDefaultFontName);
	m.def("SetMouseHandler", appSetMouseHandler);
	m.def("SetHairColorEnable", appSetHairColorEnable);
	m.def("Create", appCreate);
	m.def("SetCursor", appSetCursor);

	// Cursors
	m.attr("NORMAL") = (int)CursorImages::Normal;
	m.attr("ATTACK") = (int)CursorImages::Attack;
	m.attr("TARGET") = (int)CursorImages::Target;
	m.attr("TALK") = (int)CursorImages::Talk;
	m.attr("CANT_GO") = (int)CursorImages::Cant_Go;
	m.attr("PICK") = (int)CursorImages::Pick;
	m.attr("DOOR") = (int)CursorImages::Door;
	m.attr("CHAIR") = (int)CursorImages::Chair;
	m.attr("MAGIC") = (int)CursorImages::Magic;
	m.attr("BUY") = (int)CursorImages::Buy;
	m.attr("SELL") = (int)CursorImages::Sell;
	m.attr("CAMERA_ROTATE") = (int)CursorImages::Camera_Rotate;
	m.attr("HSIZE") = (int)CursorImages::HSize;
	m.attr("VSIZE") = (int)CursorImages::VSize;
	m.attr("HVSIZE") = (int)CursorImages::HVSize;
}
