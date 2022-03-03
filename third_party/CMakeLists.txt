# ===-----------------------------------------------------------------------===#
# Distributed under the 3-Clause BSD License. See accompanying file LICENSE or
# copy at https://opensource.org/licenses/BSD-3-Clause).
# SPDX-License-Identifier: BSD-3-Clause
# ===-----------------------------------------------------------------------===#

message("=> [third-party modules]")

# Live at Head philosophy. Always use the latest commit in the main branch in
# your projects.

FetchContent_Declare(
  asap_common
  GIT_REPOSITORY https://github.com/asap-projects/asap-common.git
  GIT_TAG origin/master)
FetchContent_MakeAvailable(asap_common)