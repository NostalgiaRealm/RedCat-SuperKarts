/*
 * FUN_0040bd51 at 0040bd51
 * int __cdecl FUN_0040bd51(int param_1)
 * Address ranges: 0040bd51-0040bdc5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0040bd51(int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (DAT_0043d6d8 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_sprite_index__d_00431e08);
  }
  iVar1 = *(int *)(DAT_0043d6d4 + 0x10 + param_1 * 0x18);
  if ((iVar1 < 0) || (DAT_00431b64 <= iVar1)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_index_00431e38);
  }
  return iVar1;
}

