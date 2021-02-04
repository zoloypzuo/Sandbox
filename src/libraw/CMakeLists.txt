add_library(libraw

"./include/internal/defines.h"
"./include/internal/libraw_bytebuffer.h"
"./include/internal/libraw_internal_funcs.h"
"./include/internal/var_defines.h"
"./include/libraw/libraw.h"
"./include/libraw/libraw_alloc.h"
"./include/libraw/libraw_const.h"
"./include/libraw/libraw_datastream.h"
"./include/libraw/libraw_internal.h"
"./include/libraw/libraw_types.h"
"./include/libraw/libraw_version.h"

"./src/dcb_demosaicing.c"
)
