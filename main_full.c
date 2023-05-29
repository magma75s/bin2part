# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.c"
# 1 "project.h" 1



# 1 "d:\\projects/STA/sta_def.h" 1
# 14 "d:\\projects/STA/sta_def.h"
# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stdint.h" 1 3 4


# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdint.h" 1 3 4
# 24 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdint.h" 3 4
# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stddef.h" 1 3 4
# 324 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stddef.h" 3 4
typedef short unsigned int wchar_t;
# 353 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stddef.h" 3 4
typedef short unsigned int wint_t;
# 25 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdint.h" 2 3 4


typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned uint_least32_t;
typedef long long int_least64_t;
typedef unsigned long long uint_least64_t;





typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
typedef long long int_fast64_t;
typedef unsigned long long uint_fast64_t;
# 66 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdint.h" 3 4
  typedef int intptr_t;
# 75 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdint.h" 3 4
  typedef unsigned int uintptr_t;




typedef long long intmax_t;
typedef unsigned long long uintmax_t;
# 4 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stdint.h" 2 3 4
# 15 "d:\\projects/STA/sta_def.h" 2
# 56 "d:\\projects/STA/sta_def.h"
typedef int sta_bool_t;
# 67 "d:\\projects/STA/sta_def.h"
struct s_clip_rect
{
 int32_t x,y,h,w;
};
typedef struct s_clip_rect clip_rect_t;




struct s_framebuffer_image
{
 uint32_t * pixels;
 int32_t h,w,pitch;
} ;
typedef struct s_framebuffer_image framebuffer_image_t;





struct s_framebuffer_bitmap
{
 framebuffer_image_t fb;
 sta_bool_t has_alpha;
};
typedef struct s_framebuffer_bitmap framebuffer_bitmap_t;





struct s_framebuffer_context
{
 framebuffer_image_t fb;
 clip_rect_t clip;
};
typedef struct s_framebuffer_context framebuffer_context_t;




struct s_framebuffer_color
{
uint8_t b;
uint8_t g;
uint8_t r;
uint8_t a;
};
typedef struct s_framebuffer_color framebuffer_color_t;
typedef struct s_framebuffer_color color_bgra_t;
typedef struct s_framebuffer_color alpha_color_t;




struct s_color_rgba
{
uint8_t r;
uint8_t g;
uint8_t b;
uint8_t a;
};
typedef struct s_color_rgba color_rgba_t;
# 141 "d:\\projects/STA/sta_def.h"
struct s_sta_rect_size
{
 int h,w;
};
typedef struct s_sta_rect_size sta_rect_size_t;



struct s_sta_point
{
 int x,y;
};
typedef struct s_sta_point sta_point_t;
# 5 "project.h" 2





# 1 "d:\\projects/STA/framebuffer_drawing.h" 1



# 1 "d:\\projects/STA/sta_def.h" 1
# 5 "d:\\projects/STA/framebuffer_drawing.h" 2

void framebuffer_image_to_context(framebuffer_image_t * fi,framebuffer_context_t * fc);

void framebuffer_image_set_pixel( framebuffer_image_t * fi,int x,int y,uint32_t color);
void framebuffer_context_set_pixel( framebuffer_context_t * fc,int x,int y,uint32_t color);

void framebuffer_image_set_alpha_pixel( framebuffer_image_t * fi,int x,int y,uint32_t color);
void framebuffer_context_set_alpha_pixel( framebuffer_context_t * fc,int x,int y,uint32_t color);

uint32_t framebuffer_image_get_pixel( framebuffer_image_t * fi,int x,int y);
uint32_t framebuffer_context_get_pixel( framebuffer_context_t * fc,int x,int y );

uint32_t * framebuffer_image_get_pixel_pointer( framebuffer_image_t * fi,int x,int y);
uint32_t * framebuffer_context_get_pixel_pointer( framebuffer_context_t * fc,int x,int y );

void framebuffer_image_fill_color( framebuffer_image_t * fi,uint32_t color);
void framebuffer_context_fill_color(framebuffer_context_t * fc,uint32_t color);
void framebuffer_image_fill_alpha_color( framebuffer_image_t * fi,uint32_t color);
void framebuffer_context_fill_alpha_color(framebuffer_context_t * fc,uint32_t color);

void framebuffer_context_line_horizontal(framebuffer_context_t * fc,int x0,int y,int x1,uint32_t color);
void framebuffer_image_line_horizontal(framebuffer_image_t * fi,int x0,int y,int x1,uint32_t color);

void framebuffer_context_line_vertical(framebuffer_context_t * fc,int x,int y0,int y1,uint32_t color);
void framebuffer_image_line_vertical(framebuffer_image_t * fi,int x,int y0,int y1,uint32_t color);

void framebuffer_context_line_horizontal_alpha(framebuffer_context_t * fc,int x0,int y,int x1,uint32_t color,uint8_t alpha);
void framebuffer_image_line_horizontal_alpha(framebuffer_image_t * fi,int x0,int y,int x1,uint32_t color,uint8_t alpha);

void framebuffer_context_line_vertical_alpha(framebuffer_context_t * fc,int x,int y0,int y1,uint32_t color,uint8_t alpha);
void framebuffer_image_line_vertical_alpha(framebuffer_image_t * fi,int x,int y0,int y1,uint32_t color,uint8_t alpha);

void framebuffer_context_fill_rectangle(framebuffer_context_t * fc,int x,int y,int w,int h,uint32_t color);
void framebuffer_image_fill_rectangle(framebuffer_image_t * fi,int x,int y,int w,int h,uint32_t color);

void framebuffer_context_rectangle(framebuffer_context_t * fc,int x,int y,int h,int w,uint32_t color);
void framebuffer_image_rectangle(framebuffer_image_t * fi,int x,int y,int h,int w,uint32_t color);

void framebuffer_context_rectangle_alpha(framebuffer_context_t * fc,int x,int y,int h,int w,uint32_t color);
void framebuffer_image_rectangle_alpha(framebuffer_image_t * fi,int x,int y,int h,int w,uint32_t color);

void framebuffer_image_blend_pixel( framebuffer_image_t * fi,int x,int y,uint32_t alpha_color);
void framebuffer_context_blend_pixel( framebuffer_context_t * fc,int x,int y,uint32_t alpha_color);

void framebuffer_context_set_clipping(framebuffer_context_t * fc,int x,int y,int w,int h);

void framebuffer_image_draw_line(framebuffer_image_t * fi,int x1, int y1, int x2, int y2, uint32_t color);
void framebuffer_context_draw_line(framebuffer_context_t * fc,int x1, int y1, int x2, int y2, uint32_t color);



void framebuffer_image_draw_circle(framebuffer_image_t * fi,double cx, double cy, int radius, uint32_t linecolor , int do_blend,int linewidth, int do_fill_color,uint32_t fillcolor);
void framebuffer_context_draw_circle(framebuffer_context_t * fc,double cx, double cy, int radius, uint32_t linecolor ,int do_blend, int linewidth, int do_fill_color,uint32_t fillcolor);

void framebuffer_image_make_gray(framebuffer_image_t * fi);
# 11 "project.h" 2
# 1 "d:\\projects/STA/framebuffer_image_new.h" 1




# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 1 3
# 15 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/_mingw.h" 1 3
# 31 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/_mingw.h" 3
       
# 32 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/_mingw.h" 3
# 16 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 2 3





# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stddef.h" 1 3 4
# 212 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stddef.h" 3 4
typedef unsigned int size_t;
# 22 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 2 3
# 112 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 3
   extern __attribute__ ((__dllimport__)) int __mb_cur_max;
# 137 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 3
 int* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _errno(void);


 int* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __doserrno(void);
# 303 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 3
 double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atof (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atoi (const char*);
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atol (const char*);






double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __strtod (const char*, char**);



static

__inline__ double __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
strtod (const char* __restrict__ __nptr, char** __restrict__ __endptr)
{
  return __strtod(__nptr, __endptr);
}
float __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtof (const char * __restrict__, char ** __restrict__);
long double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtold (const char * __restrict__, char ** __restrict__);




 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtol (const char*, char**, int);
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoul (const char*, char**, int);



 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstol (const wchar_t*, wchar_t**, int);
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstoul (const wchar_t*, wchar_t**, int);
 double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstod (const wchar_t*, wchar_t**);

float __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstof( const wchar_t * __restrict__, wchar_t ** __restrict__);
long double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstold (const wchar_t * __restrict__, wchar_t ** __restrict__);


 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wgetenv(const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wputenv(const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsearchenv(const wchar_t*, const wchar_t*, wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsystem(const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wmakepath(wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsplitpath (const wchar_t*, wchar_t*, wchar_t*, wchar_t*, wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfullpath (wchar_t*, const wchar_t*, size_t);




 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstombs (char*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wctomb (char*, wchar_t);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mblen (const char*, size_t);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mbstowcs (wchar_t*, const char*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mbtowc (wchar_t*, const char*, size_t);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rand (void);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) srand (unsigned int);

 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) calloc (size_t, size_t) __attribute__ ((__malloc__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) malloc (size_t) __attribute__ ((__malloc__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) realloc (void*, size_t);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) free (void*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) abort (void) __attribute__ ((__noreturn__));
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) exit (int) __attribute__ ((__noreturn__));


int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atexit (void (*)(void));

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) system (const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getenv (const char*);


 void* __attribute__((__cdecl__)) bsearch (const void*, const void*, size_t, size_t,
          int (*)(const void*, const void*));
 void __attribute__((__cdecl__)) qsort(void*, size_t, size_t,
      int (*)(const void*, const void*));

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) abs (int) __attribute__ ((__const__));
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) labs (long) __attribute__ ((__const__));
# 393 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 3
typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

 div_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) div (int, int) __attribute__ ((__const__));
 ldiv_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ldiv (long, long) __attribute__ ((__const__));
# 505 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdlib.h" 3
void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _Exit(int) __attribute__ ((__noreturn__));





typedef struct { long long quot, rem; } lldiv_t;

lldiv_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) lldiv (long long, long long) __attribute__ ((__const__));

long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) llabs(long long);





long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoll (const char* __restrict__, char** __restrict, int);
unsigned long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoull (const char* __restrict__, char** __restrict__, int);


long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atoll (const char *);
# 6 "d:\\projects/STA/framebuffer_image_new.h" 2






framebuffer_image_t * framebuffer_image_new_malloc(int w,int h);
framebuffer_image_t * framebuffer_image_empty_malloc(framebuffer_image_t * fi);
framebuffer_image_t * framebuffer_image_copy_malloc(framebuffer_image_t * fi);
# 12 "project.h" 2
# 1 "d:\\projects/STA/bmp_24_bits_read_write.h" 1







typedef struct {
    char cfType[2];
    int cfSize;
    int cfReserved;
    int cfoffBits;
} __attribute__((packed)) bitmap_file_header_t;

typedef struct
{
    int ciSize;
    int ciWidth;
    int ciHeight;
    int short ciPlanes;
    int short ciPerPixelBits;
    int ciCompress;
    int ciSizeImage;
    int ciXPixelsPerMeter;
    int ciYPixelsPerMeter;
    int ciClrUsed;
    int ciClrImportant;
} __attribute__((packed)) bitmap_info_header_t;

typedef struct
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} __attribute__((packed)) bitmap_pixel_t;



framebuffer_image_t * bmp_24_bits_read_from_buffer_malloc(void * buffer,uint32_t buffer_size);
framebuffer_image_t * bmp_24_bits_read_from_file_malloc(const char * file_name);

void * bmp_24_bits_write_to_buffer_malloc(framebuffer_context_t * fc,uint32_t * out_buffer_size);
sta_bool_t bmp_24_bits_write_to_file(const char * file_name,framebuffer_context_t * fc);

sta_bool_t framebuffer_image_write_to_file(framebuffer_image_t * fi,const char * file_name);
# 13 "project.h" 2
# 38 "project.h"
# 1 "project.c" 1
# 10 "project.c"
# 1 "d:\\projects/STA\\file_read_write_all.h" 1
# 21 "d:\\projects/STA\\file_read_write_all.h"
void * file_read_all_malloc(const char * file_name,sta_bool_t be_null_term_output,long * out_size);
void * file_binary_read_all_malloc(const char * file_name,long * out_size);
char * file_text_read_all_malloc(const char * file_name);
sta_bool_t file_write_all(const char * file_name,const void * buffer,long buffer_size);
sta_bool_t file_write_all_text(const char * file_name,const char * text);
# 38 "d:\\projects/STA\\file_read_write_all.h"
# 1 "d:\\projects/STA\\/file_read_write_all.c" 1
# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 1 3
# 26 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stddef.h" 1 3 4
# 27 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 2 3

# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stdarg.h" 1 3 4
# 40 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 29 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 2 3
# 129 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
typedef struct _iobuf
{
 char* _ptr;
 int _cnt;
 char* _base;
 int _flag;
 int _file;
 int _charbuf;
 int _bufsiz;
 char* _tmpfname;
} FILE;
# 154 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
extern __attribute__ ((__dllimport__)) FILE _iob[];
# 169 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fopen (const char*, const char*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) freopen (const char*, const char*, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fflush (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fclose (FILE*);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) remove (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rename (const char*, const char*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tmpfile (void);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tmpnam (char*);
# 191 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) setvbuf (FILE*, char*, int, size_t);

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) setbuf (FILE*, char*);
# 204 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_fprintf(FILE*, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_printf(const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_sprintf(char*, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_snprintf(char*, size_t, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vfprintf(FILE*, const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vprintf(const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vsprintf(char*, const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vsnprintf(char*, size_t, const char*, __gnuc_va_list);
# 241 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
static __inline__ __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
int fprintf (FILE *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

static __inline__ __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
int printf (const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vprintf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

static __inline__ __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
int sprintf (char *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

static __inline__ __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
int vfprintf (FILE *__stream, const char *__format, __gnuc_va_list __local_argv)
{
  return __mingw_vfprintf( __stream, __format, __local_argv );
}

static __inline__ __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
int vprintf (const char *__format, __gnuc_va_list __local_argv)
{
  return __mingw_vprintf( __format, __local_argv );
}

static __inline__ __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
int vsprintf (char *__stream, const char *__format, __gnuc_va_list __local_argv)
{
  return __mingw_vsprintf( __stream, __format, __local_argv );
}
# 308 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_fprintf(FILE*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_printf(const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_sprintf(char*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vfprintf(FILE*, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vprintf(const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vsprintf(char*, const char*, __gnuc_va_list);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _snprintf (char*, size_t, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vsnprintf (char*, size_t, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vscprintf (const char*, __gnuc_va_list);
# 331 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) snprintf (char *, size_t, const char *, ...);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsnprintf (char *, size_t, const char *, __gnuc_va_list);

int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vscanf (const char * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfscanf (FILE * __restrict__, const char * __restrict__,
       __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsscanf (const char * __restrict__,
       const char * __restrict__, __gnuc_va_list);







 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fscanf (FILE*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) scanf (const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) sscanf (const char*, const char*, ...);




 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetc (FILE*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgets (char*, int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputc (int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputs (const char*, FILE*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) gets (char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) puts (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ungetc (int, FILE*);







 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _filbuf (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _flsbuf (int, FILE*);



extern inline __attribute__((__gnu_inline__)) int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getc (FILE* __F)
{
  return (--__F->_cnt >= 0)
    ? (int) (unsigned char) *__F->_ptr++
    : _filbuf (__F);
}

extern inline __attribute__((__gnu_inline__)) int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putc (int __c, FILE* __F)
{
  return (--__F->_cnt >= 0)
    ? (int) (unsigned char) (*__F->_ptr++ = (char)__c)
    : _flsbuf (__c, __F);
}

extern inline __attribute__((__gnu_inline__)) int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getchar (void)
{
  return (--(&_iob[0])->_cnt >= 0)
    ? (int) (unsigned char) *(&_iob[0])->_ptr++
    : _filbuf ((&_iob[0]));
}

extern inline __attribute__((__gnu_inline__)) int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putchar(int __c)
{
  return (--(&_iob[1])->_cnt >= 0)
    ? (int) (unsigned char) (*(&_iob[1])->_ptr++ = (char)__c)
    : _flsbuf (__c, (&_iob[1]));}
# 412 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fread (void*, size_t, size_t, FILE*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwrite (const void*, size_t, size_t, FILE*);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fseek (FILE*, long, int);
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ftell (FILE*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rewind (FILE*);
# 455 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
typedef long long fpos_t;




 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetpos (FILE*, fpos_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fsetpos (FILE*, const fpos_t*);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) feof (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ferror (FILE*);
# 480 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) clearerr (FILE*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) perror (const char*);
# 563 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwprintf (FILE*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wprintf (const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _snwprintf (wchar_t*, size_t, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfwprintf (FILE*, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vwprintf (const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vsnwprintf (wchar_t*, size_t, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vscwprintf (const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwscanf (FILE*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wscanf (const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) swscanf (const wchar_t*, const wchar_t*, ...);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetwc (FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputwc (wchar_t, FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ungetwc (wchar_t, FILE*);
# 584 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/stdio.h" 3
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetws (wchar_t*, int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputws (const wchar_t*, FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getwc (FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getwchar (void);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _getws (wchar_t*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putwc (wint_t, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _putws (const wchar_t*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putwchar (wint_t);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfdopen(int, const wchar_t *);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfopen (const wchar_t*, const wchar_t*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfreopen (const wchar_t*, const wchar_t*, FILE*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfsopen (const wchar_t*, const wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtmpnam (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtempnam (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wrename (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wremove (const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wperror (const wchar_t*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wpopen (const wchar_t*, const wchar_t*);



int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) snwprintf (wchar_t* s, size_t n, const wchar_t* format, ...);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsnwprintf (wchar_t* s, size_t n, const wchar_t* format, __gnuc_va_list arg);





int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vwscanf (const wchar_t * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfwscanf (FILE * __restrict__,
         const wchar_t * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vswscanf (const wchar_t * __restrict__,
         const wchar_t * __restrict__, __gnuc_va_list);
# 2 "d:\\projects/STA\\/file_read_write_all.c" 2

# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/string.h" 1 3
# 24 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/string.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/include/stddef.h" 1 3 4
# 25 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/string.h" 2 3
# 36 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/string.h" 3
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memchr (const void*, int, size_t) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memcmp (const void*, const void*, size_t) __attribute__ ((__pure__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memcpy (void*, const void*, size_t);
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memmove (void*, const void*, size_t);
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memset (void*, int, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcat (char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strchr (const char*, int) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcmp (const char*, const char*) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcoll (const char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcpy (char*, const char*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcspn (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strerror (int);

 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strlen (const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncat (char*, const char*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncmp (const char*, const char*, size_t) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncpy (char*, const char*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strpbrk (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strrchr (const char*, int) __attribute__ ((__pure__));
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strspn (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strstr (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtok (char*, const char*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strxfrm (char*, const char*, size_t);
# 126 "c:\\mingw\\bin\\../lib/gcc/i686-pc-mingw32/4.6.3/../../../../include/string.h" 3
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscat (wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcschr (const wchar_t*, wchar_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscpy (wchar_t*, const wchar_t*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscspn (const wchar_t*, const wchar_t*);

 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcslen (const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncat (wchar_t*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncmp(const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncpy(wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcspbrk(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsrchr(const wchar_t*, wchar_t);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsspn(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsstr(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstok(wchar_t*, const wchar_t*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsxfrm(wchar_t*, const wchar_t*, size_t);
# 4 "d:\\projects/STA\\/file_read_write_all.c" 2


 void * file_read_all_malloc(const char * file_name,sta_bool_t be_null_term_output,long * out_size)
{

 FILE * f = fopen(file_name,"rb");
 if(!f)
  return 0;

 if(fseek(f,0,2))
 {
  fclose(f);
  return 0;
 }

 long size = ftell(f);

 void* buffer=0;
 char * text;


    if(size > 0)
 {
  if(be_null_term_output)
  size++;

  if(out_size)
 *out_size = size;

  if(!fseek(f,0,0))
  {

   buffer = malloc(size);
   if(buffer)
   {
    if(!fread(buffer,1,size,f))
    {
     free(buffer);
     fclose(f);
     return 0;
    }
    if(be_null_term_output)
    {
     text = (char*)buffer;
     text[size - 1]=0;
    }

   }
  }

 }
 fclose(f);
 return buffer;
}

void * file_binary_read_all_malloc(const char * file_name,long * out_size)
{
 return file_read_all_malloc(file_name,0,out_size);
}
char * file_text_read_all_malloc(const char * file_name)
{
 return (char * ) file_read_all_malloc(file_name,1,0);
}


sta_bool_t file_write_all(const char * file_name,const void * buffer,long buffer_size)
{
 FILE * f=fopen(file_name,"wb");
 if(f)
 {
  if(fwrite(buffer,1,buffer_size,f) == buffer_size)
  {
  fclose(f);
  return 1;
  }
  fclose(f);
 }

 return 0;
}
sta_bool_t file_write_all_text(const char * file_name,const char * text)
{
 return file_write_all(file_name,text,strlen(text));
}
# 39 "d:\\projects/STA\\file_read_write_all.h" 2
# 11 "project.c" 2
# 39 "project.h" 2
# 2 "main.c" 2


int main(int argc, const char * argv[])
{

if(argc != 5)
{
 puts("error:usage bin2part.exe out_filename.ext in_filename.ext start size");
 return 0;
}
  long file_size;
  char * file_data;
        long start=atoi(argv[3]);
  long size = atoi(argv[4]);

   file_data = (char*)file_binary_read_all_malloc(argv[2],&file_size);
   if(file_data)
   {
if(start >= file_size || start + size > file_size)
{
 puts("error:start or size cross file size.");
 free(file_data);
 return 0;
}
    if(!file_write_all(argv[1],&file_data[start],size))
     puts("error:can't create output file.");

    free(file_data);
   }
   else
    puts("error:can't read input file.");

 return 0;
}
