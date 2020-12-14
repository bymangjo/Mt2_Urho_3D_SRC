#include "Python.h"

#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/IO/File.h>

#include <fstream>

namespace py = pybind11;
using namespace Urho3D;

Python::Python(Context* context) :
	Object(context)
{

}

Python::~Python()
{

}

bool Python::IsInitialized()
{
	return Py_IsInitialized();
}

void Python::Initialize(const char* arguments)
{
	Py_SetProgramName(const_cast<char*>("Urho3D-Metin2"));
	//Py_SetPythonHome((char*)(current_path().string() + "\\lib").c_str());

	PatchBuiltins(arguments);


}

const char* Python::GetVersion()
{
	return Py_GetVersion();
}

void Python::LoadScript(const char* scriptName)
{
	if (!IsInitialized())
		throw new std::exception("Python interpreter not initialized!");

	File runScript(context_, scriptName, FILE_READ);

	if (!runScript.IsOpen())
	{
		std::string str = "The specified run script file ";
		str += scriptName;
		str += " does not exists!";
		throw new std::exception(str.c_str());
	}

	pybind11::dict mainNamespace = pybind11::cast<pybind11::dict>(pybind11::module::import("__main__").attr("__dict__"));

	pybind11::exec("import __main__", mainNamespace, mainNamespace);

	auto fileSize = runScript.GetSize();
	auto fileContent = std::make_unique<char[]>(fileSize + 1);

	runScript.Read(fileContent.get(), fileSize);
	fileContent.get()[fileSize] = '\0';
	runScript.Close();


	std::string runString = "exec(compile('''";
	runString += fileContent.get();
	runString += "''', '";
	runString += scriptName;
	runString += "', 'exec'))";

	auto obj = PyUnicode_Decode(runString.c_str(), runString.length(), "cp949", nullptr);

	if (!obj)
	{
		throw new std::exception("Unable to decode string");
	}

	auto str = PyUnicode_AsUTF8String(obj);

	if (!str)
	{
		Py_DECREF(obj);
		throw new std::exception("Cannot get converted string as UTF-8");
	}

	pybind11::exec(py::str(str), mainNamespace, mainNamespace);

	Py_DECREF(str);
	Py_DECREF(obj);
}

void Python::PatchBuiltins(const char* arguments)
{
	pybind11::module builtins = pybind11::module::import("__builtin__");

	// New root mitigation
	builtins.attr("__USE_CYTHON__") = 0;

#ifdef _DEBUG
	builtins.attr("__DEBUG__") = 1;
#else
	builtins.attr("__DEBUG__") = 0;
#endif

	builtins.attr("__COMMAND_LINE__") = arguments;

	builtins.attr("TRUE") = true;
	builtins.attr("FALSE") = false;
}
