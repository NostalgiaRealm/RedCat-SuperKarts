/*
 * FUN_00442020 at 00442020
 * undefined4 __register FUN_00442020(void)
 * Address ranges: 00442020-0044206e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00442020(void)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 uVar3;
  int *piVar4;
  int in_stack_00000004;
  
  piVar4 = (int *)(in_stack_00000004 + -0x10);
  uVar3 = CONCAT31((int3)((uint)unaff_EBX >> 8),1);
  iVar1 = FUN_0044268c(*piVar4);
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    do {
      iVar2 = FUN_00442650(*piVar4,iVar1);
      if (*(char *)(iVar2 + 0x4b) != '\0') {
        return uVar3;
      }
      iVar2 = FUN_00442650(*piVar4,iVar1);
      if (*(char *)(iVar2 + 0x51) != '\x03') {
        return uVar3;
      }
      iVar1 = iVar1 + -1;
    } while (iVar1 != -1);
  }
  return 0;
}

