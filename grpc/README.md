# gRPC

## Installing

Clone the gRPC repository to your system.

```bash
git clone git@github.com:grpc/grpc.git
```

Initialize the submodules

```bash
git submodule update --init
```

### Version 1.15.1

This example is using version version 1.15.1. You can try to work from `master`, or the latest release, but just in case, you can checkout a branch from the `v1.15.1` tag.

```bash
git checkout -b 1.15.1 v1.15.1
```

You may want to have the submodules synced with version they were released.

```bash
git submodule update
```

## Building gRPC

Follow these instructions (https://github.com/grpc/grpc/blob/master/BUILDING.md) to build gRPC C++ from source.

In case you have a previous version of gRPC installed on your computer, you will need to remove the installed headers from `usr/local/include`. Just run:

```bash
sudo rm -rf /usr/local/include/grpc++
sudo rm -rf /usr/local/include/grpc
```

## Generating the protobuf and gRPC classes

Change to the `grpc` directory inside the `study_group` repository.

```bash
cd grpc
```

### gRPC

```bash
protoc -I ./ --grpc_out=./ --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin hitchhiker.proto
```

### protobuf

```bash
protoc -I ./ --cpp_out=./ hitchhiker.proto
```

## Compiling and linking

Create directories to host the build and binary files. This helps to keep the source control clean, as those directories are ignored in commits.

```bash
mkdir build bin
```

Compile the proto calsses to objects (`.o` files)

```bash
clang++ hitchhiker.pb.cc -std=c++17 -c -o ./build/hitchhiker.pb.o
```

```bash
clang++ hitchhiker.grpc.pb.cc -std=c++17 -c -o ./build/hitchhiker.grpc.pb.o
```

Build the server and client

```bash
clang++ DeepThought.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/DeepThought
```

```bash
clang++ Magrathean.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/Magrathean
```

## Ask the ultimate question

In one terminal run Deep Though

```bash
./bin/DeepThought
```

In another terminal, run Magrathean

```bash
./bin/Magrathean
```

