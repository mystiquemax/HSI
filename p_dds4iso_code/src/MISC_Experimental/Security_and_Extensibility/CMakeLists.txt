# MIT License
# 
# Copyright (c) 2024 Samuel Brodie, Timo Oksanen, Henri Hornburg, Daniel Ostermeier, Maksim Pavlov Technical University of Munich
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.15.0)
project(HSI_PoC_Security)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:\\Program Files\\rti_connext_dds-7.2.0\\resource\\cmake")

# Replace this part with your openssl path; The given path corresponds to the standard install directory for openssl with rti connext
set(OPENSSL_ROOT_DIR "C:\\Program Files\\rti_connext_dds-7.2.0\\third_party\\openssl-3.0.9\\x64Win64VS2017\\release")

find_package(RTIConnextDDS REQUIRED COMPONENTS core security_plugins)

set(PATH_TO_POC "../../PoC_Applications/")

set(HSI_STANDARD_INCLUDE_DIR "${PATH_TO_POC}Autogen_DDS_Types")
set(ABSTRACT_DPS_INCLUDE_DIR "${PATH_TO_POC}Generic_Modules/Generic_DPs")
set(TASK_CONTROLLER_DP_INCLUDE_DIR "${PATH_TO_POC}Primary_Usecases/Task_Controller_dp")
set(HSI_INFORMATION_MODEL_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/Security_InformationModel/")

file(GLOB HSI_Standard_SOURCES_CXX  "${PATH_TO_POC}Autogen_DDS_Types/HSI_Standard_topics.*" "${PATH_TO_POC}Autogen_DDS_Types/HSI_Standard_topicsPlugin.*")

# Abstract Domain Participants Sources could also be compiled into a (static) library and linked
file(GLOB ABSTRACT_DP_SOURCES "${PATH_TO_POC}Generic_Modules/Generic_DPs/*")
file(GLOB APP_UTILS "${PATH_TO_POC}Primary_Usecases/app_utils.hpp")

file(GLOB SECTION_DP_SOURCES  "${PATH_TO_POC}Primary_Usecases/Modular_Sprayer/Section_dp/Section_dp.*")
file(GLOB TANK_DP_SOURCES  "${PATH_TO_POC}Primary_Usecases/Modular_Sprayer/Tank_dp/Tank_dp.*")
file(GLOB SPRAYER_DP_SOURCES "${PATH_TO_POC}Primary_Usecases/Modular_Sprayer/Sprayer_dp/Sprayer_dp.*")
set(SPRAYER_DP_SOURCES  ${SPRAYER_DP_SOURCES} ${TANK_DP_SOURCES} ${SECTION_DP_SOURCES})
file(GLOB TASK_CONTROLLER_DP_SOURCES  "${PATH_TO_POC}Primary_Usecases/Task_Controller_dp/TC_logic.*")
file(GLOB TC_AS_CLI "${PATH_TO_POC}Primary_Usecases/Task_Controller_dp/TC_as_cli.*")

file(GLOB GNSS_DP_SOURCES "${PATH_TO_POC}Primary_Usecases/GNSS/GNSS_dp.*")
file(GLOB TECU_DP_SOURCES "${PATH_TO_POC}Primary_Usecases/TECU_dp/Vehicle_dp.*")

# Build shared library for the Task Controller GUI
if (${BUILD_GUI_LIB})
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
	add_library(HSI_SPRAYER_LIB SHARED ${HSI_Standard_SOURCES_CXX} ${TASK_CONTROLLER_DP_SOURCES})
	target_include_directories(HSI_SPRAYER_LIB PRIVATE ${PROJECT_SOURCE_DIR} ${HSI_STANDARD_INCLUDE_DIR} ${ABSTRACT_DPS_INCLUDE_DIR} ${TASK_CONTROLLER_DP_INCLUDE_DIR} ${APP_UTILS})
	target_link_libraries(HSI_SPRAYER_LIB PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)
	set_target_properties(HSI_SPRAYER_LIB PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG  "${PATH_TO_POC}/TC_GUI_C_sharp/bin/Debug/net8.0-windows"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE  "${PATH_TO_POC}/TC_GUI_C_sharp/bin/Release/net8.0-windows"
	)
	# Copy your file(s) based on the build type
	add_custom_command(TARGET HSI_SPRAYER_LIB POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
			${HSI_INFORMATION_MODEL_DIR}
			$<$<CONFIG:Debug>:"${PATH_TO_POC}/TC_GUI_C_sharp/bin/Debug/net8.0-windows/InformationModel">
			$<$<CONFIG:Release>:"${PATH_TO_POC}/TC_GUI_C_sharp/bin/Release/net8.0-windows/InformationModel">
	)
endif()

# Add C-define for path to InformationModel
add_compile_definitions(PATH_INFORMATION_MODEL="${HSI_INFORMATION_MODEL_DIR}")

# Executables for Library Tractor

# TaskController
add_executable(gui_TC_as_cli ${HSI_Standard_SOURCES_CXX} ${TASK_CONTROLLER_DP_SOURCES} ${TC_AS_CLI} ${APP_UTILS})
target_include_directories(gui_TC_as_cli PRIVATE ${PROJECT_SOURCE_DIR} ${HSI_STANDARD_INCLUDE_DIR}
	${ABSTRACT_DPS_INCLUDE_DIR} ${TASK_CONTROLLER_DP_INCLUDE_DIR} ${APP_UTILS})
target_link_libraries(gui_TC_as_cli PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)

# Sprayer Device
add_executable(Sprayer ${PATH_TO_POC}Primary_Usecases/Modular_Sprayer/Sprayer_dp/main.cpp ${SPRAYER_DP_SOURCES} ${HSI_Standard_SOURCES_CXX} ${ABSTRACT_DP_SOURCES} ${APP_UTILS})
# needed since files lie upstream and then down again
target_include_directories(Sprayer PRIVATE ${PROJECT_SOURCE_DIR} ${HSI_STANDARD_INCLUDE_DIR} ${ABSTRACT_DPS_INCLUDE_DIR} ${APP_UTILS})
# cpp2_api is the modern c++ API, while cpp_api is the traditional one
target_link_libraries(Sprayer PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)

# Simple Sprayer
add_executable(Simple_Sprayer ${PATH_TO_POC}Primary_Usecases/Simple_Sprayer/simple_sprayer.cpp ${HSI_Standard_SOURCES_CXX} ${APP_UTILS})
# needed since files lie upstream and then down again
target_include_directories(Simple_Sprayer PRIVATE ${PROJECT_SOURCE_DIR} ${HSI_STANDARD_INCLUDE_DIR} ${APP_UTILS})
# cpp2_api is the modern c++ API, while cpp_api is the traditional one
target_link_libraries(Simple_Sprayer PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)

# GNSS
add_executable(GNSS ${PATH_TO_POC}Primary_Usecases/GNSS/main.cpp ${GNSS_DP_SOURCES} ${HSI_Standard_SOURCES_CXX} ${APP_UTILS})
# needed since files lie upstream and then down again
target_include_directories(GNSS PRIVATE ${PROJECT_SOURCE_DIR} ${HSI_STANDARD_INCLUDE_DIR} ${APP_UTILS})
# cpp2_api is the modern c++ API, while cpp_api is the traditional one
target_link_libraries(GNSS PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)

# Tractor/Vehicle
add_executable(Vehicle ${PATH_TO_POC}Primary_Usecases/TECU_dp/main.cpp ${TECU_DP_SOURCES} ${HSI_Standard_SOURCES_CXX} ${APP_UTILS})
# needed since files lie upstream and then down again
target_include_directories(Vehicle PRIVATE ${PROJECT_SOURCE_DIR} ${HSI_STANDARD_INCLUDE_DIR} ${APP_UTILS})
# cpp2_api is the modern c++ API, while cpp_api is the traditional one
target_link_libraries(Vehicle PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)

