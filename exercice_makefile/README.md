# Directory description
This directory contains the first exercise: writing a Makefile for the given project.

# Project description
## Directory structure
```
.
├── README.md
├── main.c
├── libs
│  └── stubs.c
├── t1.c
├── t1.h
├── t2.c
└── t2.h
```

## Expected makefile
Running `make` should produce the following commands:
```bash
arm-none-eabi-gcc -Wall -Werror -g -Og  -mthumb -c -o main.o main.c
arm-none-eabi-gcc -Wall -Werror -g -Og  -mthumb -c -o t1.o t1.c
arm-none-eabi-gcc -Wall -Werror -g -Og  -mthumb -c -o t2.o t2.c
arm-none-eabi-gcc -g -O2  -mthumb -c -o stubs.o libs/stubs.c
arm-none-eabi-gcc -L/opt/mylibs -mthumb main.o t1.o stubs.o t2.o  -lm -o hello
```

There should be a clean target, `.h` files must not be forgotten and the makefile must be as clean and short as possible.
