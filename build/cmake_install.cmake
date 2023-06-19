# Install script for directory: /home/littlegirl112/workspace/Inshi-C

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/littlegirl112/workspace/Inshi-C/build/R5/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/R4/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/R3/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/R2/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H31/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H30/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H29/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H28/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H27/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H26/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H25/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H24/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H23/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H22/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H21/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H20/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H19/cmake_install.cmake")
  include("/home/littlegirl112/workspace/Inshi-C/build/H18/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/littlegirl112/workspace/Inshi-C/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
