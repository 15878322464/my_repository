# CMakeLists.txt的预定义变量：
# 如果出现${OpenCV_INCLUDE_DIRS}类似的第三方库名的变量，那就是find_package()之后找到的相关库的cmake配置文件里的变量，具体的变量可以到/usr/local/lib/cmake相关库库文件里查看.cmake文件内容
# ${PROJECT_SOURCE_DIR}  //整个项目的根目录，通常是指包含顶层CMakeLists.txt文件所在的目录，这个变量在项目的所有 CMakeLists.txt 文件中都是相同的
# ${PROJECT_NAME}  //自定义的项目名
# ${PROJECT_BINARY_DIR}  //是CMake生成一系列文件的目录，如果是在build中cmake那就是对应的...../build
# ${CMAKE_CURRENT_SOURCE_DIR} // 当前CMakeList.txt所在的文件夹目录。

# 必须设置的基础选项：
cmake_minimum_required(VERSION 2.8.11)  # 设置需要的cmake最低版本号
project(BinaryReader)  # 项目名称，自定义

# set是设置环境变量
SET(CMAKE_C_COMPILER "/usr/bin/gcc")  # 指定c编译器路径
SET(CMAKE_CXX_COMPILER "/usr/bin/g++")  # 指定c++编译器路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/app) # 设置

# 收集源cpp文件路径:
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/logic/sqlite3 SRC_LIST) # 搜集所有在指定路径下的源文件的文件名,并将输出结果列表储存在指定的变量中,同一个cmake里的相同变量可以一直添加搜集到的文件名。注意,不能递归遍历搜索
file(GLOB_RECURSE SRC_LIST src/*.cpp src/*.h) # 将src目录下的所有.cpp和.h后缀的文件都存入SRC_LIST 变量中。

# 添加链接库时的搜索目录，cmake编译时默认只在系统库/usr/lib或者本地库/usr/local/lib去找，如果项目中有用到安装在其他路径的库,记得添加进来
link_directories(/path/to/lib1 /path/to/lib2)

# 查找软件包
find_package(
package_name # 要查找的软件包的名称。通常情况下，这个名称与软件包的导入文件（Find<package_name>.cmake）中定义的一致，每个软件包的变量都不同，所有具体的都要到对应的.cmake文件查看
[version] # 可选参数，指定要查找的软件包的版本号。
[EXACT] # 可选参数，要求查找的软件包的版本与指定的版本完全匹配。
[QUIET] # 可选参数，如果设置了这个参数，当找不到指定的软件包时不会输出错误消息。
[REQUIRED] # 可选参数，如果设置了这个参数，当找不到指定的软件包时会产生致命错误。
[COMPONENmponent1 [component2 ...]] # 可选参数，指定要查找的软件包的组件列表。
[OPTIONAL_COMPONENTS optional_component1 [optional_component2 ...]] # 可选参数，指定可选组件的列表。如果指定的组件不存在，则不会产生错误。
[NO_POLICY_SCOPE]) # 可选参数，用于设置 CMake 策略范围。
# 示例：find_package(Boost REQUIRED COMPONENTS filesystem system) 查找Boost库，并指定了要求的组件（filesystem 和 system）

# 编译打包库文件
add_library(${PROJECT_NAME} STATIC # SHARED | MODULE 可指定链接为静态库、动态库、还是模块库
    src/database1.cpp
    src/database2.cpp
    ......
)

# 把头文件包含进来：
include_directories(
    ${PROJECT_SOURCE_DIR}/include  # 源代码目录下的头文件引用
    "/usr/include/eigen3/"  # 本地的源代码路径,没有自定义路径的话,一般默认安装在/usr/local/usr/include/
    ${OpenCV_INCLUDE_DIRS}  # 第三方库的变量,使用他的前提是要先安装对应库以及find_package找到它
)

# 创建程序
add_executable(database_reader database_reader.cc)

# 链接库
target_link_libraries(database_reader ${PROJECT_NAME} sqlite3 ${OpenCV_LIBS} )

