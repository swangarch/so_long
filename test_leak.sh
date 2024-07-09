#!/bin/bash

echo "______________________________________________Not valid maps"
valgrind ./so_long maps/map10.ber
valgrind ./so_long maps/map11.ber
valgrind ./so_long maps/map12.ber
valgrind ./so_long maps/map13.ber
valgrind ./so_long maps/map14.ber
valgrind ./so_long maps/map15.ber
valgrind ./so_long maps/map16.ber
valgrind ./so_long maps/map17.ber
valgrind ./so_long maps/map18.ber
valgrind ./so_long maps/map19.ber
valgrind ./so_long maps/map20.ber
valgrind ./so_long maps/map21.ber
valgrind ./so_long maps/map22.ber
valgrind ./so_long maps/map23.ber

echo "______________________________________________Valid maps"
valgrind ./so_long maps/map00.ber
valgrind ./so_long maps/map01.ber
valgrind ./so_long maps/map02.ber
valgrind ./so_long maps/map03.ber
valgrind ./so_long maps/map04.ber
valgrind ./so_long maps/map05.ber
valgrind ./so_long maps/map06.ber

echo "______________________________________________Done"
