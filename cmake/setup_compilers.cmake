# https://github.com/lefticus/cppbestpractices/blob/master/02-Use_the_Tools_Available.md

set(MSVC_Warnings
  /W4 # Baseline reasonable warnings
  /w14242 # 'identifier': conversion from 'type1' to 'type1', possible loss of data
  /w14254 # 'operator': conversion from 'type1:field_bits' to 'type2:field_bits', possible loss of data
  /w14263 # 'function': member function does not override any base class virtual member function
  /w14265 # 'classname': class has virtual functions, but destructor is not virtual instances of this class may not be destructed correctly
  /w14287 # 'operator': unsigned/negative constant mismatch
  /we4289 # nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside the for-loop scope
  /w14296 # 'operator': expression is always 'boolean_value'
  /w14311 # 'variable': pointer truncation from 'type1' to 'type2'
  /w14545 # expression before comma evaluates to a function which is missing an argument list
  /w14546 # function call before comma missing argument list
  /w14547 # 'operator': operator before comma has no effect; expected operator with side-effect
  /w14549 # 'operator': operator before comma has no effect; did you intend 'operator'?
  /w14555 # expression has no effect; expected expression with side- effect
  /w14619 # pragma warning: there is no warning number 'number'
  /w14640 # Enable warning on thread un-safe static member initialization
  /w14826 # Conversion from 'type1' to 'type_2' is sign-extended. This may cause unexpected runtime behavior.
  /w14905 # wide string literal cast to 'LPSTR'
  /w14906 # string literal cast to 'LPWSTR'
  /w14928 # illegal copy-initialization; more than one user-defined conversion has been implicitly LearnSDL.exelied
  /permissive- # standards conformance mode for MSVC compiler.
  # TODO: Define optimizations for release builds
  # /O1: Optimize for minimum size. This flag performs basic optimizations to reduce code size.
  # /O2: Optimize for speed. This flag enables a higher level of optimizations that prioritize execution speed.
  # /Ox: Full optimization. This combines various optimizations from both /O1 and /O2 and is used for maximum optimization.
  # /Os: Optimize for space. This flag performs size optimizations to reduce the size of the executable.
  # /Ob1, /Ob2: Control inlining. /Ob1 enables inline expansion of functions marked as inline. /Ob2 allows more aggressive inlining based on heuristics.
  # /Ot: Optimize for fast code. This flag focuses on maximizing execution speed and is similar to /O2, but with more emphasis on speed.
  # /GL: Whole program optimization. This flag performs optimizations across multiple translation units to improve overall performance.
  # /Gy: Enable function-level linking. This flag allows the linker to remove unused functions, reducing the size of the executable.
  # /GS-: Disable buffer security checks. Use this if you're sure your code is safe and want to optimize out some security checks.
  # /fp:fast: Optimize floating-point calculations for speed. This might change the order of floating-point operations for performance.
  # /arch: Specify the target architecture. For example, /arch:AVX2 targets systems that support the AVX2 instruction set.
  # /Qpar: Enable automatic parallelization. This flag allows the compiler to parallelize loops and improve multi-core performance.
  # /Qvec-report: Generate a report on vectorization attempts and successes.
  # /Qipo: Interprocedural optimization. This flag performs optimizations across different source files.
  # /Qinline-max-size: Control inlining size threshold. Useful to control aggressive inlining.
  # /Qunroll: Enable loop unrolling for better performance.
  # /Qopt-report: Generate a report on optimization decisions.
  )
set(CLANG_Warnings
  -Wall
  -Wextra # reasonable and standard
  -Wshadow # warn the user if a variable declaration shadows one from a parent context
  -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps catch hard to track down memory errors
  -Wcast-align # warn for potential performance problem casts
  -Wunused # warn on anything being unused
  -Woverloaded-virtual # warn if you overload (not override) a virtual function
  -Wpedantic # warn if non-standard C++ is used
  -Wconversion # warn on type conversions that may lose data
  -Wsign-conversion # warn on sign conversions
  -Wnull-dereference # warn if a null dereference is detected
  -Wformat=2 # warn on security issues around functions that format output (ie printf)
  # TODO: Define optimizations for release builds
  # -O1: Optimize for minimum size. This flag performs basic optimizations to reduce code size.
  # -O2: Optimize for speed. This flag enables a higher level of optimizations that prioritize execution speed.
  # -O3: Optimize more aggressively for speed. This flag performs even more aggressive optimizations than -O2.
  # -Os: Optimize for size. This flag focuses on reducing code size.
  # -Ofast: Optimize for execution speed and disregard strict compliance with language standards. This can result in more aggressive optimizations but might not adhere to some language rules.
  # -Oz: Optimize for small code size. This flag aims to produce the smallest executable size.
  # -march=: Specify the target architecture for optimizations. For example, -march=native optimizes for the host's architecture.
  # -mllvm: Pass optimization options directly to LLVM. For example, -mllvm -loop-unroll-threshold=100 specifies a loop unrolling threshold.
  # -march=native: Automatically determine the host's architecture and optimize for it.
  # -mavx2, -mavx512f, etc.: Enable specific instruction sets for vectorization (e.g., AVX2, AVX-512).
  # -mllvm -inline-threshold=: Set the threshold for function inlining.
  # -finline-functions: Enable inlining of small functions.
  # -flto: Enable link-time optimization for better cross-file optimizations.
  # -ffast-math: Allow aggressive floating-point optimizations.
  # -funroll-loops: Enable loop unrolling.
  # -fomit-frame-pointer: Omit frame pointers to save space.
  # -fno-exceptions: Disable C++ exceptions for performance and code size.
  # -fno-unwind-tables: Omit unwind tables for smaller code size.
  # -fprofile-use: Use profile-guided optimization based on existing profile data.
  # -fprofile-instr-generate: Generate profile data for profile-guided optimization.
  )
set(GCC_Warnings
  ${CLANG_Warnings}
  -Wmisleading-indentation # warn if indentation implies blocks where blocks
  # Commented out:
  # The following produce problems in some versions of Clang in Windows.
  # -Wduplicated-branches # warn if if / else branches have duplicated code
  # -Wduplicated-cond # warn if if / else chain has duplicated conditions
  # -Wlogical-op # warn about logical operations being used where bitwise were
  # -Wuseless-cast # warn if you perform a cast to the same type
  # TODO: Define optimizations for release builds
  # -O1: Optimize for minimum size. This flag performs basic optimizations to reduce code size.
  # -O2: Optimize for speed. This flag enables a higher level of optimizations that prioritize execution speed.
  # -O3: Optimize more aggressively for speed. This flag performs even more aggressive optimizations than -O2.
  # -Os: Optimize for size. This flag focuses on reducing code size.
  # -Ofast: Optimize for execution speed and disregard strict compliance with language standards. Similar to Clang's -Ofast.
  # -Og: Optimize for debugging. This flag enables optimizations that do not interfere with debugging.
  # -march=: Specify the target architecture for optimizations. For example, -march=native optimizes for the host's architecture.
  # -march=native: Automatically determine the host's architecture and optimize for it.
  # -mavx2, -mavx512f, etc.: Enable specific instruction sets for vectorization (e.g., AVX2, AVX-512).
  # -finline-functions: Enable inlining of small functions.
  # -funroll-loops: Enable loop unrolling.
  # -ffast-math: Allow aggressive floating-point optimizations.
  # -fomit-frame-pointer: Omit frame pointers to save space.
  # -fno-exceptions: Disable C++ exceptions for performance and code size.
  # -fno-unwind-tables: Omit unwind tables for smaller code size.
  # -flto: Enable link-time optimization for better cross-file optimizations.
  # -fprefetch-loop-arrays: Enable automatic prefetching of loop arrays.
  # -malign-data: Control data alignment to improve cache performance.
  # -fprofile-use: Use profile-guided optimization based on existing profile data.
  # -fprofile-instr-generate: Generate profile data for profile-guided optimization.
  )

if (MSVC)
  set(compiler_settings ${MSVC_Warnings})
elseif (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  set(compiler_settings ${CLANG_Warnings})
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Helper feature for clang-based tools
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(compiler_settings ${GCC_Warnings})
else ()
  message(MY_Warning "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
endif ()