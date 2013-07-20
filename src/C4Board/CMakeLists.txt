SET(Target C4Board)

SET(${Target}_SRCLIST
	Board.h
	Board.cpp
	Move.h
	Move.cpp
	Player.h
)

ADD_LIBRARY(${Target} ${${Target}_SRCLIST})