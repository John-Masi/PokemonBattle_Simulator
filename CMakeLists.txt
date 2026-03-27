set(CMAKE_CXX STANDARD 17)
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
