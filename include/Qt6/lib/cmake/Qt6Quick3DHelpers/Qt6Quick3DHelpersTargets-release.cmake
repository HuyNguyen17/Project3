#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Quick3DHelpers" for configuration "Release"
set_property(TARGET Qt6::Quick3DHelpers APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::Quick3DHelpers PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQt6Quick3DHelpers.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt6::Quick3D;Qt6::Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6Quick3DHelpers.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::Quick3DHelpers )
list(APPEND _cmake_import_check_files_for_Qt6::Quick3DHelpers "${_IMPORT_PREFIX}/lib/libQt6Quick3DHelpers.a" "${_IMPORT_PREFIX}/bin/Qt6Quick3DHelpers.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
