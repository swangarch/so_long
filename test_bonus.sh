#!/bin/bash

echo "______________________________________________Not valid maps"
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map10.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map11.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map12.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map13.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map14.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map15.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map16.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map17.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map18.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map19.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map20.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map21.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map22.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map23.ber

echo "______________________________________________Valid maps"
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map00.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map01.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map02.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map03.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map04.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map05.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map06.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map07.ber
valgrind --leak-check=full --track-origins=yes ./so_long_bonus maps/map08.ber

echo "______________________________________________Done"
