# Compiler
CC = g++

# Compiler options
CFLAGS = -I src/include
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
    node.cpp \
    linkedlist.cpp \
    queue.cpp \
    hashmap.cpp \

DEPS = \
    $(SRCDIR)/lib/nodes/node.cpp \
    $(SRCDIR)/lib/lists/linkedlist.cpp \
    $(SRCDIR)/lib/queues/queue.cpp \
    $(SRCDIR)/lib/collections/hashmap.cpp \
    $(SRCDIR)/main.cpp

# Regla principal
all: $(TARGET)

# Compilación del ejecutable
$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $^ $(OFLAGS) $@

# Limpieza
clean:
	rm -f $(TARGET)