#!/bin/bash

echo "______________________________________________Valid maps"
valgrind --leak-check=full ./so_long_bonus maps/map02.ber 
valgrind --leak-check=full ./so_long_bonus maps/map07.ber 

echo "______________________________________________Done"
