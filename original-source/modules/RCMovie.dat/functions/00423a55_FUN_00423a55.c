/*
 * FUN_00423a55 at 00423a55
 * undefined __cdecl FUN_00423a55(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3, undefined4 param_4, int param_5, int param_6, int param_7, PVOID param_8)
 * Address ranges: 00423a55-00423afc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_00423a55(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3,undefined4 param_4,
            int param_5,int param_6,int param_7,PVOID param_8)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint local_c;
  uint local_8;
  
  if ((DAT_0043e460 != 0) &&
     (iVar1 = FUN_004200cc(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar1 != 0)) {
    return;
  }
  piVar2 = (int *)FUN_004201f5(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar2 <= param_6) && (param_6 <= piVar2[1])) {
      iVar3 = piVar2[3] * 0x10 + piVar2[4];
      iVar1 = *(int *)(iVar3 + -0xc);
      if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
        FUN_00423c0e(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar3 + -0x10),(byte *)0x0,
                     piVar2,param_7,param_8);
      }
    }
    piVar2 = piVar2 + 5;
  }
  return;
}

