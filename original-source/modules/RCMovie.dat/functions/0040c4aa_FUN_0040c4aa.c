/*
 * FUN_0040c4aa at 0040c4aa
 * undefined4 __cdecl FUN_0040c4aa(int param_1, undefined4 * param_2)
 * Address ranges: 0040c4aa-0040c530
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040c4aa(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_004320d0);
  }
  if (*(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20) == 2) {
    uVar1 = FUN_00402631(*(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20),param_2);
    *(undefined4 *)(DAT_0043d6e8 + param_1 * 0x20) = uVar1;
  }
  else {
    *param_2 = *(undefined4 *)(DAT_0043d6e8 + 8 + param_1 * 0x20);
  }
  return 0;
}

