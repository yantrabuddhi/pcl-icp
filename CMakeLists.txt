project(icp_analysis)
#Find PCL 1.7
find_package(PCL 1.7 REQUIRED)
include_directories(BEFORE ${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
if (NOT PCL_FOUND)
    MESSAGE(FATAL_ERROR "PCL not found.\n")
endif (NOT PCL_FOUND)

find_package(Eigen3)
include_directories(BEFORE ${EIGEN3_INCLUDE_DIR})

add_executable(icp_a
icp_algo.cpp
)


target_link_libraries(icp_a
${PCL_LIBRARIES}
)
