
#set(CMAKE_BUILD_TYPE Debug)

if(NOT ENABLE_GUI)
  return()
endif()

option(BUILD_JVRC_PLUGIN "Building a plugin and a customizer for JVRC" OFF)
if(NOT BUILD_JVRC_PLUGIN)
  return()
endif()
if(NOT BUILD_PYTHON_PLUGIN)
  message(FATAL_ERROR "DRCUserInterfacePlugin requires PythonPlugin")
endif()

set(sources
  JVRCPlugin.cpp
  JVRCTask.cpp
  JVRCManagerItem.cpp
  JVRCScoreView.cpp
  SphereMarkerDevice.cpp
  SceneNodeFinder.cpp
)

set(target CnoidJVRCPlugin)
make_gettext_mofiles(${target} mofiles)
add_cnoid_plugin(${target} SHARED ${sources} ${mofiles})
target_link_libraries(${target} CnoidBodyPlugin)
apply_common_setting_for_plugin(${target})

file(MAKE_DIRECTORY ${CNOID_SOURCE_SHARE_DIR}/jvrc)

configure_file(JVRC-Task-R3_A.yaml ${CNOID_SOURCE_SHARE_DIR}/jvrc COPYONLY)

configure_file(JVRC-Robot-Marker.wrl ${CNOID_SOURCE_SHARE_DIR}/jvrc COPYONLY)

install(DIRECTORY ${CNOID_SOURCE_SHARE_DIR}/jvrc DESTINATION ${CNOID_SHARE_SUBDIR})

add_subdirectory(customizer)
add_subdirectory(python)
