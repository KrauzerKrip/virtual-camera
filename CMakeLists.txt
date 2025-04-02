cmake_minimum_required(VERSION 3.30)
project(droid_cam_client_qt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
  Core
  Gui
  Widgets
        MultimediaWidgets
  REQUIRED)

add_executable(droid_cam_client_qt main.cpp main_window.h main_window.cpp)
target_link_libraries(droid_cam_client_qt
  Qt::Core
  Qt::Gui
  Qt::Widgets
        Qt::MultimediaWidgets
)

