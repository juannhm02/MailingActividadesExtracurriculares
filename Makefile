# Makefile para compilar proyecto C++
# Detectar arquitectura del sistema
UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

# Compilador
CXX = g++

# Opciones de compilación comunes
CXXFLAGS = -IEntities -IVistas -Wall -g -Wc++11-extensions -std=c++11

# Ajustar opciones de compilación para arquitecturas específicas
ifeq ($(UNAME_S),Darwin)
    ifeq ($(UNAME_M),arm64)
        # Opciones para macOS arm64
        CXXFLAGS += -O2 -march=armv8-a
    else
        # Opciones para otras arquitecturas en macOS
        CXXFLAGS += -O2 -march=x86-64
    endif
endif

# Nombre del ejecutable
TARGET = aplicacion

# Directorios
ENTITIESDIR = Entities
VISTASDIR = Vistas
OBJDIR = obj

# Archivos fuente y objeto
SOURCES := $(wildcard $(ENTITIESDIR)/*.cpp) $(wildcard $(VISTASDIR)/*.cpp)
OBJECTS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(SOURCES)))

# Regla por defecto
all: $(TARGET)

# Enlazar objetos para crear el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar cada archivo fuente a objeto
$(OBJDIR)/%.o: $(ENTITIESDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(VISTASDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Incluir todas las dependencias
DEP := $(OBJECTS:.o=.d)
-include $(DEP)

# Generar archivos de dependencias
CXXFLAGS += -MMD -MP



# Makefile para compilar proyecto C++ con pruebas unitarias

# Nombre del ejecutable de pruebas
TEST_TARGET = tests

# Archivos fuente y objeto para las pruebas
TEST_SOURCES := Tests.cpp
TEST_OBJECTS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(TEST_SOURCES)))

# Regla para compilar y ejecutar las pruebas
test: $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $^
	./$(TEST_TARGET)

# Regla para compilar archivos de pruebas
$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar también el ejecutable de pruebas
clean:
	rm -rf $(OBJDIR) $(TARGET) $(TEST_TARGET)

# Agregar la regla test a .PHONY
.PHONY: all clean test
