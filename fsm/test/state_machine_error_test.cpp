//===----------------------------------------------------------------------===//
// Distributed under the 3-Clause BSD License. See accompanying file LICENSE or
// copy at https://opensource.org/licenses/BSD-3-Clause).
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//

#include "fsm/fsm.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Eq;
using testing::Ne;
using testing::StrEq;

namespace asap::fsm {

namespace {

// NOLINTNEXTLINE
TEST(StateMachineError, DefaultConstructor) {
  const StateMachineError err;
  EXPECT_THAT(err.What(), Ne(""));
}

// NOLINTNEXTLINE
TEST(StateMachineError, ConstructWithMessage) {
  const StateMachineError err("__error__");
  EXPECT_THAT(err.What(), StrEq("__error__"));
}

// NOLINTNEXTLINE
TEST(StateMachineError, CopyConstructor) {
  const StateMachineError err("__error__");
  const StateMachineError copy(err); // NOLINT
  EXPECT_THAT(std::string(copy.What()), Eq(std::string(err.What())));
}

// NOLINTNEXTLINE
TEST(StateMachineError, MoveConstructor) {
  StateMachineError err("__error__");
  const StateMachineError copy(std::move(err));
  EXPECT_THAT(copy.What(), StrEq("__error__"));
}

// NOLINTNEXTLINE
TEST(StateMachineError, Assign) {
  const StateMachineError err("__error__");
  const StateMachineError copy = err; // NOLINT
  EXPECT_THAT(copy.What(), StrEq("__error__"));
  EXPECT_THAT(err.What(), StrEq("__error__"));
}

// NOLINTNEXTLINE
TEST(StateMachineError, MoveAssign) {
  StateMachineError err("__error__");
  const StateMachineError copy = std::move(err);
  EXPECT_THAT(copy.What(), StrEq("__error__"));
}

} // namespace

} // namespace asap::fsm
