#include <stdbool.h>
#define XM_STRUCT_HEADER(xm_name_xm) typedef struct xmacros_##xm_name_xm xm_name_xm; \
                                     struct xmacros_##xm_name_xm {

#define XM_STRUCT_MEMBER_INT(xm_name_xm) int xm_name_xm;
#define XM_STRUCT_MEMBER_CHAR(xm_name_xm) char xm_name_xm;
#define XM_STRUCT_MEMBER_CHAR_STAR(xm_name_xm) char* xm_name_xm;
#define XM_STRUCT_MEMBER_LONG(xm_name_xm) long xm_name_xm;
#define XM_STRUCT_MEMBER_SHORT(xm_name_xm) short xm_name_xm;
#define XM_STRUCT_MEMBER_BOOL(xm_name_xm) bool xm_name_xm;

//#define XM_STRUCT_MEMBER_CUSTOM_T(xm_name_xm)  xm_name_xm;


#define XM_STRUCT_FOOTER };
