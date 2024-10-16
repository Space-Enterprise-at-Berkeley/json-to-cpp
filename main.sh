#!/bin/bash

source env/bin/activate
rm bin/*
cd src
python compile.py
