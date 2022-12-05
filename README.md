# nudpcast
[UDPCast](https://wwww.udpcast.linux.lu/) by [Alain Knaff](http://knaff.lu/), patched.

Currently based on [udpcast-20211207](https://www.udpcast.linux.lu/download/udpcast-20211207.tar.gz).

## Development

Run `./configure` to set up the Makefile, then `make` to compile. Requires gcc.

## Changes

* Uses SO_REUSEADDR on sockets.
