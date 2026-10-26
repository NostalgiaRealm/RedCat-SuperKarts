/*
 * FUN_0040ba4c at 0040ba4c
 * int __cdecl FUN_0040ba4c(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040ba4c-0040bae7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0040ba4c(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 < 0) || (DAT_00431b64 <= param_3)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_array_00431c0c);
  }
  if (DAT_0043d6f4 == 0) {
    FUN_0040187a((byte *)s__s__d____get_ysize_of_mem_image_w_00431c4c);
  }
  if (*(int *)(DAT_0043d6e8 + 0xc + param_3 * 0x20) < 1) {
    FUN_0040187a((byte *)s__s__d____suspect_illegal_image_y_00431c84);
  }
  return DAT_0043d6e8 + 0xc + param_3 * 0x20;
}

