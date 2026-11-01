# C++ Terminal Image Renderer

A simple C++ program that converts digital images into RGB pixel matrices and renders them directly in the terminal using ANSI escape sequences.

## Overview

This project explores how digital images are represented using matrices and how individual pixel colors can be reproduced in a terminal without a conventional graphics library.

The program loads an image, extracts its RGB values, reduces its resolution based on user input, and displays the resulting image using colored terminal character cells.

## How It Works

1. **Image Loading:** Uses the `stb_image.h` library to load an image and retrieve its RGB pixel data.
2. **Resolution Adjustment:** Samples pixels at intervals determined by a user-specified target width to reduce the image's resolution.
3. **Matrix Construction:** Stores the sampled RGB values in a two-dimensional `std::vector`.
4. **Terminal Rendering:** Iterates through the matrix and uses 24-bit RGB ANSI escape sequences to display each pixel as a colored block.

## Technologies Used

- C++17
- Standard Template Library (`std::vector`)
- stb_image.h for image loading
- ANSI escape sequences for terminal rendering

## Compilation and Usage

Compile the program using a C++17-compatible compiler:

`g++ -std=c++17 terminal_image.cpp -o terminal_image`

Run the executable:

`./terminal_image`

When prompted, provide the path to an image file and a target width.

The program will process the image and display a lower-resolution representation directly in the terminal.

**Note:** A terminal supporting 24-bit RGB colors is recommended. The image dimensions should be selected to fit the terminal window.

## Dependencies

This project uses [stb_image.h](https://github.com/nothings/stb), a single-header image-loading library.

The header must be available alongside the C++ source file when compiling.

## What I Learned

This project was created to explore:

- Representing images using two-dimensional matrices
- Accessing and manipulating RGB pixel data
- Working with dynamically sized 2D vectors in C++
- Downsampling images through pixel selection
- Rendering colored graphics using ANSI terminal escape sequences

## Future Improvements

- More accurate aspect-ratio preservation
- Support for terminal window dimensions
- Improved image scaling
- Terminal-based image animation
