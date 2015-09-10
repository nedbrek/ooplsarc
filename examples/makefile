FILES :=              \
    Hello             \
    UnitTests3        \
    Coverage1         \
    Coverage2         \
    Coverage3         \
    Exceptions        \
    StrCmp            \
    Exceptions2       \
    Exceptions3       \
    Types             \
    Representations   \
    Variables         \
    Operators         \
    StackVsHeap       \
    Valgrind          \
    Selection         \
    Iteration         \
    TypeAliases       \
    Initializations   \
    Auto              \
    Consts            \
    Consts2           \
    Arrays

#    Types             \
#    Functions         \
#    AbstractClasses   \
#    Handle1           \
#    Handle2           \
#    Handle3           \
#    MethodOverriding1 \
#    MethodOverriding2

CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

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
