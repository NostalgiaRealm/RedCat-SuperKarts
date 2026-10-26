/*
 * FUN_00453e90 at 00453e90
 * undefined FUN_00453e90(void)
 * Address ranges: 00453e90-00453eae;00454610-00454669
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453e90(void)

{
  undefined *puStack_4;
  
  if ((DAT_00543d38 & 1) == 0) {
    DAT_00543d38 = DAT_00543d38 | 1;
    puStack_4 = &DAT_00543d40;
    FUN_00454720(&puStack_4,*DAT_00543d44,DAT_00543d44);
    FUN_004bc150(DAT_00543d44);
    DAT_00543d44 = (undefined4 *)0x0;
    DAT_00543d4c = 0;
    DAT_00543d58 = DAT_00543d58 + -1;
    if (DAT_00543d58 == 0) {
      FUN_004bc150(DAT_00543d54);
      DAT_00543d54 = 0;
    }
    return;
  }
  return;
}

