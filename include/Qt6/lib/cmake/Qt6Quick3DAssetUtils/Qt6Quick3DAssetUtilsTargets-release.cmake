#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Quick3DAssetUtils" for configuration "Release"
set_property(TARGET Qt6::Quick3DAssetUtils APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::Quick3DAssetUtils PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQt6Quick3DAssetUtils.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt6::Qml"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6Quick3DAssetUtils.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::Quick3DAssetUtils )
list(APPEND _cmake_import_check_files_for_Qt6::Quick3DAssetUtils "${_IMPORT_PREFIX}/lib/libQt6Quick3DAssetUtils.a" "${_IMPORT_PREFIX}/bin/Qt6Quick3DAssetUtils.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
