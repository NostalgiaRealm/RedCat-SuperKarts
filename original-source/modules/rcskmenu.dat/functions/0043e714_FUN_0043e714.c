/*
 * FUN_0043e714 at 0043e714
 * undefined4 __register FUN_0043e714(int param_1)
 * Address ranges: 0043e714-0043e747
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043e714(int param_1)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  undefined1 uVar4;
  
  cVar1 = FUN_00426854(param_1);
  uVar4 = cVar1 == '\0';
  if (!(bool)uVar4) {
    iVar2 = FUN_0040303c(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
    puVar3 = FUN_00403ee0(*(uint **)(*(int *)(param_1 + 0x18) + 0x70),*(uint **)(iVar2 + 0x60));
    if ((bool)uVar4) {
      return CONCAT31((int3)((uint)puVar3 >> 8),1);
    }
  }
  return 0;
}

