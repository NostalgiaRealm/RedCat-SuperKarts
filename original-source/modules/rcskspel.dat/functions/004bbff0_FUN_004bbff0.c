/*
 * FUN_004bbff0 at 004bbff0
 * undefined FUN_004bbff0(void)
 * Address ranges: 004bbff0-004bc060
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bbff0(void)

{
  if (DAT_006b5d30 != 0) {
    if (DAT_006b5d34 != 0) {
      DAT_006b5d34 = 0;
      (**(code **)(*DAT_006b5d28 + 0x20))(DAT_006b5d28);
      (**(code **)(*DAT_006b5d28 + 8))(DAT_006b5d28);
    }
    if (DAT_006b5d38 != 0) {
      DAT_006b5d38 = 0;
      (**(code **)(*DAT_006b5c24 + 0x20))(DAT_006b5c24);
      (**(code **)(*DAT_006b5c24 + 8))(DAT_006b5c24);
    }
    (**(code **)(*DAT_006b5d2c + 8))(DAT_006b5d2c);
    DAT_006b5d30 = 0;
  }
  return;
}

