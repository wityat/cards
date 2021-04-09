cmake_minimum_required(VERSION 3.14)
project(cards C)

set(CMAKE_C_STANDARD 11)

add_executable(cards main.c cards.c cards.h games.c games.h decks.c decks.h tables.c tables.h)