#!/bin/bash

echo "______________________________________________Valid maps"
valgrind --leak-check=full ./so_long maps/map02.ber 

echo "______________________________________________Done"
