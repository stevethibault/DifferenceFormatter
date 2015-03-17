/* Namespace for Google classes */
#define GOOGLE_NAMESPACE ::ctemplate

/* the location of <unordered_map> or <hash_map> */
#define HASH_MAP_H <unordered_map>

/* the namespace of hash_map/hash_set */
#define HASH_NAMESPACE std

/* the location of <unordered_set> or <hash_set> */
#define HASH_SET_H  <unordered_set>

/* define if the compiler has hash_map */
#define HAVE_HASH_MAP  1

/* define if the compiler has hash_set */
#define HAVE_HASH_SET  1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H  1

/* define if the compiler implements namespaces */
#define HAVE_NAMESPACES  1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H  1

/* Define to 1 if you have the <stdlib.h> header file. */
/* #undef HAVE_STDLIB */

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H  1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H  1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H  1

/* Define to 1 if the system has the type `uint32_t'. */
#define HAVE_UINT32_T 1

/* Define to 1 if the system has the type `uint64_t'. */
/* #undef HAVE_UINT64_T */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* define if the compiler supports unordered_{map,set} */
#define HAVE_UNORDERED_MAP

/* Define to 1 if the system has the type `__uint32. */
#define HAVE___INT32  1

/* Define to 1 if the system has the type `__uint64. */
#define HAVE___INT64 1

/* The namespace to put the htmlparser code. */
#define HTMLPARSER_NAMESPACE  google_ctemplate_streamhtmlparser

/* Define to the full name and version of this package. */
#define PACKAGE_STRING  "ctemplate 1.1"

/* printf format code for printing a size_t and ssize_t */
#define PRIdS  "Id"

/* printf format code for printing a size_t and ssize_t */
#define PRIuS  "Iu"

/* printf format code for printing a size_t and ssize_t */
#define PRIxS  "Ix"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS  1

/* the namespace where STL code like vector<> is defined */
#define STL_NAMESPACE  std

/* Stops putting the code inside the Google namespace */
#define _END_GOOGLE_NAMESPACE_ } // namespace ctemplate

/* Puts following code inside the Google namespace */
#define _START_GOOGLE_NAMESPACE_ namespace ctemplate {

#ifdef _WIN32
#include <windows/port.h>
#define CTEMPLATE_DLL_DECL
#endif
