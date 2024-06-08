# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/vehicle_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/vehicle_autogen.dir/ParseCache.txt"
  "vehicle_autogen"
  )
endif()
