# CMakeLists.txt for jssender sender application

add_executable (jssender jssender.cpp send_socket.cpp send_socket.hpp ServiceTester.h)

target_link_libraries (jssender LINK_PUBLIC JoystickLibrary)