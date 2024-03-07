#ifndef UTILS_H
#define UTILS_H

inline int coerceAtMost(const int value, const int limit) {
    return (limit < value) ? limit : value;
}

inline int coerceAtLeast(const int value, const int limit) {
    return (limit > value) ? limit : value;
}

#endif
