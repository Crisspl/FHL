cmake_minimum_required(VERSION 2.8)

project(FHL)

set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake-modules/")

set(FHL_SRCS_GRAPHICS
	src/FHL/Graphics/Buffer.cpp
	src/FHL/Graphics/Color.cpp             
	src/FHL/Graphics/ColoredRect.cpp       
	src/FHL/Graphics/Configurator.cpp      
	src/FHL/Graphics/Light.cpp             
	src/FHL/Graphics/Mesh.cpp              
	src/FHL/Graphics/Model.cpp
	src/FHL/Graphics/ModelData.cpp
	src/FHL/Graphics/RenderConf.cpp
	src/FHL/Graphics/Renderer.cpp
	src/FHL/Graphics/RenderTexture.cpp
	src/FHL/Graphics/ResMgr.cpp
	src/FHL/Graphics/Shader.cpp
	src/FHL/Graphics/shaderSrcs.cpp
	src/FHL/Graphics/Sizeable.cpp
	src/FHL/Graphics/Sprite.cpp
	src/FHL/Graphics/Texture.cpp
	src/FHL/Graphics/TexturedSizeable.cpp
	src/FHL/Graphics/Transformable.cpp
	src/FHL/Graphics/Transformable3D.cpp
	src/FHL/Graphics/Vao.cpp
	src/FHL/Graphics/VertexArray.cpp
)
set(FHL_HEADERS_GRAPHICS
	src/FHL/Graphics/Buffer.h              
	src/FHL/Graphics/Color.h				  
	src/FHL/Graphics/ColoredRect.h         
	src/FHL/Graphics/Configurator.h        
	src/FHL/Graphics/Light.h               
	src/FHL/Graphics/Litable.h             
	src/FHL/Graphics/Mesh.h              
	src/FHL/Graphics/Model.h
	src/FHL/Graphics/ModelData.h
	src/FHL/Graphics/Renderable.h
	src/FHL/Graphics/RenderConf.h
	src/FHL/Graphics/Renderer.h
	src/FHL/Graphics/RenderMatrices.h
	src/FHL/Graphics/RenderTexture.h
	src/FHL/Graphics/ResMgr.h
	src/FHL/Graphics/Shader.h
	src/FHL/Graphics/shaderSrcs.h
	src/FHL/Graphics/Sizeable.h
	src/FHL/Graphics/Sprite.h
	src/FHL/Graphics/Texture.h
	src/FHL/Graphics/TexturedSizeable.h
	src/FHL/Graphics/Transformable.h
	src/FHL/Graphics/Transformable3D.h
	src/FHL/Graphics/UsingShader.h
	src/FHL/Graphics/Vao.h
	src/FHL/Graphics/Vertex.h
	src/FHL/Graphics/VertexArray.h
	src/FHL/Graphics/View.h
)
set(FHL_SRCS_GRAPHICS_IMPL
	src/FHL/Graphics/impl/UniformLocMgr.cpp
)
set(FHL_HEADERS_GRAPHICS_IMPL
	src/FHL/Graphics/impl/UniformLocMgr.h
)

set(FHL_SRCS_MATHS
	src/FHL/Maths/Quaternion.cpp
)
set(FHL_HEADERS_MATHS
	src/FHL/Maths/BoolVec.h          
	src/FHL/Maths/Constants.h        
	src/FHL/Maths/Mat4.h           
	src/FHL/Maths/mathsFuncs.h
	src/FHL/Maths/Plane.h
	src/FHL/Maths/Quaternion.h
	src/FHL/Maths/swizzle.h
	src/FHL/Maths/Vec2.h
	src/FHL/Maths/Vec3.h
	src/FHL/Maths/Vec4.h
	src/FHL/Maths/VecBase.h
	src/FHL/Maths/vectors.h
)

set(FHL_SRCS_UTILITY
	src/FHL/Utility/Circle.cpp        
	src/FHL/Utility/Clock.cpp       
	src/FHL/Utility/Cube.cpp
	src/FHL/Utility/Debug.cpp
	src/FHL/Utility/OrientedCube.cpp
	src/FHL/Utility/OrientedRect.cpp
	src/FHL/Utility/Rect.cpp
)
set(FHL_HEADERS_UTILITY
	src/FHL/Utility/Circle.h        
	src/FHL/Utility/Clock.h
	src/FHL/Utility/Compare.h
	src/FHL/Utility/Cube.h
	src/FHL/Utility/Debug.h
	src/FHL/Utility/OrientedCube.h
	src/FHL/Utility/OrientedRect.h
	src/FHL/Utility/Rect.h
)

set(FHL_SRCS_GL
	src/FHL/GL/flextGL.cpp
	src/FHL/GL/flextGLInit.cpp
	src/FHL/GL/OpenGlLoader.cpp
)
set(FHL_HEADERS_GL
	src/FHL/GL/flextGL.h
	src/FHL/GL/OpenGL.h
	src/FHL/GL/OpenGlLoader.h
)
set(FHL_HEADERS_COMMON
	src/FHL/common.h
)

add_library(fhl SHARED 
	${FHL_SRCS_GRAPHICS} ${FHL_SRCS_GRAPHICS_IMPL} ${FHL_SRCS_MATHS} ${FHL_SRCS_UTILITY} ${FHL_SRCS_GL}
	${FHL_HEADERS_GRAPHICS} ${FHL_HEADERS_GRAPHICS_IMPL} ${FHL_HEADERS_MATHS} ${FHL_HEADERS_UTILITY} ${FHL_HEADERS_GL} ${FHL_HEADERS_COMMON}
)

source_group("Header Files\\Graphics" FILES ${FHL_HEADERS_GRAPHICS})
source_group("Source Files\\Graphics" FILES ${FHL_SRCS_GRAPHICS})
source_group("Header Files\\Graphics\\impl" FILES ${FHL_HEADERS_GRAPHICS_IMPL})
source_group("Source Files\\Graphics\\impl" FILES ${FHL_SRCS_GRAPHICS_IMPL})
source_group("Header Files\\Maths" FILES ${FHL_HEADERS_MATHS})
source_group("Source Files\\Maths" FILES ${FHL_SRCS_MATHS})
source_group("Header Files\\Utility" FILES ${FHL_HEADERS_UTILITY})
source_group("Source Files\\Utility" FILES ${FHL_SRCS_UTILITY})
source_group("Header Files\\GL" FILES ${FHL_HEADERS_GL})
source_group("Source Files\\GL" FILES ${FHL_SRCS_GL})
source_group("Header Files" FILES ${FHL_HEADERS_COMMON})
	
find_package(assimp REQUIRED)
find_package(SOIL REQUIRED)
find_package(OpenGL REQUIRED)

set(LINK_LIBS ${ASSIMP_LIBRARY} ${SOIL_LIBRARIES} ${OPENGL_gl_LIBRARY})
if (UNIX)
	list(APPEND LINK_LIBS "{CMAKE_DL_LIBS}")
endif()

target_include_directories(fhl PUBLIC ${ASSIMP_INCLUDE_DIR} ${SOIL_INCLUDE_PATH} src/)
target_link_libraries(fhl ${LINK_LIBS})

set_target_properties(fhl PROPERTIES DEBUG_POSTFIX -d)

if(MSVC)
	target_compile_options(fhl PUBLIC "/Qvec-report:1") 
	# msvc bug, for some reason it works fine with this option
endif()

add_definitions(-DFHL_TARGET_SHARED -DNOMINMAX)
if(WIN32)
	add_definitions(-DFHL_PLATFORM_WINDOWS)
elseif(APPLE)
	add_definitions(-DFHL_PLATFORM_APPLE)
endif()
