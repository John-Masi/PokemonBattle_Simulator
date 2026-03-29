set(CMAKE_CXX STANDARD 20)
set(CMAKE_CXX STANDARD_REQUIRED ON)

set(SOURCES
  src/data.h
  src/attributes.h
  src/battle.hpp
  src/battle.cpp
  src/trainer.hpp
  src/trainer.cpp
)



add_executable(pokemon ${SOURCES})
target_include_directories(pokemon PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_compile_features(pokemon PRIVATE cxx_std_20)
