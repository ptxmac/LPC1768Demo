# arm
INCLUDE(CMakeForceCompiler)


set(CMAKE_SYSTEM_NAME Generic)

set(COMPILER_ROOT "/Users/ptx/gcc-arm-none-eabi-4_7-2012q4")

CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GNU)

