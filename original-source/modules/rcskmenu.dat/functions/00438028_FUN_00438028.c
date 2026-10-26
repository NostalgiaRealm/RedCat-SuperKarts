/*
 * FUN_00438028 at 00438028
 * undefined __register FUN_00438028(int param_1, byte param_2)
 * Address ranges: 00438028-00438068
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00438028(int param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != *(byte *)(param_1 + 0x33)) {
    iVar1 = *(int *)(param_1 + 0x58);
    if (iVar1 != 0) {
      iVar2 = FUN_004383a0(iVar1,param_1);
      FUN_004366d4(iVar1,iVar2,param_2);
    }
    *(byte *)(param_1 + 0x33) = param_2;
    if ((*(char *)(param_1 + 0x2c) != '\0') && (*(char *)(param_1 + 0x31) != '\0')) {
      FUN_00437f14(param_1);
    }
  }
  return;
}

