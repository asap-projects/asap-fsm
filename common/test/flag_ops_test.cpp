/*     SPDX-License-Identifier: BSD-3-Clause     */

//        Copyright The Authors 2021.
//    Distributed under the 3-Clause BSD License.
//    (See accompanying file LICENSE or copy at
//   https://opensource.org/licenses/BSD-3-Clause)

#include "common/flag_ops.h"

#include <common/compilers.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <cstdint>

// Disable compiler and linter warnings originating from the unit test framework and for which we
// cannot do anything.
// Additionally every TEST or TEST_X macro usage must be preceded by a '// NOLINTNEXTLINE'.
ASAP_DIAGNOSTIC_PUSH
#if defined(__clang__) && ASAP_HAS_WARNING("-Wused-but-marked-unused")
#pragma clang diagnostic ignored "-Wused-but-marked-unused"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
// NOLINTBEGIN(used-but-marked-unused)

using ::testing::Eq;
using ::testing::IsTrue;
using ::testing::Ne;

namespace asap {

namespace {

// NOLINTNEXTLINE
TEST(FlagOps, SetSingleBit) {
  constexpr auto TEST_MASK = 0x100010u;
  constexpr auto TEST_FLAGS = 0x1000u;
  constexpr auto RESULT_MASK = 0x101010u;

  std::uint32_t mask = TEST_MASK;
  std::uint32_t flag = TEST_FLAGS;

  FlagSet(mask, flag);
  // bit corresponding to flag is set
  EXPECT_THAT((mask & flag), Ne(0u));
  // other bits not touched
  EXPECT_THAT(mask, Eq(RESULT_MASK));
}

// NOLINTNEXTLINE
TEST(FlagOps, SetMultipleBits) {
  constexpr auto TEST_MASK = 0x100010u;
  constexpr auto TEST_FLAGS = 0x1001u;
  constexpr auto RESULT_MASK = 0x101011u;

  std::uint32_t mask = TEST_MASK;
  std::uint32_t flag = TEST_FLAGS;

  FlagSet(mask, flag);
  EXPECT_THAT(mask, Eq(RESULT_MASK));
}

// NOLINTNEXTLINE
TEST(FlagOps, ClearSingleBit) {
  constexpr auto TEST_MASK = 0x100010u;
  constexpr auto TEST_FLAGS = 0x10u;
  constexpr auto RESULT_MASK = 0x100000u;

  std::uint32_t mask = TEST_MASK;
  std::uint32_t flag = TEST_FLAGS;

  FlagClear(mask, flag);
  // bit corresponding to flag is cleared
  EXPECT_THAT((mask & flag), Eq(0u));
  // other bits not touched
  EXPECT_THAT(mask, Eq(RESULT_MASK));
}

// NOLINTNEXTLINE
TEST(FlagOps, ClearMultipleBits) {
  constexpr auto TEST_MASK = 0x10101010u;
  constexpr auto TEST_FLAGS = 0x101000u;
  constexpr auto RESULT_MASK = 0x10000010u;

  std::uint32_t mask = TEST_MASK;
  std::uint32_t flag = TEST_FLAGS;

  FlagClear(mask, flag);
  EXPECT_THAT((mask & flag), Eq(0u));
  EXPECT_THAT(mask, Eq(RESULT_MASK));
}

// NOLINTNEXTLINE
TEST(FlagOps, FlipSingleBit) {
  constexpr auto INITIAL_MASK = 0x10101010u;
  constexpr auto TEST_FLAGS = 0x101000u;
  constexpr auto RESULT_MASK = 0x10000010u;

  std::uint32_t mask = INITIAL_MASK;
  std::uint32_t flag = TEST_FLAGS;

  FlagFlip(mask, flag);
  // bit corresponding to flag is cleared
  EXPECT_THAT((mask & flag), Eq(0u));
  // other bits not touched
  EXPECT_THAT(mask, Eq(RESULT_MASK));

  FlagFlip(mask, flag);
  // bit corresponding to flag is cleared
  EXPECT_THAT((mask & flag), Ne(0u));
  // other bits not touched
  EXPECT_THAT(mask, Eq(INITIAL_MASK));
}

// NOLINTNEXTLINE
TEST(FlagOps, FlipMultipleBits) {
  constexpr auto INITIAL_MASK = 0x10101010u;
  constexpr auto TEST_FLAGS = 0x11111111u;
  constexpr auto RESULT_MASK = 0x01010101u;

  std::uint32_t mask = INITIAL_MASK;
  std::uint32_t flag = TEST_FLAGS;

  FlagFlip(mask, flag);
  EXPECT_THAT(mask, Eq(RESULT_MASK));
  FlagFlip(mask, flag);
  EXPECT_THAT(mask, Eq(INITIAL_MASK));
}

// NOLINTNEXTLINE
TEST(FlagOps, TestMultipleBits) {
  constexpr auto TEST_MASK = 0x100010u;
  constexpr auto TEST_FLAGS = 0x10u;

  std::uint32_t mask = TEST_MASK;
  std::uint32_t flag = TEST_FLAGS;

  EXPECT_THAT(FlagTest(mask, flag), IsTrue());
  EXPECT_THAT(FlagTest(mask, mask), IsTrue());
}

} // namespace

} // namespace asap

// NOLINTEND(used-but-marked-unused)
ASAP_DIAGNOSTIC_POP
