#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::3DRender" for configuration "Release"
set_property(TARGET Qt6::3DRender APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::3DRender PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQt63DRender.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt6::Concurrent"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt63DRender.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::3DRender )
list(APPEND _cmake_import_check_files_for_Qt6::3DRender "${_IMPORT_PREFIX}/lib/libQt63DRender.a" "${_IMPORT_PREFIX}/bin/Qt63DRender.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)