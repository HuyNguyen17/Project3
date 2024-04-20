#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Quick3DHelpersImpl" for configuration "Release"
set_property(TARGET Qt6::Quick3DHelpersImpl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::Quick3DHelpersImpl PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQt6Quick3DHelpersImpl.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt6::Qml;Qt6::Quick;Qt6::Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6Quick3DHelpersImpl.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::Quick3DHelpersImpl )
list(APPEND _cmake_import_check_files_for_Qt6::Quick3DHelpersImpl "${_IMPORT_PREFIX}/lib/libQt6Quick3DHelpersImpl.a" "${_IMPORT_PREFIX}/bin/Qt6Quick3DHelpersImpl.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)