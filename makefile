CXX=g++
CC=gcc
LD=$(CXX)
CXX_FLAGS=-g -I ./
CC_FLAGS=-g -I ./
LD_FLAGS=-g -l glfw
CXX_SRC=$(shell find . -type f -name "*.cpp")
CC_SRC=$(shell find . -type f -name "*.c")
OBJS=$(patsubst %, %.o, $(CXX_SRC)) $(patsubst %, %.o, $(CC_SRC))
OUTPUT=glt

test: $(OUTPUT)
	@printf "[TEST] $<\n"
	@./$<

$(OUTPUT):	$(OBJS)
	@printf "[LD] -> $@\n"
	@$(LD) $(LD_FLAGS) $(OBJS) -o $@

%.cpp.o: %.cpp
	@printf "[CXX] $<\n"
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

%.c.o: %.c
	@printf "[CC] $<\n"
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OUTPUT)