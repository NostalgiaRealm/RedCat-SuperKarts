/*
 * FUN_0040c43d at 0040c43d
 * undefined4 __cdecl FUN_0040c43d(int param_1)
 * Address ranges: 0040c43d-0040c4a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040c43d(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00432090);
  }
  if (*(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20) == 2) {
    uVar1 = FUN_0040235c(*(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20));
    *(undefined4 *)(DAT_0043d6e8 + param_1 * 0x20) = uVar1;
  }
  return 0;
}

