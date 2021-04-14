.PHONY : clean all

comp.out : comp.cc
	g++ comp.cc -o comp.out

ans.out : ans.cc
	g++ ans.cc -o ans.out

sol.out : sol.cc
	g++ sol.cc -o sol.out

rand.out : rand.cc
	g++ rand.cc -o rand.out

run : comp.out ans.out sol.out rand.out
	./comp.out sol.out ans.out rand.out

all : comp.out ans.out sol.out rand.out
	echo "make all!"

clean :
	rm comp.out

remove :
	rm data.in data.out data.ans