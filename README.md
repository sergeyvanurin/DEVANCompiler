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
      int a; int b;
      a = 5; b = 3;
      while (a > 0) a = a - 1;
      if (a > b) System.out.println(a);
      else System.out.println(b);
  }
}
```
