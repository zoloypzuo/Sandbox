add_library(gorilla_audio

"./include/gorilla/ga.h"
"./include/gorilla/gau.h"
"./include/gorilla/ga_internal.h"
"./include/gorilla/common/gc_common.h"
"./include/gorilla/common/gc_thread.h"
"./include/gorilla/common/gc_types.h"
"./include/gorilla/devices/ga_openal.h"
"./include/gorilla/devices/ga_xaudio2.h"

"./src/ga.c"
"./src/gau.c"
"./src/ga_stream.c"
"./src/common/gc_common.c"
"./src/common/gc_thread.c"
"./src/devices/ga_openal.c"
"./src/devices/ga_xaudio2.c"
)
