# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# [EDIT] Set Path to OpenCV and include the directories
# pathToOpenCV is just an example to how to write in Window.
# General format: C:/Users/user-name/OpenCV-2.4.11-android-sdk/OpenCV-android-sdk
# Notice: Make sure you have a copy of the unzip OpenCV downloaded from the Internet
# in your username directory.

set(pathToOpenCV C:/Users/doxua/OpenCV-2.4.11-android-sdk/OpenCV-android-sdk)
include_directories(${pathToOpenCV}/sdk/native/jni/include)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )


# [EDIT] Similar to above lines, add the OpenCV library
add_library( lib_opencv SHARED IMPORTED )

set(pathToProject C:/Users/doxua/AndroidStudioProjects/OpenCVJNIAndroidStudio)
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathToProject}/app/src/main/jniLibs/${ANDROID_ABI}/libopencv_java.so)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} lib_opencv ) #EDIT