/*
 * FUN_00413ad2 at 00413ad2
 * undefined4 __cdecl FUN_00413ad2(int param_1, LPCSTR param_2, uint param_3)
 * Address ranges: 00413ad2-00413c46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00413ad2(int param_1,LPCSTR param_2,uint param_3)

{
  FILE *pFVar1;
  undefined4 uVar2;
  char local_38c [768];
  int local_8c;
  int local_88;
  char local_84;
  char local_83;
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  short local_42;
  
  pFVar1 = (FILE *)FUN_00409d69(param_2);
  if (pFVar1 == (FILE *)0x0) {
    uVar2 = 1000;
  }
  else {
    if ((param_3 & 2) != 0) {
      FUN_00413622((int *)pFVar1,local_38c);
    }
    FUN_00409b18((int *)pFVar1,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)pFVar1);
    if ((pFVar1->_flag & 0x20U) == 0) {
      if ((((param_3 & 1) != 0) && (local_84 == '\n')) && (local_83 == '\x05')) {
        local_8c = ((int)local_7a - (int)local_7e) + 1;
        local_88 = ((int)local_7c - (int)local_80) + 1;
        if (DAT_0042c354 < local_8c) {
          local_8c = DAT_0042c354;
        }
        FUN_004015a6((byte *)s_bpl__d__width__d_00434cd4);
        FUN_00414a90(param_1,(undefined4 *)pFVar1,(int)local_42,local_8c);
      }
      if ((param_3 & 6) == 6) {
        FUN_0040e96f((void *)0x6,DAT_0043d760,0,0x100);
      }
      FUN_00409f20(pFVar1);
      uVar2 = 0;
    }
    else {
      FUN_0041f368(pFVar1);
      uVar2 = 0x3e9;
    }
  }
  return uVar2;
}

