/*
 * FUN_00413c47 at 00413c47
 * int * __cdecl FUN_00413c47(LPCSTR param_1, int * param_2, int * param_3)
 * Address ranges: 00413c47-00413dec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl FUN_00413c47(LPCSTR param_1,int *param_2,int *param_3)

{
  FILE *pFVar1;
  char local_388 [768];
  int *local_88;
  char local_84;
  char local_83;
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  short local_42;
  
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    local_88 = (int *)0x0;
  }
  else {
    if (DAT_0043d754 != 0) {
      FUN_00413622((int *)pFVar1,local_388);
    }
    FUN_00409b18((int *)pFVar1,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)pFVar1);
    FUN_004015a6((byte *)s__s__d____header_read__00434cf4);
    if ((pFVar1->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00434d1c);
      if ((local_84 == '\n') && (local_83 == '\x05')) {
        *param_2 = ((int)local_7c - (int)local_80) + 1;
        *param_3 = ((int)local_7a - (int)local_7e) + 1;
        FUN_004015a6((byte *)s_creating_surface__d__d_00434d40);
        local_88 = (int *)FUN_004028e3(*param_2,*param_3);
        FUN_004015a6((byte *)s_creation_succesfull_00434d58);
        FUN_00414f40(local_88,(undefined4 *)pFVar1,(int)local_42,*param_3);
      }
      FUN_004015a6((byte *)s__s__d____closing_00434d7c);
      FUN_00409f20(pFVar1);
    }
    else {
      FUN_00409f20(pFVar1);
      local_88 = (int *)0x0;
    }
  }
  return local_88;
}

