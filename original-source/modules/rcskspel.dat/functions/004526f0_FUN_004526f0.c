/*
 * FUN_004526f0 at 004526f0
 * undefined FUN_004526f0(void)
 * Address ranges: 004526f0-00452749
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004526f0(int param_1)

{
  int local_4;
  
  local_4 = param_1;
  FUN_00452890(&local_4,**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  DAT_00543d30 = DAT_00543d30 + -1;
  if (DAT_00543d30 == 0) {
    FUN_004bc150(DAT_00543d2c);
    DAT_00543d2c = 0;
  }
  return;
}

