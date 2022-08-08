# CMakeLists.txt for jssender sender application

add_executable (jssender jssender.cpp ServiceTester.h)

target_link_libraries (jssender LINK_PUBLIC JoystickLibrary)