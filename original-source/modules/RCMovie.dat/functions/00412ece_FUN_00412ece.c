/*
 * FUN_00412ece at 00412ece
 * undefined4 __stdcall FUN_00412ece(void)
 * Address ranges: 00412ece-00412f43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00412ece(void)

{
  HWND pHVar1;
  int iVar2;
  
  pHVar1 = GetFocus();
  if (((pHVar1 != DAT_0043842c) && (iVar2 = FUN_004120d6(), iVar2 != -1)) &&
     (*(int *)(&DAT_0043dba4 + *(int *)(DAT_0043d850 + 8 + iVar2 * 0x1c) * 0x1c) != 0)) {
    (**(code **)(&DAT_0043dba4 + *(int *)(DAT_0043d850 + 8 + iVar2 * 0x1c) * 0x1c))
              (DAT_0043d850 + iVar2 * 0x1c);
  }
  return 1;
}

