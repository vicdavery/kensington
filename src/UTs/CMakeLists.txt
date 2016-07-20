project(UnitTests)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(..)

add_executable(node_test node_test.cpp ../node.cpp)
target_link_libraries(node_test ${GTEST_BOTH_LIBRARIES})

add_executable(edge_test edge_test.cpp ../node.cpp)
target_link_libraries(edge_test ${GTEST_BOTH_LIBRARIES})


add_test(NodeTests node_test)
add_test(EdgeTests edge_test)
