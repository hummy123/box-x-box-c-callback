#!/bin/sh
mlton -link-opt "$(pkg-config --cflags glfw3) $(pkg-config --static --libs glfw3)" \
  -export-header ffi/export.h \
  book-and-box.mlb \
  ffi/glad.c \
  ffi/glfw-export.c \
  ffi/gles3-export.c \
  ffi/glfw-key-input.c
