
# 1 "/usr/include/stdio.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h"

# 1 "/usr/include/features.h"

# 1 "/usr/include/features-time64.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h"

# 1 "/usr/include/stdc-predef.h"

# 1 "/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc_headers/platform_fix/linux_glibc/sys/cdefs.h"

# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h"

# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h"

# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h"

# 14 "/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc_headers/include/stddef.h"
typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef int wchar_t;
typedef struct {
 long long __ll;
 long double __ld;
} max_align_t;
# 4 "/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc_headers/include/stdarg.h"
typedef __builtin_va_list va_list;
# 25 "/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc_headers/include/stdarg.h"
typedef va_list __gnuc_va_list;
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h"

# 31 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/time64.h"

# 145 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h"

# 13 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h"
typedef struct
{
 int __count;
 union
 {
 unsigned int __wch;
 char __wchb[4];
 } __value;
} __mbstate_t;
# 10 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h"
typedef struct _G_fpos_t
{
 __off_t __pos;
 __mbstate_t __state;
} __fpos_t;
# 10 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h"
typedef struct _G_fpos64_t
{
 __off64_t __pos;
 __mbstate_t __state;
} __fpos64_t;
# 4 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h"
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 4 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h"
struct _IO_FILE;


typedef struct _IO_FILE FILE;
# 35 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h"
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
 int _flags;


 char *_IO_read_ptr;
 char *_IO_read_end;
 char *_IO_read_base;
 char *_IO_write_base;
 char *_IO_write_ptr;
 char *_IO_write_end;
 char *_IO_buf_base;
 char *_IO_buf_end;


 char *_IO_save_base;
 char *_IO_backup_base;
 char *_IO_save_end;

 struct _IO_marker *_markers;

 struct _IO_FILE *_chain;

 int _fileno;
 int _flags2;
 __off_t _old_offset;


 unsigned short _cur_column;
 signed char _vtable_offset;
 char _shortbuf[1];

 _IO_lock_t *_lock;







 __off64_t _offset;

 struct _IO_codecvt *_codecvt;
 struct _IO_wide_data *_wide_data;
 struct _IO_FILE *_freeres_list;
 void *_freeres_buf;
 size_t __pad5;
 int _mode;

 char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
# 27 "/usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h"
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
 size_t __nbytes);







typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
 size_t __nbytes);







typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);


typedef int cookie_close_function_t (void *__cookie);






typedef struct _IO_cookie_io_functions_t
{
 cookie_read_function_t *read;
 cookie_write_function_t *write;
 cookie_seek_function_t *seek;
 cookie_close_function_t *close;
} cookie_io_functions_t;
# 64 "/usr/include/stdio.h"
typedef __off_t off_t;
# 78 "/usr/include/stdio.h"
typedef __ssize_t ssize_t;






typedef __fpos_t fpos_t;
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h"

# 149 "/usr/include/stdio.h"
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) ;

extern int rename (const char *__old, const char *__new) ;



extern int renameat (int __oldfd, const char *__old, int __newfd,
 const char *__new) ;
# 184 "/usr/include/stdio.h"
extern int fclose (FILE *__stream) ;
# 194 "/usr/include/stdio.h"
extern FILE *tmpfile (void)
 ;
# 211 "/usr/include/stdio.h"
extern char *tmpnam (char[20]) ;




extern char *tmpnam_r (char __s[20]) ;
# 228 "/usr/include/stdio.h"
extern char *tempnam (const char *__dir, const char *__pfx)
 ;






extern int fflush (FILE *__stream);








extern int fflush_unlocked (FILE *__stream);
# 264 "/usr/include/stdio.h"
extern FILE *fopen (const char *restrict __filename,
 const char *restrict __modes)
 ;




extern FILE *freopen (const char *restrict __filename,
 const char *restrict __modes,
 FILE *restrict __stream) ;
# 299 "/usr/include/stdio.h"
extern FILE *fdopen (int __fd, const char *__modes)
 ;





extern FILE *fopencookie (void *restrict __magic_cookie,
 const char *restrict __modes,
 cookie_io_functions_t __io_funcs)
 ;




extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
 ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc)
 ;
# 334 "/usr/include/stdio.h"
extern void setbuf (FILE *restrict __stream, char *restrict __buf)
 ;



extern int setvbuf (FILE *restrict __stream, char *restrict __buf,
 int __modes, size_t __n) ;




extern void setbuffer (FILE *restrict __stream, char *restrict __buf,
 size_t __size) ;


extern void setlinebuf (FILE *__stream) ;







extern int fprintf (FILE *restrict __stream,
 const char *restrict __format, ...) ;




extern int printf (const char *restrict __format, ...);

extern int sprintf (char *restrict __s,
 const char *restrict __format, ...) ;





extern int vfprintf (FILE *restrict __s, const char *restrict __format,
 __gnuc_va_list __arg) ;




extern int vprintf (const char *restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *restrict __s, const char *restrict __format,
 __gnuc_va_list __arg) ;



extern int snprintf (char *restrict __s, size_t __maxlen,
 const char *restrict __format, ...)
 __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *restrict __s, size_t __maxlen,
 const char *restrict __format, __gnuc_va_list __arg)
 __attribute__ ((__format__ (__printf__, 3, 0)));





extern int vasprintf (char **restrict __ptr, const char *restrict __f,
 __gnuc_va_list __arg)
 __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **restrict __ptr,
 const char *restrict __fmt, ...)
 __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **restrict __ptr,
 const char *restrict __fmt, ...)
 __attribute__ ((__format__ (__printf__, 2, 3))) ;




extern int vdprintf (int __fd, const char *restrict __fmt,
 __gnuc_va_list __arg)
 __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *restrict __fmt, ...)
 __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *restrict __stream,
 const char *restrict __format, ...) ;




extern int scanf (const char *restrict __format, ...) ;

extern int sscanf (const char *restrict __s,
 const char *restrict __format, ...) ;
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h"

# 214 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h"
typedef float _Float32;
# 251 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h"
typedef double _Float64;
# 268 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h"
typedef double _Float32x;
# 285 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h"
typedef long double _Float64x;
# 463 "/usr/include/stdio.h"
extern int fscanf (FILE *restrict __stream, const char *restrict __format, ...) __asm__("__isoc99_fscanf")

 ;
extern int scanf (const char *restrict __format, ...) __asm__("__isoc99_scanf")
 ;
extern int sscanf (const char *restrict __s, const char *restrict __format, ...) __asm__("__isoc99_sscanf")

;
# 490 "/usr/include/stdio.h"
extern int vfscanf (FILE *restrict __s, const char *restrict __format,
 __gnuc_va_list __arg)
 __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *restrict __format, __gnuc_va_list __arg)
 __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *restrict __s,
 const char *restrict __format, __gnuc_va_list __arg)
 __attribute__ ((__format__ (__scanf__, 2, 0)));
# 540 "/usr/include/stdio.h"
extern int vfscanf (FILE *restrict __s, const char *restrict __format, __gnuc_va_list __arg) __asm__("__isoc99_vfscanf")



 __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *restrict __format, __gnuc_va_list __arg) __asm__("__isoc99_vscanf")

 __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *restrict __s, const char *restrict __format, __gnuc_va_list __arg) __asm__("__isoc99_vsscanf")



 __attribute__ ((__format__ (__scanf__, 2, 0)));
# 575 "/usr/include/stdio.h"
extern int fgetc (FILE *__stream) ;
extern int getc (FILE *__stream) ;





extern int getchar (void);






extern int getc_unlocked (FILE *__stream) ;
extern int getchar_unlocked (void);
# 600 "/usr/include/stdio.h"
extern int fgetc_unlocked (FILE *__stream) ;
# 611 "/usr/include/stdio.h"
extern int fputc (int __c, FILE *__stream) ;
extern int putc (int __c, FILE *__stream) ;





extern int putchar (int __c);








extern int fputc_unlocked (int __c, FILE *__stream) ;







extern int putc_unlocked (int __c, FILE *__stream) ;
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream) ;


extern int putw (int __w, FILE *__stream) ;







extern char *fgets (char *restrict __s, int __n, FILE *restrict __stream)
 ;
# 694 "/usr/include/stdio.h"
extern __ssize_t __getdelim (char **restrict __lineptr,
 size_t *restrict __n, int __delimiter,
 FILE *restrict __stream) ;
extern __ssize_t getdelim (char **restrict __lineptr,
 size_t *restrict __n, int __delimiter,
 FILE *restrict __stream) ;







extern __ssize_t getline (char **restrict __lineptr,
 size_t *restrict __n,
 FILE *restrict __stream) ;







extern int fputs (const char *restrict __s, FILE *restrict __stream)
 ;





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream) ;






extern size_t fread (void *restrict __ptr, size_t __size,
 size_t __n, FILE *restrict __stream)
 ;




extern size_t fwrite (const void *restrict __ptr, size_t __size,
 size_t __n, FILE *restrict __s) ;
# 766 "/usr/include/stdio.h"
extern size_t fread_unlocked (void *restrict __ptr, size_t __size,
 size_t __n, FILE *restrict __stream)
 ;
extern size_t fwrite_unlocked (const void *restrict __ptr, size_t __size,
 size_t __n, FILE *restrict __stream)
 ;







extern int fseek (FILE *__stream, long int __off, int __whence)
 ;




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream) ;
# 803 "/usr/include/stdio.h"
extern int fseeko (FILE *__stream, __off_t __off, int __whence)
 ;




extern __off_t ftello (FILE *__stream) ;
# 829 "/usr/include/stdio.h"
extern int fgetpos (FILE *restrict __stream, fpos_t *restrict __pos)
 ;




extern int fsetpos (FILE *__stream, const fpos_t *__pos) ;
# 860 "/usr/include/stdio.h"
extern void clearerr (FILE *__stream) ;

extern int feof (FILE *__stream) ;

extern int ferror (FILE *__stream) ;



extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;







extern void perror (const char *__s) ;




extern int fileno (FILE *__stream) ;




extern int fileno_unlocked (FILE *__stream) ;








extern int pclose (FILE *__stream) ;





extern FILE *popen (const char *__command, const char *__modes)
 ;






extern char *ctermid (char *__s)
 ;
# 941 "/usr/include/stdio.h"
extern void flockfile (FILE *__stream) ;



extern int ftrylockfile (FILE *__stream) ;


extern void funlockfile (FILE *__stream) ;
# 959 "/usr/include/stdio.h"
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 1 "/usr/include/stdlib.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h"

# 59 "/usr/include/stdlib.h"
typedef struct
 {
 int quot;
 int rem;
 } div_t;



typedef struct
 {
 long int quot;
 long int rem;
 } ldiv_t;





 typedef struct
 {
 long long int quot;
 long long int rem;
 } lldiv_t;
# 98 "/usr/include/stdlib.h"
extern size_t __ctype_get_mb_cur_max (void) ;



extern double atof (const char *__nptr)
 ;

extern int atoi (const char *__nptr)
 ;

extern long int atol (const char *__nptr)
 ;



 extern long long int atoll (const char *__nptr)
 ;



extern double strtod (const char *restrict __nptr,
 char **restrict __endptr)
 ;



extern float strtof (const char *restrict __nptr,
 char **restrict __endptr) ;

extern long double strtold (const char *restrict __nptr,
 char **restrict __endptr)
 ;
# 177 "/usr/include/stdlib.h"
extern long int strtol (const char *restrict __nptr,
 char **restrict __endptr, int __base)
 ;

extern unsigned long int strtoul (const char *restrict __nptr,
 char **restrict __endptr, int __base)
 ;




extern long long int strtoq (const char *restrict __nptr,
 char **restrict __endptr, int __base)
 ;


extern unsigned long long int strtouq (const char *restrict __nptr,
 char **restrict __endptr, int __base)
 ;





extern long long int strtoll (const char *restrict __nptr,
 char **restrict __endptr, int __base)
 ;


extern unsigned long long int strtoull (const char *restrict __nptr,
 char **restrict __endptr, int __base)
 ;
# 505 "/usr/include/stdlib.h"
extern char *l64a (long int __n) ;


extern long int a64l (const char *__s)
 ;
# 33 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;
# 59 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;
# 97 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __pid_t pid_t;





typedef __id_t id_t;
# 114 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h"
typedef __clock_t clock_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h"
typedef __clockid_t clockid_t;
# 10 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h"
typedef __time_t time_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h"
typedef __timer_t timer_t;
# 148 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h"
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 158 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;




typedef int register_t;
# 1 "/usr/include/endian.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/endianness.h"

# 33 "/usr/include/x86_64-linux-gnu/bits/byteswap.h"
static inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{



 return ((__uint16_t) ((((__bsx) >> 8) & 0xff) | (((__bsx) & 0xff) << 8)));

}






static inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{



 return ((((__bsx) & 0xff000000u) >> 24) | (((__bsx) & 0x00ff0000u) >> 8) | (((__bsx) & 0x0000ff00u) << 8) | (((__bsx) & 0x000000ffu) << 24));

}
# 69 "/usr/include/x86_64-linux-gnu/bits/byteswap.h"
 static inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{



 return ((((__bsx) & 0xff00000000000000ull) >> 56) | (((__bsx) & 0x00ff000000000000ull) >> 40) | (((__bsx) & 0x0000ff0000000000ull) >> 24) | (((__bsx) & 0x000000ff00000000ull) >> 8) | (((__bsx) & 0x00000000ff000000ull) << 8) | (((__bsx) & 0x0000000000ff0000ull) << 24) | (((__bsx) & 0x000000000000ff00ull) << 40) | (((__bsx) & 0x00000000000000ffull) << 56));

}
# 32 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h"
static inline __uint16_t
__uint16_identity (__uint16_t __x)
{
 return __x;
}

static inline __uint32_t
__uint32_identity (__uint32_t __x)
{
 return __x;
}

static inline __uint64_t
__uint64_identity (__uint64_t __x)
{
 return __x;
}
# 1 "/usr/include/x86_64-linux-gnu/sys/select.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/select.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h"

# 5 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h"
typedef struct
{
 unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h"
typedef __sigset_t sigset_t;
# 8 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h"
struct timeval
{




 __time_t tv_sec;
 __suseconds_t tv_usec;

};
# 11 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h"
struct timespec
{



 __time_t tv_sec;




 __syscall_slong_t tv_nsec;
# 31 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h"
};
# 43 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 59 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef struct
 {






 __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


 } fd_set;






typedef __fd_mask fd_mask;
# 102 "/usr/include/x86_64-linux-gnu/sys/select.h"
extern int select (int __nfds, fd_set *restrict __readfds,
 fd_set *restrict __writefds,
 fd_set *restrict __exceptfds,
 struct timeval *restrict __timeout);
# 127 "/usr/include/x86_64-linux-gnu/sys/select.h"
extern int pselect (int __nfds, fd_set *restrict __readfds,
 fd_set *restrict __writefds,
 fd_set *restrict __exceptfds,
 const struct timespec *restrict __timeout,
 const __sigset_t *restrict __sigmask);
# 185 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h"

# 25 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h"
typedef union
{
 unsigned long long int __value64;
 struct
 {
 unsigned int __low;
 unsigned int __high;
 } __value32;
} __atomic_wide_counter;
# 51 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
typedef struct __pthread_internal_list
{
 struct __pthread_internal_list *__prev;
 struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
 struct __pthread_internal_slist *__next;
} __pthread_slist_t;
# 22 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h"
struct __pthread_mutex_s
{
 int __lock;
 unsigned int __count;
 int __owner;

 unsigned int __nusers;



 int __kind;

 short __spins;
 short __elision;
 __pthread_list_t __list;
# 53 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h"
};
# 23 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h"
struct __pthread_rwlock_arch_t
{
 unsigned int __readers;
 unsigned int __writers;
 unsigned int __wrphase_futex;
 unsigned int __writers_futex;
 unsigned int __pad3;
 unsigned int __pad4;

 int __cur_writer;
 int __shared;
 signed char __rwelision;




 unsigned char __pad1[7];


 unsigned long int __pad2;


 unsigned int __flags;
# 55 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h"
};
# 94 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
struct __pthread_cond_s
{
 __atomic_wide_counter __wseq;
 __atomic_wide_counter __g1_start;
 unsigned int __g_refs[2] ;
 unsigned int __g_size[2];
 unsigned int __g1_orig_size;
 unsigned int __wrefs;
 unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct
{
 int __data ;
} __once_flag;
# 27 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef unsigned long int pthread_t;




typedef union
{
 char __size[4];
 int __align;
} pthread_mutexattr_t;




typedef union
{
 char __size[4];
 int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
 char __size[56];
 long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
 struct __pthread_mutex_s __data;
 char __size[40];
 long int __align;
} pthread_mutex_t;


typedef union
{
 struct __pthread_cond_s __data;
 char __size[48];
 long long int __align;
} pthread_cond_t;





typedef union
{
 struct __pthread_rwlock_arch_t __data;
 char __size[56];
 long int __align;
} pthread_rwlock_t;

typedef union
{
 char __size[8];
 long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
 char __size[32];
 long int __align;
} pthread_barrier_t;

typedef union
{
 char __size[4];
 int __align;
} pthread_barrierattr_t;
# 521 "/usr/include/stdlib.h"
extern long int random (void) ;


extern void srandom (unsigned int __seed) ;





extern char *initstate (unsigned int __seed, char *__statebuf,
 size_t __statelen) ;



extern char *setstate (char *__statebuf) ;







struct random_data
 {
 int32_t *fptr;
 int32_t *rptr;
 int32_t *state;
 int rand_type;
 int rand_deg;
 int rand_sep;
 int32_t *end_ptr;
 };

extern int random_r (struct random_data *restrict __buf,
 int32_t *restrict __result) ;

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
 ;

extern int initstate_r (unsigned int __seed, char *restrict __statebuf,
 size_t __statelen,
 struct random_data *restrict __buf)
 ;

extern int setstate_r (char *restrict __statebuf,
 struct random_data *restrict __buf)
 ;





extern int rand (void) ;

extern void srand (unsigned int __seed) ;



extern int rand_r (unsigned int *__seed) ;







extern double drand48 (void) ;
extern double erand48 (unsigned short int __xsubi[3]) ;


extern long int lrand48 (void) ;
extern long int nrand48 (unsigned short int __xsubi[3])
 ;


extern long int mrand48 (void) ;
extern long int jrand48 (unsigned short int __xsubi[3])
 ;


extern void srand48 (long int __seedval) ;
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
 ;
extern void lcong48 (unsigned short int __param[7]) ;





struct drand48_data
 {
 unsigned short int __x[3];
 unsigned short int __old_x[3];
 unsigned short int __c;
 unsigned short int __init;
 unsigned long long int __a;

 };


extern int drand48_r (struct drand48_data *restrict __buffer,
 double *restrict __result) ;
extern int erand48_r (unsigned short int __xsubi[3],
 struct drand48_data *restrict __buffer,
 double *restrict __result) ;


extern int lrand48_r (struct drand48_data *restrict __buffer,
 long int *restrict __result)
 ;
extern int nrand48_r (unsigned short int __xsubi[3],
 struct drand48_data *restrict __buffer,
 long int *restrict __result)
 ;


extern int mrand48_r (struct drand48_data *restrict __buffer,
 long int *restrict __result)
 ;
extern int jrand48_r (unsigned short int __xsubi[3],
 struct drand48_data *restrict __buffer,
 long int *restrict __result)
 ;


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
 ;

extern int seed48_r (unsigned short int __seed16v[3],
 struct drand48_data *__buffer) ;

extern int lcong48_r (unsigned short int __param[7],
 struct drand48_data *__buffer)
 ;


extern __uint32_t arc4random (void)
 ;


extern void arc4random_buf (void *__buf, size_t __size)
 ;



extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
 ;




extern void *malloc (size_t __size)
 ;

extern void *calloc (size_t __nmemb, size_t __size)
 ;






extern void *realloc (void *__ptr, size_t __size)
 ;


extern void free (void *__ptr) ;







extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)


 ;


extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
 ;
# 7 "/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc_headers/include/alloca.h"
extern void *alloca (size_t);
# 712 "/usr/include/stdlib.h"
extern void *valloc (size_t __size)
 ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
 ;




extern void *aligned_alloc (size_t __alignment, size_t __size)

 ;



extern void abort (void) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) ;







extern int at_quick_exit (void (*__func) (void)) ;






extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
 ;





extern void exit (int __status) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__noreturn__));





extern void _Exit (int __status) __attribute__ ((__noreturn__));




extern char *getenv (const char *__name) ;
# 786 "/usr/include/stdlib.h"
extern int putenv (char *__string) ;





extern int setenv (const char *__name, const char *__value, int __replace)
 ;


extern int unsetenv (const char *__name) ;






extern int clearenv (void) ;
# 814 "/usr/include/stdlib.h"
extern char *mktemp (char *__template) ;
# 827 "/usr/include/stdlib.h"
extern int mkstemp (char *__template) ;
# 849 "/usr/include/stdlib.h"
extern int mkstemps (char *__template, int __suffixlen) ;
# 870 "/usr/include/stdlib.h"
extern char *mkdtemp (char *__template) ;
# 923 "/usr/include/stdlib.h"
extern int system (const char *__command) ;
# 940 "/usr/include/stdlib.h"
extern char *realpath (const char *restrict __name,
 char *restrict __resolved) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 960 "/usr/include/stdlib.h"
extern void *bsearch (const void *__key, const void *__base,
 size_t __nmemb, size_t __size, __compar_fn_t __compar)
 ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
 __compar_fn_t __compar) ;








extern int abs (int __x) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__const__)) ;


 extern long long int llabs (long long int __x)
 __attribute__ ((__const__)) ;






extern div_t div (int __numer, int __denom)
 __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
 __attribute__ ((__const__)) ;


 extern lldiv_t lldiv (long long int __numer,
 long long int __denom)
 __attribute__ ((__const__)) ;
# 1012 "/usr/include/stdlib.h"
extern char *ecvt (double __value, int __ndigit, int *restrict __decpt,
 int *restrict __sign) ;




extern char *fcvt (double __value, int __ndigit, int *restrict __decpt,
 int *restrict __sign) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
 ;




extern char *qecvt (long double __value, int __ndigit,
 int *restrict __decpt, int *restrict __sign)
 ;
extern char *qfcvt (long double __value, int __ndigit,
 int *restrict __decpt, int *restrict __sign)
 ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
 ;




extern int ecvt_r (double __value, int __ndigit, int *restrict __decpt,
 int *restrict __sign, char *restrict __buf,
 size_t __len) ;
extern int fcvt_r (double __value, int __ndigit, int *restrict __decpt,
 int *restrict __sign, char *restrict __buf,
 size_t __len) ;

extern int qecvt_r (long double __value, int __ndigit,
 int *restrict __decpt, int *restrict __sign,
 char *restrict __buf, size_t __len)
 ;
extern int qfcvt_r (long double __value, int __ndigit,
 int *restrict __decpt, int *restrict __sign,
 char *restrict __buf, size_t __len)
 ;





extern int mblen (const char *__s, size_t __n) ;


extern int mbtowc (wchar_t *restrict __pwc,
 const char *restrict __s, size_t __n) ;


extern int wctomb (char *__s, wchar_t __wchar) ;



extern size_t mbstowcs (wchar_t *restrict __pwcs,
 const char *restrict __s, size_t __n)
 ;

extern size_t wcstombs (char *restrict __s,
 const wchar_t *restrict __pwcs, size_t __n)


 ;






extern int rpmatch (const char *__response) ;
# 1099 "/usr/include/stdlib.h"
extern int getsubopt (char **restrict __optionp,
 char *const *restrict __tokens,
 char **restrict __valuep)
 ;
# 1145 "/usr/include/stdlib.h"
extern int getloadavg (double __loadavg[], int __nelem)
 ;
# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h"

# 1 "/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc_headers/platform_fix/linux_glibc/string.h"

# 1 "/usr/include/string.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h"

# 43 "/usr/include/string.h"
extern void *memcpy (void *restrict __dest, const void *restrict __src,
 size_t __n) ;


extern void *memmove (void *__dest, const void *__src, size_t __n)
 ;





extern void *memccpy (void *restrict __dest, const void *restrict __src,
 int __c, size_t __n)
 ;




extern void *memset (void *__s, int __c, size_t __n) ;


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
 ;
# 80 "/usr/include/string.h"
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
 ;
# 107 "/usr/include/string.h"
extern void *memchr (const void *__s, int __c, size_t __n)
 ;
# 141 "/usr/include/string.h"
extern char *strcpy (char *restrict __dest, const char *restrict __src)
 ;

extern char *strncpy (char *restrict __dest,
 const char *restrict __src, size_t __n)
 ;


extern char *strcat (char *restrict __dest, const char *restrict __src)
 ;

extern char *strncat (char *restrict __dest, const char *restrict __src,
 size_t __n) ;


extern int strcmp (const char *__s1, const char *__s2)
 ;

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
 ;


extern int strcoll (const char *__s1, const char *__s2)
 ;

extern size_t strxfrm (char *restrict __dest,
 const char *restrict __src, size_t __n)
 ;
# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h"

# 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h"
struct __locale_struct
{

 struct __locale_data *__locales[13];


 const unsigned short int *__ctype_b;
 const int *__ctype_tolower;
 const int *__ctype_toupper;


 const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 24 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h"
typedef __locale_t locale_t;
# 175 "/usr/include/string.h"
extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
 ;


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
 locale_t __l)
 ;





extern char *strdup (const char *__s)
 ;






extern char *strndup (const char *__string, size_t __n)
 ;
# 246 "/usr/include/string.h"
extern char *strchr (const char *__s, int __c)
 ;
# 273 "/usr/include/string.h"
extern char *strrchr (const char *__s, int __c)
 ;
# 286 "/usr/include/string.h"
extern char *strchrnul (const char *__s, int __c)
 ;





extern size_t strcspn (const char *__s, const char *__reject)
 ;


extern size_t strspn (const char *__s, const char *__accept)
 ;
# 323 "/usr/include/string.h"
extern char *strpbrk (const char *__s, const char *__accept)
 ;
# 350 "/usr/include/string.h"
extern char *strstr (const char *__haystack, const char *__needle)
 ;




extern char *strtok (char *restrict __s, const char *restrict __delim)
 ;



extern char *__strtok_r (char *restrict __s,
 const char *restrict __delim,
 char **restrict __save_ptr)
 ;

extern char *strtok_r (char *restrict __s, const char *restrict __delim,
 char **restrict __save_ptr)
 ;
# 380 "/usr/include/string.h"
extern char *strcasestr (const char *__haystack, const char *__needle)
 ;







extern void *memmem (const void *__haystack, size_t __haystacklen,
 const void *__needle, size_t __needlelen)


 ;



extern void *__mempcpy (void *restrict __dest,
 const void *restrict __src, size_t __n)
 ;
extern void *mempcpy (void *restrict __dest,
 const void *restrict __src, size_t __n)
 ;




extern size_t strlen (const char *__s)
 ;




extern size_t strnlen (const char *__string, size_t __maxlen)
 ;




extern char *strerror (int __errnum) ;
# 432 "/usr/include/string.h"
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__("__xpg_strerror_r")


 ;
# 458 "/usr/include/string.h"
extern char *strerror_l (int __errnum, locale_t __l) ;
# 34 "/usr/include/strings.h"
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
 ;


extern void bcopy (const void *__src, void *__dest, size_t __n)
 ;


extern void bzero (void *__s, size_t __n) ;
# 68 "/usr/include/strings.h"
extern char *index (const char *__s, int __c)
 ;
# 96 "/usr/include/strings.h"
extern char *rindex (const char *__s, int __c)
 ;






extern int ffs (int __i) ;





extern int ffsl (long int __l) ;
 extern int ffsll (long long int __ll)
 ;



extern int strcasecmp (const char *__s1, const char *__s2)
 ;


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
 ;






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
 ;



extern int strncasecmp_l (const char *__s1, const char *__s2,
 size_t __n, locale_t __loc)
 ;
# 466 "/usr/include/string.h"
extern void explicit_bzero (void *__s, size_t __n)
 ;



extern char *strsep (char **restrict __stringp,
 const char *restrict __delim)
 ;




extern char *strsignal (int __sig) ;
# 489 "/usr/include/string.h"
extern char *__stpcpy (char *restrict __dest, const char *restrict __src)
 ;
extern char *stpcpy (char *restrict __dest, const char *restrict __src)
 ;



extern char *__stpncpy (char *restrict __dest,
 const char *restrict __src, size_t __n)
 ;
extern char *stpncpy (char *restrict __dest,
 const char *restrict __src, size_t __n)
 ;




extern size_t strlcpy (char *restrict __dest,
 const char *restrict __src, size_t __n)
 ;



extern size_t strlcat (char *restrict __dest,
 const char *restrict __src, size_t __n)
 ;
# 1 "/usr/include/time.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/time.h"

# 7 "/usr/include/x86_64-linux-gnu/bits/types/struct_tm.h"
struct tm
{
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;


 long int tm_gmtoff;
 const char *tm_zone;




};
# 8 "/usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h"
struct itimerspec
 {
 struct timespec it_interval;
 struct timespec it_value;
 };
# 49 "/usr/include/time.h"
struct sigevent;
# 72 "/usr/include/time.h"
extern clock_t clock (void) ;



extern time_t time (time_t *__timer) ;


extern double difftime (time_t __time1, time_t __time0)
 __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) ;
# 100 "/usr/include/time.h"
extern size_t strftime (char *restrict __s, size_t __maxsize,
 const char *restrict __format,
 const struct tm *restrict __tp)
 ;
# 117 "/usr/include/time.h"
extern size_t strftime_l (char *restrict __s, size_t __maxsize,
 const char *restrict __format,
 const struct tm *restrict __tp,
 locale_t __loc) ;
# 133 "/usr/include/time.h"
extern struct tm *gmtime (const time_t *__timer) ;



extern struct tm *localtime (const time_t *__timer) ;
# 155 "/usr/include/time.h"
extern struct tm *gmtime_r (const time_t *restrict __timer,
 struct tm *restrict __tp) ;



extern struct tm *localtime_r (const time_t *restrict __timer,
 struct tm *restrict __tp) ;
# 180 "/usr/include/time.h"
extern char *asctime (const struct tm *__tp) ;



extern char *ctime (const time_t *__timer) ;
# 198 "/usr/include/time.h"
extern char *asctime_r (const struct tm *restrict __tp,
 char *restrict __buf) ;



extern char *ctime_r (const time_t *restrict __timer,
 char *restrict __buf) ;
# 218 "/usr/include/time.h"
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) ;



extern int daylight;
extern long int timezone;
# 247 "/usr/include/time.h"
extern time_t timegm (struct tm *__tp) ;
# 264 "/usr/include/time.h"
extern time_t timelocal (struct tm *__tp) ;







extern int dysize (int __year) __attribute__ ((__const__));
# 282 "/usr/include/time.h"
extern int nanosleep (const struct timespec *__requested_time,
 struct timespec *__remaining);


extern int clock_getres (clockid_t __clock_id, struct timespec *__res) ;


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp)
 ;


extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
 ;
# 324 "/usr/include/time.h"
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
 const struct timespec *__req,
 struct timespec *__rem);
# 339 "/usr/include/time.h"
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) ;




extern int timer_create (clockid_t __clock_id,
 struct sigevent *restrict __evp,
 timer_t *restrict __timerid) ;


extern int timer_delete (timer_t __timerid) ;



extern int timer_settime (timer_t __timerid, int __flags,
 const struct itimerspec *restrict __value,
 struct itimerspec *restrict __ovalue) ;


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
 ;
# 377 "/usr/include/time.h"
extern int timer_getoverrun (timer_t __timerid) ;






extern int timespec_get (struct timespec *__ts, int __base)
 ;
# 1 "./../cgs.h"

# 1 "/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc_headers/include/stdbool.h"

# 1 "/usr/include/limits.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/local_lim.h"

# 1 "/usr/include/linux/limits.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h"

# 1 "/usr/include/x86_64-linux-gnu/bits/posix2_lim.h"

# 147 "./../cgs.h"
typedef struct CGS__INCOMPAT {char c;} CGS__INCOMPAT;

struct CGS_Allocator;

typedef struct CGS_Allocation
{
 void *ptr;
 size_t n;
} CGS_Allocation;

typedef CGS_Allocation(*cgs_alloc_func) (struct CGS_Allocator*, size_t alignment, size_t n);
typedef void (*cgs_dealloc_func)(struct CGS_Allocator*, void *ptr, size_t n);
typedef CGS_Allocation(*cgs_realloc_func)(struct CGS_Allocator*, void *ptr, size_t alignment, size_t old_size, size_t new_size);

typedef struct CGS_Allocator
{
 cgs_alloc_func alloc;
 cgs_dealloc_func dealloc;
 cgs_realloc_func realloc;
} CGS_Allocator;

typedef struct CGS_Buffer
{
 char *ptr;
 unsigned int cap;
} CGS_Buffer;

 CGS_Allocation cgs__allocator_invoke_alloc(CGS_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb);
 void cgs__allocator_invoke_dealloc(CGS_Allocator *allocator, void *ptr, size_t obj_size, size_t nb);
 CGS_Allocation cgs__allocator_invoke_realloc(CGS_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb);

 CGS_Allocator *cgs_get_default_allocator();
# 199 "./../cgs.h"
typedef struct CGS_DStr
{
 char *chars;
 CGS_Allocator *allocator;
 unsigned int cap;
 unsigned int len;
} CGS_DStr;


typedef struct CGS_StrBuf
{
 char *chars;
 unsigned int cap;
 unsigned int len;
} CGS_StrBuf;


typedef struct CGS_StrView
{
 const char *chars;
 unsigned int len;
} CGS_StrView;

typedef struct CGS_ZStrView
{
 const char *chars;
 unsigned int len;
} CGS_ZStrView;


typedef struct CGS_StrViewArray
{
 CGS_StrView *strs;
 unsigned int cap;
 unsigned int len;
} CGS_StrViewArray;

enum CGS__MutStrType
{
 CGS__DSTR_TY = 0,
 CGS__STRBUF_TY,
 CGS__BUF_TY
};

typedef struct CGS_MutStrRef
{
 unsigned char ty;
 union
 {
 CGS_Buffer buf;
 CGS_DStr *dstr;
 CGS_StrBuf *strbuf;
 } str;
} CGS_MutStrRef;
# 270 "./../cgs.h"
enum CGS__ErrorCode
{


 CGS_OK, CGS_DST_TOO_SMALL, CGS_ALLOC_ERROR, CGS_INDEX_OUT_OF_BOUNDS, CGS_BAD_RANGE, CGS_NOT_FOUND, CGS_ALIASING_NOT_SUPPORTED, CGS_ENCODING_ERROR, CGS_IO_ERROR, CGS_CALLBACK_EXIT, CGS_TOO_MANY_ARGS, CGS_NOT_ENOUGH_ARGS, CGS_BAD_FORMAT, CGS_TYPE_MISMATCH,


};

typedef struct CGS_Error
{
 unsigned char ec;
} CGS_Error;

typedef struct CGS_Writer
{
 CGS_Error (* const write)(struct CGS_Writer *dst, CGS_StrView str);
} CGS_Writer;

typedef struct CGS_FileWriter
{
 CGS_Writer base;
 FILE *file;
} CGS_FileWriter;

typedef struct CGS_LenWriter
{
 CGS_Writer base;
 unsigned int len;
} CGS_LenWriter;

typedef struct CGS_LenPtrWriter
{
 CGS_Writer base;
 unsigned int *len;
} CGS_LenPtrWriter;

typedef struct CGS_DStrWriter
{
 CGS_Writer base;
 CGS_DStr *dstr;
} CGS_DStrWriter;

typedef struct CGS_StrBufWriter
{
 CGS_Writer base;
 CGS_StrBuf *strbuf;
} CGS_StrBufWriter;

typedef struct CGS_CStrWriter
{
 CGS_Writer base;
 CGS_Buffer buf;
} CGS_CStrWriter;

typedef struct CGS_MutStrRefWriter
{
 CGS_Writer base;
 void *any;
 unsigned int cap_opt;
} CGS_MutStrRefWriter;

typedef struct CGS_ChainWriter
{
 CGS_Writer base;
 CGS_Writer *a;
 CGS_Writer *b;
} CGS_ChainWriter;

typedef struct CGS_CustomWriter
{
 CGS_Writer base;
 void *ctx;
} CGS_CustomWriter;

typedef struct CGS__FixedMutStrRef
{
 char *chars;
 unsigned int *len;
 unsigned int cap;
} CGS__FixedMutStrRef;

typedef struct CGS_ArrayFmt
{
 void *array;
 size_t nb;
 size_t elm_size;

 CGS_Error(*elm_tostr)(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);

 CGS_StrView open;
 CGS_StrView close;
 CGS_StrView separator;
 CGS_StrView trailing_separator;
} CGS_ArrayFmt;

typedef enum CGS__AlignModeEnum
{
 CGS__ALIGNMODE_CENTER,
 CGS__ALIGNMODE_LEFT,
 CGS__ALIGNMODE_RIGHT
} CGS__AlignModeEnum;

typedef struct CGS__AlignModeStruct
{
 unsigned char align_mode;
} CGS__AlignModeStruct;
# 390 "./../cgs.h"
typedef struct CGS__AlignFmt
{
 const void *obj;
 CGS_Error(*tostr_p)(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 unsigned int width;
 CGS__AlignModeStruct align_mode;
 char fill_char;
} CGS__AlignFmt;

typedef struct CGS__RepeatFmt
{
 const void *obj;
 CGS_Error(*tostr_p)(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 unsigned int n;
} CGS__RepeatFmt;

typedef struct CGS__DStrAppendAllocator
{
 CGS_Allocator base;
 struct CGS_DStr *owner;
} CGS__DStrAppendAllocator;

typedef struct CGS_AppenderState
{
 CGS_DStr appender_dstr;
 CGS__DStrAppendAllocator dstr_append_allocator;
 CGS_StrBuf appender_buf;
} CGS_AppenderState;







typedef struct CGS__Result_int { int val; CGS_Error err; } CGS__Result_int;
typedef struct CGS__Result_CGS_StrView { CGS_StrView val; CGS_Error err; } CGS__Result_CGS_StrView;
# 1020 "./../cgs.h"
typedef char cgs__c;
typedef signed char cgs__sc;
typedef unsigned char cgs__uc;
typedef short cgs__s;
typedef unsigned short cgs__us;
typedef int cgs__i;
typedef unsigned int cgs__ui;
typedef long cgs__l;
typedef unsigned long cgs__ul;
typedef long long cgs__ll;
typedef unsigned long long cgs__ull;
# 1073 "./../cgs.h"
typedef struct CGS__Integer_d_Fmt_cgs__c { cgs__c obj; } CGS__Integer_d_Fmt_cgs__c; typedef struct CGS__Integer_x_Fmt_cgs__c { cgs__c obj; } CGS__Integer_x_Fmt_cgs__c; typedef struct CGS__Integer_o_Fmt_cgs__c { cgs__c obj; } CGS__Integer_o_Fmt_cgs__c; typedef struct CGS__Integer_b_Fmt_cgs__c { cgs__c obj; } CGS__Integer_b_Fmt_cgs__c; typedef struct CGS__Integer_X_Fmt_cgs__c { cgs__c obj; } CGS__Integer_X_Fmt_cgs__c; typedef struct CGS__Integer_d_Fmt_cgs__sc { cgs__sc obj; } CGS__Integer_d_Fmt_cgs__sc; typedef struct CGS__Integer_x_Fmt_cgs__sc { cgs__sc obj; } CGS__Integer_x_Fmt_cgs__sc; typedef struct CGS__Integer_o_Fmt_cgs__sc { cgs__sc obj; } CGS__Integer_o_Fmt_cgs__sc; typedef struct CGS__Integer_b_Fmt_cgs__sc { cgs__sc obj; } CGS__Integer_b_Fmt_cgs__sc; typedef struct CGS__Integer_X_Fmt_cgs__sc { cgs__sc obj; } CGS__Integer_X_Fmt_cgs__sc; typedef struct CGS__Integer_d_Fmt_cgs__uc { cgs__uc obj; } CGS__Integer_d_Fmt_cgs__uc; typedef struct CGS__Integer_x_Fmt_cgs__uc { cgs__uc obj; } CGS__Integer_x_Fmt_cgs__uc; typedef struct CGS__Integer_o_Fmt_cgs__uc { cgs__uc obj; } CGS__Integer_o_Fmt_cgs__uc; typedef struct CGS__Integer_b_Fmt_cgs__uc { cgs__uc obj; } CGS__Integer_b_Fmt_cgs__uc; typedef struct CGS__Integer_X_Fmt_cgs__uc { cgs__uc obj; } CGS__Integer_X_Fmt_cgs__uc; typedef struct CGS__Integer_d_Fmt_cgs__s { cgs__s obj; } CGS__Integer_d_Fmt_cgs__s; typedef struct CGS__Integer_x_Fmt_cgs__s { cgs__s obj; } CGS__Integer_x_Fmt_cgs__s; typedef struct CGS__Integer_o_Fmt_cgs__s { cgs__s obj; } CGS__Integer_o_Fmt_cgs__s; typedef struct CGS__Integer_b_Fmt_cgs__s { cgs__s obj; } CGS__Integer_b_Fmt_cgs__s; typedef struct CGS__Integer_X_Fmt_cgs__s { cgs__s obj; } CGS__Integer_X_Fmt_cgs__s; typedef struct CGS__Integer_d_Fmt_cgs__us { cgs__us obj; } CGS__Integer_d_Fmt_cgs__us; typedef struct CGS__Integer_x_Fmt_cgs__us { cgs__us obj; } CGS__Integer_x_Fmt_cgs__us; typedef struct CGS__Integer_o_Fmt_cgs__us { cgs__us obj; } CGS__Integer_o_Fmt_cgs__us; typedef struct CGS__Integer_b_Fmt_cgs__us { cgs__us obj; } CGS__Integer_b_Fmt_cgs__us; typedef struct CGS__Integer_X_Fmt_cgs__us { cgs__us obj; } CGS__Integer_X_Fmt_cgs__us; typedef struct CGS__Integer_d_Fmt_cgs__i { cgs__i obj; } CGS__Integer_d_Fmt_cgs__i; typedef struct CGS__Integer_x_Fmt_cgs__i { cgs__i obj; } CGS__Integer_x_Fmt_cgs__i; typedef struct CGS__Integer_o_Fmt_cgs__i { cgs__i obj; } CGS__Integer_o_Fmt_cgs__i; typedef struct CGS__Integer_b_Fmt_cgs__i { cgs__i obj; } CGS__Integer_b_Fmt_cgs__i; typedef struct CGS__Integer_X_Fmt_cgs__i { cgs__i obj; } CGS__Integer_X_Fmt_cgs__i; typedef struct CGS__Integer_d_Fmt_cgs__ui { cgs__ui obj; } CGS__Integer_d_Fmt_cgs__ui; typedef struct CGS__Integer_x_Fmt_cgs__ui { cgs__ui obj; } CGS__Integer_x_Fmt_cgs__ui; typedef struct CGS__Integer_o_Fmt_cgs__ui { cgs__ui obj; } CGS__Integer_o_Fmt_cgs__ui; typedef struct CGS__Integer_b_Fmt_cgs__ui { cgs__ui obj; } CGS__Integer_b_Fmt_cgs__ui; typedef struct CGS__Integer_X_Fmt_cgs__ui { cgs__ui obj; } CGS__Integer_X_Fmt_cgs__ui; typedef struct CGS__Integer_d_Fmt_cgs__l { cgs__l obj; } CGS__Integer_d_Fmt_cgs__l; typedef struct CGS__Integer_x_Fmt_cgs__l { cgs__l obj; } CGS__Integer_x_Fmt_cgs__l; typedef struct CGS__Integer_o_Fmt_cgs__l { cgs__l obj; } CGS__Integer_o_Fmt_cgs__l; typedef struct CGS__Integer_b_Fmt_cgs__l { cgs__l obj; } CGS__Integer_b_Fmt_cgs__l; typedef struct CGS__Integer_X_Fmt_cgs__l { cgs__l obj; } CGS__Integer_X_Fmt_cgs__l; typedef struct CGS__Integer_d_Fmt_cgs__ul { cgs__ul obj; } CGS__Integer_d_Fmt_cgs__ul; typedef struct CGS__Integer_x_Fmt_cgs__ul { cgs__ul obj; } CGS__Integer_x_Fmt_cgs__ul; typedef struct CGS__Integer_o_Fmt_cgs__ul { cgs__ul obj; } CGS__Integer_o_Fmt_cgs__ul; typedef struct CGS__Integer_b_Fmt_cgs__ul { cgs__ul obj; } CGS__Integer_b_Fmt_cgs__ul; typedef struct CGS__Integer_X_Fmt_cgs__ul { cgs__ul obj; } CGS__Integer_X_Fmt_cgs__ul; typedef struct CGS__Integer_d_Fmt_cgs__ll { cgs__ll obj; } CGS__Integer_d_Fmt_cgs__ll; typedef struct CGS__Integer_x_Fmt_cgs__ll { cgs__ll obj; } CGS__Integer_x_Fmt_cgs__ll; typedef struct CGS__Integer_o_Fmt_cgs__ll { cgs__ll obj; } CGS__Integer_o_Fmt_cgs__ll; typedef struct CGS__Integer_b_Fmt_cgs__ll { cgs__ll obj; } CGS__Integer_b_Fmt_cgs__ll; typedef struct CGS__Integer_X_Fmt_cgs__ll { cgs__ll obj; } CGS__Integer_X_Fmt_cgs__ll; typedef struct CGS__Integer_d_Fmt_cgs__ull { cgs__ull obj; } CGS__Integer_d_Fmt_cgs__ull; typedef struct CGS__Integer_x_Fmt_cgs__ull { cgs__ull obj; } CGS__Integer_x_Fmt_cgs__ull; typedef struct CGS__Integer_o_Fmt_cgs__ull { cgs__ull obj; } CGS__Integer_o_Fmt_cgs__ull; typedef struct CGS__Integer_b_Fmt_cgs__ull { cgs__ull obj; } CGS__Integer_b_Fmt_cgs__ull; typedef struct CGS__Integer_X_Fmt_cgs__ull { cgs__ull obj; } CGS__Integer_X_Fmt_cgs__ull;
# 1119 "./../cgs.h"
typedef struct CGS__Floating_f_Fmt_float { float obj; int precision; } CGS__Floating_f_Fmt_float; typedef struct CGS__Floating_g_Fmt_float { float obj; int precision; } CGS__Floating_g_Fmt_float; typedef struct CGS__Floating_e_Fmt_float { float obj; int precision; } CGS__Floating_e_Fmt_float; typedef struct CGS__Floating_a_Fmt_float { float obj; int precision; } CGS__Floating_a_Fmt_float; typedef struct CGS__Floating_F_Fmt_float { float obj; int precision; } CGS__Floating_F_Fmt_float; typedef struct CGS__Floating_G_Fmt_float { float obj; int precision; } CGS__Floating_G_Fmt_float; typedef struct CGS__Floating_E_Fmt_float { float obj; int precision; } CGS__Floating_E_Fmt_float; typedef struct CGS__Floating_A_Fmt_float { float obj; int precision; } CGS__Floating_A_Fmt_float; typedef struct CGS__Floating_f_Fmt_double { double obj; int precision; } CGS__Floating_f_Fmt_double; typedef struct CGS__Floating_g_Fmt_double { double obj; int precision; } CGS__Floating_g_Fmt_double; typedef struct CGS__Floating_e_Fmt_double { double obj; int precision; } CGS__Floating_e_Fmt_double; typedef struct CGS__Floating_a_Fmt_double { double obj; int precision; } CGS__Floating_a_Fmt_double; typedef struct CGS__Floating_F_Fmt_double { double obj; int precision; } CGS__Floating_F_Fmt_double; typedef struct CGS__Floating_G_Fmt_double { double obj; int precision; } CGS__Floating_G_Fmt_double; typedef struct CGS__Floating_E_Fmt_double { double obj; int precision; } CGS__Floating_E_Fmt_double; typedef struct CGS__Floating_A_Fmt_double { double obj; int precision; } CGS__Floating_A_Fmt_double;
# 1403 "./../cgs.h"
struct cgs__fail_type { int dummy; };
typedef void(*cgs__tostr_fail)(struct cgs__fail_type*);
# 1456 "./../cgs.h"
 CGS_StrView cgs__strv_cstr1(const char *str);
 CGS_StrView cgs__strv_ucstr1(const unsigned char *str);
 CGS_StrView cgs__strv_dstr1(CGS_DStr str);
 CGS_StrView cgs__strv_dstr_ptr1(const CGS_DStr *str);
 CGS_StrView cgs__strv_strv1(CGS_StrView str);
 CGS_StrView cgs__strv_zstrv1(CGS_ZStrView str);
 CGS_StrView cgs__strv_strbuf1(CGS_StrBuf str);
 CGS_StrView cgs__strv_strbuf_ptr1(const CGS_StrBuf *str);
 CGS_StrView cgs__strv_mutstr_ref1(CGS_MutStrRef str);

 CGS_StrView cgs__strv_cstr2(const char *str, unsigned int begin);
 CGS_StrView cgs__strv_ucstr2(const unsigned char *str, unsigned int begin);
 CGS_StrView cgs__strv_dstr2(CGS_DStr str, unsigned int begin);
 CGS_StrView cgs__strv_dstr_ptr2(const CGS_DStr *str, unsigned int begin);
 CGS_StrView cgs__strv_strv2(CGS_StrView str, unsigned int begin);
 CGS_StrView cgs__strv_zstrv2(CGS_ZStrView str, unsigned int begin);
 CGS_StrView cgs__strv_strbuf2(CGS_StrBuf str, unsigned int begin);
 CGS_StrView cgs__strv_strbuf_ptr2(const CGS_StrBuf *str, unsigned int begin);
 CGS_StrView cgs__strv_mutstr_ref2(CGS_MutStrRef str, unsigned int begin);

 CGS_StrView cgs__strv_cstr3(const char *str, unsigned int begin, unsigned int end);
 CGS_StrView cgs__strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end);
 CGS_StrView cgs__strv_dstr3(CGS_DStr str, unsigned int begin, unsigned int end);
 CGS_StrView cgs__strv_dstr_ptr3(const CGS_DStr *str, unsigned int begin, unsigned int end);
 CGS_StrView cgs__strv_strv3(CGS_StrView str, unsigned int begin, unsigned int end);
 CGS_StrView cgs__strv_zstrv3(CGS_ZStrView str, unsigned int begin, unsigned int end);
 CGS_StrView cgs__strv_strbuf3(CGS_StrBuf str, unsigned int begin, unsigned int end);
 CGS_StrView cgs__strv_strbuf_ptr3(const CGS_StrBuf *str, unsigned int begin, unsigned int end);
 CGS_StrView cgs__strv_mutstr_ref3(CGS_MutStrRef str, unsigned int begin, unsigned int end);

 CGS_ZStrView cgs__zstrv_cstr1(const char *str);
 CGS_ZStrView cgs__zstrv_ucstr1(const unsigned char *str);
 CGS_ZStrView cgs__zstrv_dstr1(CGS_DStr str);
 CGS_ZStrView cgs__zstrv_dstr_ptr1(const CGS_DStr *str);
 CGS_ZStrView cgs__zstrv_strv1(CGS_ZStrView str);
 CGS_ZStrView cgs__zstrv_strbuf1(CGS_StrBuf str);
 CGS_ZStrView cgs__zstrv_strbuf_ptr1(const CGS_StrBuf *str);
 CGS_ZStrView cgs__zstrv_mutstr_ref1(CGS_MutStrRef str);

 CGS_ZStrView cgs__zstrv_cstr2(const char *str, unsigned int begin);
 CGS_ZStrView cgs__zstrv_ucstr2(const unsigned char *str, unsigned int begin);
 CGS_ZStrView cgs__zstrv_dstr2(CGS_DStr str, unsigned int begin);
 CGS_ZStrView cgs__zstrv_dstr_ptr2(const CGS_DStr *str, unsigned int begin);
 CGS_ZStrView cgs__zstrv_strv2(CGS_ZStrView str, unsigned int begin);
 CGS_ZStrView cgs__zstrv_strbuf2(CGS_StrBuf str, unsigned int begin);
 CGS_ZStrView cgs__zstrv_strbuf_ptr2(const CGS_StrBuf *str, unsigned int begin);
 CGS_ZStrView cgs__zstrv_mutstr_ref2(CGS_MutStrRef str, unsigned int begin);

 CGS_StrBuf cgs__strbuf_from_cstr_cap(const char *ptr, unsigned int cap);
 CGS_StrBuf cgs__strbuf_from_cstr(const char *ptr);
 CGS_StrBuf cgs__strbuf_from_buf(CGS_Buffer buf);

 CGS_Buffer cgs__buf_from_cstr(const char *str);
 CGS_Buffer cgs__buf_from_ucstr(const unsigned char *str);
 CGS_Buffer cgs__buf_from_carr(const char *str, size_t cap);
 CGS_Buffer cgs__buf_from_ucarr(const unsigned char *str, size_t cap);

 CGS_MutStrRef cgs__cstr_as_mutstr_ref(const char *str);
 CGS_MutStrRef cgs__ucstr_as_mutstr_ref(const unsigned char *str);
 CGS_MutStrRef cgs__buf_as_mutstr_ref(CGS_Buffer str);
 CGS_MutStrRef cgs__dstr_ptr_as_mutstr_ref(const CGS_DStr *str);
 CGS_MutStrRef cgs__strbuf_ptr_as_mutstr_ref(const CGS_StrBuf *str);
 CGS_MutStrRef cgs__mutstr_ref_as_mutstr_ref(CGS_MutStrRef str);

 CGS__FixedMutStrRef cgs__buf_as_fmutstr_ref(CGS_Buffer buf, unsigned int *len_ptr);
 CGS__FixedMutStrRef cgs__buf_as_fmutstr_ref_zero_len(CGS_Buffer buf, unsigned int *len_ptr);
 CGS__FixedMutStrRef cgs__strbuf_ptr_as_fmutstr_ref(CGS_StrBuf *strbuf);
 CGS__FixedMutStrRef cgs__mutstr_ref_as_fmutstr_ref2(CGS_MutStrRef mutstr_ref, unsigned int *len_ptr);
 CGS__FixedMutStrRef cgs__mutstr_ref_as_fmutstr_ref_zero_len(CGS_MutStrRef mutstr_ref, unsigned int *len_ptr);
 CGS__FixedMutStrRef cgs__dstr_ptr_as_fmutstr_ref(CGS_DStr *dstr);

 CGS_MutStrRef cgs__make_appender_mutstr_ref(CGS_MutStrRef owner, CGS_AppenderState *state);
 CGS_Error cgs__mutstr_ref_commit_appender(CGS_MutStrRef owner, CGS_MutStrRef appender);

 char *cgs__cstr_as_cstr(const char *str);
 char *cgs__ucstr_as_cstr(const unsigned char *str);
 char *cgs__dstr_as_cstr(CGS_DStr str);
 char *cgs__dstr_ptr_as_cstr(const CGS_DStr *str);
 char *cgs__strv_as_cstr(CGS_StrView str);
 char *cgs__strbuf_as_cstr(CGS_StrBuf str);
 char *cgs__strbuf_ptr_as_cstr(const CGS_StrBuf *str);
 char *cgs__mutstr_ref_as_cstr(CGS_MutStrRef str);

 unsigned int cgs__strv_cap(CGS_StrView sv);
 unsigned int cgs__dstr_cap(CGS_DStr str);
 unsigned int cgs__dstr_ptr_cap(const CGS_DStr *str);
 unsigned int cgs__strbuf_cap(CGS_StrBuf str);
 unsigned int cgs__strbuf_ptr_cap(const CGS_StrBuf *str);
 unsigned int cgs__mutstr_ref_cap(CGS_MutStrRef str);
 unsigned int cgs__mutstr_ref_len(CGS_MutStrRef str);


 CGS_DStr cgs__dstr_init(unsigned int cap, CGS_Allocator *allocator);

 CGS_DStr cgs__dstr_init_from(CGS_StrView from, CGS_Allocator *allocator);
 void cgs__dstr_deinit(CGS_DStr *dstr);
 CGS_Error cgs__dstr_append(CGS_DStr *dstr, CGS_StrView src);
 CGS_Error cgs__dstr_prepend_strv(CGS_DStr *dstr, CGS_StrView src);
 CGS_Error cgs__dstr_insert(CGS_DStr *dstr, CGS_StrView src, unsigned int idx);
 CGS_Error cgs__dstr_fread_until(CGS_DStr *dstr, FILE *stream, int delim);
 CGS_Error cgs__dstr_append_fread_until(CGS_DStr *dstr, FILE *stream, int delim);
 CGS_Error cgs__dstr_shrink_to_fit(CGS_DStr *dstr);
 CGS_Error cgs__dstr_ensure_cap(CGS_DStr *dstr, unsigned int at_least);

 CGS_Error cgs__mutstr_ref_putc(CGS_MutStrRef dst, char c);
 CGS_Error cgs__mutstr_ref_copy(CGS_MutStrRef dst, CGS_StrView src);
 CGS_Error cgs__mutstr_ref_append(CGS_MutStrRef dst, CGS_StrView src);
 CGS_Error cgs__mutstr_ref_delete_range(CGS_MutStrRef str, unsigned int begin, unsigned int end);
 CGS_Error cgs__mutstr_ref_insert(CGS_MutStrRef dst, CGS_StrView src, unsigned int idx);
 CGS__Result_int cgs__mutstr_ref_replace(CGS_MutStrRef str, CGS_StrView target, CGS_StrView replacement);
 CGS_Error cgs__mutstr_ref_replace_first(CGS_MutStrRef str, CGS_StrView target, CGS_StrView replacement);
 CGS_Error cgs__mutstr_ref_replace_range(CGS_MutStrRef str, unsigned int begin, unsigned int end, CGS_StrView replacement);
 CGS_Error cgs__mutstr_ref_clear(CGS_MutStrRef str);
 CGS_Error cgs__strv_arr_join(CGS_MutStrRef dst, CGS_StrViewArray strs, CGS_StrView delim);
 CGS__Result_CGS_StrView cgs__next_tok(CGS_StrView *base, CGS_StrView delim);
 CGS__Result_CGS_StrView cgs__next_tok_any(CGS_StrView *base, CGS_StrView delim_set);
 CGS_StrView cgs__skip(CGS_StrView src, CGS_StrView delim);
 CGS_StrView cgs__skip_any(CGS_StrView src, CGS_StrView delim_set);

 CGS_Error cgs__fmutstr_ref_putc(CGS__FixedMutStrRef dst, char c);
 CGS_Error cgs__fmutstr_ref_copy(CGS__FixedMutStrRef dst, CGS_StrView src);
 CGS_Error cgs__fmutstr_ref_append(CGS__FixedMutStrRef dst, CGS_StrView src);
 CGS_Error cgs__fmutstr_ref_delete_range(CGS__FixedMutStrRef str, unsigned int begin, unsigned int end);
 CGS_Error cgs__fmutstr_ref_insert(CGS__FixedMutStrRef dst, CGS_StrView src, unsigned int idx);
 CGS__Result_int cgs__fmutstr_ref_replace(CGS__FixedMutStrRef str, CGS_StrView target, CGS_StrView replacement);
 CGS_Error cgs__fmutstr_ref_replace_first(CGS__FixedMutStrRef str, CGS_StrView target, CGS_StrView replacement);
 CGS_Error cgs__fmutstr_ref_replace_range(CGS__FixedMutStrRef str, unsigned int begin, unsigned int end, CGS_StrView replacement);
 CGS_Error cgs__fmutstr_ref_clear(CGS__FixedMutStrRef str);
 CGS_Error cgs__strv_arr_join_into_fmutstr_ref(CGS__FixedMutStrRef dst, CGS_StrViewArray strs, CGS_StrView delim);

 CGS_Error cgs__dstr_putc(CGS_DStr *dst, char c);
 CGS_Error cgs__dstr_copy(CGS_DStr *dstr, CGS_StrView src);
 CGS__Result_int cgs__dstr_replace(CGS_DStr *dstr, CGS_StrView target, CGS_StrView replacement);
 CGS_Error cgs__dstr_replace_first(CGS_DStr *dstr, CGS_StrView target, CGS_StrView replacement);
 CGS_Error cgs__dstr_replace_range(CGS_DStr *dstr, unsigned int begin, unsigned int end, CGS_StrView replacement);
 CGS_Error cgs__strv_arr_join_into_dstr(CGS_DStr *dstr, CGS_StrViewArray strs, CGS_StrView delim);


 CGS_StrViewArray cgs__strv_split(CGS_StrView str, CGS_StrView delim, CGS_Allocator* allocator);
 CGS_Error cgs__strv_split_iter(CGS_StrView str, CGS_StrView delim, _Bool(*cb)(CGS_StrView found, void *ctx), void *ctx);

 CGS_StrViewArray cgs__strv_arr_from(const CGS_StrView *carr, unsigned int nb);

 _Bool cgs__strv_equal(CGS_StrView str1, CGS_StrView str2);
 CGS_StrView cgs__strv_find(CGS_StrView hay, CGS_StrView needle);
 unsigned int cgs__strv_count(CGS_StrView hay, CGS_StrView needle);
 CGS_StrView cgs__trim_view(CGS_StrView str);
 CGS_Error cgs__trim(CGS__FixedMutStrRef str);
 CGS_StrView cgs__strv_cspn(CGS_StrView src, CGS_StrView charset);
 CGS_StrView cgs__strv_spn(CGS_StrView src, CGS_StrView charset);
 _Bool cgs__strv_starts_with(CGS_StrView hay, CGS_StrView needle);
 _Bool cgs__strv_ends_with(CGS_StrView hay, CGS_StrView needle);

 CGS_Error cgs__map_chars(CGS__FixedMutStrRef str, _Bool(*map)(char *c,void *arg), void *arg);
 void cgs__chars_tolower(CGS__FixedMutStrRef str);
 void cgs__chars_toupper(CGS__FixedMutStrRef str);

 CGS_Error cgs__mutstr_ref_fread_until(CGS_MutStrRef dst, FILE *stream, int delim);
 CGS_Error cgs__mutstr_ref_append_fread_until(CGS_MutStrRef dst, FILE *stream, int delim);

 CGS_Error cgs__fmutstr_ref_fread_until(CGS__FixedMutStrRef dst, FILE *stream, int delim);
 CGS_Error cgs__fmutstr_ref_append_fread_until(CGS__FixedMutStrRef dst, FILE *stream, int delim);

 unsigned int cgs__fprint_strv(FILE *stream, CGS_StrView str);
 unsigned int cgs__fprintln_strv(FILE *stream, CGS_StrView str);

 CGS_Error cgs__append_fmt(CGS_Writer *dst, CGS_ZStrView fmt, unsigned int nargs, void **objs, CGS_Error(*tostr_p_funcs[])(CGS_Writer*, const void*, CGS_StrView));
 CGS_Error cgs__appendln_fmt_(CGS_Writer *dst, CGS_ZStrView fmt, unsigned int nargs, void **objs, CGS_Error(*tostr_p_funcs[])(CGS_Writer*, const void*, CGS_StrView));
 CGS_DStr cgs__asprintf(CGS_Writer *dst, CGS_ZStrView fmt, unsigned int nargs, void **objs, CGS_Error(*tostr_p_funcs[])(CGS_Writer*, const void*, CGS_StrView));
 CGS_DStr cgs__asprintf_with_allocator(CGS_Writer *dst, CGS_ZStrView fmt, unsigned int nargs, void **objs, CGS_Error(*tostr_p_funcs[])(CGS_Writer*, const void*, CGS_StrView));

 CGS_MutStrRefWriter cgs__mutstr_ref_to_writer(CGS_MutStrRef ref);


 CGS_Error cgs__bool_tostr (CGS_Writer *dst, _Bool obj, CGS_StrView fmt_arg);
 CGS_Error cgs__cstr_tostr (CGS_Writer *dst, const char *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__ucstr_tostr (CGS_Writer *dst, const unsigned char *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__char_tostr (CGS_Writer *dst, char obj, CGS_StrView fmt_arg);
 CGS_Error cgs__schar_tostr (CGS_Writer *dst, signed char obj, CGS_StrView fmt_arg);
 CGS_Error cgs__uchar_tostr (CGS_Writer *dst, unsigned char obj, CGS_StrView fmt_arg);
 CGS_Error cgs__short_tostr (CGS_Writer *dst, short obj, CGS_StrView fmt_arg);
 CGS_Error cgs__ushort_tostr(CGS_Writer *dst, unsigned short obj, CGS_StrView fmt_arg);
 CGS_Error cgs__int_tostr (CGS_Writer *dst, int obj, CGS_StrView fmt_arg);
 CGS_Error cgs__uint_tostr (CGS_Writer *dst, unsigned int obj, CGS_StrView fmt_arg);
 CGS_Error cgs__long_tostr (CGS_Writer *dst, long obj, CGS_StrView fmt_arg);
 CGS_Error cgs__ulong_tostr (CGS_Writer *dst, unsigned long obj, CGS_StrView fmt_arg);
 CGS_Error cgs__llong_tostr (CGS_Writer *dst, long long obj, CGS_StrView fmt_arg);
 CGS_Error cgs__ullong_tostr(CGS_Writer *dst, unsigned long long obj, CGS_StrView fmt_arg);
 CGS_Error cgs__float_tostr (CGS_Writer *dst, float obj, CGS_StrView fmt_arg);
 CGS_Error cgs__double_tostr(CGS_Writer *dst, double obj, CGS_StrView fmt_arg);

 CGS_Error cgs__dstr_tostr (CGS_Writer *dst, CGS_DStr obj, CGS_StrView fmt_arg);
 CGS_Error cgs__dstr_ptr_tostr (CGS_Writer *dst, const CGS_DStr *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__strv_tostr (CGS_Writer *dst, CGS_StrView obj, CGS_StrView fmt_arg);
 CGS_Error cgs__zstrv_tostr (CGS_Writer *dst, CGS_ZStrView obj, CGS_StrView fmt_arg);
 CGS_Error cgs__strbuf_tostr (CGS_Writer *dst, CGS_StrBuf obj, CGS_StrView fmt_arg);
 CGS_Error cgs__strbuf_ptr_tostr(CGS_Writer *dst, const CGS_StrBuf *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__mutstr_ref_tostr(CGS_Writer *dst, CGS_MutStrRef obj, CGS_StrView fmt_arg);

 CGS_Error cgs__error_tostr (CGS_Writer *dst, CGS_Error obj, CGS_StrView fmt_arg);
 CGS_Error cgs__arrayfmt_tostr (CGS_Writer *dst, CGS_ArrayFmt obj, CGS_StrView fmt_arg);
 CGS_Error cgs__alignfmt_tostr (CGS_Writer *dst, CGS__AlignFmt obj, CGS_StrView fmt_arg);
 CGS_Error cgs__repeatfmt_tostr (CGS_Writer *dst, CGS__RepeatFmt obj, CGS_StrView fmt_arg);


 CGS_Error cgs__bool_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__cstr_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__ucstr_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__char_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__schar_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__uchar_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__short_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__ushort_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__int_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__uint_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__long_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__ulong_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__llong_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__ullong_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__float_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__double_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);

 CGS_Error cgs__dstr_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__dstr_ptr_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__strv_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__zstrv_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__strbuf_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__strbuf_ptr_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__mutstr_ref_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);

 CGS_Error cgs__error_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__arrayfmt_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__alignfmt_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
 CGS_Error cgs__repeatfmt_tostr_p (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);


 CGS_Error cgs__DStrWriter_write (CGS_Writer *dst, CGS_StrView str);
 CGS_Error cgs__StrBufWriter_write(CGS_Writer *dst, CGS_StrView str);
 CGS_Error cgs__CStrWriter_write (CGS_Writer *dst, CGS_StrView str);
 CGS_Error cgs__FileWriter_write (CGS_Writer *dst, CGS_StrView str);
 CGS_Error cgs__LenWriter_write (CGS_Writer *dst, CGS_StrView str);
 CGS_Error cgs__LenPtrWriter_write(CGS_Writer *dst, CGS_StrView str);
 CGS_Error cgs__ChainWriter_write (CGS_Writer *dst, CGS_StrView str);
# 1713 "./../cgs.h"
 CGS_Error cgs__Integer_d_Fmt_cgs__c_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__c obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__c_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__c obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__c_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__c obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__c_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__c obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__c_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__c obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__c_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__c_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__c_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__c_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__c_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__sc_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__sc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__sc_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__sc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__sc_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__sc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__sc_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__sc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__sc_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__sc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__sc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__sc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__sc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__sc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__sc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__uc_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__uc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__uc_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__uc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__uc_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__uc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__uc_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__uc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__uc_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__uc obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__uc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__uc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__uc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__uc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__uc_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__s_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__s obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__s_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__s obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__s_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__s obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__s_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__s obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__s_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__s obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__s_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__s_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__s_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__s_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__s_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__us_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__us obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__us_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__us obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__us_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__us obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__us_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__us obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__us_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__us obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__us_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__us_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__us_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__us_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__us_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__i_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__i obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__i_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__i obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__i_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__i obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__i_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__i obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__i_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__i obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__i_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__i_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__i_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__i_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__i_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__ui_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__ui obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__ui_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__ui obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__ui_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__ui obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__ui_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__ui obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__ui_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__ui obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__ui_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__ui_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__ui_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__ui_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__ui_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__l_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__l obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__l_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__l obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__l_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__l obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__l_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__l obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__l_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__l obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__l_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__l_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__l_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__l_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__l_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__ul_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__ul obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__ul_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__ul obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__ul_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__ul obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__ul_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__ul obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__ul_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__ul obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__ul_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__ul_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__ul_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__ul_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__ul_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__ll_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__ll obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__ll_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__ll obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__ll_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__ll obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__ll_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__ll obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__ll_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__ll obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__ll_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__ll_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__ll_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__ll_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__ll_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__ull_tostr(CGS_Writer *dst, CGS__Integer_d_Fmt_cgs__ull obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__ull_tostr(CGS_Writer *dst, CGS__Integer_x_Fmt_cgs__ull obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__ull_tostr(CGS_Writer *dst, CGS__Integer_o_Fmt_cgs__ull obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__ull_tostr(CGS_Writer *dst, CGS__Integer_b_Fmt_cgs__ull obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__ull_tostr(CGS_Writer *dst, CGS__Integer_X_Fmt_cgs__ull obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_d_Fmt_cgs__ull_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_x_Fmt_cgs__ull_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_o_Fmt_cgs__ull_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_b_Fmt_cgs__ull_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Integer_X_Fmt_cgs__ull_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);
# 1736 "./../cgs.h"
 CGS_Error cgs__Floating_f_Fmt_float_tostr(CGS_Writer *dst, CGS__Floating_f_Fmt_float obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_g_Fmt_float_tostr(CGS_Writer *dst, CGS__Floating_g_Fmt_float obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_e_Fmt_float_tostr(CGS_Writer *dst, CGS__Floating_e_Fmt_float obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_a_Fmt_float_tostr(CGS_Writer *dst, CGS__Floating_a_Fmt_float obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_F_Fmt_float_tostr(CGS_Writer *dst, CGS__Floating_F_Fmt_float obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_G_Fmt_float_tostr(CGS_Writer *dst, CGS__Floating_G_Fmt_float obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_E_Fmt_float_tostr(CGS_Writer *dst, CGS__Floating_E_Fmt_float obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_A_Fmt_float_tostr(CGS_Writer *dst, CGS__Floating_A_Fmt_float obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_f_Fmt_float_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_g_Fmt_float_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_e_Fmt_float_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_a_Fmt_float_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_F_Fmt_float_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_G_Fmt_float_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_E_Fmt_float_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_A_Fmt_float_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_f_Fmt_double_tostr(CGS_Writer *dst, CGS__Floating_f_Fmt_double obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_g_Fmt_double_tostr(CGS_Writer *dst, CGS__Floating_g_Fmt_double obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_e_Fmt_double_tostr(CGS_Writer *dst, CGS__Floating_e_Fmt_double obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_a_Fmt_double_tostr(CGS_Writer *dst, CGS__Floating_a_Fmt_double obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_F_Fmt_double_tostr(CGS_Writer *dst, CGS__Floating_F_Fmt_double obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_G_Fmt_double_tostr(CGS_Writer *dst, CGS__Floating_G_Fmt_double obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_E_Fmt_double_tostr(CGS_Writer *dst, CGS__Floating_E_Fmt_double obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_A_Fmt_double_tostr(CGS_Writer *dst, CGS__Floating_A_Fmt_double obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_f_Fmt_double_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_g_Fmt_double_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_e_Fmt_double_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_a_Fmt_double_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_F_Fmt_double_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_G_Fmt_double_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_E_Fmt_double_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg); CGS_Error cgs__Floating_A_Fmt_double_tostr_p(CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg);





static inline CGS_MutStrRef cgs__clear_and_return(CGS_MutStrRef dst)
{
 cgs__fmutstr_ref_clear(_Generic((__typeof__(dst)*)0, CGS_DStr** : cgs__dstr_ptr_as_fmutstr_ref(_Generic(dst, CGS_DStr*: (dst), default: ((CGS_DStr*){0}) )), CGS_Buffer* : cgs__buf_as_fmutstr_ref_zero_len(_Generic(dst, CGS_Buffer: (dst), default: ((CGS_Buffer){0}) ), &(unsigned int){0}), CGS_StrBuf** : cgs__strbuf_ptr_as_fmutstr_ref(_Generic(dst, CGS_StrBuf*: (dst), default: ((CGS_StrBuf*){0}) )), char** : cgs__buf_as_fmutstr_ref_zero_len(cgs__buf_from_cstr(_Generic(dst, char*: (dst), default: ((char*){0}) )), &(unsigned int){0}), unsigned char** : cgs__buf_as_fmutstr_ref_zero_len(cgs__buf_from_ucstr(_Generic(dst, unsigned char*: (dst), default: ((unsigned char*){0}) )), &(unsigned int){0}), CGS_MutStrRef* : cgs__mutstr_ref_as_fmutstr_ref_zero_len(_Generic(dst, CGS_MutStrRef: (dst), default: ((CGS_MutStrRef){0}) ), &(unsigned int){0}), char(*)[sizeof(__typeof__(dst))] : cgs__buf_as_fmutstr_ref_zero_len(cgs__buf_from_carr(_Generic(dst, char*: (dst), default: ((char*){0}) ), sizeof(__typeof__(dst))), &(unsigned int){0}), unsigned char(*)[sizeof(__typeof__(dst))] : cgs__buf_as_fmutstr_ref_zero_len(cgs__buf_from_ucarr(_Generic(dst, unsigned char*: (dst), default: ((unsigned char*){0}) ), sizeof(__typeof__(dst))), &(unsigned int){0}) ));
 return dst;
}

static inline unsigned int cgs__return_as_u32(size_t a)
{
 return (unsigned int)a;
}

static inline unsigned int cgs__cstr_cap(const char *s)
{
 return (unsigned int)strlen(s);
}

static inline unsigned int cgs__ucstr_cap(const unsigned char *s)
{
 return (unsigned int)strlen((const char *)s);
}

static inline unsigned int cgs__strv_len(CGS_StrView sv)
{
 return sv.len;
}

static inline CGS_Error cgs__invoke_writer(CGS_Writer *dst, CGS_StrView str)
{
 return dst->write(dst, str);
}

static inline CGS_Error cgs__invoke_writer_ln(CGS_Writer *dst, CGS_StrView str)
{
 CGS_Error err = dst->write(dst, str);
 if (err.ec == CGS_OK)
 err = dst->write(dst, (CGS_StrView) {.chars = (char *)"\n", .len = 1});
 return err;
}

static inline CGS_Error cgs__writer_putc(CGS_Writer *dst, char c)
{
 return dst->write(dst, (CGS_StrView) {.chars = &c, .len = 1});
}

static inline unsigned int cgs__invoke_tostr_len(CGS_Error (*tostr_p)(CGS_Writer *, const void *, CGS_StrView fmt_arg), const void *obj)
{
 CGS_LenWriter len_writer = (CGS_LenWriter){.base = {.write = cgs__LenWriter_write}};
 tostr_p((CGS_Writer *)&len_writer, obj, (CGS_StrView) {});
 return len_writer.len;
}

static inline CGS_Error
cgs__invoke_appendln_tostr(CGS_Writer *writer, const void *obj, CGS_Error (*tostr_p)(CGS_Writer *, const void *, CGS_StrView))
{
 CGS_Error err1 = tostr_p(writer, obj, (CGS_StrView) {});
 CGS_Error err2 = cgs__invoke_writer((CGS_Writer*) _Generic((__typeof__(writer)*)0, CGS_Writer** : (writer), CGS_FileWriter** : (writer), CGS_LenWriter** : (writer), CGS_DStrWriter** : (writer), CGS_CStrWriter** : (writer), CGS_ChainWriter** : (writer), CGS_CustomWriter**: (writer), CGS_DStr** : (&(__typeof__((CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(writer, CGS_DStr*: (writer), default: ((CGS_DStr*){0}) )})[]){(CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(writer, CGS_DStr*: (writer), default: ((CGS_DStr*){0}) )}}[0]), CGS_StrBuf** : (&(__typeof__((CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(writer, CGS_StrBuf*: (writer), default: ((CGS_StrBuf*){0}) )})[]){(CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(writer, CGS_StrBuf*: (writer), default: ((CGS_StrBuf*){0}) )}}[0]), CGS_MutStrRef* : (&(__typeof__(cgs__mutstr_ref_to_writer(_Generic(writer, CGS_MutStrRef: (writer), default: ((CGS_MutStrRef){0}) )))[]){cgs__mutstr_ref_to_writer(_Generic(writer, CGS_MutStrRef: (writer), default: ((CGS_MutStrRef){0}) ))}[0]), char(*)[sizeof(__typeof__(writer))] : (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(writer)), .ptr = (char*) _Generic(writer, char*: (writer), default: ((char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(writer)), .ptr = (char*) _Generic(writer, char*: (writer), default: ((char*){0}) )}}}[0]), unsigned char(*)[sizeof(__typeof__(writer))]: (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(writer)), .ptr = (char*) _Generic(writer, unsigned char*: (writer), default: ((unsigned char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(writer)), .ptr = (char*) _Generic(writer, unsigned char*: (writer), default: ((unsigned char*){0}) )}}}[0]), FILE** : (&(__typeof__((CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(writer, FILE*: (writer), default: ((FILE*){0}) )})[]){(CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(writer, FILE*: (writer), default: ((FILE*){0}) )}}[0]), unsigned int** : (&(__typeof__((CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(writer, unsigned int*: (writer), default: ((unsigned int*){0}) )})[]){(CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(writer, unsigned int*: (writer), default: ((unsigned int*){0}) )}}[0]) ), (CGS_StrView){.chars = &(char){'\n'}, .len = 1});
 return err1.ec == CGS_OK ? err2 : err1;
}






typedef struct CGS__FmtFlags
{
 _Bool left_align : 1;
 _Bool add_plus : 1;
 _Bool zero_pad : 1;
 _Bool alt : 1;
} CGS__FmtFlags;
# 1842 "./../cgs.h"
enum
{
 CGS__LENMOD_NONE = 0,
 CGS__LENMOD_INVALID,



 CGS__LENMOD_h, CGS__LENMOD_hh, CGS__LENMOD_l, CGS__LENMOD_ll, CGS__LENMOD_j, CGS__LENMOD_z, CGS__LENMOD_t, CGS__LENMOD_L, CGS__LENMOD_H, CGS__LENMOD_w8, CGS__LENMOD_w16, CGS__LENMOD_w32, CGS__LENMOD_w64, CGS__LENMOD_wf8, CGS__LENMOD_wf16, CGS__LENMOD_wf32, CGS__LENMOD_wf64,



 CGS__LENMOD_interp
};

[[gnu::always_inline]]
static inline unsigned char cgs__fmt_spec_extract_length_modifier_(const char *length_modifier)
{
 if (strcmp(length_modifier, "h") == 0)
 return CGS__LENMOD_h;
 else if (strcmp(length_modifier, "hh") == 0)
 return CGS__LENMOD_hh;
 else if (strcmp(length_modifier, "l") == 0)
 return CGS__LENMOD_l;
 else if (strcmp(length_modifier, "ll") == 0)
 return CGS__LENMOD_ll;
 else if (strcmp(length_modifier, "j") == 0)
 return CGS__LENMOD_j;
 else if (strcmp(length_modifier, "z") == 0)
 return CGS__LENMOD_z;
 else if (strcmp(length_modifier, "t") == 0)
 return CGS__LENMOD_t;
 else if (strcmp(length_modifier, "L") == 0)
 return CGS__LENMOD_L;
 else if (strcmp(length_modifier, "H") == 0)
 return CGS__LENMOD_H;
 else if (strcmp(length_modifier, "w8") == 0)
 return CGS__LENMOD_w8;
 else if (strcmp(length_modifier, "w16") == 0)
 return CGS__LENMOD_w16;
 else if (strcmp(length_modifier, "w32") == 0)
 return CGS__LENMOD_w32;
 else if (strcmp(length_modifier, "w64") == 0)
 return CGS__LENMOD_w64;
 else if (strcmp(length_modifier, "wf8") == 0)
 return CGS__LENMOD_wf8;
 else if (strcmp(length_modifier, "wf16") == 0)
 return CGS__LENMOD_wf16;
 else if (strcmp(length_modifier, "wf32") == 0)
 return CGS__LENMOD_wf32;
 else if (strcmp(length_modifier, "wf64") == 0)
 return CGS__LENMOD_wf64;
 else if (strcmp(length_modifier, "{}") == 0)
 return CGS__LENMOD_interp;
 else if (length_modifier[0])
 return CGS__LENMOD_INVALID;
 else
 return CGS__LENMOD_NONE;
}




static inline unsigned long long cgs__fmt_spec_star_or_num_or_empty_(const char *s)
{
 if (s[0] == '*')
 return (unsigned long long)-2;
 else if (s[0])
 return strtoul(s, ((void *)0), 10);
 else
 return (unsigned long long)-1;
}







enum
{
 CGS__FmtSpec_not_integer,
 CSG__FmtSpec_ubegin,
 CGS__FmtSpec_uchar,
 CGS__FmtSpec_ushort,
 CGS__FmtSpec_uint,
 CGS__FmtSpec_ulong,
 CGS__FmtSpec_ullong,
 CGS__FmtSpec_uend_if_char_signed,
 CGS__FmtSpec_sbegin_if_char_signed,
 CGS__FmtSpec_char,
 CGS__FmtSpec_uend_if_char_unsigned,
 CGS__FmtSpec_sbegin_if_char_unsigned,
 CGS__FmtSpec_schar,
 CGS__FmtSpec_short,
 CGS__FmtSpec_int,
 CGS__FmtSpec_long,
 CGS__FmtSpec_llong,
 CGS__FmtSpec_send
};
# 1958 "./../cgs.h"
 CGS_Error cgs__appendi(
 CGS_Writer *writer, unsigned int n_specifiers, const CGS_StrView literals[], const CGS__FmtFlags flags[], const unsigned long long widths[],
 const unsigned long long precisions[], const unsigned char length_modifiers[], const char conversion_chars[], const void *interps[],
 CGS_Error (*interp_tostr_p_funcs[])(CGS_Writer *, const void *, CGS_StrView fmt_arg), const signed char *interp_is_integer, unsigned n_objs, void *objs[],
 CGS_Error (*tostr_p_funcs[])(CGS_Writer *, const void *, CGS_StrView fmt_arg), const signed char *obj_is_integer
);
# 58 "bench.c"
static unsigned long long g_sink;
static unsigned g_iters = 200000;





static double now_sec(void)
{






 struct timespec ts;
 clock_gettime(1, &ts);
 return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;



}


static unsigned clamp_len(int n, unsigned cap)
{
 if (n < 0) return 0;
 if ((unsigned)n < cap) return (unsigned)n;
 return cap ? cap - 1u : 0u;
}





typedef struct Rect { int x, y, w, h; } Rect;
typedef struct Rgba { unsigned char r, g, b, a; } Rgba;

typedef struct Event {
 unsigned int id;
 char *label;
 Rect area;
 Rgba color;
 double weight;
} Event;

static CGS_Error event_to_str(CGS_Writer *dst, Event e, CGS_StrView fmt_arg)
{
 if (cgs__strv_equal(_Generic(fmt_arg, CGS_DStr*: cgs__strv_dstr_ptr1, CGS_StrBuf*: cgs__strv_strbuf_ptr1, CGS_MutStrRef: cgs__strv_mutstr_ref1, char*: cgs__strv_cstr1, unsigned char*: cgs__strv_ucstr1, const char*: cgs__strv_cstr1, const unsigned char*: cgs__strv_ucstr1, CGS_ZStrView: cgs__strv_strv1, CGS_DStr: cgs__strv_dstr1, CGS_StrBuf: cgs__strv_strbuf1, const CGS_DStr*: cgs__strv_dstr_ptr1, const CGS_StrBuf*: cgs__strv_strbuf_ptr1, CGS_StrView: cgs__strv_strv1, CGS__INCOMPAT: 0 )(_Generic(fmt_arg, CGS_ZStrView: cgs__strv_zstrv1(_Generic(fmt_arg, CGS_ZStrView: (fmt_arg), default: ((CGS_ZStrView){0}) )), default: fmt_arg )), _Generic("short", CGS_DStr*: cgs__strv_dstr_ptr1, CGS_StrBuf*: cgs__strv_strbuf_ptr1, CGS_MutStrRef: cgs__strv_mutstr_ref1, char*: cgs__strv_cstr1, unsigned char*: cgs__strv_ucstr1, const char*: cgs__strv_cstr1, const unsigned char*: cgs__strv_ucstr1, CGS_ZStrView: cgs__strv_strv1, CGS_DStr: cgs__strv_dstr1, CGS_StrBuf: cgs__strv_strbuf1, const CGS_DStr*: cgs__strv_dstr_ptr1, const CGS_StrBuf*: cgs__strv_strbuf_ptr1, CGS_StrView: cgs__strv_strv1, CGS__INCOMPAT: 0 )(_Generic("short", CGS_ZStrView: cgs__strv_zstrv1(_Generic("short", CGS_ZStrView: ("short"), default: ((CGS_ZStrView){0}) )), default: "short" ))))
 return cgs__appendi( (CGS_Writer*) _Generic((__typeof__(dst)*)0, CGS_Writer** : (dst), CGS_FileWriter** : (dst), CGS_LenWriter** : (dst), CGS_DStrWriter** : (dst), CGS_CStrWriter** : (dst), CGS_ChainWriter** : (dst), CGS_CustomWriter**: (dst), CGS_DStr** : (&(__typeof__((CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(dst, CGS_DStr*: (dst), default: ((CGS_DStr*){0}) )})[]){(CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(dst, CGS_DStr*: (dst), default: ((CGS_DStr*){0}) )}}[0]), CGS_StrBuf** : (&(__typeof__((CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(dst, CGS_StrBuf*: (dst), default: ((CGS_StrBuf*){0}) )})[]){(CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(dst, CGS_StrBuf*: (dst), default: ((CGS_StrBuf*){0}) )}}[0]), CGS_MutStrRef* : (&(__typeof__(cgs__mutstr_ref_to_writer(_Generic(dst, CGS_MutStrRef: (dst), default: ((CGS_MutStrRef){0}) )))[]){cgs__mutstr_ref_to_writer(_Generic(dst, CGS_MutStrRef: (dst), default: ((CGS_MutStrRef){0}) ))}[0]), char(*)[sizeof(__typeof__(dst))] : (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(dst)), .ptr = (char*) _Generic(dst, char*: (dst), default: ((char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(dst)), .ptr = (char*) _Generic(dst, char*: (dst), default: ((char*){0}) )}}}[0]), unsigned char(*)[sizeof(__typeof__(dst))]: (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(dst)), .ptr = (char*) _Generic(dst, unsigned char*: (dst), default: ((unsigned char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(dst)), .ptr = (char*) _Generic(dst, unsigned char*: (dst), default: ((unsigned char*){0}) )}}}[0]), FILE** : (&(__typeof__((CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(dst, FILE*: (dst), default: ((FILE*){0}) )})[]){(CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(dst, FILE*: (dst), default: ((FILE*){0}) )}}[0]), unsigned int** : (&(__typeof__((CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(dst, unsigned int*: (dst), default: ((unsigned int*){0}) )})[]){(CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(dst, unsigned int*: (dst), default: ((unsigned int*){0}) )}}[0]) ), (sizeof((const char*[]){"",""}) / sizeof(((const char*[]){"",""})[0])), (const CGS_StrView[]){(CGS_StrView){.chars = "#", .len = sizeof("#") - 1}, (CGS_StrView){.chars = " ", .len = sizeof(" ") - 1}, (CGS_StrView){.chars = "", .len = sizeof("") - 1},}, (const CGS__FmtFlags[]){(CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') },}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned char[]){cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""),}, (char[]){'\165','\163'}, (const void*[]){}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){}, (const signed char[]){}, 0 +1 +1, (void*[]){(void*)&(__typeof__(((void)0,e.id))[]){(e.id),}[0], (void*)&(__typeof__(((void)0,e.label))[]){(e.label),}[0],}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){(CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.id)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.label)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ),}, (const signed char[]){_Generic(e.id, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.label, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ),} );

 return cgs__appendi( (CGS_Writer*) _Generic((__typeof__(dst)*)0, CGS_Writer** : (dst), CGS_FileWriter** : (dst), CGS_LenWriter** : (dst), CGS_DStrWriter** : (dst), CGS_CStrWriter** : (dst), CGS_ChainWriter** : (dst), CGS_CustomWriter**: (dst), CGS_DStr** : (&(__typeof__((CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(dst, CGS_DStr*: (dst), default: ((CGS_DStr*){0}) )})[]){(CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(dst, CGS_DStr*: (dst), default: ((CGS_DStr*){0}) )}}[0]), CGS_StrBuf** : (&(__typeof__((CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(dst, CGS_StrBuf*: (dst), default: ((CGS_StrBuf*){0}) )})[]){(CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(dst, CGS_StrBuf*: (dst), default: ((CGS_StrBuf*){0}) )}}[0]), CGS_MutStrRef* : (&(__typeof__(cgs__mutstr_ref_to_writer(_Generic(dst, CGS_MutStrRef: (dst), default: ((CGS_MutStrRef){0}) )))[]){cgs__mutstr_ref_to_writer(_Generic(dst, CGS_MutStrRef: (dst), default: ((CGS_MutStrRef){0}) ))}[0]), char(*)[sizeof(__typeof__(dst))] : (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(dst)), .ptr = (char*) _Generic(dst, char*: (dst), default: ((char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(dst)), .ptr = (char*) _Generic(dst, char*: (dst), default: ((char*){0}) )}}}[0]), unsigned char(*)[sizeof(__typeof__(dst))]: (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(dst)), .ptr = (char*) _Generic(dst, unsigned char*: (dst), default: ((unsigned char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(dst)), .ptr = (char*) _Generic(dst, unsigned char*: (dst), default: ((unsigned char*){0}) )}}}[0]), FILE** : (&(__typeof__((CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(dst, FILE*: (dst), default: ((FILE*){0}) )})[]){(CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(dst, FILE*: (dst), default: ((FILE*){0}) )}}[0]), unsigned int** : (&(__typeof__((CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(dst, unsigned int*: (dst), default: ((unsigned int*){0}) )})[]){(CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(dst, unsigned int*: (dst), default: ((unsigned int*){0}) )}}[0]) ), (sizeof((const char*[]){"","","","","","","","","","",""}) / sizeof(((const char*[]){"","","","","","","","","","",""})[0])), (const CGS_StrView[]){(CGS_StrView){.chars = "Event#", .len = sizeof("Event#") - 1}, (CGS_StrView){.chars = " \"", .len = sizeof(" \"") - 1}, (CGS_StrView){.chars = "\" rect(", .len = sizeof("\" rect(") - 1}, (CGS_StrView){.chars = ",", .len = sizeof(",") - 1}, (CGS_StrView){.chars = " ", .len = sizeof(" ") - 1}, (CGS_StrView){.chars = "x", .len = sizeof("x") - 1}, (CGS_StrView){.chars = ") rgba(", .len = sizeof(") rgba(") - 1}, (CGS_StrView){.chars = ",", .len = sizeof(",") - 1}, (CGS_StrView){.chars = ",", .len = sizeof(",") - 1}, (CGS_StrView){.chars = ",", .len = sizeof(",") - 1}, (CGS_StrView){.chars = ") w=", .len = sizeof(") w=") - 1}, (CGS_StrView){.chars = "", .len = sizeof("") - 1},}, (const CGS__FmtFlags[]){(CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') },}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_("2"),}, (const unsigned char[]){cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_("hh"), cgs__fmt_spec_extract_length_modifier_("hh"), cgs__fmt_spec_extract_length_modifier_("hh"), cgs__fmt_spec_extract_length_modifier_("hh"), cgs__fmt_spec_extract_length_modifier_(""),}, (char[]){'\165','\163','\144','\144','\144','\144','\165','\165','\165','\165','\146'}, (const void*[]){}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){}, (const signed char[]){}, 0 +1 +1 +1 +1 +1 +1 +1 +1 +1 +1 +1, (void*[]){(void*)&(__typeof__(((void)0,e.id))[]){(e.id),}[0], (void*)&(__typeof__(((void)0,e.label))[]){(e.label),}[0], (void*)&(__typeof__(((void)0,e.area.x))[]){(e.area.x),}[0], (void*)&(__typeof__(((void)0,e.area.y))[]){(e.area.y),}[0], (void*)&(__typeof__(((void)0,e.area.w))[]){(e.area.w),}[0], (void*)&(__typeof__(((void)0,e.area.h))[]){(e.area.h),}[0], (void*)&(__typeof__(((void)0,e.color.r))[]){(e.color.r),}[0], (void*)&(__typeof__(((void)0,e.color.g))[]){(e.color.g),}[0], (void*)&(__typeof__(((void)0,e.color.b))[]){(e.color.b),}[0], (void*)&(__typeof__(((void)0,e.color.a))[]){(e.color.a),}[0], (void*)&(__typeof__(((void)0,e.weight))[]){(e.weight),}[0],}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){(CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.id)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.label)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.area.x)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.area.y)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.area.w)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.area.h)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.color.r)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.color.g)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.color.b)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.color.a)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(e.weight)){0}, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ),}, (const signed char[]){_Generic(e.id, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.label, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.area.x, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.area.y, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.area.w, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.area.h, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.color.r, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.color.g, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.color.b, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.color.a, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(e.weight, char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ),} )




;
}
# 1993 "./../cgs.h"
_Static_assert(_Generic((_Generic((Event){0}, _Bool : cgs__bool_tostr, char* : cgs__cstr_tostr, unsigned char* : cgs__ucstr_tostr, char : cgs__char_tostr, signed char : cgs__schar_tostr, unsigned char : cgs__uchar_tostr, short : cgs__short_tostr, unsigned short : cgs__ushort_tostr, int : cgs__int_tostr, unsigned int : cgs__uint_tostr, long : cgs__long_tostr, unsigned long : cgs__ulong_tostr, long long : cgs__llong_tostr, unsigned long long : cgs__ullong_tostr, float : cgs__float_tostr, double : cgs__double_tostr, CGS_DStr : cgs__dstr_tostr, CGS_DStr* : cgs__dstr_ptr_tostr, CGS_StrView : cgs__strv_tostr, CGS_ZStrView : cgs__zstrv_tostr, CGS_StrBuf : cgs__strbuf_tostr, CGS_StrBuf* : cgs__strbuf_ptr_tostr, CGS_MutStrRef : cgs__mutstr_ref_tostr, const char* : cgs__cstr_tostr, const unsigned char* : cgs__ucstr_tostr, const CGS_DStr* : cgs__dstr_ptr_tostr, const CGS_StrBuf* : cgs__strbuf_ptr_tostr, CGS_Error : cgs__error_tostr, CGS_ArrayFmt : cgs__arrayfmt_tostr, CGS__AlignFmt : cgs__alignfmt_tostr, CGS__RepeatFmt : cgs__repeatfmt_tostr, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr, default: (cgs__tostr_fail){0} )), cgs__tostr_fail: 1, default: 0), "Type already has a tostr");



typedef __typeof__(Event) cgs__tostr_type_1; static inline CGS_Error cgs__tostr_func_1 (CGS_Writer *dst, cgs__tostr_type_1 obj, CGS_StrView fmt_arg) { _Static_assert(_Generic((event_to_str), __typeof__(CGS_Error(*)(CGS_Writer*, cgs__tostr_type_1, CGS_StrView)): 1, default: 0), "tostr functions must have signature `CGS_Error(CGS_Writer *dst, T src, CGS_StrView fmt_arg)`"); return event_to_str (dst, obj, fmt_arg); } static inline CGS_Error cgs__tostr_p_func_1 (CGS_Writer *dst, const void *obj, CGS_StrView fmt_arg) { return cgs__tostr_func_1(dst, * (cgs__tostr_type_1*) obj, fmt_arg); }
# 128 "bench.c"
static char BLOB[256];

static char *PIECES[8] = {
 "Ada Lovelace", "A-7719", "Architect", "Cairo",
 "SA-01", "core", "Platform", "active"
};

typedef struct Slice { char *p; int n; } Slice;

static CGS_StrView V[8];
static Slice S[8];

static void init_views(void)
{
 unsigned off = 0;
 for (int k = 0; k < 8; ++k) {
 unsigned n = (unsigned)strlen(PIECES[k]);
 memcpy(BLOB + off, PIECES[k], n);
 V[k] = _Generic(BLOB, CGS_DStr*: cgs__strv_dstr_ptr3, CGS_StrBuf*: cgs__strv_strbuf_ptr3, CGS_MutStrRef: cgs__strv_mutstr_ref3, char*: cgs__strv_cstr3, unsigned char*: cgs__strv_ucstr3, const char*: cgs__strv_cstr3, const unsigned char*: cgs__strv_ucstr3, CGS_ZStrView: cgs__strv_strv3, CGS_DStr: cgs__strv_dstr3, CGS_StrBuf: cgs__strv_strbuf3, const CGS_DStr*: cgs__strv_dstr_ptr3, const CGS_StrBuf*: cgs__strv_strbuf_ptr3, CGS_StrView: cgs__strv_strv3, CGS__INCOMPAT: 0 )(_Generic(BLOB, CGS_ZStrView: cgs__strv_zstrv1(_Generic(BLOB, CGS_ZStrView: (BLOB), default: ((CGS_ZStrView){0}) )), default: BLOB ), off, off + n);
 S[k].p = BLOB + off;
 S[k].n = (int)n;
 off += n;
 }
}

static int I32[8] = {
 0, -1, 42, -2147483647 - 1, 1234567, -99, 2147483647, -100000
};
static unsigned U32[8] = {
 0u, 1u, 0xDEADBEEFu, 4294967295u, 255u, 65535u, 0x8000u, 1000000007u
};
static long long I64[8] = {
 0, -1, 9223372036854775807LL, -9223372036854775807LL - 1,
 1000000000000LL, -42LL, 987654321987654321LL, 7LL
};
static unsigned long long U64[8] = {
 0ull, 1ull, 0xFFFFFFFFFFFFFFFFull, 0x0123456789ABCDEFull,
 1024ull, 0xCAFEBABEull, 999999999999ull, 0x10ull
};
static size_t SZ[8] = { 0, 1, 4096, 65536, 1048576, 17, 123456789, 64 };

static Event EV[8] = {
 { 1001u, "toolbar", { 0, 0, 1280, 48 }, { 32, 34, 38, 255 }, 1.00 },
 { 1002u, "sidebar", { 0, 48, 240, 720 }, { 24, 26, 30, 240 }, 0.50 },
 { 1003u, "canvas", { 240, 48, 1040, 720 }, { 250, 250, 250, 255 }, 3.25 },
 { 1004u, "statusbar", { 0, 768, 1280, 24 }, { 18, 18, 20, 200 }, 0.10 },
 { 1005u, "tooltip", { 512, 300, 180, 64 }, { 255, 214, 10, 230 }, 12.75 },
 { 1006u, "modal", { 320, 200, 640, 400 }, { 12, 12, 16, 128 }, 8.00 },
 { 1007u, "gutter", { 240, 48, 40, 720 }, { 40, 42, 48, 255 }, 0.25 },
 { 1008u, "minimap", { 1180, 48, 100, 720 }, { 60, 62, 70, 180 }, 2.50 }
};
# 193 "bench.c"
static int cgs_views(CGS_StrBuf *o, unsigned i)
{

 cgs__appendi( (CGS_Writer*) _Generic((__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))*)0, CGS_Writer** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_FileWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_LenWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_DStrWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_CStrWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_ChainWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_CustomWriter**: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_DStr** : (&(__typeof__((CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_DStr*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_DStr*){0}) )})[]){(CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_DStr*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_DStr*){0}) )}}[0]), CGS_StrBuf** : (&(__typeof__((CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_StrBuf*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_StrBuf*){0}) )})[]){(CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_StrBuf*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_StrBuf*){0}) )}}[0]), CGS_MutStrRef* : (&(__typeof__(cgs__mutstr_ref_to_writer(_Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_MutStrRef: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_MutStrRef){0}) )))[]){cgs__mutstr_ref_to_writer(_Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_MutStrRef: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_MutStrRef){0}) ))}[0]), char(*)[sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))))] : (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((char*){0}) )}}}[0]), unsigned char(*)[sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))))]: (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned char*){0}) )}}}[0]), FILE** : (&(__typeof__((CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), FILE*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((FILE*){0}) )})[]){(CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), FILE*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((FILE*){0}) )}}[0]), unsigned int** : (&(__typeof__((CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned int*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned int*){0}) )})[]){(CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned int*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned int*){0}) )}}[0]) ), (sizeof((const char*[]){"","","","","","","",""}) / sizeof(((const char*[]){"","","","","","","",""})[0])), (const CGS_StrView[]){(CGS_StrView){.chars = "", .len = sizeof("") - 1}, (CGS_StrView){.chars = "|", .len = sizeof("|") - 1}, (CGS_StrView){.chars = "|", .len = sizeof("|") - 1}, (CGS_StrView){.chars = "|", .len = sizeof("|") - 1}, (CGS_StrView){.chars = "|", .len = sizeof("|") - 1}, (CGS_StrView){.chars = "|", .len = sizeof("|") - 1}, (CGS_StrView){.chars = "|", .len = sizeof("|") - 1}, (CGS_StrView){.chars = "|", .len = sizeof("|") - 1}, (CGS_StrView){.chars = "", .len = sizeof("") - 1},}, (const CGS__FmtFlags[]){(CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') },}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned char[]){cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""),}, (char[]){'\077','\077','\077','\077','\077','\077','\077','\077'}, (const void*[]){}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){}, (const signed char[]){}, 0 +1 +1 +1 +1 +1 +1 +1 +1, (void*[]){(void*)&(__typeof__(((void)0,((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 0u) & 7u]))[]){(V[(i + 0u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 0u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 14, .fill_char = ' ' })))[]){(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 0u) & 7u]))[]){(V[(i + 0u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 0u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 14, .fill_char = ' ' })),}[0], (void*)&(__typeof__(((void)0,((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 1u) & 7u]))[]){(V[(i + 1u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 1u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 13, .fill_char = ' ' })))[]){(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 1u) & 7u]))[]){(V[(i + 1u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 1u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 13, .fill_char = ' ' })),}[0], (void*)&(__typeof__(((void)0,((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 2u) & 7u]))[]){(V[(i + 2u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 2u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 16, .fill_char = ' ' })))[]){(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 2u) & 7u]))[]){(V[(i + 2u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 2u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 16, .fill_char = ' ' })),}[0], (void*)&(__typeof__(((void)0,((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 3u) & 7u]))[]){(V[(i + 3u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 3u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 12, .fill_char = ' ' })))[]){(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 3u) & 7u]))[]){(V[(i + 3u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 3u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 12, .fill_char = ' ' })),}[0], (void*)&(__typeof__(((void)0,((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 4u) & 7u]))[]){(V[(i + 4u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 4u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 15, .fill_char = ' ' })))[]){(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 4u) & 7u]))[]){(V[(i + 4u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 4u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 15, .fill_char = ' ' })),}[0], (void*)&(__typeof__(((void)0,((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 5u) & 7u]))[]){(V[(i + 5u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 5u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 18, .fill_char = ' ' })))[]){(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 5u) & 7u]))[]){(V[(i + 5u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 5u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 18, .fill_char = ' ' })),}[0], (void*)&(__typeof__(((void)0,((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 6u) & 7u]))[]){(V[(i + 6u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 6u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 17, .fill_char = ' ' })))[]){(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 6u) & 7u]))[]){(V[(i + 6u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 6u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 17, .fill_char = ' ' })),}[0], (void*)&(__typeof__(((void)0,((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 7u) & 7u]))[]){(V[(i + 7u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 7u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 12, .fill_char = ' ' })))[]){(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 7u) & 7u]))[]){(V[(i + 7u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 7u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 12, .fill_char = ' ' })),}[0],}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){(CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 0u) & 7u]))[]){(V[(i + 0u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 0u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 14, .fill_char = ' ' }))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 1u) & 7u]))[]){(V[(i + 1u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 1u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 13, .fill_char = ' ' }))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 2u) & 7u]))[]){(V[(i + 2u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 2u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 16, .fill_char = ' ' }))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 3u) & 7u]))[]){(V[(i + 3u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 3u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 12, .fill_char = ' ' }))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 4u) & 7u]))[]){(V[(i + 4u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 4u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 15, .fill_char = ' ' }))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 5u) & 7u]))[]){(V[(i + 5u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 5u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 18, .fill_char = ' ' }))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 6u) & 7u]))[]){(V[(i + 6u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 6u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 17, .fill_char = ' ' }))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 7u) & 7u]))[]){(V[(i + 7u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 7u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 12, .fill_char = ' ' }))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ),}, (const signed char[]){_Generic(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 0u) & 7u]))[]){(V[(i + 0u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 0u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 14, .fill_char = ' ' }), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 1u) & 7u]))[]){(V[(i + 1u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 1u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 13, .fill_char = ' ' }), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 2u) & 7u]))[]){(V[(i + 2u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 2u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 16, .fill_char = ' ' }), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 3u) & 7u]))[]){(V[(i + 3u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 3u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 12, .fill_char = ' ' }), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 4u) & 7u]))[]){(V[(i + 4u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 4u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 15, .fill_char = ' ' }), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 5u) & 7u]))[]){(V[(i + 5u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 5u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 18, .fill_char = ' ' }), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 6u) & 7u]))[]){(V[(i + 6u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 6u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_LEFT}, .width = 17, .fill_char = ' ' }), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(((CGS__AlignFmt){ .obj = (void*)&(__typeof__(((void)0,V[(i + 7u) & 7u]))[]){(V[(i + 7u) & 7u]),}[0], .tostr_p = _Generic((__typeof__(V[(i + 7u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), .align_mode = (CGS__AlignModeStruct){CGS__ALIGNMODE_RIGHT}, .width = 12, .fill_char = ' ' }), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ),} )







;

 return (int)o->len;
}

static int std_views(CGS_StrBuf *o, unsigned i)
{
 const Slice *a = &S[(i + 0u) & 7u], *b = &S[(i + 1u) & 7u];
 const Slice *c = &S[(i + 2u) & 7u], *d = &S[(i + 3u) & 7u];
 const Slice *e = &S[(i + 4u) & 7u], *f = &S[(i + 5u) & 7u];
 const Slice *g = &S[(i + 6u) & 7u], *h = &S[(i + 7u) & 7u];

 int n = snprintf(o->chars, o->cap,
 "%-*.*s|%*.*s|%-*.*s|%*.*s|%-*.*s|%*.*s|%-*.*s|%*.*s",
 14, a->n, a->p,
 13, b->n, b->p,
 16, c->n, c->p,
 12, d->n, d->p,
 15, e->n, e->p,
 18, f->n, f->p,
 17, g->n, g->p,
 12, h->n, h->p);

 o->len = clamp_len(n, o->cap);
 return n;
}





static int cgs_ints(CGS_StrBuf *o, unsigned i)
{
 unsigned k = i & 7u;



 cgs__appendi( (CGS_Writer*) _Generic((__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))*)0, CGS_Writer** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_FileWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_LenWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_DStrWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_CStrWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_ChainWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_CustomWriter**: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_DStr** : (&(__typeof__((CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_DStr*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_DStr*){0}) )})[]){(CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_DStr*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_DStr*){0}) )}}[0]), CGS_StrBuf** : (&(__typeof__((CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_StrBuf*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_StrBuf*){0}) )})[]){(CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_StrBuf*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_StrBuf*){0}) )}}[0]), CGS_MutStrRef* : (&(__typeof__(cgs__mutstr_ref_to_writer(_Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_MutStrRef: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_MutStrRef){0}) )))[]){cgs__mutstr_ref_to_writer(_Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_MutStrRef: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_MutStrRef){0}) ))}[0]), char(*)[sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))))] : (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((char*){0}) )}}}[0]), unsigned char(*)[sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))))]: (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned char*){0}) )}}}[0]), FILE** : (&(__typeof__((CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), FILE*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((FILE*){0}) )})[]){(CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), FILE*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((FILE*){0}) )}}[0]), unsigned int** : (&(__typeof__((CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned int*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned int*){0}) )})[]){(CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned int*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned int*){0}) )}}[0]) ), (sizeof((const char*[]){"","","","","","","",""}) / sizeof(((const char*[]){"","","","","","","",""})[0])), (const CGS_StrView[]){(CGS_StrView){.chars = "d=", .len = sizeof("d=") - 1}, (CGS_StrView){.chars = " x=", .len = sizeof(" x=") - 1}, (CGS_StrView){.chars = " X=", .len = sizeof(" X=") - 1}, (CGS_StrView){.chars = " o=", .len = sizeof(" o=") - 1}, (CGS_StrView){.chars = " b=", .len = sizeof(" b=") - 1}, (CGS_StrView){.chars = " ll=", .len = sizeof(" ll=") - 1}, (CGS_StrView){.chars = " llx=", .len = sizeof(" llx=") - 1}, (CGS_StrView){.chars = " z=", .len = sizeof(" z=") - 1}, (CGS_StrView){.chars = "", .len = sizeof("") - 1},}, (const CGS__FmtFlags[]){(CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') },}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned char[]){cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_(""), cgs__fmt_spec_extract_length_modifier_("ll"), cgs__fmt_spec_extract_length_modifier_("ll"), cgs__fmt_spec_extract_length_modifier_("z"),}, (char[]){'\144','\170','\130','\157','\142','\144','\170','\165'}, (const void*[]){}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){}, (const signed char[]){}, 0 +1 +1 +1 +1 +1 +1 +1 +1, (void*[]){(void*)&(__typeof__(((void)0,I32[k]))[]){(I32[k]),}[0], (void*)&(__typeof__(((void)0,U32[k]))[]){(U32[k]),}[0], (void*)&(__typeof__(((void)0,U32[(k + 3u) & 7u]))[]){(U32[(k + 3u) & 7u]),}[0], (void*)&(__typeof__(((void)0,U32[(k + 5u) & 7u]))[]){(U32[(k + 5u) & 7u]),}[0], (void*)&(__typeof__(((void)0,U32[(k + 1u) & 7u]))[]){(U32[(k + 1u) & 7u]),}[0], (void*)&(__typeof__(((void)0,I64[k]))[]){(I64[k]),}[0], (void*)&(__typeof__(((void)0,U64[k]))[]){(U64[k]),}[0], (void*)&(__typeof__(((void)0,SZ[k]))[]){(SZ[k]),}[0],}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){(CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(I32[k])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(U32[k])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(U32[(k + 3u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(U32[(k + 5u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(U32[(k + 1u) & 7u])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(I64[k])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(U64[k])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(SZ[k])){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ),}, (const signed char[]){_Generic(I32[k], char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(U32[k], char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(U32[(k + 3u) & 7u], char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(U32[(k + 5u) & 7u], char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(U32[(k + 1u) & 7u], char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(I64[k], char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(U64[k], char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(SZ[k], char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ),} )







;

 return (int)o->len;
}

static int std_ints(CGS_StrBuf *o, unsigned i)
{
 unsigned k = i & 7u;





 int n = snprintf(o->chars, o->cap,
 "d=%d x=%x X=%X o=%o b=%b ll=%lld llx=%llx z=%zu",
 I32[k],
 U32[k],
 U32[(k + 3u) & 7u],
 U32[(k + 5u) & 7u],
 U32[(k + 1u) & 7u],
 I64[k],
 U64[k],
 SZ[k]);

 o->len = clamp_len(n, o->cap);
 return n;
}
# 291 "bench.c"
static int cgs_events(CGS_StrBuf *o, unsigned i)
{
 unsigned k = i & 7u;
 unsigned k1 = (k + 3u) & 7u;
 unsigned k2 = (k + 5u) & 7u;
 unsigned k3 = (k + 7u) & 7u;



 cgs__appendi( (CGS_Writer*) _Generic((__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))*)0, CGS_Writer** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_FileWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_LenWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_DStrWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_CStrWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_ChainWriter** : (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_CustomWriter**: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), CGS_DStr** : (&(__typeof__((CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_DStr*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_DStr*){0}) )})[]){(CGS_DStrWriter){.base = {.write = cgs__DStrWriter_write}, .dstr = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_DStr*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_DStr*){0}) )}}[0]), CGS_StrBuf** : (&(__typeof__((CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_StrBuf*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_StrBuf*){0}) )})[]){(CGS_StrBufWriter){.base = {.write = cgs__StrBufWriter_write}, .strbuf = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_StrBuf*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_StrBuf*){0}) )}}[0]), CGS_MutStrRef* : (&(__typeof__(cgs__mutstr_ref_to_writer(_Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_MutStrRef: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_MutStrRef){0}) )))[]){cgs__mutstr_ref_to_writer(_Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), CGS_MutStrRef: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((CGS_MutStrRef){0}) ))}[0]), char(*)[sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))))] : (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((char*){0}) )}}}[0]), unsigned char(*)[sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))))]: (&(__typeof__((CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned char*){0}) )}})[]){(CGS_CStrWriter){.base = {.write = cgs__CStrWriter_write}, .buf = {.cap = sizeof(__typeof__(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))))), .ptr = (char*) _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned char*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned char*){0}) )}}}[0]), FILE** : (&(__typeof__((CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), FILE*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((FILE*){0}) )})[]){(CGS_FileWriter){.base = {.write = cgs__FileWriter_write}, .file = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), FILE*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((FILE*){0}) )}}[0]), unsigned int** : (&(__typeof__((CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned int*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned int*){0}) )})[]){(CGS_LenPtrWriter){.base = {.write = cgs__LenPtrWriter_write}, .len = _Generic(cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) ))), unsigned int*: (cgs__clear_and_return(_Generic((__typeof__((o))*){0}, char** : cgs__cstr_as_mutstr_ref, unsigned char** : cgs__ucstr_as_mutstr_ref, CGS_DStr** : cgs__dstr_ptr_as_mutstr_ref, CGS_StrBuf** : cgs__strbuf_ptr_as_mutstr_ref, CGS_MutStrRef* : cgs__mutstr_ref_as_mutstr_ref, char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref, unsigned char(*)[sizeof(__typeof__((o)))] : cgs__buf_as_mutstr_ref )(_Generic((__typeof__((o))*){0}, char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = _Generic((o), char*: ((o)), default: ((char*){0}) ), .cap = sizeof(__typeof__((o)))}, unsigned char(*)[sizeof(__typeof__((o)))] : (CGS_Buffer){.ptr = (char*) _Generic((o), unsigned char*: ((o)), default: ((unsigned char*){0}) ), .cap = sizeof(__typeof__((o)))}, default: ((o)) )))), default: ((unsigned int*){0}) )}}[0]) ), (sizeof((const char*[]){"","","","",""}) / sizeof(((const char*[]){"","","","",""})[0])), (const CGS_StrView[]){(CGS_StrView){.chars = "", .len = sizeof("") - 1}, (CGS_StrView){.chars = " | ", .len = sizeof(" | ") - 1}, (CGS_StrView){.chars = " | ", .len = sizeof(" | ") - 1}, (CGS_StrView){.chars = " | #", .len = sizeof(" | #") - 1}, (CGS_StrView){.chars = " ", .len = sizeof(" ") - 1}, (CGS_StrView){.chars = "", .len = sizeof("") - 1},}, (const CGS__FmtFlags[]){(CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') }, (CGS__FmtFlags){ .left_align = strchr("", '-'), .add_plus = strchr("", '+'), .zero_pad = strchr("", '0'), .alt = strchr("", '#') },}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned long long[]){cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""), cgs__fmt_spec_star_or_num_or_empty_(""),}, (const unsigned char[]){cgs__fmt_spec_extract_length_modifier_("{}"), cgs__fmt_spec_extract_length_modifier_("{}"), cgs__fmt_spec_extract_length_modifier_("{}"), cgs__fmt_spec_extract_length_modifier_("{}"), cgs__fmt_spec_extract_length_modifier_("{}"),}, (char[]){'\077','\077','\077','\165','\163'}, (const void*[]){(void*)&(__typeof__(((void)0,( EV[k])))[]){(( EV[k])),}[0], (void*)&(__typeof__(((void)0,( EV[k1])))[]){(( EV[k1])),}[0], (void*)&(__typeof__(((void)0,( EV[k2])))[]){(( EV[k2])),}[0], (void*)&(__typeof__(((void)0,( EV[k3].id)))[]){(( EV[k3].id)),}[0], (void*)&(__typeof__(((void)0,( EV[k3].label)))[]){(( EV[k3].label)),}[0],}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){(CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(( EV[k]))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(( EV[k1]))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(( EV[k2]))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(( EV[k3].id))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ), (CGS_Error(*)(CGS_Writer*, const void*, CGS_StrView))_Generic((__typeof__(( EV[k3].label))){0}, cgs__tostr_type_1 : cgs__tostr_p_func_1, _Bool : cgs__bool_tostr_p, char* : cgs__cstr_tostr_p, unsigned char* : cgs__ucstr_tostr_p, char : cgs__char_tostr_p, signed char : cgs__schar_tostr_p, unsigned char : cgs__uchar_tostr_p, short : cgs__short_tostr_p, unsigned short : cgs__ushort_tostr_p, int : cgs__int_tostr_p, unsigned int : cgs__uint_tostr_p, long : cgs__long_tostr_p, unsigned long : cgs__ulong_tostr_p, long long : cgs__llong_tostr_p, unsigned long long : cgs__ullong_tostr_p, float : cgs__float_tostr_p, double : cgs__double_tostr_p, CGS_DStr : cgs__dstr_tostr_p, CGS_DStr* : cgs__dstr_ptr_tostr_p, CGS_StrView : cgs__strv_tostr_p, CGS_ZStrView : cgs__zstrv_tostr_p, CGS_StrBuf : cgs__strbuf_tostr_p, CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_MutStrRef : cgs__mutstr_ref_tostr_p, const char* : cgs__cstr_tostr_p, const unsigned char* : cgs__ucstr_tostr_p, const CGS_DStr* : cgs__dstr_ptr_tostr_p, const CGS_StrBuf* : cgs__strbuf_ptr_tostr_p, CGS_Error : cgs__error_tostr_p, CGS_ArrayFmt : cgs__arrayfmt_tostr_p, CGS__AlignFmt : cgs__alignfmt_tostr_p, CGS__RepeatFmt : cgs__repeatfmt_tostr_p, CGS__Integer_d_Fmt_cgs__c : cgs__Integer_d_Fmt_cgs__c_tostr_p, CGS__Integer_x_Fmt_cgs__c : cgs__Integer_x_Fmt_cgs__c_tostr_p, CGS__Integer_o_Fmt_cgs__c : cgs__Integer_o_Fmt_cgs__c_tostr_p, CGS__Integer_b_Fmt_cgs__c : cgs__Integer_b_Fmt_cgs__c_tostr_p, CGS__Integer_X_Fmt_cgs__c : cgs__Integer_X_Fmt_cgs__c_tostr_p, CGS__Integer_d_Fmt_cgs__sc : cgs__Integer_d_Fmt_cgs__sc_tostr_p, CGS__Integer_x_Fmt_cgs__sc : cgs__Integer_x_Fmt_cgs__sc_tostr_p, CGS__Integer_o_Fmt_cgs__sc : cgs__Integer_o_Fmt_cgs__sc_tostr_p, CGS__Integer_b_Fmt_cgs__sc : cgs__Integer_b_Fmt_cgs__sc_tostr_p, CGS__Integer_X_Fmt_cgs__sc : cgs__Integer_X_Fmt_cgs__sc_tostr_p, CGS__Integer_d_Fmt_cgs__uc : cgs__Integer_d_Fmt_cgs__uc_tostr_p, CGS__Integer_x_Fmt_cgs__uc : cgs__Integer_x_Fmt_cgs__uc_tostr_p, CGS__Integer_o_Fmt_cgs__uc : cgs__Integer_o_Fmt_cgs__uc_tostr_p, CGS__Integer_b_Fmt_cgs__uc : cgs__Integer_b_Fmt_cgs__uc_tostr_p, CGS__Integer_X_Fmt_cgs__uc : cgs__Integer_X_Fmt_cgs__uc_tostr_p, CGS__Integer_d_Fmt_cgs__s : cgs__Integer_d_Fmt_cgs__s_tostr_p, CGS__Integer_x_Fmt_cgs__s : cgs__Integer_x_Fmt_cgs__s_tostr_p, CGS__Integer_o_Fmt_cgs__s : cgs__Integer_o_Fmt_cgs__s_tostr_p, CGS__Integer_b_Fmt_cgs__s : cgs__Integer_b_Fmt_cgs__s_tostr_p, CGS__Integer_X_Fmt_cgs__s : cgs__Integer_X_Fmt_cgs__s_tostr_p, CGS__Integer_d_Fmt_cgs__us : cgs__Integer_d_Fmt_cgs__us_tostr_p, CGS__Integer_x_Fmt_cgs__us : cgs__Integer_x_Fmt_cgs__us_tostr_p, CGS__Integer_o_Fmt_cgs__us : cgs__Integer_o_Fmt_cgs__us_tostr_p, CGS__Integer_b_Fmt_cgs__us : cgs__Integer_b_Fmt_cgs__us_tostr_p, CGS__Integer_X_Fmt_cgs__us : cgs__Integer_X_Fmt_cgs__us_tostr_p, CGS__Integer_d_Fmt_cgs__i : cgs__Integer_d_Fmt_cgs__i_tostr_p, CGS__Integer_x_Fmt_cgs__i : cgs__Integer_x_Fmt_cgs__i_tostr_p, CGS__Integer_o_Fmt_cgs__i : cgs__Integer_o_Fmt_cgs__i_tostr_p, CGS__Integer_b_Fmt_cgs__i : cgs__Integer_b_Fmt_cgs__i_tostr_p, CGS__Integer_X_Fmt_cgs__i : cgs__Integer_X_Fmt_cgs__i_tostr_p, CGS__Integer_d_Fmt_cgs__ui : cgs__Integer_d_Fmt_cgs__ui_tostr_p, CGS__Integer_x_Fmt_cgs__ui : cgs__Integer_x_Fmt_cgs__ui_tostr_p, CGS__Integer_o_Fmt_cgs__ui : cgs__Integer_o_Fmt_cgs__ui_tostr_p, CGS__Integer_b_Fmt_cgs__ui : cgs__Integer_b_Fmt_cgs__ui_tostr_p, CGS__Integer_X_Fmt_cgs__ui : cgs__Integer_X_Fmt_cgs__ui_tostr_p, CGS__Integer_d_Fmt_cgs__l : cgs__Integer_d_Fmt_cgs__l_tostr_p, CGS__Integer_x_Fmt_cgs__l : cgs__Integer_x_Fmt_cgs__l_tostr_p, CGS__Integer_o_Fmt_cgs__l : cgs__Integer_o_Fmt_cgs__l_tostr_p, CGS__Integer_b_Fmt_cgs__l : cgs__Integer_b_Fmt_cgs__l_tostr_p, CGS__Integer_X_Fmt_cgs__l : cgs__Integer_X_Fmt_cgs__l_tostr_p, CGS__Integer_d_Fmt_cgs__ul : cgs__Integer_d_Fmt_cgs__ul_tostr_p, CGS__Integer_x_Fmt_cgs__ul : cgs__Integer_x_Fmt_cgs__ul_tostr_p, CGS__Integer_o_Fmt_cgs__ul : cgs__Integer_o_Fmt_cgs__ul_tostr_p, CGS__Integer_b_Fmt_cgs__ul : cgs__Integer_b_Fmt_cgs__ul_tostr_p, CGS__Integer_X_Fmt_cgs__ul : cgs__Integer_X_Fmt_cgs__ul_tostr_p, CGS__Integer_d_Fmt_cgs__ll : cgs__Integer_d_Fmt_cgs__ll_tostr_p, CGS__Integer_x_Fmt_cgs__ll : cgs__Integer_x_Fmt_cgs__ll_tostr_p, CGS__Integer_o_Fmt_cgs__ll : cgs__Integer_o_Fmt_cgs__ll_tostr_p, CGS__Integer_b_Fmt_cgs__ll : cgs__Integer_b_Fmt_cgs__ll_tostr_p, CGS__Integer_X_Fmt_cgs__ll : cgs__Integer_X_Fmt_cgs__ll_tostr_p, CGS__Integer_d_Fmt_cgs__ull : cgs__Integer_d_Fmt_cgs__ull_tostr_p, CGS__Integer_x_Fmt_cgs__ull : cgs__Integer_x_Fmt_cgs__ull_tostr_p, CGS__Integer_o_Fmt_cgs__ull : cgs__Integer_o_Fmt_cgs__ull_tostr_p, CGS__Integer_b_Fmt_cgs__ull : cgs__Integer_b_Fmt_cgs__ull_tostr_p, CGS__Integer_X_Fmt_cgs__ull : cgs__Integer_X_Fmt_cgs__ull_tostr_p, CGS__Floating_f_Fmt_float : cgs__Floating_f_Fmt_float_tostr_p, CGS__Floating_g_Fmt_float : cgs__Floating_g_Fmt_float_tostr_p, CGS__Floating_e_Fmt_float : cgs__Floating_e_Fmt_float_tostr_p, CGS__Floating_a_Fmt_float : cgs__Floating_a_Fmt_float_tostr_p, CGS__Floating_F_Fmt_float : cgs__Floating_F_Fmt_float_tostr_p, CGS__Floating_G_Fmt_float : cgs__Floating_G_Fmt_float_tostr_p, CGS__Floating_E_Fmt_float : cgs__Floating_E_Fmt_float_tostr_p, CGS__Floating_A_Fmt_float : cgs__Floating_A_Fmt_float_tostr_p, CGS__Floating_f_Fmt_double : cgs__Floating_f_Fmt_double_tostr_p, CGS__Floating_g_Fmt_double : cgs__Floating_g_Fmt_double_tostr_p, CGS__Floating_e_Fmt_double : cgs__Floating_e_Fmt_double_tostr_p, CGS__Floating_a_Fmt_double : cgs__Floating_a_Fmt_double_tostr_p, CGS__Floating_F_Fmt_double : cgs__Floating_F_Fmt_double_tostr_p, CGS__Floating_G_Fmt_double : cgs__Floating_G_Fmt_double_tostr_p, CGS__Floating_E_Fmt_double : cgs__Floating_E_Fmt_double_tostr_p, CGS__Floating_A_Fmt_double : cgs__Floating_A_Fmt_double_tostr_p ),}, (const signed char[]){_Generic(( EV[k]), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(( EV[k1]), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(( EV[k2]), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(( EV[k3].id), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ), _Generic(( EV[k3].label), char : CGS__FmtSpec_char, signed char : CGS__FmtSpec_schar, unsigned char : CGS__FmtSpec_uchar, short : CGS__FmtSpec_short, unsigned short : CGS__FmtSpec_ushort, int : CGS__FmtSpec_int, unsigned int : CGS__FmtSpec_uint, long : CGS__FmtSpec_long, unsigned long : CGS__FmtSpec_ulong, long long : CGS__FmtSpec_llong, unsigned long long : CGS__FmtSpec_ullong, default : CGS__FmtSpec_not_integer ),}, 0 , (void*[]){}, (CGS_Error(*[])(CGS_Writer*, const void*, CGS_StrView)){}, (const signed char[]){} )
# 300 "<built-in>"
;

 return (int)o->len;
}

static int std_events(CGS_StrBuf *o, unsigned i)
{
 unsigned k = i & 7u;
 const Event *e0 = &EV[k];
 const Event *e1 = &EV[(k + 3u) & 7u];
 const Event *e2 = &EV[(k + 5u) & 7u];
 const Event *e3 = &EV[(k + 7u) & 7u];





 int n = snprintf(o->chars, o->cap,
 "Event#%u \"%s\" rect(%d,%d %dx%d) rgba(%u,%u,%u,%u) w=%.2f" " | " "Event#%u \"%s\" rect(%d,%d %dx%d) rgba(%u,%u,%u,%u) w=%.2f" " | " "Event#%u \"%s\" rect(%d,%d %dx%d) rgba(%u,%u,%u,%u) w=%.2f" " | #%u %s",
 (e0)->id, (e0)->label, (e0)->area.x, (e0)->area.y, (e0)->area.w, (e0)->area.h, (unsigned)(e0)->color.r, (unsigned)(e0)->color.g, (unsigned)(e0)->color.b, (unsigned)(e0)->color.a, (e0)->weight, (e1)->id, (e1)->label, (e1)->area.x, (e1)->area.y, (e1)->area.w, (e1)->area.h, (unsigned)(e1)->color.r, (unsigned)(e1)->color.g, (unsigned)(e1)->color.b, (unsigned)(e1)->color.a, (e1)->weight, (e2)->id, (e2)->label, (e2)->area.x, (e2)->area.y, (e2)->area.w, (e2)->area.h, (unsigned)(e2)->color.r, (unsigned)(e2)->color.g, (unsigned)(e2)->color.b, (unsigned)(e2)->color.a, (e2)->weight,
 e3->id, e3->label);

 o->len = clamp_len(n, o->cap);
 return n;
}





static int std_none(CGS_StrBuf *o, unsigned i)
{
 return 0;
}

typedef int (*bench_fn)(CGS_StrBuf *out, unsigned i);

typedef struct Case {
 char *name;
 bench_fn std_fn;
 bench_fn cgs_fn;
} Case;

static Case CASES[] = {
 { "1. views  (8 aligned fields)", std_views, cgs_views },
 { "2. ints   (d/x/X/o/b/ll/z)", std_ints, cgs_ints },
 { "3. events (custom tostr)", std_events, cgs_events }
};

 static double run(bench_fn f, CGS_StrBuf *out,
 unsigned iters, unsigned rounds)
{
 double best = 1e300;

 for (unsigned r = 0; r < rounds; ++r) {
 unsigned long long acc = 0;
 double t0 = now_sec();

 for (unsigned i = 0; i < iters; ++i) {
 f(out, i);
 acc += out->len;
 acc += (unsigned char)out->chars[out->len ? out->len - 1u : 0u];
 }

 double dt = now_sec() - t0;
 g_sink += acc;
 if (dt < best) best = dt;
 }
 return best;
}

static int verify(const Case *c)
{
 char sa[512], sb[512];
 CGS_StrBuf a = cgs__strbuf_from_buf((CGS_Buffer){.ptr = (char*) _Generic(sa,char*:(sa),unsigned char*:(sa),void*:(sa)), .cap = (sizeof sa)});
 CGS_StrBuf b = cgs__strbuf_from_buf((CGS_Buffer){.ptr = (char*) _Generic(sb,char*:(sb),unsigned char*:(sb),void*:(sb)), .cap = (sizeof sb)});
 int ok = 1;

 sa[0] = sb[0] = '\0';

 for (unsigned i = 0; i < 8u; ++i) {
 c->std_fn(&a, i);
 c->cgs_fn(&b, i);

 if (strcmp(sa, sb) != 0) {
 if (ok) {
 printf("  MISMATCH in %s at i=%u\n", c->name, i);
 printf("    snprintf : [%s]\n", sa);
 printf("    cgs      : [%s]\n", sb);
 }
 ok = 0;
 }
 if (b.len != (unsigned)strlen(sb)) {
 printf("  NOTE: CGS_StrBuf.len (%u) != strlen (%u) at i=%u\n",
 b.len, (unsigned)strlen(sb), i);
 ok = 0;
 }
 }
 return ok;
}

static void sample(const Case *c)
{
 char s[512];
 CGS_StrBuf o = cgs__strbuf_from_buf((CGS_Buffer){.ptr = (char*) _Generic(s,char*:(s),unsigned char*:(s),void*:(s)), .cap = (sizeof s)});
 s[0] = '\0';
 c->cgs_fn(&o, 0u);
 printf("  sample: %s\n", s);
}

int main(int argc, char **argv)
{
 char buf[512];
 CGS_StrBuf out;
 size_t ncases = sizeof CASES / sizeof CASES[0];

 if (argc > 1) {
 unsigned long v = strtoul(argv[1], ((void *)0), 10);
 if (v) g_iters = (unsigned)v;
 }

 init_views();
 buf[0] = '\0';
 out = cgs__strbuf_from_buf((CGS_Buffer){.ptr = (char*) _Generic(buf,char*:(buf),unsigned char*:(buf),void*:(buf)), .cap = (sizeof buf)});

 printf("cgs_sprinti vs snprintf -- %u iters x %d rounds, best round kept\n\n",
 g_iters, 7);


 for (size_t k = 0; k < ncases; ++k) {
 printf("%s\n", CASES[k].name);
 sample(&CASES[k]);
 printf("  verify: %s\n\n", verify(&CASES[k]) ? "identical output" :
 "DIFFERS (see above)");
 }

 printf("%-30s %13s %13s %9s %7s\n",
 "case", "snprintf", "cgs_sprinti", "speedup", "bytes");
 printf("%-30s %13s %13s %9s %7s\n",
 "------------------------------", "-------------", "-------------",
 "---------", "-------");

 for (size_t k = 0; k < ncases; ++k) {
 double tstd, tcgs;
 unsigned bytes;



 run(CASES[k].std_fn, &out, 20000, 1);
 run(CASES[k].cgs_fn, &out, 20000, 1);

 tstd = run(CASES[k].std_fn, &out, g_iters, 7);
 tcgs = run(CASES[k].cgs_fn, &out, g_iters, 7);

 CASES[k].cgs_fn(&out, 0u);
 bytes = out.len;

 printf("%-30s %10.1f ns %10.1f ns %8.2fx %7u\n",
 CASES[k].name,
 tstd * 1e9 / (double)g_iters,
 tcgs * 1e9 / (double)g_iters,
 tstd / tcgs,
 bytes);
 }

 printf("\nchecksum %llu\n", g_sink);
 return 0;
}
