# ===-----------------------------------------------------------------------===#
# Distributed under the 3-Clause BSD License. See accompanying file LICENSE or
# copy at https://opensource.org/licenses/BSD-3-Clause).
# SPDX-License-Identifier: BSD-3-Clause
# ===-----------------------------------------------------------------------===#

# ==============================================================================
# Build instructions
# ==============================================================================

asap_add_executable(door_1 WARNING SOURCES "door_1.cpp")
target_link_libraries(door_1 PRIVATE asap::fsm)

asap_add_executable(door_2 WARNING SOURCES "door_2.cpp")
target_link_libraries(door_2 PRIVATE asap::fsm)

asap_add_executable(door_3 WARNING SOURCES "door_3.cpp")
target_link_libraries(door_3 PRIVATE asap::fsm)
