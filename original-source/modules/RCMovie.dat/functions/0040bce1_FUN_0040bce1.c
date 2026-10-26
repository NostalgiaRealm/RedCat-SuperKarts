/*
 * FUN_0040bce1 at 0040bce1
 * undefined __cdecl FUN_0040bce1(int param_1, int param_2)
 * Address ranges: 0040bce1-0040bd50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040bce1(int param_1,int param_2)

{
  if ((param_1 < 0) || (DAT_0043d6d8 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_sprite_index__d_00431da4);
  }
  if ((param_2 < 0) || (DAT_00431b64 <= param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_index_00431dd4);
  }
  *(int *)(DAT_0043d6d4 + 0x10 + param_1 * 0x18) = param_2;
  return;
}

