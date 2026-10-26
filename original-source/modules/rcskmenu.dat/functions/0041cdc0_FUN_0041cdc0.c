/*
 * FUN_0041cdc0 at 0041cdc0
 * undefined4 __register FUN_0041cdc0(int param_1)
 * Address ranges: 0041cdc0-0041cde8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041cdc0(int param_1)

{
  int iVar1;
  undefined3 uVar3;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x20);
  uVar3 = (undefined3)((uint)iVar1 >> 8);
  if ((*(int *)(iVar1 + 8) == 0) || (*(int *)(iVar1 + 8) == *(int *)(iVar1 + 0x14))) {
    if (*(int *)(iVar1 + 0x14) != 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 0x30) == 0) {
      uVar2 = CONCAT31(uVar3,1);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = CONCAT31(uVar3,1);
  }
  return uVar2;
}

