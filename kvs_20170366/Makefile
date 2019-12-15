SRCS = open.cpp put.cpp get.cpp close.cpp
OBJS = $(SRCS:%.cpp=%.o)
CC = g++

static:
	$(CC) -c $(SRCS)
	ar rcs libstatic.a $(OBJS)
	ranlib libstatic.a
	$(CC) -c test_static.cpp
	$(CC) -static -o test_static test_static.o ./libstatic.a

dll:
	$(CC) -shared -o libdll.so $(SRCS) -fPIC
	$(CC) -o test_dll test_dll.cpp -ldl
