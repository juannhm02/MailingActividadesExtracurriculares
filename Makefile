# Makefile para compilar proyecto C++

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -IEntities -IVistas -Wall -g

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

# Limpiar archivos generados
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Impedir problemas con archivos con nombres conflictivos
.PHONY: all clean
