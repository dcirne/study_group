# Open Data Format and Protobuf

This project implements a [Open Data Format](http://www.opengroup.org/iot/odf/index.htm) data structure using [Protocol Buffers](https://developers.google.com/protocol-buffers/).

## Install protobuf

Follow the instructions from [https://github.com/protocolbuffers/protobuf](https://github.com/protocolbuffers/protobuf) to install the protobuf runtime.

## Generating the protobuf classes

Change to the `odf` directory inside the `study_group` repository.

```bash
cd odf
```

Create directories to host the build and binary files. This helps to keep the source control clean, as those directories are ignored in commits.

```bash
mkdir build bin
```

Generate the classes from protobuf

```bash
protoc -I ./ --cpp_out=./ odf.proto foo_bar.proto
```

Compile the proto classes

```bash
clang++ odf.pb.cc -std=c++17 -O3 -c -o ./build/odf.pb.o
```

```bash
clang++ foo_bar.pb.cc -std=c++17 -O3 -c -o ./build/foo_bar.pb.o
```

## Build and run

```bash
clang++ main.cpp ./build/odf.pb.o ./build/foo_bar.pb.o -std=c++17 -O3 $(pkg-config --libs protobuf) -ldl -Wall -pedantic -o ./bin/odf
```

```bash
./bin/odf
```
