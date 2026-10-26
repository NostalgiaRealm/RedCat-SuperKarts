/*
 * FUN_00435f70 at 00435f70
 * undefined4 __register FUN_00435f70(int param_1)
 * Address ranges: 00435f70-00435f9e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435f70(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00426868(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    if (*(int *)(iVar2 + 100) == *(int *)(*(int *)(param_1 + 0x18) + 0x34)) {
      return CONCAT31((int3)((uint)*(int *)(iVar2 + 100) >> 8),1);
    }
  }
  return 0;
}

