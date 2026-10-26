/*
 * _SmackSoundUseWin@0 at 00407240
 * undefined1 * __stdcall _SmackSoundUseWin@0(void)
 * Address ranges: 00407240-004072b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * _SmackSoundUseWin_0(void)

{
  uint in_EAX;
  
                    /* 0x7240  37  _SmackSoundUseWin@0 */
  if (DAT_0040e84c == (code *)0x0) {
    DAT_00410474 = FUN_00407400;
    DAT_0040e84c = FUN_00407570;
    DAT_0041047c = FUN_00407370;
    DAT_00410478 = FUN_00407520;
    DAT_00410470 = FUN_004073d0;
    DAT_0040e850 = FUN_00407360;
    DAT_0040e854 = FUN_00407350;
    DAT_0040e858 = &DAT_004072c0;
    return &LAB_00407301;
  }
  return (undefined1 *)(in_EAX & 0xffffff00);
}

