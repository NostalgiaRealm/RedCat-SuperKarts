/*
 * FUN_00415412 at 00415412
 * undefined4 __cdecl FUN_00415412(int param_1, undefined4 param_2)
 * Address ranges: 00415412-00415500
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00415412(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_0043db84 == 0) {
    FUN_0040187a((byte *)s__s__d____current_ascii_set_not_d_004354e4);
  }
  if ((param_1 < 0) || (*(int *)(DAT_0043db88 + 100) <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_0043551c);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_1 * 0xc);
  if (iVar1 == 0) {
    FUN_0040187a((byte *)s__s__d____unlocking_ascii_char_th_0043555c);
  }
  else if (iVar1 == 1) {
    FUN_004027f9((int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_1 * 0xc),param_2);
  }
  else if (iVar1 == 2) {
    FUN_004027f9(*(int **)(DAT_0043d6e8 + 4 +
                          *(int *)(*(int *)(DAT_0043db88 + 0x68) + 4 + param_1 * 0xc) * 0x20),
                 param_2);
  }
  return 0;
}

