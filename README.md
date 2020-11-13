# Gyrosnake
A snake game on a stm32l475 displayed on a 8x8 led matrix and controlled by the embedded gyroscope of the microcontroller.

## Use
You might need to update the `udev rules` to use the following commands without `sudo`.

### Compilation
`make` to create the binary.

`make re` to `clean-all` and then `make`.

### gdb
`make gdb_server` to launch the JLink GDB Server.

`make gdb` to launch gdb and connect it to the server.

Beware that if you're not configured to allow reading `.gdbinit`, you might have to connect *by hand* to the server.

When in `gdb`, use `flash` to upload the program on the microcontroller, and `c` to run it.

### Clean
`make clean` to clean intermediate binaries.

`make clean-all` to clean all binaries, including the final `.bin` file.
