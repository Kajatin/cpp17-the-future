#include <chrono>
#include <iostream>

inline std::uint64_t hardware_timestamp() {
#if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
    std::cout << "hardware_timestamp: _MSC_VER" << std::endl;
    return __rdtsc();
#elif defined(__GNUC__) && (defined(__i386__) || FOLLY_X64)
    std::cout << "hardware_timestamp: __GNUC__" << std::endl;
    return __builtin_ia32_rdtsc();
#elif defined(__aarch64__)
    std::cout << "hardware_timestamp: __aarch64__" << std::endl;
    uint64_t cval;
    asm volatile("mrs %0, cntvct_el0"
                 : "=r"(cval));
    return cval;
#else
    // use steady_clock::now() as an approximation for the timestamp counter on
    // non-x86 systems
    std::cout << "hardware_timestamp: std::chrono::steady_clock::now()" << std::endl;
    return std::chrono::steady_clock::now().time_since_epoch().count();
#endif
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << hardware_timestamp() << std::endl;
    return 0;
}
