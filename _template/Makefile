################################################################################
# Super Awesome Makefile for CMSC341
# By Jamison Bryant (jbryant93@umbc.edu) - Fall 2017
#
# Contains a variety of routines (called "targets") that automate certain tasks
# that are commonly repeated so I don't have to type them in 3 billion times.
################################################################################

FILES = src/*.cpp include/*.h README.txt
USERNAME = jbryant2
THISHOST = $(shell hostname)
HOSTNAME = linux1.gl.umbc.edu
PROJECT = $(shell basename `pwd`)

##
# Compiles and builds the program.
##

build:
	echo Building...

##
# Runs the program.
##

run:
	echo Running...

##
# Deletes temp and trash files from the dir.
##

clean:
	echo Cleaning...

##
# Deploys source code files to GL
##

deploy:
	if [ "$(THISHOST)" == "$(HOSTNAME)" ]; then\
		echo Already on GL, nothing to do...;\
	else\
		echo Deploying source code to GL...;\
		sshpass -f ~/password.txt rsync -rv --delete $(FILES) $(USERNAME)@$(HOSTNAME):cmsc341/$(PROJECT)/;\
	fi\
