// Concepts library
#include <concepts> // (C++20) Fundamental library concepts

// Coroutines library
// #include <coroutine> // (C++20)	Coroutine support library

// Utilities library
#include <any> // (C++17) std::any class
#include <bitset> // std::bitset class template
#include <chrono> // (C++11) C++ time utilities
#include <compare> // (C++20) Three-way comparison operator support
#include <csetjmp> // Macro (and function) that saves (and jumps) to an execution context
#include <csignal> // Functions and macro constants for signal management
#include <cstdarg> // Handling of variable length argument lists
#include <cstddef> // Standard macros and typedefs
#include <cstdlib> // General purpose utilities: program control, dynamic memory allocation, random numbers, sort and search
#include <ctime> //	C-style time/date utilities
#include <expected> // (C++23)	std::expected class template
#include <functional> // Function objects, Function invocations, Bind operations and Reference wrappers
#include <initializer_list> // (C++11)	std::initializer_list class template
#include <optional> // (C++17) std::optional class template
#include <source_location> // (C++20) Supplies means to obtain source code location
#include <tuple> // (C++11) std::tuple class template
#include <type_traits> // (C++11) Compile-time type information
#include <typeindex> // (C++11)	std::type_index
#include <typeinfo> // Runtime type information utilities
#include <utility>	// Various utility components
#include <variant> // (C++17) std::variant class template
#include <version> // (C++20) Supplies implementation-dependent library information

//Dynamic memory management
#include <memory> // High-level memory management utilities
#include <memory_resource> // (C++17) Polymorphic allocators and memory resources
#include <new> // Low-level memory management utilities
#include <scoped_allocator> // (C++11)	Nested allocator class

// Numeric limits
#include <cfloat> // Limits of floating-point types
#include <cinttypes> // (C++11)	Formatting macros, intmax_t and uintmax_t math and conversions
#include <climits> // Limits of integral types
#include <cstdint> // (C++11) Fixed-width integer types and limits of other types
#include <limits> // Uniform way to query properties of arithmetic types
// #include <stdfloat> // (C++23) Optional extended floating-point types

// Error handling
#include <cassert> // Conditionally compiled macro that compares its argument to zero
#include <cerrno> // Macro containing the last error number
#include <exception> // Exception handling utilities
#include <stacktrace> // (C++23) Stacktrace library
#include <stdexcept> // Standard exception objects
#include <system_error> // (C++11) Defines std::error_code, a platform-dependent error code

// Strings library
#include <cctype> // Functions to determine the category of narrow characters
#include <charconv> // (C++17) std::to_chars and std::from_chars
#include <cstring> // Various narrow character string handling functions
#include <cuchar> // (C++11) C-style Unicode character conversion functions
#include <cwchar> // Various wide and multibyte string handling functions
#include <cwctype> // Functions to determine the category of wide characters
// #include <format> // (C++20) Formatting library including std::format
#include <string> // std::basic_string class template
#include <string_view> // (C++17) std::basic_string_view class template

// Containers library
#include <array> // (C++11) std::array container
#include <deque> // std::deque container
// #include <flat_map> // (C++23) std::flat_map and std::flat_multimap container adaptors
// #include <flat_set> // (C++23) std::flat_set and std::flat_multiset container adaptors
#include <forward_list> // (C++11) std::forward_list container
#include <list> // std::list container
#include <map> // std::map and std::multimap associative containers
// #include <mdspan> // (C++23) std::mdspan view
#include <queue> // std::queue and std::priority_queue container adaptors
#include <set> // std::set and std::multiset associative containers
#include <span> // (C++20) std::span view
#include <stack> // std::stack container adaptor
#include <unordered_map> // (C++11)	std::unordered_map and std::unordered_multimap unordered associative containers
#include <unordered_set> // (C++11)	std::unordered_set and std::unordered_multiset unordered associative containers
#include <vector> // std::vector container

// Iterators library
#include <iterator> // Range iterators

// Ranges library
// #include <generator> // (C++23) std::generator class template
#include <ranges> // (C++20) Range access, primitives, requirements, utilities and adaptors

// Algorithms library
#include <algorithm> // Algorithms that operate on ranges
#include <execution> // (C++17)	Predefined execution policies for parallel versions of the algorithms

// Numerics library
#include <bit> // (C++20) Bit manipulation functions
#include <cfenv> // (C++11) Floating-point environment access functions
#include <cmath> // Common mathematics functions
#include <complex> // Complex number type
#include <numbers> // (C++20) Math constants
#include <numeric> // Numeric operations on values in ranges
#include <random> // (C++11) Random number generators and distributions
#include <ratio> // (C++11) Compile-time rational arithmetic
#include <valarray> // Class for representing and manipulating arrays of values

// Localization library
#include <clocale> // C localization utilities
#include <locale> //Localization utilities

// Input/output library
#include <cstdio> // C-style input-output functions
#include <fstream> // std::basic_fstream, std::basic_ifstream, std::basic_ofstream class templates and several typedefs
#include <iomanip> // Helper functions to control the format of input and output
#include <ios> // std::ios_base class, std::basic_ios class template and several typedefs
#include <iosfwd> // Forward declarations of all classes in the input/output library
#include <iostream> // Several standard stream objects
#include <istream> // std::basic_istream class template and several typedefs
#include <ostream> // std::basic_ostream, std::basic_iostream class templates and several typedefs
// #include <print> // (C++23) Formatted output library including std::print
#include <spanstream> // (C++23) std::basic_spanstream, std::basic_ispanstream, std::basic_ospanstream class templates and typedefs
#include <sstream> // std::basic_stringstream, std::basic_istringstream, std::basic_ostringstream class templates and several typedefs
#include <streambuf> // std::basic_streambuf class template
#include <syncstream> // (C++20) std::basic_osyncstream, std::basic_syncbuf, and typedefs

// Filesystem library
#include <filesystem> // (C++17) std::path class and supporting functions

// Regular Expressions library
#include <regex> // (C++11) Classes, algorithms and iterators to support regular expression processing

// Atomic Operations library
#include <atomic> // (C++11) Atomic operations library

// Thread support library
#include <barrier> // (C++20) Barriers
#include <condition_variable> // (C++11) Thread waiting conditions
#include <future> // (C++11) Primitives for asynchronous computations
#include <latch> // (C++20) Latches
#include <mutex> // (C++11) Mutual exclusion primitives
#include <semaphore> // (C++20) Semaphores
#include <shared_mutex> // (C++14) Shared mutual exclusion primitives
#include <stop_token> // (C++20) Stop tokens for std::jthread
#include <thread> // (C++11) std::thread class and supporting functions

using namespace std;

int main(){

    cout << "Hello cpp 23" << endl;

    return 0;
}
