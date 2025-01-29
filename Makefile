# Compiler
CC = g++

# Compiler options
CFLAGS = -I src/include
OFLAGS = -o

# Directories
SRCDIR = src
SUBDIRS = \
    nodes \
    lists \

# Executable
TARGET = main.o

# Dependencies and objects
_DEPS = \
    node.cpp \
    linkedlist.cpp

DEPS = \
    $(SRCDIR)/lib/nodes/node.cpp \
    $(SRCDIR)/lib/lists/linkedlist.cpp \
    $(SRCDIR)/main.cpp

# Regla principal
all: $(TARGET)

# Compilación del ejecutable
$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $^ $(OFLAGS) $@

# Limpieza
clean:
	rm -f $(TARGET)