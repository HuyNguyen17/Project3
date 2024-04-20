#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::DataVisualization" for configuration "Release"
set_property(TARGET Qt6::DataVisualization APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::DataVisualization PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQt6DataVisualization.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6DataVisualization.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::DataVisualization )
list(APPEND _cmake_import_check_files_for_Qt6::DataVisualization "${_IMPORT_PREFIX}/lib/libQt6DataVisualization.a" "${_IMPORT_PREFIX}/bin/Qt6DataVisualization.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)