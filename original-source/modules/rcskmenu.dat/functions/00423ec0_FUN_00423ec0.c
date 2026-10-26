/*
 * FUN_00423ec0 at 00423ec0
 * undefined FUN_00423ec0(void)
 * Address ranges: 00423ec0-00423f2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423ec0(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint *puVar2;
  uint auStack_98 [35];
  
  if (((PTR_DAT_0047c9d8[8] == '\0') || (*(int *)PTR_DAT_0047c9d4 == 2)) ||
     ((*(byte *)((int)param_2 + 5) & 8) == 0)) {
    FUN_00442aac(param_1,param_2);
  }
  else {
    puVar2 = auStack_98;
    for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    auStack_98[1] = auStack_98[1] & 0xfffff7ff;
    FUN_00442aac(param_1,auStack_98);
    if (*(HWND *)(param_1 + 0x14c) != (HWND)0x0) {
      SendMessageA(*(HWND *)(param_1 + 0x14c),0xcf,1,0);
    }
  }
  return;
}

