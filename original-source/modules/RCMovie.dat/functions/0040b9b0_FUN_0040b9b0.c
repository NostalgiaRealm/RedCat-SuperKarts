/*
 * FUN_0040b9b0 at 0040b9b0
 * int __cdecl FUN_0040b9b0(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040b9b0-0040ba4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0040b9b0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 < 0) || (DAT_00431b64 <= param_3)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_array_00431b68);
  }
  if (DAT_0043d6f4 == 0) {
    FUN_0040187a((byte *)s__s__d____get_xsize_of_mem_image_w_00431ba8);
  }
  if (*(int *)(DAT_0043d6e8 + 8 + param_3 * 0x20) < 1) {
    FUN_0040187a((byte *)s__s__d____suspect_illegal_image_x_00431be0);
  }
  return DAT_0043d6e8 + 8 + param_3 * 0x20;
}

