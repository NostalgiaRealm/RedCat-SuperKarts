/*
 * FUN_00461b20 at 00461b20
 * undefined __register FUN_00461b20(int param_1)
 * Address ranges: 00461b20-00461b40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461b20(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    FUN_00461b44(param_1,uVar1,'\0');
    uVar1 = uVar1 + 1;
  } while ((char)uVar1 != '\x06');
  FUN_00461d74(param_1);
  return;
}

