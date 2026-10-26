/*
 * FUN_00406810 at 00406810
 * undefined FUN_00406810(void)
 * Address ranges: 00406810-00406837
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00406810(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  
  if (*(int *)(param_2 + 0x38) != 0) {
    lVar2 = FUN_00406ce0(param_1,param_2);
    param_2 = (uint)((ulonglong)lVar2 >> 0x20);
  }
  *(undefined4 *)(param_2 + 100) = 0;
  uVar1 = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)(param_2 + 0x60) = uVar1;
  *(undefined4 *)(param_2 + 0x5c) = uVar1;
  *(undefined4 *)(param_2 + 0x50) = uVar1;
  return;
}

