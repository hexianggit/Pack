#project name :  Pack
PROJECT(Pack)

#包含prep.cmake(定义编译时的选项)
INCLUDE($ENV{ABCMAKE}/common/prep.cmake)

#设置版本号，和向下兼容性
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
CMAKE_POLICY(VERSION 2.8)

SET(NEED_BASECORE TRUE)

SET(AUTO_RUN OFF)




#target name:Pack
SET(TARGET_NAME Pack)


#THRIFT

#TARGET_TYPE 
#LIBRARY | ARCHIVE | RUNTIME | COMPONENT
#动态库  | 静态库  | 可执行   |  组件

SET(TARGET_TYPE RUNTIME)

INCLUDE($ENV{ABCMAKE}/common/target.cmake)