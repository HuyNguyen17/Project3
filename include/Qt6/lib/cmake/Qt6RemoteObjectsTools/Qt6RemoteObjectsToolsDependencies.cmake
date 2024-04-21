# Copyright (C) 2024 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

# Find "ModuleTools" dependencies, which are other ModuleTools packages.
set(Qt6RemoteObjectsTools_FOUND FALSE)
set(__qt_RemoteObjectsTools_tool_deps "")
foreach(__qt_RemoteObjectsTools_target_dep ${__qt_RemoteObjectsTools_tool_deps})
    list(GET __qt_RemoteObjectsTools_target_dep 0 __qt_RemoteObjectsTools_pkg)
    list(GET __qt_RemoteObjectsTools_target_dep 1 __qt_RemoteObjectsTools_version)

    if (NOT ${__qt_RemoteObjectsTools_pkg}_FOUND)
        find_dependency(${__qt_RemoteObjectsTools_pkg} ${__qt_RemoteObjectsTools_version})
    endif()
endforeach()

set(Qt6RemoteObjectsTools_FOUND TRUE)
