#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QQuick3DProfilerAdapterFactoryPlugin" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::QQuick3DProfilerAdapterFactoryPlugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::QQuick3DProfilerAdapterFactoryPlugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELWITHDEBINFO ""
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/./plugins/qmltooling/libqmldbg_quick3dprofiler.so"
  IMPORTED_NO_SONAME_RELWITHDEBINFO "TRUE"
  )

list(APPEND _cmake_import_check_targets Qt6::QQuick3DProfilerAdapterFactoryPlugin )
list(APPEND _cmake_import_check_files_for_Qt6::QQuick3DProfilerAdapterFactoryPlugin "${_IMPORT_PREFIX}/./plugins/qmltooling/libqmldbg_quick3dprofiler.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)