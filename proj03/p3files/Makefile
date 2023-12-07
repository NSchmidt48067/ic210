part1: part1.cpp Pos.cpp easycurses.cpp glib.cpp glib.h
	g++ part1.cpp Pos.cpp easycurses.cpp glib.cpp -l ncurses -o part1
part2: part2.cpp Pos.cpp easycurses.cpp glib.cpp
	g++ part2.cpp Pos.cpp glib.cpp easycurses.cpp -l ncurses -o part2
part3: part3.cpp Pos.cpp easycurses.cpp glib.cpp
	g++ part3.cpp Pos.cpp glib.cpp easycurses.cpp -l ncurses -o part3
part4: part4.cpp Pos.cpp easycurses.cpp glib4.cpp
	g++ part4.cpp Pos.cpp glib4.cpp easycurses.cpp -l ncurses -o part4
part5: part5.cpp Pos.cpp easycurses.cpp glib4.cpp p5main.cpp
	g++ part5.cpp Pos.cpp glib4.cpp p5main.cpp easycurses.cpp -l ncurses -o part5
################## DON'T TOUCH BELOW ##################
run1: part1
	@./part1
run_%: %
	@test -f $* && echo "$*: Code compiled successfully" 

