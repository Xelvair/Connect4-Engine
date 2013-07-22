SET(Target C4AI)

SET(${Target}_SRCLIST
	IEvaluator.h
	TestEvaluator.h
	TestEvaluator.cpp
	CheckPath.h
	GameNode.h
	GameNode.cpp
	TestTreeGenerator.h
	TestTreeGenerator.cpp
	ITreeGenerator.h
	GameTree.h
	GameTree.cpp
	EvaluatorV2.h
	EvaluatorV2.cpp
)

ADD_LIBRARY(${Target} ${${Target}_SRCLIST})