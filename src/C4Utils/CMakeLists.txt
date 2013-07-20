SET(Target C4Utils)

SET(${Target}_SRCLIST
	Vec2.h
	Vec2.inl
	Array2.h
	Array2.inl
)

ADD_LIBRARY(${Target} ${${Target}_SRCLIST})