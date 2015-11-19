FILES :=       \
    Accumulate \
    AllOf      \
    Copy       \
    Incr       \
    IsPrime1   \
    IsPrime2   \
    Equal      \
    Fill       \
    Shapes1    \
    StrCmp     \
    Transform  \
    Vector1    \
    Vector2    \
    Vector3    \
    Vector4    \
    Shapes1    \
    Shapes2    \
    Shapes3    \
    Handle1    \
    Handle2    \
    SharedPtr

CXX        := g++-4.8
CXXFLAGS   += -pedantic -std=c++11 -Wall -MP -MMD
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind
DEP := $(addsuffix .d, $(FILES))

all: StrCmp

-include $(DEP)

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
