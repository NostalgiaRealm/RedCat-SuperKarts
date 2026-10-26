/*
 * FUN_004414e8 at 004414e8
 * undefined4 __register FUN_004414e8(int * param_1)
 * Address ranges: 004414e8-00441513
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004414e8(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x24] != 0) {
    iVar1 = (**(code **)(*param_1 + 0x54))();
    uVar2 = FUN_00403024((int *)param_1[0x24],iVar1);
    if ((char)uVar2 != '\0') {
      return CONCAT31((int3)((uint)uVar2 >> 8),1);
    }
  }
  return 0;
}

