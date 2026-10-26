/*
 * FUN_0040bae8 at 0040bae8
 * int __cdecl FUN_0040bae8(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040bae8-0040bb4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0040bae8(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 < 0) || (DAT_00431b64 <= param_3)) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_image_array_00431cb0);
  }
  if (DAT_0043d6f4 == 0) {
    FUN_0040187a((byte *)s__s__d____get_mx_of_mem_image_whi_00431cec);
  }
  return DAT_0043d6e8 + 0x10 + param_3 * 0x20;
}

