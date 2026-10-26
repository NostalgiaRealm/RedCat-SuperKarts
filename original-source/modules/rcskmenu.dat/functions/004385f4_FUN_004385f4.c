/*
 * FUN_004385f4 at 004385f4
 * undefined4 __register FUN_004385f4(int param_1)
 * Address ranges: 004385f2-004385fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004385f4(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = param_1;
    param_1 = *(int *)(iVar1 + 0x58);
  } while (param_1 != 0);
  return *(undefined4 *)(iVar1 + 100);
}

