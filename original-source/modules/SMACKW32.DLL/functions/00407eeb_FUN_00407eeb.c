/*
 * FUN_00407eeb at 00407eeb
 * undefined4 __stdcall FUN_00407eeb(void)
 * Address ranges: 00407eeb-00407f29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00407eeb(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_0040ef44)();
  if ((*(int *)(iVar1 + 0x78) != 2) &&
     (iVar1 = (*(code *)PTR_FUN_0040ef44)(), *(int *)(iVar1 + 0x78) != 3)) {
    return 1;
  }
  iVar1 = (*(code *)PTR_FUN_0040ef44)();
  if ((*(int *)(iVar1 + 0x90) != 2) &&
     (iVar1 = (*(code *)PTR_FUN_0040ef44)(), *(int *)(iVar1 + 0x90) != 3)) {
    return 1;
  }
  return 0;
}

