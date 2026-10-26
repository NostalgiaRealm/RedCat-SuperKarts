/*
 * FUN_00406873 at 00406873
 * undefined4 __stdcall FUN_00406873(void)
 * Address ranges: 00406873-00406950
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00406873(void)

{
  undefined4 local_8;
  
  if (DAT_0043d43c != 0) {
    FUN_0040681d();
    for (local_8 = 0; local_8 < DAT_0043d414; local_8 = local_8 + 1) {
      if (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) != 0) {
        if (*(int *)(DAT_0043d420 + 0x34 + local_8 * 0x44) == 1) {
          (**(code **)(**(int **)(DAT_0043d420 + 0x2c + local_8 * 0x44) + 8))
                    (*(undefined4 *)(DAT_0043d420 + 0x2c + local_8 * 0x44));
        }
        (**(code **)(**(int **)(DAT_0043d420 + 0x28 + local_8 * 0x44) + 8))
                  (*(undefined4 *)(DAT_0043d420 + 0x28 + local_8 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x30 + local_8 * 0x44) = 0;
        *(undefined4 *)(DAT_0043d420 + 0x38 + local_8 * 0x44) = 0;
      }
    }
  }
  return 0;
}

