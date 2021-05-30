# How to run this (under unix):
# make time
# make timeopt

time: row col
	time -p ./row; time -p ./col

row: row.cpp matrixSum.cpp matrixSum.h
	g++ -O0 row.cpp matrixSum.cpp -o row

col: col.cpp matrixSum.cpp matrixSum.h
	g++ -O0 col.cpp matrixSum.cpp -o col

timeopt: rowopt colopt
	time -p ./rowopt; time -p ./colopt

rowopt: row.cpp
	g++ -O3 row.cpp matrixSum.cpp -o rowopt

colopt: col.cpp
	g++ -O3 col.cpp matrixSum.cpp -o colopt
