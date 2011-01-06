TEMPLATE = app
DESTDIR = dist
TARGET = yaca
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
QT = core gui
SOURCES +=  main.cpp \
            algo/BaseAlgo.cpp \
            algo/Vigenere.cpp \ 
            algo/Scytale.cpp \
            algo/Caesar.cpp \
            algo/Enigma.cpp \
            ui/UI.cpp \
            ui/VigenereUI.cpp \
            ui/CaesarUI.cpp \
            ui/ScytaleUI.cpp \
            ui/EnigmaUI.cpp 
HEADERS +=  algo/Scytale.h \
            algo/BaseAlgo.h \
            algo/Caesar.h \
            algo/Vigenere.h \
            algo/Enigma.h \
            ui/UI.h \
            ui/CaesarUI.h \
            ui/ScytaleUI.h \
            ui/VigenereUI.h \
            ui/EnigmaUI.h
OBJECTS_DIR = build
QMAKE_CC = gcc
QMAKE_CXX = g++

