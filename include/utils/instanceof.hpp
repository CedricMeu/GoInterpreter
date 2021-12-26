#ifndef GOINTERPRETER_UTILS_INSTANCEOF_HPP
#define GOINTERPRETER_UTILS_INSTANCEOF_HPP

template<typename Base, typename T>
inline bool instanceof(const T *test) {
    const Base *base = dynamic_cast<const Base *>(test);
    return base != nullptr;
}

#endif