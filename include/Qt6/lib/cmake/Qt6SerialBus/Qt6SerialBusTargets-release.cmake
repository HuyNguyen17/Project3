#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::SerialBus" for configuration "Release"
set_property(TARGET Qt6::SerialBus APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::SerialBus PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQt6SerialBus.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6SerialBus.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::SerialBus )
list(APPEND _cmake_import_check_files_for_Qt6::SerialBus "${_IMPORT_PREFIX}/lib/libQt6SerialBus.a" "${_IMPORT_PREFIX}/bin/Qt6SerialBus.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
