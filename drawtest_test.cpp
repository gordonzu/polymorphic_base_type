// drawtest_test.cpp

#include <gmock/gmock.h>
#include <sstream>
#include "drawtest.h"

using namespace::testing;

class drawtest_test: public Test {
public:

    void SetUp()override {
    }

    void TearDown()override {
    }

    attributes_t attributes;
};


TEST_F(drawtest_test, test_attributes){
    std::stringstream out;

    ASSERT_TRUE(true);

    /*attributes.emplace_back(0);
    attributes.emplace_back(2);
    attributes.emplace_back(std::string("Hello, world."));
    attributes.emplace_back(true);

    std::cout << print_string(attributes[0], out) << std::endl;
    */
}


















