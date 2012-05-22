#include <gtest/gtest.h>

#include <EmailReader_test.h>
#include <EntityGenerator_test.h>
#include <Graph_test.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
