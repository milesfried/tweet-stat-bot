cmake_minimum_required(VERSION 3.15)
project(21su_pa02_template)

set(CMAKE_CXX_STANDARD 17)
##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....
# if you need more, add them here and in the foreach stmt below.
set (input01 "data/su21_pa02.csv")
#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach()

# Create the executable for sorting
add_executable(21su_pa02_template main.cpp DSVector.h DSString.cpp DSString.h tweet.cpp tweet.h captain.h)