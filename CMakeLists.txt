cmake_minimum_required(VERSION 3.5)

project(awsiot
  LANGUAGES C)

add_subdirectory(external_libs/mbedTLS)
add_subdirectory(external_libs/jsmn)

add_library(awsiot STATIC
  src/aws_iot_json_utils.c
  src/aws_iot_mqtt_client.c
  src/aws_iot_mqtt_client_common_internal.c
  src/aws_iot_mqtt_client_connect.c
  src/aws_iot_mqtt_client_publish.c
  src/aws_iot_mqtt_client_subscribe.c
  src/aws_iot_mqtt_client_unsubscribe.c
  src/aws_iot_mqtt_client_yield.c
  src/aws_iot_shadow_actions.c
  src/aws_iot_shadow.c
  src/aws_iot_shadow_json.c
  src/aws_iot_shadow_records.c

  platform/linux/common/timer.c
  platform/linux/mbedtls/network_mbedtls_wrapper.c
  platform/linux/pthread/threads_pthread_wrapper.c
)

target_include_directories(awsiot
  PUBLIC
    include
    platform/linux/common
    platform/linux/mbedtls
    platform/linux/pthread
  PRIVATE
    external_libs/jsmn
    ../aws-iot-libraries
)

target_link_libraries(awsiot PUBLIC mbedtls PRIVATE jsmn)
