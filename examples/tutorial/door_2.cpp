//===----------------------------------------------------------------------===//
// Distributed under the 3-Clause BSD License. See accompanying file LICENSE or
// copy at https://opensource.org/licenses/BSD-3-Clause).
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//

#include <fsm/fsm.h>

#include <iostream>

using asap::fsm::ByDefault;
using asap::fsm::Continue;
using asap::fsm::DoNothing;
using asap::fsm::On;
using asap::fsm::StateMachine;
using asap::fsm::Status;
using asap::fsm::TransitionTo;
using asap::fsm::Will;

struct OpenEvent {};
struct CloseEvent {};

struct ClosedState;
struct OpenState;

struct ClosedState
    : Will<ByDefault<DoNothing>, On<OpenEvent, TransitionTo<OpenState>>> {
  using Will::Handle;

  template <typename Event> auto OnEnter(const Event & /*event*/) -> Status {
    std::cout << "   > door is closed\n";
    return Continue{};
  }

  [[nodiscard]] static auto Handle(const CloseEvent & /*event*/) -> DoNothing {
    std::cerr << "Error: the door is already closed!\n";
    return DoNothing{};
  }
};

struct OpenState
    : Will<ByDefault<DoNothing>, On<CloseEvent, TransitionTo<ClosedState>>> {
  using Will::Handle;

  template <typename Event> auto OnEnter(const Event & /*event*/) -> Status {
    std::cout << "   > door is open\n";
    return Continue{};
  }

  [[nodiscard]] static auto Handle(const OpenEvent & /*event*/) -> DoNothing {
    std::cerr << "Error: the door is already open!\n";
    return DoNothing{};
  }
};

using Door = StateMachine<ClosedState, OpenState>;

auto main() -> int {
  Door door{ClosedState{}, OpenState{}};
  std::cout << "-- Starting\n";

  std::cout << "-- sending close event\n";
  door.Handle(CloseEvent{});

  std::cout << "-- sending open event\n";
  door.Handle(OpenEvent{});

  std::cout << "-- sending open event\n";
  door.Handle(OpenEvent{});

  std::cout << "-- sending close event\n";
  door.Handle(CloseEvent{});
}
