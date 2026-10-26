/*
 * FUN_00408533 at 00408533
 * undefined __fastcall FUN_00408533(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408533-00408581
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00408533(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *unaff_FS_OFFSET;
  
  iVar1 = (*(code *)PTR_FUN_0040ef44)(param_2);
  if (*(undefined4 **)(iVar1 + 0x54) != (undefined4 *)0x0) {
    *unaff_FS_OFFSET = **(undefined4 **)(iVar1 + 0x54);
  }
  iVar1 = (*(code *)PTR_FUN_0040ef44)();
  *(undefined4 *)(iVar1 + 0x54) = 0;
  iVar1 = FUN_00407eeb();
  if (iVar1 != 0) {
    FUN_00407f56(extraout_ECX,extraout_EDX);
    iVar1 = (*(code *)PTR_FUN_0040ef44)();
    *(undefined4 *)(iVar1 + 0x78) = 2;
    iVar1 = (*(code *)PTR_FUN_0040ef44)();
    *(undefined4 *)(iVar1 + 0x90) = 2;
  }
  return;
}

