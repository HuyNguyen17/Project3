#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::qopcuaxmldatatypes2cpp" for configuration "Release"
set_property(TARGET Qt6::qopcuaxmldatatypes2cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::qopcuaxmldatatypes2cpp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/qopcuaxmldatatypes2cpp.exe"
  )

list(APPEND _cmake_import_check_targets Qt6::qopcuaxmldatatypes2cpp )
list(APPEND _cmake_import_check_files_for_Qt6::qopcuaxmldatatypes2cpp "${_IMPORT_PREFIX}/bin/qopcuaxmldatatypes2cpp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
