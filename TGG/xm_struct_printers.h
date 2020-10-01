#include <stdbool.h>
#define XM_STRUCT_HEADER(xm_name_xm) void print_##xm_name_xm(xm_name_xm* record) {\
                                               printf("--STRUCT '"#xm_name_xm"'\n");

#define XM_STRUCT_MEMBER_INT(xm_name_xm)       printf("int   " #xm_name_xm ": %d\n", record->xm_name_xm);
#define XM_STRUCT_MEMBER_CHAR(xm_name_xm)      printf("char  " #xm_name_xm ": %c\n", record->xm_name_xm);
#define XM_STRUCT_MEMBER_CHAR_STAR(xm_name_xm) printf("char* " #xm_name_xm ": %s\n", record->xm_name_xm);
#define XM_STRUCT_MEMBER_LONG(xm_name_xm)      printf("long  " #xm_name_xm ": %ld\n", record->xm_name_xm);
#define XM_STRUCT_MEMBER_SHORT(xm_name_xm)     printf("short " #xm_name_xm ": %hd\n", record->xm_name_xm);
#define XM_STRUCT_MEMBER_BOOL(xm_name_xm)      printf("bool  " #xm_name_xm ": %d\n", record->xm_name_xm);

//#define XM_STRUCT_MEMBER_CUSTOM_T(xm_name_xm)  printf("CUSTOM_T "#xm_name_xm":\n\t.x: %d\n\t.y: %d\n\t.z: %d\n" \
                                               , record->xm_name_xm.x, record->xm_name_xm.y, record->xm_name_xm.z);

#define XM_STRUCT_FOOTER                       printf("--END OF STRUCT\n\n");\
                                               }
