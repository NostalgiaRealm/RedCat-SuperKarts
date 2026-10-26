/*
 * FUN_00435f3c at 00435f3c
 * undefined4 __register FUN_00435f3c(int param_1)
 * Address ranges: 00435f3c-00435f6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435f3c(int param_1)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  undefined1 uVar4;
  
  cVar1 = FUN_00426854(param_1);
  uVar4 = cVar1 == '\0';
  if (!(bool)uVar4) {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    puVar3 = FUN_00403ee0(*(uint **)(*(int *)(param_1 + 0x18) + 0x4c),*(uint **)(iVar2 + 0x60));
    if ((bool)uVar4) {
      return CONCAT31((int3)((uint)puVar3 >> 8),1);
    }
  }
  return 0;
}

