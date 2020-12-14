#pragma once

#include <pybind11/embed.h> // everything needed for embedding
#include <Urho3D/Core/Object.h>

class Python : public Urho3D::Object
{
public:
	URHO3D_OBJECT(Python, Urho3D::Object);

	Python(Urho3D::Context* context);
	~Python();

	void LoadScript(const char* scriptName);

	void Initialize(const char* arguments);
	bool IsInitialized();

	const char* GetVersion();

protected:
	void PatchBuiltins(const char* arguments);

	pybind11::scoped_interpreter Interpreter;
};

