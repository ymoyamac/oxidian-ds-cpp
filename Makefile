# Compiler
CC = g++

# Compiler options
CFLAGS = -std=c++20 -I src/include
OFLAGS = -o
#OFLAGS = -Wall -Wextra -o

# Directories
SRCDIR = src
SUBDIRS = \
    nodes \
    lists \
    queues \
    collections \

# Executable
TARGET = main.o

# Dependencies and objects
_DEPS = \
    simple_node.cpp \
    linked_list.cpp \
    queue.cpp \
    hash_map.cpp \

DEPS = \
    $(SRCDIR)/lib/nodes/simple_node.cpp \
    $(SRCDIR)/lib/lists/linked_list.cpp \
    $(SRCDIR)/lib/queues/queue.cpp \
    $(SRCDIR)/lib/hash/hash_map.cpp \
    $(SRCDIR)/main.cpp

# Regla principal
all: $(TARGET)

# Compilación del ejecutable
$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $^ $(OFLAGS) $@

# Limpieza
clean:
	rm -f $(TARGET)