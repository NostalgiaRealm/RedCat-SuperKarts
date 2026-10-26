/*
 * FUN_0040c531 at 0040c531
 * undefined4 __cdecl FUN_0040c531(int param_1)
 * Address ranges: 0040c531-0040c59e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040c531(int param_1)

{
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00432110);
  }
  if (*(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20) == 2) {
    FUN_004027f9(*(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20),
                 *(undefined4 *)(DAT_0043d6e8 + param_1 * 0x20));
  }
  return 0;
}

