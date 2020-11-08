# ExecDocs

## Building

To build the project you need a conan.io installed and call below command in project directory:

### Visual Studio

```shell
mkdir build; cd build; conan install .. -r bincrafters && cmake .. -A x64 && cmake --build . --config Release && ctest -V
```

### GCC/clang

```shell
mkdir build; cd build; conan install .. -r bincrafters && cmake .. && cmake --build . --config Release && ctest -V
```
