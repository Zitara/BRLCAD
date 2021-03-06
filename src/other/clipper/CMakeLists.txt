# Minimum required version of CMake
cmake_minimum_required(VERSION 2.8)
if(COMMAND CMAKE_POLICY)
  CMAKE_POLICY(SET CMP0003 NEW)
endif(COMMAND CMAKE_POLICY)

# Set CMake project name
project(CLIPPER)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

if(NOT LIB_DIR)
  set(LIB_DIR lib)
endif(NOT LIB_DIR)
if(NOT BIN_DIR)
  set(BIN_DIR bin)
endif(NOT BIN_DIR)

if(NOT DEFINED BUILD_SHARED_LIBS)
  set(BUILD_SHARED_LIBS ON)
endif(NOT DEFINED BUILD_SHARED_LIBS)

if(BUILD_SHARED_LIBS)
  add_library(clipper SHARED clipper.cpp)
  set_target_properties(clipper PROPERTIES VERSION 4.6.0 SOVERSION 4)
  if(MSVC)
    set_property(TARGET clipper APPEND PROPERTY COMPILE_DEFINITIONS "CLIPPER_DLL_EXPORTS")
  endif(MSVC)
  install(TARGETS clipper
    RUNTIME DESTINATION ${BIN_DIR}
    LIBRARY DESTINATION ${LIB_DIR}
    ARCHIVE DESTINATION ${LIB_DIR})
endif(BUILD_SHARED_LIBS)

if(BUILD_STATIC_LIBS)
  add_library(clipper-static STATIC clipper.cpp)
  if(MSVC)
    # msvc does not append 'lib' - do it here to have consistent name
    set_target_properties(clipper-static PROPERTIES PREFIX "lib")
  else(MSVC)  
    set_target_properties(clipper-static PROPERTIES OUTPUT_NAME "clipper")
  endif(MSVC)
  install(TARGETS clipper-static
    RUNTIME DESTINATION ${BIN_DIR}
    LIBRARY DESTINATION ${LIB_DIR}
    ARCHIVE DESTINATION ${LIB_DIR})
endif(BUILD_STATIC_LIBS)

install(FILES clipper.hpp DESTINATION include)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8

