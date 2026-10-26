/*
 * FUN_00429a44 at 00429a44
 * undefined __register FUN_00429a44(int param_1)
 * Address ranges: 00429a44-00429a7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429a44(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    uVar1 = FUN_00429bfc(param_1);
    if ((char)uVar1 != '\0') {
      uVar1 = FUN_0043fc5c(*(int *)(param_1 + 4));
      if ((char)uVar1 == '\0') {
        FUN_0042a14c(param_1,0);
      }
      else {
        FUN_0042a14c(param_1,*(int *)(param_1 + 0x10));
      }
    }
  }
  return;
}

