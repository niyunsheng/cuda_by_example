CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# 开启选项支持cuda
project(chapter_04 LANGUAGES CXX CUDA)

# 输出可执行路径
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

# 包含头文件
include_directories(../common)

# Find OpenCV
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
ELSE()
    message(ERROR " OpenCV not found!")
endif()

# CUDA
find_package(CUDA)
if (NOT CUDA_FOUND)
	message("CUDA not found!")
endif()

# nvcc flags  
# set(CUDA_NVCC_FLAGS -arch=compute_30;-G;-g)  
  
#set(CUDA_NVCC_FLAGS -gencode arch=compute_20,code=sm_20;-G;-g)  
#set(CUDA_NVCC_FLAGS -gencode arch=compute_52,code=sm_52;-G;-g) 

ADD_EXECUTABLE(add_loop_cpu add_loop_cpu.cu)

ADD_EXECUTABLE(add_loop_gpu add_loop_gpu.cu)

ADD_EXECUTABLE(add_loop_long add_loop_long.cu)


ADD_EXECUTABLE(julia_cpu julia_cpu.cu)
TARGET_LINK_LIBRARIES(julia_cpu ${OpenCV_LIBS}) # 链接

ADD_EXECUTABLE(julia_gpu julia_gpu.cu)
TARGET_LINK_LIBRARIES(julia_gpu ${OpenCV_LIBS})