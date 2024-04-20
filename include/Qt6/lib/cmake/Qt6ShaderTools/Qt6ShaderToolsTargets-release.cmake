#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::ShaderTools" for configuration "Release"
set_property(TARGET Qt6::ShaderTools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::ShaderTools PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQt6ShaderTools.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6ShaderTools.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::ShaderTools )
list(APPEND _cmake_import_check_files_for_Qt6::ShaderTools "${_IMPORT_PREFIX}/lib/libQt6ShaderTools.a" "${_IMPORT_PREFIX}/bin/Qt6ShaderTools.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
