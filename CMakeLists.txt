cmake_minimum_required(VERSION 3.0)	 

project(graph)			

set(SOURCE_EXE main.cpp  src/helperFunctions.cpp)		

include_directories("inc/" )	

add_executable(graph ${SOURCE_EXE})	

