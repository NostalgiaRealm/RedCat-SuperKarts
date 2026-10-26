/*
 * FUN_004084f5 at 004084f5
 * undefined __fastcall FUN_004084f5(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004084f5-00408532
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004084f5(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_FS_OFFSET;
  undefined8 uVar2;
  
  uVar2 = (*(code *)PTR_FUN_0040ef44)(param_2);
  *(int *)((int)uVar2 + 0x54) = (int)((ulonglong)uVar2 >> 0x20);
  uVar2 = (*(code *)PTR_FUN_0040ef44)();
  **(undefined4 **)((int)uVar2 + 0x54) = (int)((ulonglong)uVar2 >> 0x20);
  iVar1 = (*(code *)PTR_FUN_0040ef44)();
  *(undefined **)(*(int *)(iVar1 + 0x54) + 4) = &DAT_00408142;
  uVar2 = (*(code *)PTR_FUN_0040ef44)();
  *(undefined4 *)(unaff_FS_OFFSET + (int)((ulonglong)uVar2 >> 0x20)) =
       *(undefined4 *)((int)uVar2 + 0x54);
  return;
}

