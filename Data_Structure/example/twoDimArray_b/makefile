# How to run this (under unix):
# make time
# make timeopt

time: row col
	time -p ./row; time -p ./col

row: row.cpp
	gcc -O0 row.cpp -o row

col: col.cpp
	gcc -O0 col.cpp -o col

timeopt: rowopt colopt
	time -p ./rowopt; time -p ./colopt

rowopt: row.cpp
	gcc -O3 row.cpp -o rowopt

colopt: col.cpp
	gcc -O3 col.cpp -o colopt
