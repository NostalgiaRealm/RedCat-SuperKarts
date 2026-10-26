/*
 * FUN_0043e3f8 at 0043e3f8
 * undefined __register FUN_0043e3f8(int param_1)
 * Address ranges: 0043e3f8-0043e420
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e3f8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    uVar1 = FUN_0043fc2c(*(int *)(param_1 + 0x58));
    if ((char)uVar1 == '\0') {
      *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xffffff7f;
    }
    else {
      *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 0x80;
    }
  }
  return;
}

