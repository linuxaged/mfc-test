cmake_minimum_required(VERSION 3.4)
cmake_policy(SET CMP0091 NEW)

project(MfcTest VERSION)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<1:${PROJECT_SOURCE_DIR}/bin/$<CONFIG>>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${PROJECT_SOURCE_DIR}/bin/$<CONFIG>>)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /utf-8 /arch:AVX2 /openmp:experimental /D _HAS_EXCEPTIONS=0")
string(REGEX REPLACE "/Ob[0-3]" "/Ob3" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REGEX REPLACE "/EHsc" "/EHs-c-" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(RESOURCE_ROOT
	res/mfc_test0.ico
)
source_group(res FILES ${RESOURCE_ROOT})

set(CMAKE_MFC_FLAG 2)
add_executable(${PROJECT_NAME} WIN32
	${RESOURCE_ROOT}
	mfctest0.rc
	pch.h
	pch.cpp
	targetver.h
	resource.h
	mfc_test0Dlg.h
	mfc_test0Dlg.cpp
	mfc_test0.h
	mfc_test0.cpp
)

target_precompile_headers( ${PROJECT_NAME} PRIVATE pch.h )
target_compile_options(${PROJECT_NAME} PRIVATE "/MP")
set_target_properties(${PROJECT_NAME} PROPERTIES
	VS_GLOBAL_KEYWORD "MFCProj"
	LINK_FLAGS "/ENTRY:\"wWinMainCRTStartup\""
)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
