clean:
	cd examples; make clean
	@echo
	cd exercises; make clean

config:
	git config -l

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/ooplsarc.git
	git push -u origin master

pull:
	@rsync -r -t -u -v --delete             \
    --include "Hello.c++"                   \
    --include "Assertions.c++"              \
    --include "UnitTests1.c++"              \
    --include "UnitTests2.c++"              \
    --include "UnitTests3.c++"              \
    --include "Coverage1.c++"               \
    --include "Coverage2.c++"               \
    --include "Coverage3.c++"               \
    --include "Exceptions.c++"              \
    --include "Exceptions2.c++"             \
    --include "Exceptions3.c++"             \
    --include "Types.c++"                   \
    --include "Operators.c++"               \
    --include "Representations.c++"         \
    --include "Variables.c++"               \
    --include "Arguments.c++"               \
    --include "Cache.c++"                   \
    --include "Returns.c++"                 \
    --include "Selection.c++"               \
    --include "Iteration.c++"               \
    --include "StackVsHeap.c++"             \
    --include "Valgrind.c++"                \
    --include "Lambdas.c++"                 \
    --include "Iterators.c++"               \
    --include "Consts.c++"                  \
    --include "Consts2.c++"                 \
    --include "Arrays.c++"                  \
    --include "FunctionDefaults.c++"        \
    --include "Friends.c++"                 \
    --include "Conversions.c++"             \
    --include "Initializations.c++"         \
    --include "FunctionOverloading.c++"     \
    --include "FunctionGenerics.c++"        \
    --include "FunctionSpecializations.c++" \
    --include "Sequences.c++"               \
    --include "Sets.c++"                    \
    --include "Maps.c++"                    \
    --include "TypeAliases.c++"             \
    --include "Auto.c++"                    \
    --include "MethodOverriding1.c++"       \
    --include "MethodOverriding2.c++"       \
    --include "LocalVariables.c++"          \
    --include "GlobalVariables.c++"         \
    --include "ClassVariables.c++"          \
    --include "InstanceVariables.c++"       \
    --exclude "*"                           \
    ../../../examples/c++/ examples
	@rsync -r -t -u -v --delete             \
    --include "IsPrime1.c++"                \
    --include "IsPrime1.h"                  \
    --include "IsPrime2.c++"                \
    --include "IsPrime2.h"                  \
    --include "StrCmp.c++"                  \
    --include "StrCmp.h"                    \
    --include "Incr.c++"                    \
    --include "Incr.h"                      \
    --include "Equal.h"                     \
    --include "Equal.c++"                   \
    --include "Copy.h"                      \
    --include "Copy.c++"                    \
    --include "Fill.h"                      \
    --include "Fill.c++"                    \
    --include "AllOf.h"                     \
    --include "AllOf.c++"                   \
    --include "Accumulate.c++"              \
    --include "Accumulate.h"                \
    --include "Transform.c++"               \
    --include "Transform.h"                 \
    --include "RangeIterator.c++"           \
    --include "RangeIterator.h"             \
    --include "Range.c++"                   \
    --include "Range.h"                     \
    --include "Vector1.c++"                 \
    --include "Vector1.h"                   \
    --include "Vector2.c++"                 \
    --include "Vector2.h"                   \
    --include "Memory.h"                    \
    --include "Stack.c++"                   \
    --include "Stack.h"                     \
    --include "Queue.c++"                   \
    --include "PriorityQueue.c++"           \
    --include "Allocator.c++"               \
    --include "Allocator.h"                 \
    --include "Move.c++"                    \
    --include "Move.h"                      \
    --include "Vector3.c++"                 \
    --include "Vector3.h"                   \
    --include "Vector4.c++"                 \
    --include "Vector4.h"                   \
    --include "Shapes1.c++"                 \
    --include "Shapes1.h"                   \
    --include "Shapes2.c++"                 \
    --include "Shapes2.h"                   \
    --include "Shapes3.c++"                 \
    --include "Shapes3.h"                   \
    --include "Shapes.h"                    \
    --include "Handle1.c++"                 \
    --include "Handle2.c++"                 \
    --include "Handle3.c++"                 \
    --include "Reflection.c++"              \
    --exclude "*"                           \
    ../../../exercises/c++/ exercises

push:
	make clean
	@echo
	git add .travis.yml
	git add examples
	git add exercises
	git add makefile
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

testx:
	cd examples; make testx
	@echo
	cd exercises; make testx

testy:
	cd examples; make testy
	@echo
	cd exercises; make testy

testz:
	cd examples; make testz
	@echo
	cd exercises; make testz
