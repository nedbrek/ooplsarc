FILES :=

CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

ifeq ($(CXX), clang++)
    GCOV      := gcov-4.6
    GCOVFLAGS := --coverage
else
    CXX       := g++-4.8
    GCOV      := gcov-4.8
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
endif

%.appx: %.c++
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.appy: %.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) $< -o $@ $(LDFLAGS)

%.appz: %.c++
	$(CXX) $(CXXFLAGS) $(GPROFFLAGS) $< -o $@ $(LDFLAGS)

%.c++x: %.appx
	$(VALGRIND) ./$<

%.c++y: %.appy
	./$<
	$(GCOV) -b ./$(<:.appy=.c++) | grep -A 5 "File '$(<:.appy=.c++)'"

%.c++z: %.appz
	./$<
	$(GPROF) ./$<

clean:
	rm -f *.appx
	rm -f *.appy
	rm -f *.appz
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov

testx: $(FILES:=.c++x)

testy: $(FILES:=.c++y)

testz: $(FILES:=.c++z)
