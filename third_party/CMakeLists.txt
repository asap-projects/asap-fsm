# ===-----------------------------------------------------------------------===#
# Distributed under the 3-Clause BSD License. See accompanying file LICENSE or
# copy at https://opensource.org/licenses/BSD-3-Clause).
# SPDX-License-Identifier: BSD-3-Clause
# ===-----------------------------------------------------------------------===#

message("=> [third-party modules]")

# Live at Head philosophy. Always use the latest commit in the main branch in your projects.
FetchContent_Declare(
        asap_common
        GIT_REPOSITORY https://github.com/asap-projects/asap-common.git
        GIT_TAG origin/master)
FetchContent_MakeAvailable(asap_common)

#FetchContent_GetProperties(asap_common)
##if(NOT asap_common_POPULATED)
#    FetchContent_Populate(asap_common)
#    message(STATUS "Catch source dir: ${asap_common_SOURCE_DIR}")
#    message(STATUS "Catch binary dir: ${asap_common_BINARY_DIR}")
#    add_subdirectory(${asap_common_SOURCE_DIR} ${asap_common_BINARY_DIR})
##endif()
#
