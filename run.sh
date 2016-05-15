#!/bin/bash
VIDEO="/home/piotr/Programy/UAV_Challenge/video/GOPR1802.MP4"
CLASIFIER="/home/piotr/Programy/UAV_Challenge/data/cascade.xml"
echo "Video file: $VIDEO"
echo "Clasifier file: $CLASIFIER"
./uav_raspberry $VIDEO $CLASIFIER