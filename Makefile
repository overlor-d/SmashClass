# Makefile - Cross-platform (Windows client & Linux server)

# Detect OS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
# ----- Linux server configuration -----
  CXX       := g++
  CXXFLAGS  := -std=c++20
  LDFLAGS   := -lsfml-network
  TARGET_SERVER := server
else
# ----- Windows client & server configuration -----
  SFML_PATH    := C:/SFML-3.0.0
  SFML_INCLUDE := $(SFML_PATH)/include
  SFML_LIB     := $(SFML_PATH)/lib

  CXX       := g++
  CXXFLAGS  := -std=c++20 -I"$(SFML_INCLUDE)"
  LDFLAGS   := -L"$(SFML_LIB)" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

  TARGET_CLIENT := client.exe
  TARGET_SERVER := server.exe
endif

SRC_CLIENT := src/main.cpp
SRC_SERVER := src/server.cpp

.PHONY: all client server exec_client exec_server clean

all: client server

client:
ifeq ($(UNAME_S),Linux)
	@echo "Client build not supported on Linux."
else
	$(CXX) $(CXXFLAGS) $(SRC_CLIENT) -o $(TARGET_CLIENT) $(LDFLAGS)
endif

exec_client:
ifeq ($(UNAME_S),Linux)
	@echo "Client execution not supported on Linux."
else
	./$(TARGET_CLIENT)
endif

server:
	$(CXX) $(CXXFLAGS) $(SRC_SERVER) -o $(TARGET_SERVER) $(LDFLAGS)

exec_server:
	./$(TARGET_SERVER)

clean:
	rm -f $(TARGET_CLIENT) $(TARGET_SERVER)

