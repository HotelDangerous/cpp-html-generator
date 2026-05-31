# cpp-html-generator

A small C++ project for generating static HTML documents from C++ code.

This project is an early experiment in building a simple document-generation system. The goal is to create HTML pages using C++ classes instead of writing the HTML by hand.

## Current Status

Work in progress.

The project can currently generate a basic HTML document and write it to a file that can be opened in a browser.

## Motivation

This project was inspired by document-building ideas from *Design Patterns* and by a larger goal of building algorithm visualizations with C++.

The long-term idea is to use C++ to generate structured HTML documents containing blocks such as:

- paragraphs
- buttons
- button rows
- grids
- algorithm visualization containers
- interactive layouts

For now, the focus is intentionally small: generate a valid HTML document from C++.

## Project Goals

- Practice C++ project structure
- Practice file output with C++
- Build a simple document abstraction
- Eventually support reusable HTML blocks
- Keep the generated HTML viewable in a normal browser

## Example Workflow

Build the project:

```bash
cmake -S . -B build
cmake --build build
```
