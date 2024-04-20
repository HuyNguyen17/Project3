#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::DeclarativeOpcua" for configuration "Release"
set_property(TARGET Qt6::DeclarativeOpcua APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::DeclarativeOpcua PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQt6DeclarativeOpcua.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt6::Qml"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6DeclarativeOpcua.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::DeclarativeOpcua )
list(APPEND _cmake_import_check_files_for_Qt6::DeclarativeOpcua "${_IMPORT_PREFIX}/lib/libQt6DeclarativeOpcua.a" "${_IMPORT_PREFIX}/bin/Qt6DeclarativeOpcua.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)