/*
 * FUN_00453594 at 00453594
 * undefined4 __register FUN_00453594(int param_1, uint param_2)
 * Address ranges: 00453594-0045359e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00453594(int param_1,uint param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x24 + (param_2 & 0x7f) * 4) + 0x10);
}

