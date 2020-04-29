cmake_minimum_required(VERSION 3.16)

project(record LANGUAGES CXX)

set(CMAKE_PREFIX_PATH $ENV{QTDIR512_64})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS Core Widgets Gui Multimedia Network LinguistTools REQUIRED)

include_directories(../libmp3lame/vector ../libmp3lame ../include)

file(GLOB form_files ./*.ui)
source_group("Form Files" FILES ${form_files})

file(GLOB res_files ./*.qrc)
source_group("Resource Files" FILES ${res_files})

file(GLOB head_files ./*.h)
source_group("Header Files" FILES ${head_files})

file(GLOB sour_files ./*.cpp)
source_group("Source Files" FILES ${sour_files})

file(GLOB lib_files ../libmp3lame/*.c ../libmp3lame/*.h)
source_group("libmp3lame" FILES ${lib_files})

file(GLOB vector_files ../libmp3lame/vector/*.*)
source_group("libmp3lame\\vector" FILES ${vector_files})

#set(include_files ../include/CLog.h ../include/macro.h ../include/MD5.h ../include/record_dll.h ../include/SliceIdGenerator.h ../include/Voice.h)

set(src_list
 ${form_files}
 ${res_files}
 ${head_files}
 ${sour_files}
 ${lib_files}
 #${include_files}
 )  

#设置输出文件存放路径
set(EXECUTABLE_OUTPUT_PATH ./bin)
#设置DEBUG输出文件名
set(CMAKE_DEBUG_POSTFIX d)

add_executable(${PROJECT_NAME} ${src_list})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Multimedia Qt5::Network ../../lib/record64)

#target_link_libraries(${PROJECT_NAME} debug ../../lib/recordd64) 
#target_link_libraries(${PROJECT_NAME} optimized ../../lib/record64)

set_Target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#target_compile_definitions(${PROJECT_NAME} PRIVATE RECORD_DLL_LIB)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/Config.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/dll/record64.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/ini/furu_config.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>/ini/furu_config.ini
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/ini/pifu_config.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>/ini/pifu_config.ini
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/ini/rufang_type_config.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>/ini/rufang_type_config.ini
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/ini/rutou_config.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>/ini/rutou_config.ini
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/ini/start_end.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>/ini/start_end.ini
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/ini/tengtong_config.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>/ini/tengtong_config.ini
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/ini/xianti_config.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>/ini/xianti_config.ini
 COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/ini/yiye_config.ini $<TARGET_FILE_DIR:${PROJECT_NAME}>/ini/yiye_config.ini
 )