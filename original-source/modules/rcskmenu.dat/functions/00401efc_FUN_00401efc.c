/*
 * FUN_00401efc at 00401efc
 * undefined __register FUN_00401efc(void)
 * Address ranges: 00401efc-00401f45
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401efc(void)

{
  if (0 < (int)DAT_0047d488) {
    if ((int)DAT_0047d488 < 0xc) {
      DAT_0047d434 = 7;
    }
    else {
      *DAT_0047d48c = DAT_0047d488 | 2;
      FUN_00401ce8((int)(DAT_0047d48c + 1));
      DAT_0047d48c = (uint *)0x0;
      DAT_0047d488 = 0;
    }
  }
  return;
}

