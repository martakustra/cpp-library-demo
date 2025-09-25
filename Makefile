CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

GTEST_INC = -I/usr/local/include
GTEST_LIBS = -L/usr/local/lib -lgtest -lgtest_main -pthread

INCLUDES = -Isrc

COV_FLAGS = -O0 -g -fprofile-instr-generate -fcoverage-mapping

SRC = src/Book.cpp src/Library.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = app

all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==== GoogleTest ====
test_book: tests/book_test.cpp src/Book.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INC) $^ -o $@ $(GTEST_LIBS)

run_book: test_book
	./test_book

clean:
	rm -f $(TARGET) test_book *.o src/*.o

# ==== Coverage (clang/llvm) ====
coverage_book: clean
	$(MAKE) test_book CXX=clang++ CXXFLAGS="$(CXXFLAGS) $(COV_FLAGS)"
	mkdir -p coverage
	LLVM_PROFILE_FILE="coverage/%p_%m.profraw" ./test_book
	llvm-profdata merge -sparse coverage/*.profraw -o coverage/coverage.profdata
	mkdir -p coverage_html
	llvm-cov show ./test_book \
		-instr-profile=coverage/coverage.profdata \
		-format=html -output-dir=coverage_html \
		-ignore-filename-regex='(third_party|tests)/' \
		-Xdemangler c++filt \
		src/*.cpp
	@echo "HTML raport: coverage_html/index.html"

coverage_lib: clean
	$(MAKE) test_lib CXX=clang++ CXXFLAGS="$(CXXFLAGS) $(COV_FLAGS)"
	mkdir -p coverage
	LLVM_PROFILE_FILE="coverage/%p_%m.profraw" ./test_lib
	llvm-profdata merge -sparse coverage/*.profraw -o coverage/coverage.profdata
	mkdir -p coverage_html
	llvm-cov show ./test_lib \
		-instr-profile=coverage/coverage.profdata \
		-format=html -output-dir=coverage_html \
		-ignore-filename-regex='(third_party|tests)/' \
		-Xdemangler c++filt \
		src/*.cpp
	@echo "HTML raport: coverage_html/index.html"
