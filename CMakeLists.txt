cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Zephymail)

# Include header files
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Find GSASL and GnuTLS libraries
find_library(GSASL_LIBRARY NAMES gsasl)
find_library(GNUTLS_LIBRARY NAMES gnutls)
find_library(ICUUC_LIBRARY NAMES icuuc)
find_library(ICUI18N_LIBRARY NAMES icui18n)

# Add executable
add_executable(Zephymail ${SOURCES})
target_link_libraries(Zephymail ${Lib_Vmime})

# Link VMime, GSASL, and GnuTLS libraries
target_link_libraries(Zephymail
    ${CMAKE_SOURCE_DIR}/lib/libvmime.a
    ${GSASL_LIBRARY}
    ${GNUTLS_LIBRARY}
    ${ICUUC_LIBRARY}
    ${ICUI18N_LIBRARY}
)