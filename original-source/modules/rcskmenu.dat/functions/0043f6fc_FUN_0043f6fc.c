/*
 * FUN_0043f6fc at 0043f6fc
 * undefined __register FUN_0043f6fc(int param_1)
 * Address ranges: 0043f6fc-0043f737
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f6fc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined1 *)(param_1 + 0x49) = 0;
  *(undefined1 *)(param_1 + 0x46) = 0;
  iVar1 = FUN_004178b0(*(int *)(param_1 + 0x58));
  if (iVar1 != *(int *)(param_1 + 0x74)) {
    *(byte *)(param_1 + 0x88) = *(byte *)(param_1 + 0x88) | 0x10;
    uVar2 = FUN_004178b0(*(int *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x74) = uVar2;
  }
  FUN_004405f0(param_1,0xb00e,0,0);
  return;
}

