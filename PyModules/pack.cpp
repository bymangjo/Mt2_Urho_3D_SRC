/*
	File: pack.cpp

	Implemention of Python pack file module
*/
#include "../Game.h"

#include <pybind11/stl.h>

#include <Urho3D/IO/Log.h>
#include <Urho3D/IO/FileSystem.h>

#include <fstream>

namespace py = pybind11;

bool packExist(std::string fileName)
{
	URHO3D_LOGDEBUGF("pack.Exist: %s", fileName.c_str());

	auto fileSystem = Game::Instance()->GetSubsystem<Urho3D::FileSystem>();

	return fileSystem->FileExists(fileName.c_str());
}

py::handle packGet(std::string fileName)
{
	// todo: migrate
	URHO3D_LOGDEBUGF("pack.Get: %s\n", fileName.c_str());

	std::ifstream f(fileName, std::fstream::binary);
	if (!f.is_open())
	{
		std::string exception = "Unable to find file: ";
		exception += fileName;
		throw std::exception(exception.c_str());
	}

	f.seekg(0, f.end);
	size_t size = (size_t)f.tellg();
	f.seekg(0, f.beg);

	std::vector<uint8_t> data;
	data.resize(size);
	data.reserve(size);

	f.read((char*)data.data(), size);
	f.close();

	PyObject* object = Py_BuildValue("s#", data.data(), size);
	return py::handle(object);
}


PYBIND11_EMBEDDED_MODULE(pack, m)
{
	m.def("Exist", packExist);
	m.def("Get", packGet);
}
