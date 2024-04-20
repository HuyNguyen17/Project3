# Additional target information for Qt6QuickControls2WindowsStyleImpl
if(NOT DEFINED QT_DEFAULT_IMPORT_CONFIGURATION)
    set(QT_DEFAULT_IMPORT_CONFIGURATION RELEASE)
endif()
__qt_internal_promote_target_to_global_checked(Qt6::QuickControls2WindowsStyleImpl)
get_target_property(_qt_imported_location Qt6::QuickControls2WindowsStyleImpl IMPORTED_LOCATION_RELEASE)
get_target_property(_qt_imported_implib Qt6::QuickControls2WindowsStyleImpl IMPORTED_IMPLIB_RELEASE)
get_target_property(_qt_imported_location_default Qt6::QuickControls2WindowsStyleImpl IMPORTED_LOCATION_${QT_DEFAULT_IMPORT_CONFIGURATION})
get_target_property(_qt_imported_implib_default Qt6::QuickControls2WindowsStyleImpl IMPORTED_IMPLIB_${QT_DEFAULT_IMPORT_CONFIGURATION})

# Import target "Qt6::QuickControls2WindowsStyleImpl" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::QuickControls2WindowsStyleImpl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)

if(_qt_imported_location)
    set_property(TARGET Qt6::QuickControls2WindowsStyleImpl PROPERTY IMPORTED_LOCATION_RELWITHDEBINFO "${_qt_imported_location}")
endif()
if(_qt_imported_implib)
    set_property(TARGET Qt6::QuickControls2WindowsStyleImpl PROPERTY IMPORTED_IMPLIB_RELWITHDEBINFO "${_qt_imported_implib}")
endif()

# Import target "Qt6::QuickControls2WindowsStyleImpl" for configuration "MinSizeRel"
set_property(TARGET Qt6::QuickControls2WindowsStyleImpl APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)

if(_qt_imported_location)
    set_property(TARGET Qt6::QuickControls2WindowsStyleImpl PROPERTY IMPORTED_LOCATION_MINSIZEREL "${_qt_imported_location}")
endif()
if(_qt_imported_implib)
    set_property(TARGET Qt6::QuickControls2WindowsStyleImpl PROPERTY IMPORTED_IMPLIB_MINSIZEREL "${_qt_imported_implib}")
endif()

# Default configuration
if(_qt_imported_location_default)
    set_property(TARGET Qt6::QuickControls2WindowsStyleImpl PROPERTY IMPORTED_LOCATION "${_qt_imported_location_default}")
endif()
if(_qt_imported_implib_default)
    set_property(TARGET Qt6::QuickControls2WindowsStyleImpl PROPERTY IMPORTED_IMPLIB "${_qt_imported_implib_default}")
endif()
__qt_internal_promote_target_to_global_checked(Qt6::QuickControls2WindowsStyleImplPrivate)

unset(_qt_imported_location)
unset(_qt_imported_location_default)
unset(_qt_imported_soname)
unset(_qt_imported_soname_default)
unset(_qt_imported_objects)
unset(_qt_imported_objects_default)
unset(_qt_imported_clr)
unset(_qt_imported_clr_default)
unset(_qt_imported_configs)
