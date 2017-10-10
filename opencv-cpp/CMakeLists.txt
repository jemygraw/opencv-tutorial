cmake_minimum_required(VERSION 3.2)
project(opencv-cpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
link_libraries(opencv_core
opencv_imgcodecs
opencv_highgui
opencv_imgproc
opencv_videoio
)

set(SOURCE_FILES ex1_show_image.cpp ex2_play_video.cpp ex3_play_control.cpp
 ex4_image_gaussian.cpp ex4_play_video_gaussian.cpp  ex5_image_shrink.cpp
 ex6_write_gray_video.cpp ex7_matrix_operations.cpp  ex8_saturate_sv.cpp
 ex9_image_roi.cpp ex10_alpha_merge.cpp ex11_flip_image.cpp ex12_draw_image.cpp
 ex13_chapter3_exercise.cpp ex14_image_read.cpp ex15_mouse_draw_rect.cpp
 ex16_camera_record.cpp
 case_filter_background.cpp
 main.cpp)
add_executable(opencv-cpp ${SOURCE_FILES} main.cpp)