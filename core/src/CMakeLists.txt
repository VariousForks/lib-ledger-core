
list(APPEND ledger-core-sources
        bytes/BytesReader.cpp
        ledger-core.h
        math/BigInt.cpp utils/endian.cpp
        utils/endian.h
        utils/hex.cpp
        bytes/BytesWriter.cpp
        bytes/BytesWriter.h
        async/ExecutionContext.hpp
        async/Callback.hpp
        async/EventEmitter.hpp
        )

set(ANDROID_CPP_FEATURES exceptions)

# Automaticall ADD djinni api files to the library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
file(GLOB ledger-core-djinni-api-sources
        "api/*"
        )
list(APPEND ledger-core-sources ${ledger-core-djinni-api-sources})

if (TARGET_JNI)
    message(STATUS "Configure project for JNI")
    #find_package(JNI REQUIRED)
    file(GLOB ledger-core-jni-sources
            "jni/*.cpp"
            "jni/*.hpp"
            "jni/jni/*"
            )
    list(APPEND ledger-core-sources ${ledger-core-jni-sources})
endif()

add_library (
        ledger-core SHARED
        ${ledger-core-sources}
        api_impl/LedgerCoreImpl.cpp api_impl/LedgerCoreImpl.hpp)

target_link_libraries(ledger-core bigd)
target_link_libraries(ledger-core fmt)

file(GLOB_RECURSE LEDGER_CORE_HEADERS
        "*.hpp"
        "*.h"
        )

file(GLOB LEDGER_CORE_API_HEADERS
        "api/*.hpp"
        )

include_directories(ledger-core ../lib/bigd)

if (TARGET_JNI)
   # include_directories(ledger-core ${JNI_INCLUDE_DIRS})
   # target_link_libraries(ledger-core ${JNI_LIBRARIES})
endif()

file(GLOB ledger-core-header
        "*"
        )
file(COPY ${ledger-core-header} DESTINATION ${CMAKE_BINARY_DIR}/include/ledger/core FILES_MATCHING PATTERN "*.h")
file(COPY ${ledger-core-header} DESTINATION ${CMAKE_BINARY_DIR}/include/ledger/core FILES_MATCHING PATTERN "*.hpp")

target_include_directories (ledger-core PUBLIC ..)
target_include_directories (ledger-core PUBLIC ../lib/bigd)
target_include_directories (ledger-core PUBLIC ../lib/fmt-3.0.0)

install(TARGETS ledger-core DESTINATION "lib")
install(FILES ${LEDGER_CORE_API_HEADERS} DESTINATION "include/ledger-core")