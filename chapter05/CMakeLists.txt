CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# 开启选项支持cuda
project(chapter_05 LANGUAGES CXX CUDA)

# 输出可执行路径
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

# 包含头文件
# include_directories(../common) # 这个是否包含均可，因为原函数中指明了相对路径

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
  
# set(CUDA_NVCC_FLAGS -gencode arch=compute_20,code=sm_20;-G;-g)  
# set(CUDA_NVCC_FLAGS -gencode arch=compute_52,code=sm_52;-G;-g) 

ADD_EXECUTABLE(add_loop_blocks add_loop_blocks.cu)

ADD_EXECUTABLE(add_loop_long_blocks add_loop_long_blocks.cu)

ADD_EXECUTABLE(dot_5 dot.cu)

ADD_EXECUTABLE(ripple_5 ripple.cu)
TARGET_LINK_LIBRARIES(ripple_5 ${OpenCV_LIBS})

ADD_EXECUTABLE(shared_bitmap shared_bitmap.cu)
TARGET_LINK_LIBRARIES(shared_bitmap ${OpenCV_LIBS})