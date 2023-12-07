part1: part1.cpp struct.cpp 
	g++ part1.cpp struct.cpp  -o part1
part2: part2.cpp struct2.cpp
	g++ part2.cpp struct2.cpp -o part2
part3: part3.cpp struct3.cpp
	g++ part3.cpp struct3.cpp -o part3
part4: part4.cpp struct4.cpp
	g++ part4.cpp struct4.cpp -o part4

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py