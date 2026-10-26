/*
 * FUN_00412dad at 00412dad
 * undefined __cdecl FUN_00412dad(int param_1)
 * Address ranges: 00412dad-00412ecd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00412dad(int param_1)

{
  int local_8;
  
  local_8 = 0;
  if (DAT_0043d850 != 0) {
    FUN_00412ca1();
  }
  DAT_0043d850 = param_1;
  DAT_00434008 = 0xffffffff;
  DAT_0043d84c = 0;
  for (; *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) != -1; local_8 = local_8 + 1) {
    if ((*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) ||
       ((&DAT_0043db90)[*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c] == '\0')) {
      FUN_0040187a((byte *)s__s__d_____destroy_form__Unused_c_00434b50);
    }
    else if (*(int *)(&DAT_0043db94 + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c) != 0) {
      (**(code **)(&DAT_0043db94 + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c))
                (DAT_0043d850 + local_8 * 0x1c,local_8);
    }
    DAT_0043d84c = DAT_0043d84c + 1;
  }
  DAT_0043d84c = DAT_0043d84c + -1;
  return;
}

