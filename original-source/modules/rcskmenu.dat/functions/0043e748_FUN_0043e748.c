/*
 * FUN_0043e748 at 0043e748
 * undefined4 __register FUN_0043e748(int param_1)
 * Address ranges: 0043e748-0043e776
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043e748(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00426890(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (*(char *)(iVar2 + 0x6a) == *(char *)(*(int *)(param_1 + 0x18) + 0x47)) {
      return CONCAT31((int3)((uint)iVar2 >> 8),1);
    }
  }
  return 0;
}

