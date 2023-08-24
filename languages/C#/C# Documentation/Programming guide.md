### Types

#### Boxing and Unboxing

Boxing is the process of converting a value type to the type object or to any interface type implemented by this value type.

When the common language runtime (CLR) boxes a value type, it **wraps the value inside a System.Object instance and stores it on the managed heap**. Unboxing extracts the value type from the object. Boxing is implicit; unboxing is explicit. The concept of boxing and unboxing underlies the C# unified view of the type system in which a value of any type can be treated as an object.
