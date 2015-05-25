CFLAGS = -g
OBJS = test-coro.o ../coro.o ../buffer.o ../message.o
EXES = test-coro test-decode

all: $(OBJS) $(EXES)

test-coro: test-coro.o ../coro.o
	$(CXX) ${CFLAGS} $^ -o $@
	
test-decode: test-decode.o ../buffer.o ../message.o
	$(CXX) ${CFLAGS} $^ -o $@

.cpp.o:
	$(CXX) ${CFLAGS} -c $< -o $@
	
clean:
	rm -f ${EXES} ${OBJS} 
