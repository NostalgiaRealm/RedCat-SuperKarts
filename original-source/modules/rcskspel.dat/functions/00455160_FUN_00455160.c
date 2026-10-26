/*
 * FUN_00455160 at 00455160
 * undefined FUN_00455160(void)
 * Address ranges: 00455160-0045517e;00456b30-00456b89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455160(void)

{
  undefined *puStack_4;
  
  if ((DAT_00544060 & 1) == 0) {
    DAT_00544060 = DAT_00544060 | 1;
    puStack_4 = &DAT_00544068;
    FUN_00456c40(&puStack_4,*DAT_0054406c,DAT_0054406c);
    FUN_004bc150(DAT_0054406c);
    DAT_0054406c = (undefined4 *)0x0;
    DAT_00544074 = 0;
    DAT_00544a88 = DAT_00544a88 + -1;
    if (DAT_00544a88 == 0) {
      FUN_004bc150(DAT_00544a84);
      DAT_00544a84 = 0;
    }
    return;
  }
  return;
}

