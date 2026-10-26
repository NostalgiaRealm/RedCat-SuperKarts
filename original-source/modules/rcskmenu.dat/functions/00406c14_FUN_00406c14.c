/*
 * FUN_00406c14 at 00406c14
 * uint __register FUN_00406c14(uint param_1, uint param_2)
 * Address ranges: 00406c14-00406c1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00406c14(uint param_1,uint param_2)

{
  return param_1 | (param_2 & 0xff0000) << 8;
}

