#####################################################
# You may need to change the parameters under here. #
#####################################################

# Step 1: Choose a compiler. By default, use clang++

# If you use clang++, make sure the following line does not start with a comment (#)
#CXX=clang++
# If you use g++, uncomment the following line
CXX=g++

# Set default compiler parameters
# -Wall 	shows all warnings when compiling, always use this!
# -std=c++11 	enables the C++11 standard mode

#macos
#CXXFLAGS = -Wall -std=c++11

#windows 
CXXFLAGS = -std=gnu++0x

# Step 2: If you use clang++ under Mac OS X, remove these comments
#CXXFLAGS += -stdlib=libc++
#LFLAGS += -stdlib=libc++

# Step 3: Run 'make' in the same directory as this file


############################
# Settings #
############################

IDIR =include

ODIR=obj
LDIR =lib
SDIR=src


################################
# Settings for the testing app #
################################

build: $(ODIR)/main.o $(ODIR)/image.o $(ODIR)/functions.o
	$(CXX) -o main $^ $(CXXFLAGS)

$(ODIR)/image.o: $(SDIR)/image.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/main.o: $(SDIR)/main.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/functions.o: $(SDIR)/functions.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -r -f obj/*.o
	rm -r -f main