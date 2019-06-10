cmake_minimum_required(VERSION 3.5)

project(jsmn
  LANGUAGES C)

add_library(jsmn STATIC
  jsmn.c
)

target_include_directories(jsmn
  PUBLIC
    .
)
