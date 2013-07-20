#ADD_SUBDIRECTORY(C4Utils) #We don't need C4Utils as it's header-only right now
ADD_SUBDIRECTORY(C4Board)
ADD_SUBDIRECTORY(C4AI)

ADD_EXECUTABLE(Connect4 main.cpp)

TARGET_LINK_LIBRARIES(Connect4 C4AI C4Board)