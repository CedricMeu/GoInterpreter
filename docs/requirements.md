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
- [p] arrays
- [p] structs
- [p] function literals
- [ ] nil

# expressions
- [p] function calls
- [p] arithemtic
- [p] logical operations
- [p] string concatenation
- [p] indexing (string, array, map)
- [p] selector for structs
- [p] conversions (`float(some_int)`)
- [ ] adres operators

# statements
- [p] type declarations
- [p] variable declarations
- [fixme] short variable declarations
- [p] assignment
- [p] return
- [p] if
- [p] single expression
- [p] switch statement
- [p] break
- [p] continue
- [p] for conditional
- [ ] for range

# functions
- [p] block scopes
- [p] function declarations
- [p] can have all types as input and output
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
- [x] if last token in specific subset of tokentypes, return `";"` on recognising a `"\n"`
- [ ] garbage collector

# Notes
Go strings are not null terminated but by length of the array, `"t\000est"` prints `test` and has length `5`.