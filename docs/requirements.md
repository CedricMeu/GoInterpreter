## Requirements
# legend
- p : implemented in lexer and parser
- t : p and implemented in typechecking
- x : t and implemented in interpreter (done)

# Types
- [t] bool
- [t] int
- [t] float32
- [t] byte
- [t] rune
- [t] type declarations
- [t] string
- [t] array
- [t] slice
- [t] struct
- [t] function
- [t] maps
- [t] pointers

# literals
- [t] bool `true` and `false`
- [t] integers
- [t] floats
- [t] runes (eg. `'c'` and including escaped chars `'\n'` etc.)
- [t] strings (interpreted)
- [t] arrays
- [t] structs
- [t] function literals
- [ ] nil

# expressions
- [t] function calls
- [t] arithemtic
- [t] logical operations
- [t] string concatenation
- [t] indexing (string, array, map)
- [t] selector for structs
- [fixme] conversions (`float(some_int)`)
- [ ] adres operators

# statements
- [t] type declarations
- [t] variable declarations
- [fixme] short variable declarations
- [t] assignment
- [t] return
- [t] if
- [t] single expression
- [t] switch statement
- [t] break
- [t] continue
- [t] for conditional
- [ ] for range

# functions
- [t] block scopes
- [t] function declarations
- [t] can have all types as input and output
- [ ] varargs (`...`)
- [fixme] multiple return values

# built in
- [ ] print
- [ ] len (array)
- [ ] delete (map entry)
- [ ] new (pointer)
- [ ] copy

# mics
- [ ] Only support 1 source file with `package main` as begin
- [ ] main function with no parameters
- [x] if last token in specific subset of tokentypes, return `";"` on recognising a `"\n"`
- [ ] garbage collector

# Notes
Go strings are not null terminated but by length of the array, `"t\000est"` prints `test` and has length `5`.