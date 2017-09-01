################################################################################
# Super Awesome Makefile for CMSC341
# By Jamison Bryant (jbryant93@umbc.edu) - Fall 2017
#
# Contains a variety of routines (called "targets") that automate certain tasks
# that are commonly repeated so I don't have to type them in 3 billion times.
################################################################################

FILES = src/*.cpp include/*.h README.txt Makefile
USERNAME = jbryant2
THISHOST = $(shell hostname)
HOSTNAME = linux1.gl.umbc.edu
PROJECT = $(shell basename `pwd`)

# Customize these commands for each project
EXECUTABLE = a.out
BUILDCMD = g++ -g
RUNCMD = ./$(EXECUTABLE)

##
# Compiles and builds the program.
##

build:
	$(BUILDCMD)

##
# Runs the program.
##

run:
	$(RUNCMD)

##
# Launches the program debugger.
##

debug:
	gdb $(EXECUTABLE) 

##
# Deletes temp and trash files from the dir.
##

clean:
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
