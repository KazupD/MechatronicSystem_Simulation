clear; clc; close all;

udpportObj = udpport("datagram","LocalPort",8080);

data = read(udpportObj,1,"double").Data
