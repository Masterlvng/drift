CFLAGS = -g
OBJS = test-coro.o ../coro.o
EXES = test-coro

all: $(OBJS) $(EXES)

test-coro: test-coro.o ../coro.o
	$(CXX) ${CFLAGS} $^ -o $@

.cpp.o:
	$(CXX) ${CFLAGS} -c $< -o $@
	
clean:
	rm -f ${EXES} ${OBJS} 
