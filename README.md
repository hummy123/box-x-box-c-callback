# box-x-box

## What is this?

This is a fork of [sml-pong-wars](https://github.com/hummy123/sml-pong-wars) which adds just one feature: with the `i, e, j,  k, l` keys, it's possible to move one of the boxes around.

## Building

Building the program and running it is exactly the same as it is for sml-pong-wars.

## How the callback is set in code

The callback is set entirely in C. There are files `ffi/glfw-key-input.c` and `ffi/glfw-key-input.sml`.

`ffi/glfw-key-input.c` is short and well-commented. It doesn't call any functions exported from MLton. It just:

- Creates a boolean array which indicates if various keys are pressed
- Defines getter functions to get the state of various keys
- Defines a callback function that mutates an element of the array to indicate if the key is pressed or not

`ffi/glfw-key-input.sml` is also short. It just: 

- Imports a function to register the GLFW callback
- Imports the getter functions which return the current state of that key

Finally, there is `imperative-shell/shell.sml`, which:

- Calls the getter functions in the main loop to query the state of the keys (lines 11 - 16)
- Registers the key callback with GLFW at line 38

