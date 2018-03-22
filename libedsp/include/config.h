//
// Created by Mohammed Boujemaoui on 08/10/2017.
//

#ifndef EDSP_EDSP_H
#define EDSP_EDSP_H

#define EDSP_VERSION_MAJOR     0
#define EDSP_VERSION_MINOR     0
#define EDSP_VERSION_BUILD     0
#define EDSP_VERSION_LABEL     ""

#define EDSP_BEGIN_NAMESPACE  namespace edsp {
#define EDSP_END_NAMESPACE      }

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define EDSP_X64
#else
#define EDSP_X86
#endif
#endif

#if __GNUC__
#if __x86_64__ || __ppc64__
#define EDSP_X64
#else
#define EDSP_X86
#endif
#endif

#define EDSP_NOEXCEPT noexcept
#define EDSP_INLINE   inline


#define EDSP_EXPORT EXPORT
#define EDSP_UNUSED(x) (void)x;


#define EDSP_DISABLE_COPY(Class) \
    Class(const Class &) = delete; \
    Class &operator=(const Class &) = delete;

#define EDSP_DISABLE_DEFAULT(Class) \
    Class() = delete;

#define EDSP_DCL_TEMPLATE(X, Type) \
    template class X<Type>;

#endif //EDSP_EDSP_H
