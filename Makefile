# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra # Cambio de -std=c++11 a -std=c++17
LDFLAGS = -lstdc++fs # Bandera para enlazar con la biblioteca del sistema de archivos
SRCDIR = .
INCDIR = include
OBJDIR = obj
BINDIR = .

# Archivos fuente
SRCS := $(SRCDIR)/src/AgregarContactos.cpp \
        $(SRCDIR)/src/ArbolAlv.cpp \
        $(SRCDIR)/src/Buscar.cpp \
        $(SRCDIR)/src/CrearCampo.cpp \
        $(SRCDIR)/src/CrearGrupo.cpp \
        $(SRCDIR)/src/Exportaciones.cpp \
        $(SRCDIR)/src/GeneradorDotFile.cpp \
        $(SRCDIR)/src/Graficas.cpp \
        $(SRCDIR)/src/Importacion.cpp \
        $(SRCDIR)/src/Reportes.cpp \
        $(SRCDIR)/src/start.cpp \
        $(SRCDIR)/src/Terminal.cpp \
        main.cpp

OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
# Archivos de encabezado
INCS := $(wildcard $(INCDIR)/hash/*.h) \
        $(wildcard $(INCDIR)/recursos/*.h) \
        $(wildcard $(INCDIR)/Nodos/*.h) \
        $(wildcard $(INCDIR)/utilidades/*.h)
# Objetivo principal
TARGET = $(BINDIR)/Gestion-de-contacto
# Reglas
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Limpiar
clean:
	m -rf $(OBJDIR) $(BINDIR)

.PHONY: clean


