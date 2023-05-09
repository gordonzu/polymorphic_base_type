// drawtest_test.cpp

#include "gtest/gtest.h"
#include <sstream>
#include "object.h"

using namespace::testing;

class object_t_test: public Test {
public:
    void SetUp()override {
    }

    void TearDown()override {
    }

    attributes_t attributes;
};

TEST_F(object_t_test, test_attributes) {
    attributes.emplace(0, 2);
    attributes.emplace(1, 2);
    attributes.emplace(2, 2);
    attributes.emplace(3, 2);

    map_size(attributes);
    print_map(attributes);

    attributes.clear();
    map_size(attributes);

    attributes.emplace("key1", "value1");
    attributes.emplace("key2", "value1");
    attributes.emplace("key3", "value1");
    attributes.emplace("key4", "value1");

    print_map(attributes);   
    attributes.clear();

    attributes.emplace("key1", 33); 
    attributes.emplace("key2", 43); 
    attributes.emplace("key3", 53);

    print_map(attributes);
    attributes.clear();

    attributes.emplace("key1", true); 
    attributes.emplace("key2", false); 
    attributes.emplace("key3", false);

    print_map(attributes);
    attributes.clear();

    attributes.emplace(0, 2);
    attributes.emplace("key1", "value1");
    attributes.emplace("key2", 43); 
    attributes.emplace("key3", false);

    print_map(attributes);
    ASSERT_TRUE(true);
}


















