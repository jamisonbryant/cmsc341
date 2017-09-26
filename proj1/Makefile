################################################################################
# Super Awesome Makefile for CMSC341
# By Jamison Bryant (jbryant93@umbc.edu) - Fall 2017
#
# Contains a variety of routines (called "targets") that automate certain tasks
# that are commonly repeated so I don't have to type them in 3 billion times.
################################################################################

FILES = src/*.cpp include/*.h test/*.cpp Makefile
USERNAME = jbryant2
THISHOST = $(shell hostname)
HOSTNAME = linux1.gl.umbc.edu
PROJECT = $(shell basename `pwd`)

##
# Prepares the environment for the build process
##
prepare: clean
	mkdir bin

##
# Compiles and builds the program.
##

build: prepare t01 t02 t03 t04 t05 t06 t07 t08 t09 t10 t11 t12 t13

t01: prepare
	g++ -g -I include test/p1test01.cpp src/InnerCB.cpp -o bin/t01.out

t02: prepare
	g++ -g -I include test/p1test02.cpp src/InnerCB.cpp -o bin/t02.out
	
t03: prepare
	g++ -g -I include test/p1test03.cpp src/InnerCB.cpp -o bin/t03.out

t04: prepare
	g++ -g -I include test/p1test04.cpp src/InnerCB.cpp -o bin/t04.out

t05: prepare
	g++ -g -I include test/p1test05.cpp src/InnerCB.cpp -o bin/t05.out

t06: prepare
	g++ -g -I include test/p1test06.cpp src/InnerCB.cpp src/CBofCB.cpp -o bin/t06.out

t07: prepare
	g++ -g -I include test/p1test07.cpp src/InnerCB.cpp src/CBofCB.cpp -o bin/t07.out

t08: prepare
	g++ -g -I include test/p1test08.cpp src/InnerCB.cpp src/CBofCB.cpp -o bin/t08.out

t09: prepare
	g++ -g -I include test/p1test09.cpp src/InnerCB.cpp src/CBofCB.cpp -o bin/t09.out

t10: prepare
	g++ -g -I include test/p1test10.cpp src/InnerCB.cpp src/CBofCB.cpp -o bin/t10.out

t11: prepare
	g++ -g -I include test/p1test11.cpp src/InnerCB.cpp src/CBofCB.cpp -o bin/t11.out

t12: prepare
	g++ -g -I include test/p1test12.cpp src/InnerCB.cpp src/CBofCB.cpp -o bin/t12.out

t13: prepare
	g++ -g -I include test/p1test13.cpp src/InnerCB.cpp src/CBofCB.cpp -o bin/t13.out


##
# Runs the program.
##

run: build
	#$(RUNCMD)

##
# Launches the program debugger.
##

debug:
	#gdb $(EXECUTABLE) 

##
# Deletes temp and trash files from the dir.
##

clean:
	rm -rf bin
	rm -f *.out
	rm -f typescript

##
# Deploys source code files to GL
##

deploy:
	@if [ "$(THISHOST)" == "$(HOSTNAME)" ]; then\
		echo Already on GL, nothing to do...;\
	else\
		sshpass -f ~/password.txt rsync -rv --ignore-missing-args \
			--delete $(FILES) $(USERNAME)@$(HOSTNAME):cmsc341/$(PROJECT)/;\
	fi\
