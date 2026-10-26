/*
 * FUN_00432910 at 00432910
 * int * __register FUN_00432910(int param_1)
 * Address ranges: 00432910-00432993
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00432910(int param_1)

{
  int *piVar1;
  HANDLE pvVar2;
  undefined4 extraout_EDX;
  tagPOINT tStack_14;
  
  GetCursorPos(&tStack_14);
  piVar1 = FUN_0043e0b0(&tStack_14,CONCAT31((int3)((uint)extraout_EDX >> 8),1));
  if ((piVar1 != (int *)0x0) && ((*(byte *)(piVar1 + 8) & 0x10) != 0)) {
    piVar1 = (int *)0x0;
  }
  pvVar2 = FUN_0043caec();
  if (piVar1 != *(int **)(param_1 + 0x3c)) {
    if (((*(int *)(param_1 + 0x3c) != 0) && (pvVar2 == (HANDLE)0x0)) ||
       ((pvVar2 != (HANDLE)0x0 && (pvVar2 == *(HANDLE *)(param_1 + 0x3c))))) {
      FUN_004405f0(*(int *)(param_1 + 0x3c),0xb014,0,0);
    }
    *(int **)(param_1 + 0x3c) = piVar1;
    if (((*(int *)(param_1 + 0x3c) != 0) && (pvVar2 == (HANDLE)0x0)) ||
       ((pvVar2 != (HANDLE)0x0 && (pvVar2 == *(HANDLE *)(param_1 + 0x3c))))) {
      FUN_004405f0(*(int *)(param_1 + 0x3c),0xb013,0,0);
    }
  }
  return piVar1;
}

