/*
 * FUN_00435f0c at 00435f0c
 * undefined4 __register FUN_00435f0c(int param_1)
 * Address ranges: 00435f0c-00435f3a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435f0c(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00426840(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (*(int *)(iVar2 + 0x5c) == *(int *)(*(int *)(param_1 + 0x18) + 0x48)) {
      return CONCAT31((int3)((uint)*(int *)(iVar2 + 0x5c) >> 8),1);
    }
  }
  return 0;
}

