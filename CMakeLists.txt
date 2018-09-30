cmake_minimum_required(VERSION 3.9)
project(GluonEngine)

message(${CMAKE_SOURCE_DIR})

# set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD 11)

add_executable(GluonEngine
        GluonEngine/src/Entity/ComponentIds.h
        GluonEngine/src/Entity/Entity.cpp
        GluonEngine/src/Entity/Entity.h
        GluonEngine/src/Entity/EntityComponent.h
        GluonEngine/src/Entity/MaterialComponent.cpp
        GluonEngine/src/Entity/MaterialComponent.h
        GluonEngine/src/Entity/RenderComponent.cpp
        GluonEngine/src/Entity/RenderComponent.h
        GluonEngine/src/Entity/SpinningComponent.cpp
        GluonEngine/src/Entity/SpinningComponent.h
        GluonEngine/src/Files/FileUtils.cpp
        GluonEngine/src/Files/FileUtils.h
        GluonEngine/src/Graphics/BufferedRenderer.cpp
        GluonEngine/src/Graphics/BufferedRenderer.h
        GluonEngine/src/Graphics/Camera.h
        GluonEngine/src/Graphics/Common.h
        GluonEngine/src/Graphics/FPSCamera.cpp
        GluonEngine/src/Graphics/FPSCamera.h
        GluonEngine/src/Graphics/IndexedModel.h
        GluonEngine/src/Graphics/Mesh.cpp
        GluonEngine/src/Graphics/Mesh.h
        GluonEngine/src/Graphics/OpenGLRenderDevice.cpp
        GluonEngine/src/Graphics/OpenGLRenderDevice.h
        GluonEngine/src/Graphics/OrthographicCamera.cpp
        GluonEngine/src/Graphics/OrthographicCamera.h
        GluonEngine/src/Graphics/RenderDevice.h
        GluonEngine/src/Graphics/Renderer.h
        GluonEngine/src/Graphics/RenderTarget.cpp
        GluonEngine/src/Graphics/RenderTarget.h
        GluonEngine/src/Graphics/Shader.cpp
        GluonEngine/src/Graphics/Shader.h
        GluonEngine/src/Graphics/Texture.cpp
        GluonEngine/src/Graphics/Texture.h
        GluonEngine/src/Graphics/Transform.cpp
        GluonEngine/src/Graphics/Transform.h
        GluonEngine/src/Graphics/Vertex.h
        GluonEngine/src/Graphics/Window.cpp
        GluonEngine/src/Graphics/Window.h
        GluonEngine/src/Lib/stb_image.h
        GluonEngine/src/Bundles.h
        GluonEngine/src/Common.h
        GluonEngine/src/Game.cpp
        GluonEngine/src/Game.h
        GluonEngine/src/Layer.cpp
        GluonEngine/src/Layer.h
        GluonEngine/src/Scene.cpp
        GluonEngine/src/Scene.h
        GluonEngine/src/Timer.h
        GluonEngine/main.cpp
        GluonEngine/TestGame.cpp
        GluonEngine/TestLayer.cpp
        GluonEngine/TestLayer.h
        GluonEngine/TestLayer2D.cpp
        GluonEngine/TestLayer2D.h
        GluonEngine/glad.c GluonEngine/src/Input/KeyboardInputManager.cpp GluonEngine/src/Input/KeyboardInputManager.h GluonEngine/src/Input/InputStatus.cpp GluonEngine/src/Input/InputStatus.h GluonEngine/src/Input/Keys.h GluonEngine/src/Input/InputManager.cpp GluonEngine/src/Input/InputManager.h)

target_compile_definitions(GluonEngine PRIVATE GLEW_STATIC)

include_directories(GluonEngine ${CMAKE_SOURCE_DIR}/dep/incl)
target_link_libraries(GluonEngine -L${CMAKE_SOURCE_DIR}/dep/lib)
target_link_libraries(GluonEngine glfw3)