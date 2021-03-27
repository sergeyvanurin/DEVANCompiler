# DEVANCompiler

## Build and run
Build project:
```
mkdir build && cd build && cmake .. && make && cd ..
```

Then run it passing a mini-java file as a first argument and output file to print tree as a second argument:
`./build/Compiler <mini-java file> <output file>`

Simple mini-java program:
```
class Program {
  public static void main () {
  int num;
  num = 5;
  }
}
```
