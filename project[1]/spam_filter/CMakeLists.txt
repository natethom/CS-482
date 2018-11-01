cmake_minimum_required(VERSION 3.5.1)
project(spam_filter)

add_compile_options(-std=c++11)

#Can manually add the sources using the set command as follows:
set(TRAIN_SOURCES src/spam_train.cpp)
set(CLASSIFY_SOURCES src/spam_classify.cpp)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.cpp")

add_executable(training ${TRAIN_SOURCES})
add_executable(classify ${CLASSIFY_SOURCES})
