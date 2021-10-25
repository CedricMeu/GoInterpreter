## Requirements
# legend
- p : implemented in lexer and parser
- v : p and implemented in validation
- t : v and implemented in typechecking
- x : v and implemented in interpreter (done)

# Types
- [p] bool
- [p] int
- [p] float32
- [p] byte
- [p] rune
- [p] type declarations
- [p] string
- [p] array
- [p] slice
- [p] struct
- [p] function
- [p] maps
- [p] pointers

# literals
- [p] bool `true` and `false`
- [p] integers
- [p] floats
- [p] runes (eg. `'c'` and including escaped chars `'\n'` etc.)
- [p] strings (interpreted)
- [ ] arrays
- [ ] structs
- [ ] function literals
- [ ] nil

# expressions
- [ ] function calls
- [ ] arithemtic
- [ ] assignment
- [ ] logical operations
- [ ] string concatenation
- [ ] indexing (string, array, map)
- [ ] selector for structs
- [ ] conversions (`float(some_int)`)
- [ ] adres operators

# statements
- [p] variable declarations
- [p] short variable declarations
- [ ] return
- [ ] if
- [ ] for (itterative and range)
- [ ] single expression
- [ ] switch statement
- [ ] break
- [ ] continue

# functions
- [ ] block scopes
- [ ] function declarations
- [ ] can have all types as input and output
- [ ] varargs (`...`)

# built in
- [ ] print
- [ ] len (array)
- [ ] delete (map entry)
- [ ] new (pointer)
- [ ] copy


# mics
- [ ] Only support 1 source file with `package main` as begin
- [ ] main function with no parameters
- [ ] if last token in specific subset of tokentypes, return `";"` on recognising a `"\n"`
- [ ] type declarations
- [ ] garbage collector

# Notes
Go strings are not null terminated but by length of the array, `"t\000est"` prints `test` and has length `5`.