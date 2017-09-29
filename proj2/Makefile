SHELL = /usr/bin/bash

SOURCE_DIR = src
TEST_DIR = test
INCLUDE_DIR = include
OUTPUT_DIR = bin
DIST_DIR = dist

BUILD_CMD = g++ -Wall -I $(INCLUDE_DIR) -lmingw32 -mwindows

##
# Removes temporary files from project directory
##
clean:
	@echo "[make ] target 'clean' requested"

	@echo "[clean] deleting Visual Studio output directories..."
	rm -rf Debug Release

	@echo "[clean] deleting g++ output directories..."
	rm -rf $(OUTPUT_DIR)

	@echo "[clean] deleting dist output directories..."
	rm -rf $(DIST_DIR)

	@echo "[clean] deleting Vim swapfiles..."
	rm -f *.swp

##
# Builds the project
##
build: clean
	@echo "[make ] target 'build' requested"

	@echo "[build] creating g++ output directory..."
	mkdir $(OUTPUT_DIR)

	@echo "[build] building project source code..."
	$(BUILD_CMD) $(INCLUDE_DIR)/*.h $(SOURCE_DIR)/*.cpp -o $(OUTPUT_DIR)/proj2.out

	@echo "[build] building provided project tests..."
	$(foreach TEST_FILE, $(TEST_DIR)/*.cpp, $(BUILD_CMD) $(TEST_FILE) -o $(OUTPUT_DIR)/$(basename $(TEST_FILE)).out)

##
# Runs the project test suite
##
test: build
	@echo "[make ] target 'test' requested"

	@echo "[test ] running provided project tests..."
	./$(OUTPUT_DIR)/p2comptest.out
	./$(OUTPUT_DIR)/p2timetest1.out
	./$(OUTPUT_DIR)/p2timetest2.out
	./$(OUTPUT_DIR)/p2timetest3.out

##
# Times the execution of each test
##
time: build
	@echo "[make ] target 'time' requested"

	@echo "[time ] timing provided project tests..."
	/usr/bin/time -o tmp/time/p2comptest.time ./$(OUTPUT_DIR)/p2comptest.out
	/usr/bin/time -o tmp/time/p2timetest1.time ./$(OUTPUT_DIR)/ptimetest1.out
	/usr/bin/time -o tmp/time/p2timetest2.time ./$(OUTPUT_DIR)/ptimetest2.out
	/usr/bin/time -o tmp/time/p2timetest3.time ./$(OUTPUT_DIR)/ptimetest3.out

	@echo "[time ] processing timing test results..."
	@echo "Timing test results:\n\n" >> timetests.txt

	@echo "p2comptest:\n\n" >> timetests.txt
	@cat tmp/time/p2comptest.time >> timetests.txt
	@echo "\n\n========================================\n\n"

	@echo "p.time.tmptest1:\n\n" >> timetests.txt
	@cat tmp/time/p2timetest1.time >> timetests.txt
	@echo "\n\n========================================\n\n"

	@echo "p.time.tmptest2:\n\n" >> timetests.txt
	@cat tmp/time/p2timetest2.time >> timetests.txt
	@echo "\n\n========================================\n\n"

	@echo "p.time.tmptest3:\n\n" >> timetests.txt
	@cat tmp/time/p2timetest3.time  >> timetests.txt
	@echo "\n\n========================================\n\n"
	@echo "Timing test details logged in timetests.txt" >>  timetests.txt

	@echo "[time ] cleaning up temporary files..."
	rm -rf tmp/time

	@echo "[time ] timing test complete"
	@cat timetests.txt

##
# Checks the program for memory leaks
##
check: build
	@echo "[make ] target 'check' requested"

##
# Generates project documentation
##
docs:
	@echo "[make ] target 'docs' requested"

##
# Prepares the project for distribution
##
dist: build
	@echo "[make ] target 'dist' requested"

	@echo "[dist ] creating dist output directory..."
	mkdir dist

##
# Deploys the project distribution to GL
##
deploy: dist
	@echo "[make ] target 'deploy' requested"

