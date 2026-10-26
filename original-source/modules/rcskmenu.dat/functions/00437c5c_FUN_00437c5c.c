/*
 * FUN_00437c5c at 00437c5c
 * undefined4 __register FUN_00437c5c(int param_1)
 * Address ranges: 00437c5c-00437c89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00437c5c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 0x58); (iVar1 != 0 && (*(int *)(iVar1 + 0x70) == 0));
      iVar1 = *(int *)(iVar1 + 0x58)) {
  }
  if (iVar1 == 0) {
    iVar1 = thunk_FUN_004385f4(param_1);
    if (iVar1 != 0) {
      uVar2 = *(undefined4 *)(iVar1 + 0x3c);
    }
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x70);
  }
  return uVar2;
}

