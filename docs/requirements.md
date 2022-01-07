## Requirements
# legend
- p : implemented in lexer and parser
- t : p and implemented in typechecking
- x : t and implemented in interpreter (done)

# Types
- [x] bool
- [x] int
- [x] float32
- [x] byte
- [x] rune
- [x] type declarations
- [x] string
- [x] array
- [x] slice
- [x] struct
- [x] function
- [x] maps
- [t] pointers

# literals
- [x] bool `true` and `false`
- [x] integers
- [x] floats
- [x] runes (eg. `'c'` and including escaped chars `'\n'` etc.)
- [x] strings (interpreted)
- [t] arrays
- [t] structs
- [x] function literals
- [ ] nil

# expressions
- [x] function calls
- [x] arithemtic
- [x] logical operations
- [x] string concatenation
- [x] indexing (string, array, map)
- [x] selector for structs
- [fixme] conversions (`float(some_int)`)
- [t-ish] adres operators

# statements
- [x] type declarations
- [x] variable declarations
- [fixme] short variable declarations
- [x] assignment
- [x] return
- [x] if
- [x] single expression
- [x] switch statement
- [x] break
- [x] continue
- [x] for conditional

# functions
- [x] block scopes
- [x] function declarations
- [x] can have all types as input and output
- [fixme] multiple return values

# built in
- [x] print
- [ ] len (array)
- [ ] delete (map entry)
- [ ] new (pointer)
- [ ] copy

# mics
- [x] main function with no parameters
- [x] if last token in specific subset of tokentypes, return `";"` on recognising a `"\n"`
- [ ] garbage collector

# Notes
Go strings are not null terminated but by length of the array, `"t\000est"` prints `test` and has length `5`.

*NOT IMPLEMENTED:* Variable declarations cant be done without a value even though the validator allows it.
*NOT IMPLEMENTED:* Composit literals