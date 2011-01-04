# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = src
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += algo/Vigenere.cpp main.cpp algo/Scytale.cpp ui/VigenereUI.cpp algo/Caesar.cpp algo/BaseAlgo.cpp ui/UI.cpp ui/CaesarUI.cpp ui/ScytaleUI.cpp
HEADERS += algo/Scytale.h ui/ScytaleUI.h ui/VigenereUI.h algo/BaseAlgo.h ui/CaesarUI.h ui/UI.h algo/Caesar.h algo/Vigenere.h
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
