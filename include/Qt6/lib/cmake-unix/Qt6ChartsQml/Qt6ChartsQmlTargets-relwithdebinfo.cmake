#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::ChartsQml" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::ChartsQml APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::ChartsQml PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "Qt6::Qml"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libQt6ChartsQml.so.6.7.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libQt6ChartsQml.so.6"
  )

list(APPEND _cmake_import_check_targets Qt6::ChartsQml )
list(APPEND _cmake_import_check_files_for_Qt6::ChartsQml "${_IMPORT_PREFIX}/lib/libQt6ChartsQml.so.6.7.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
