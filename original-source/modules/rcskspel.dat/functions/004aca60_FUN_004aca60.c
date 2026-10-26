/*
 * FUN_004aca60 at 004aca60
 * undefined FUN_004aca60(void)
 * Address ranges: 004aca60-004acad3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004aca60(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_006a62e8;
  if (DAT_006a62ec != 0) {
    if (DAT_006a62e8 != (undefined4 *)0x0) {
      if (DAT_006a62e8[3] == 1) {
        FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)DAT_006a62e8 + 0x2d,
                     DAT_006a62e8 + 5,DAT_006a62e8[1]);
        FUN_004bc150(*puVar1);
      }
      if (puVar1[3] != 0) {
        FUN_004bc150(puVar1[4]);
        puVar1[3] = 0;
      }
      FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
      FUN_004bc150(puVar1);
    }
    DAT_006a62ec = 1;
  }
  return;
}

