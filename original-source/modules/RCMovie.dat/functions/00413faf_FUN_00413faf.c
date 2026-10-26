/*
 * FUN_00413faf at 00413faf
 * int * __cdecl FUN_00413faf(LPCSTR param_1, int * param_2, int * param_3, undefined4 param_4)
 * Address ranges: 00413faf-00414158
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl FUN_00413faf(LPCSTR param_1,int *param_2,int *param_3,undefined4 param_4)

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
    FUN_004015a6((byte *)s__s__d____header_read__00434e44);
    if ((pFVar1->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00434e6c);
      if ((local_84 == '\n') && (local_83 == '\x05')) {
        *param_2 = ((int)local_7c - (int)local_80) + 1;
        *param_3 = ((int)local_7a - (int)local_7e) + 1;
        FUN_004015a6((byte *)s_creating_surface__d__d_00434e90);
        local_88 = (int *)FUN_00402a32(*param_2,*param_3,param_4);
        FUN_004015a6((byte *)s_creation_succesfull_00434ea8);
        FUN_00414f40(local_88,(undefined4 *)pFVar1,(int)local_42,*param_3);
      }
      FUN_004015a6((byte *)s__s__d____closing_00434ecc);
      FUN_00409f20(pFVar1);
    }
    else {
      FUN_00409f20(pFVar1);
      local_88 = (int *)0x0;
    }
  }
  return local_88;
}

