#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::MultimediaQuickPrivate" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::MultimediaQuickPrivate APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::MultimediaQuickPrivate PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "Qt6::Qml;Qt6::Core"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libQt6MultimediaQuick.so.6.7.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libQt6MultimediaQuick.so.6"
  )

list(APPEND _cmake_import_check_targets Qt6::MultimediaQuickPrivate )
list(APPEND _cmake_import_check_files_for_Qt6::MultimediaQuickPrivate "${_IMPORT_PREFIX}/lib/libQt6MultimediaQuick.so.6.7.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
