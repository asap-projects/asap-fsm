//===----------------------------------------------------------------------===//
// Distributed under the 3-Clause BSD License. See accompanying file LICENSE or
// copy at https://opensource.org/licenses/BSD-3-Clause).
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//

#include <fsm/fsm.h>

#include <iostream>

using asap::fsm::ByDefault;
using asap::fsm::DoNothing;
using asap::fsm::On;
using asap::fsm::StateMachine;
using asap::fsm::TransitionTo;
using asap::fsm::Will;

struct OpenEvent {};
struct CloseEvent {};

struct ClosedState;
struct OpenState;

struct ClosedState :
    // Using the state helpers to completely implement the state
    // in a declarative way
    Will<
        // Default action is to do nothing
        ByDefault<DoNothing>,
        // Specific action on a specific event
        On<OpenEvent, TransitionTo<OpenState>>> {};

struct OpenState
    : Will<ByDefault<DoNothing>, On<CloseEvent, TransitionTo<ClosedState>>> {};

using Door = StateMachine<ClosedState, OpenState>;

void PrintDoorState(const Door &door) {
  std::cout << "   > door is " << (door.IsIn<OpenState>() ? "open" : "closed")
            << "\n";
}

auto main() -> int {
  Door door{ClosedState{}, OpenState{}};
  std::cout << "-- Starting\n";
  PrintDoorState(door);

  std::cout << "-- sending close event\n";
  door.Handle(CloseEvent{});
  PrintDoorState(door);

  std::cout << "-- sending open event\n";
  door.Handle(OpenEvent{});
  PrintDoorState(door);

  std::cout << "-- sending close event\n";
  door.Handle(CloseEvent{});
  PrintDoorState(door);
}
