cmake_minimum_required(VERSION 3.4)

project(deviceclient)

add_definitions(-std=c++11 -DDEVICE_CLIENT_APP_VERSION="1.0.0")
include_directories(
	${Utils_INCLUDE_DIRS}
    ${Event_INCLUDE_DIRS}
    ${ClientBL_INCLUDE_DIRS}
    ${Core_INCLUDE_DIRS}
    ${Device_INCLUDE_DIRS}
	${Network_INCLUDE_DIRS}
	${Network_INCLUDE_DIRS}/http
	${Auto_INCLUDE_DIRS}
    ../libDevice/include
    ../libDevice/src
    src/
)

if(DEFINED IC_UNIT_TEST)
	if (${IC_UNIT_TEST} EQUAL 1)
		include_directories(
		    ${ClientBL_SOURCE_DIR}/src
		)
		file(
			GLOB TEST_CPP_FILES unittest/*.cpp
		)
	endif ()
endif ()

#Do not use global Recursive as it will add files inside all sub folders files which are not required for creation of .o object files
file(
   GLOB CPP_FILES src/*.cpp
)



if(DEFINED IC_UNIT_TEST)
	if (${IC_UNIT_TEST} EQUAL 1)
		message([WARNING] "Adding Client Test files" )
		add_executable(deviceclient
			${CPP_FILES}
			${TEST_CPP_FILES}
		)
	else ()
		add_executable(deviceclient
			${CPP_FILES}
		)
	endif ()
else()
	add_executable(deviceclient
		${CPP_FILES}
	)

endif ()

target_link_libraries(deviceclient
    Utils
    Event
    ClientBL
    Network
    Core
    Device
	Auto
    zmq
)

if(DEFINED IC_UNIT_TEST)
	if(${IC_UNIT_TEST} EQUAL 1)

		message([WARNING] "Adding Test Dependencies " )
		find_library(libgtest
			gtest
		)

		include_directories(
			${GTEST_INC}
		)
		target_link_libraries(deviceclient
			gtest
		)
	endif ()
endif()
