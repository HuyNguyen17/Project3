# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "3.1.0")
   message(FATAL_ERROR "CMake >= 3.1.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 3.1.0...3.27)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS Qt6::qmlcachegen Qt6::qmldom Qt6::qmllint Qt6::qmltc Qt6::qmltyperegistrar Qt6::qmljsrootgen Qt6::qmlimportscanner Qt6::qmlformat Qt6::qmlprofiler Qt6::qmltime Qt6::qmlplugindump Qt6::qmltestrunner)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target Qt6::qmlcachegen
add_executable(Qt6::qmlcachegen IMPORTED)

set_target_properties(Qt6::qmlcachegen PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmldom
add_executable(Qt6::qmldom IMPORTED)

set_target_properties(Qt6::qmldom PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmllint
add_executable(Qt6::qmllint IMPORTED)

set_target_properties(Qt6::qmllint PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmltc
add_executable(Qt6::qmltc IMPORTED)

set_target_properties(Qt6::qmltc PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmltyperegistrar
add_executable(Qt6::qmltyperegistrar IMPORTED)

set_target_properties(Qt6::qmltyperegistrar PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmljsrootgen
add_executable(Qt6::qmljsrootgen IMPORTED)

set_target_properties(Qt6::qmljsrootgen PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmlimportscanner
add_executable(Qt6::qmlimportscanner IMPORTED)

set_target_properties(Qt6::qmlimportscanner PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmlformat
add_executable(Qt6::qmlformat IMPORTED)

set_target_properties(Qt6::qmlformat PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmlprofiler
add_executable(Qt6::qmlprofiler IMPORTED)

set_target_properties(Qt6::qmlprofiler PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmltime
add_executable(Qt6::qmltime IMPORTED)

set_target_properties(Qt6::qmltime PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmlplugindump
add_executable(Qt6::qmlplugindump IMPORTED)

set_target_properties(Qt6::qmlplugindump PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Create imported target Qt6::qmltestrunner
add_executable(Qt6::qmltestrunner IMPORTED)

set_target_properties(Qt6::qmltestrunner PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_QT_MAJOR_VERSION "6"
  _qt_package_version "6.7.0"
)

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/Qt6QmlToolsTargets-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
endforeach()
unset(_cmake_config_file)
unset(_cmake_config_files)

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(_cmake_target IN LISTS _cmake_import_check_targets)
  if(CMAKE_VERSION VERSION_LESS "3.28"
      OR NOT DEFINED _cmake_import_check_xcframework_for_${_cmake_target}
      OR NOT IS_DIRECTORY "${_cmake_import_check_xcframework_for_${_cmake_target}}")
    foreach(_cmake_file IN LISTS "_cmake_import_check_files_for_${_cmake_target}")
      if(NOT EXISTS "${_cmake_file}")
        message(FATAL_ERROR "The imported target \"${_cmake_target}\" references the file
   \"${_cmake_file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
      endif()
    endforeach()
  endif()
  unset(_cmake_file)
  unset("_cmake_import_check_files_for_${_cmake_target}")
endforeach()
unset(_cmake_target)
unset(_cmake_import_check_targets)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
