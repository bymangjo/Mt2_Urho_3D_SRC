#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/Input/Input.h>

#include "Python.h"

// All Urho3D classes reside in namespace Urho3D
using namespace Urho3D;

class Game : public Application
{
    // Enable type information.
    URHO3D_OBJECT(Game, Application);

public:
    /// Construct.
    Game(Context* context);

    /// Setup before engine initialization. Modifies the engine parameters.
    virtual void Setup();
    /// Setup after engine initialization. Creates the logo, console & debug HUD.
    virtual void Start();
    /// Cleanup after the main loop. Called by Application.
    virtual void Stop();

    static Game* Instance() { return instance_; }
protected:
    /// Mouse mode option to use in the sample.
    MouseMode useMouseMode_;
    Python python_;

    static Game* instance_;

private:
    /// Set custom window Title & Icon
    void SetWindowTitleAndIcon();
    /// Initialize mouse mode on non-web platform.
    void InitMouseMode(MouseMode mode);
    /// Create console and debug HUD.
    void CreateConsoleAndDebugHud();
    /// Handle request for mouse mode on web platform.
    void HandleMouseModeRequest(StringHash eventType, VariantMap& eventData);
    /// Handle request for mouse mode change on web platform.
    void HandleMouseModeChange(StringHash eventType, VariantMap& eventData);
    /// Handle key down event to process key controls common to all samples.
    void HandleKeyDown(StringHash eventType, VariantMap& eventData);
    /// Handle key up event to process key controls common to all samples.
    void HandleKeyUp(StringHash eventType, VariantMap& eventData);
};