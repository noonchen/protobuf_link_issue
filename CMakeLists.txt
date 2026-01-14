cmake_minimum_required(VERSION 3.10)
project(test_protobuf)

find_package(Protobuf CONFIG REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS test.proto)

add_executable(test_cpp test.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(test_cpp protobuf::libprotoc)