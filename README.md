# Robbie02
# This project isn't finished!!!

# What is it?
This is 3D-scene

# Development
- language: c++
- compiler: MinGW
- development environment: Visual Studio Code
- 3D library: OpenGL (freeglut.dll)*

*) The library needs put to the folder "bin". If the folder "bin" don't exist, create it in the root of the project.

# Compilation
The project's settings lie in folder ".vs code".
You need to rewrite paths for compilation.
Write yours path to the "gcc" compiler:
- "c_cpp_properties.json" setting "compilerPath"
- "launch.json" setting "miDebuggerPath"
- "tasks.json" setting "label" и "command"

# Run projects in Visual Studio Code:
- Start debugging "F5"
- Run without debugging "Ctrl+F5"

# The project content.
- The function "main" lie in file "Robbie.cpp"
- The folder "include" contains headers files.
- The folder "source" contains code:
- - "events" - handling keyboard and mouse events.
- - "geometry" - processing of camera and scene objects.
- - "objects" - base classes for scene objects.
- - "system" - settings and program logs.
- - "windows" - creating the scene.

# After compilation and launch, the following files and folders will be created in the "bin" folder:
- folder "logs" - text logs ("DD-MM-YYYY.logs").
- folder "scena" - for save scene (format file - txt).
- freeglut.dll - the OpenGL library.
- "Robbie.exe" - executable file
- "settings.conf" - application settings (keyboard shortcuts, window sizes).

# Default keyboard shortcuts ("~/source/events/KeyHandler.cpp")
- Exit="ESC",'q'
- Turn left="LEFT"
- Forward="UP"
- Turn right="RIGHT"
- back="DOWN"   
- up="PAGE_UP"     
- down="PAGE_DOWN"   
- The first control method of camera="F1"
- The second control method of camera="F2"
- Centering the camera view="F3"
- Setting the default camera view="F4"
- Quick loading of the scene="F5"
