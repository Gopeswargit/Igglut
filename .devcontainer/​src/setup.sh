#!/bin/bash
export DISPLAY=:1
Xvfb :1 -screen 0 1024x768x24 & 
fluxbox & 
x11vnc -display :1 -nopw -forever -bg &
g++ src/main.cpp -o engine -lGL -lGLU -lglut
# ইঞ্জিন রান করা এবং ব্যাকগ্রাউন্ডে রাখা (স্থায়ী করার জন্য)
nohup ./engine > engine.log 2>&1 &
echo "ইঞ্জিন চালু হয়েছে! এখন PORTS ট্যাব থেকে ৫৯০০ পোর্টের লিঙ্কে যান।"


