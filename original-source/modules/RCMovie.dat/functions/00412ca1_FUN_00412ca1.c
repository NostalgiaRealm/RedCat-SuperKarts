/*
 * FUN_00412ca1 at 00412ca1
 * undefined __stdcall FUN_00412ca1(void)
 * Address ranges: 00412ca1-00412d95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412ca1(void)

{
  int local_8;
  
  local_8 = 0;
  if (DAT_0043d850 != 0) {
    for (; *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) != -1; local_8 = local_8 + 1) {
      if ((*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) == -1) ||
         ((&DAT_0043db90)[*(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c] == '\0')) {
        FUN_0040187a((byte *)s__s__d_____destroy_form__Unused_c_00434b08);
      }
      else if (*(int *)(&DAT_0043db98 + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c) != 0) {
        (**(code **)(&DAT_0043db98 + *(int *)(DAT_0043d850 + 8 + local_8 * 0x1c) * 0x1c))
                  (DAT_0043d850 + local_8 * 0x1c);
      }
    }
    DAT_0043d850 = 0;
    DAT_0043d84c = 0;
  }
  return;
}

