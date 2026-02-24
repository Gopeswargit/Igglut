#!/bin/bash
export DISPLAY=:1
Xvfb :1 -screen 0 1024x768x24 & 
fluxbox & 
x11vnc -display :1 -nopw -forever -bg &
g++ src/main.cpp -o engine -lGL -lGLU -lglut
nohup ./engine &

