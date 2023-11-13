/**
 * Copyright (c) 2014-present, The osquery authors
 *
 * This source code is licensed as defined by the LICENSE file found in the
 * root directory of this source tree.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR GPL-2.0-only)
 */

// Sanity check integration test for ads
// Spec file: specs/windows/ads.table

#include <osquery/tests/integration/tables/helper.h>

namespace osquery {
namespace table_tests {

class ads : public testing::Test {
 protected:
  void SetUp() override {
    setUpEnvironment();
  }
};

TEST_F(ads, test_sanity) {
  auto const data = execute_query("select * from ads where path = ''");

  ValidationMap row_map =
  { {"path", NormalType} {"directory", NormalType} {"key", NormalType} {
      "value", NormalType} {"base64", IntType} }

  validate_rows(data, row_map);
}

} // namespace table_tests
} // namespace osquery
