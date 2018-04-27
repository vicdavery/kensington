project(UnitTests)

enable_testing()

find_package(GTest REQUIRED)

add_executable(node_test node_test.cpp ../node.cpp)
target_link_libraries(node_test ${GTEST_BOTH_LIBRARIES})

add_executable(edge_test edge_test.cpp ../node.cpp)
target_link_libraries(edge_test ${GTEST_BOTH_LIBRARIES})

add_executable(player_test player_test.cpp)
target_link_libraries(player_test ${GTEST_BOTH_LIBRARIES})

add_executable(board_test board_test.cpp ../board.cpp ../node.cpp)
target_link_libraries(board_test ${GTEST_BOTH_LIBRARIES})

add_executable(layout_config_parser_test layout_config_parser_test.cpp)
target_link_libraries(board_test ${GTEST_BOTH_LIBRARIES})

gtest_discover_tests(node_test)
gtest_discover_tests(edge_test)
gtest_discover_tests(player_test)
gtest_discover_tests(board_test)
gtest_discover_tests(layout_config_parser_test)

