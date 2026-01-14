cmake_minimum_required(VERSION 3.10)
project(test_protobuf)

find_package(Protobuf CONFIG REQUIRED)

add_library(proto_ser SHARED ser.cpp test.pb.cc)

target_include_directories(proto_ser PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${PROTOBUF_INCLUDE_DIRS})

target_compile_definitions(proto_ser PRIVATE SER_BUILD=1)

target_link_libraries(proto_ser PUBLIC protobuf::libprotobuf)
