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

In case you have a previous version of gRPC installed on your computer, you will need to remove the installed headers from `usr/local/include`. Just run:

```bash
sudo rm -rf /usr/local/include/grpc++
sudo rm -rf /usr/local/include/grpc
```

Follow these instructions (https://github.com/grpc/grpc/blob/master/BUILDING.md) to build gRPC C++ from source.

After `make` finishes executing, run:

```bash
sudo make install
```

This step is needed to install gRPC's libraries and headers in the system directories.


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

Compile the proto classes to objects (`.o` files)

```bash
clang++ hitchhiker.pb.cc -std=c++17 -c -o ./build/hitchhiker.pb.o
```

```bash
clang++ hitchhiker.grpc.pb.cc -std=c++17 -c -o ./build/hitchhiker.grpc.pb.o
```

### Build the synchronous server and client

```bash
clang++ DeepThought.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/DeepThought
```

```bash
clang++ Magrathean.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/Magrathean
```

#### Ask the ultimate question

In one terminal run Deep Though

```bash
./bin/DeepThought
```

In another terminal, run Magrathean

```bash
./bin/Magrathean
```

### Build the asynchronous server and client

```bash
clang++ DeepThought_Async.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/DeepThought_Async
```

```bash
clang++ Magrathean_Async.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/Magrathean_Async
```

#### Ask the ultimate question

In one terminal run Deep Though

```bash
./bin/DeepThought_Async
```

In another terminal, run Magrathean

```bash
./bin/Magrathean_Async
```

### Try mixing sync and async

You can mix the excution of synchronous and asynchronous client and server. Try, see what happens.


## Stream

Now let's take a look at streams. When you need to place multiple requests at once, receive multiple responses at once, or both, you use streams (Read and Write)

### Build the synchronous stream server and client

```bash
clang++ DeepThought.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/DeepThought
```

```bash
clang++ Magrathean.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/Magrathean
```

#### Ask the ultimate question

In one terminal run Deep Though

```bash
./bin/DeepThought
```

In another terminal, run Magrathean

```bash
./bin/Magrathean
```


### Build the asynchronous stream server and client

```bash
clang++ DeepThought_AsyncStream.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/DeepThought_AsyncStream
```

```bash
clang++ Magrathean_Stream.cpp ./build/hitchhiker.pb.o ./build/hitchhiker.grpc.pb.o -std=c++17 -L/usr/local/lib $(pkg-config --libs protobuf grpc++ grpc) -lgrpc++_reflection -ldl -o ./bin/Magrathean_Stream
```

#### Ask the ultimate question

In one terminal run Deep Though

```bash
./bin/DeepThought_AsyncStream
```

In another terminal, run Magrathean

```bash
./bin/Magrathean_Stream
```
