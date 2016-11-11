
cmake_minimum_required(VERSION 2.6)
 
project(GreenBay)
 
if(EXISTS "/usr/local/lib/OGRE/cmake")
   set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
   set(OGRE_SAMPLES_INCLUDEPATH "/usr/local/share/OGRE/samples/Common/include/") 
   
   elseif(EXISTS "/usr/lib/OGRE/cmake")
      set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
	  set(OGRE_SAMPLES_INCLUDEPATH "/usr/share/OGRE/samples/Common/include/") 
	
   else ()
	  message(SEND_ERROR "Failed to find module path.")
endif(EXISTS "/usr/local/lib/OGRE/cmake")
 
set(CMAKE_BUILD_TYPE "RelWithDebInfo" FORCE)
set(CMAKE_DEBUG_POSTFIX "_d")
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/bin")
 
find_package(OGRE REQUIRED)
find_package(OIS REQUIRED)

if(NOT OIS_FOUND)
	message(SEND_ERROR "Failed to find OIS.")
endif()
 
# Find Boost
if (NOT OGRE_BUILD_PLATFORM_IPHONE)
	set(Boost_USE_STATIC_LIBS ${OGRE_STATIC})
	set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37")
	# Components that need linking (NB does not include header-only components like bind)
	set(OGRE_BOOST_COMPONENTS thread date_time)
	find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	if (NOT Boost_FOUND)
		# Try again with the other type of libs
		set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
		find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	endif()

	find_package(Boost QUIET)
	include_directories(${Boost_INCLUDE_DIR})
	add_definitions(-DBOOST_ALL_NO_LIB)
	set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
endif()
 
set(HDRS ./include/Halo.h ./include/Raptor.h ./include/Game.h ./include/CollisionTestedObject.h)
set(SRCS ./src/Halo.cpp ./src/Raptor.cpp ./src/Game.cpp ./src/Main.cpp)
set(OGREAL_INCLUDE_DIR "/usr/local/include/OgreAL")
set(OGREAL_LIB "/usr/local/lib/libOgreAL.so.0.0.0")
set(OGREODE_INCLUDE_DIR "/usr/local/include/OgreOde_Core")
set(OGREODE_LIB "/usr/local/lib/libOgreOde_Core_d.so.1.3.0")

include_directories(${OIS_INCLUDE_DIRS} ${OGRE_INCLUDE_DIRS} ${OGRE_SAMPLES_INCLUDEPATH} ${OGRE_Overlay_INCLUDE_DIRS} ${OGREAL_INCLUDE_DIR} ${OGREODE_INCLUDE_DIR}) 
add_executable(${PROJECT_NAME} ${HDRS} ${SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX _d)
target_link_libraries(${PROJECT_NAME} ${OGRE_LIBRARIES} ${OIS_LIBRARIES} ${OGRE_Overlay_LIBRARIES} ${OGREAL_LIB} ${OGREODE_LIB})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin CONFIGURATIONS All)


  
