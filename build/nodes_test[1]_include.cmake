if(EXISTS "/home/oster/Electrolisys/build/nodes_test[1]_tests.cmake")
  include("/home/oster/Electrolisys/build/nodes_test[1]_tests.cmake")
else()
  add_test(nodes_test_NOT_BUILT nodes_test_NOT_BUILT)
endif()