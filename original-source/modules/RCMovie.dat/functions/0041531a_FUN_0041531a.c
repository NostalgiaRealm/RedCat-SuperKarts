/*
 * FUN_0041531a at 0041531a
 * undefined4 __cdecl FUN_0041531a(int param_1, undefined4 * param_2)
 * Address ranges: 0041531a-00415411
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0041531a(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_8;
  
  if (DAT_0043db84 == 0) {
    FUN_0040187a((byte *)s__s__d____current_ascii_set_not_d_00435428);
  }
  if ((param_1 < 0) || (*(int *)(DAT_0043db88 + 100) <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00435460);
  }
  iVar1 = *(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_1 * 0xc);
  if (iVar1 == 0) {
    FUN_0040187a((byte *)s__s__d____locking_ascii_char_that_004354a0);
  }
  else if (iVar1 == 1) {
    local_8 = FUN_00402631((int *)**(undefined4 **)(*(int *)(DAT_0043db88 + 0x68) + param_1 * 0xc),
                           param_2);
  }
  else if (iVar1 == 2) {
    local_8 = FUN_00402631(*(int **)(DAT_0043d6e8 + 4 +
                                    *(int *)(*(int *)(DAT_0043db88 + 0x68) + 4 + param_1 * 0xc) *
                                    0x20),param_2);
  }
  return local_8;
}

