cmake_minimum_required(VERSION 3.20.0)

set(ZEPHYR_EXTRA_MODULES /home/sid/workspace/HVAC_Motor/hvac_motor/modules)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(hw_test VERSION 0.1.0 LANGUAGES C)

target_sources(app PRIVATE src/main.c)

target_compile_options(app
PRIVATE
-Wall -Wextra -Werror -Wno-unused-function)


