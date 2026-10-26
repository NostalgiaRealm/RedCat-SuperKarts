/*
 * FUN_0042c3b0 at 0042c3b0
 * undefined FUN_0042c3b0(void)
 * Address ranges: 0042c3b0-0042c4b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c3b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  CHAR local_40 [64];
  
  iVar1 = 0;
  if (DAT_0053be50 != 0) {
    FUN_004b1d60(s_Race_ini_004e9fa8);
    wsprintfA(local_40,s_LAP_RECORD_E_d_004e9fb4,DAT_0053b9b4);
    FUN_004b1e70(s_BEST_TIMES_004e9fc4,local_40,DAT_0053ba0c);
    wsprintfA(local_40,s_RACE_RECORD_E_d_004e9fd0,DAT_0053b9b4);
    FUN_004b1e70(s_BEST_TIMES_004e9fe0,local_40,DAT_0053ba10);
    if ((DAT_004ed1c0 < 0) || (9 < DAT_004ed1c0)) {
      DAT_004ed1c0 = 0;
    }
    FUN_004bea92(local_40,s_TIME_CHECK_COUNT_E_d_004e9fec,DAT_0053b9b4);
    FUN_004b1e70(s_BEST_TIMES_004ea004,local_40,DAT_004ed1c0);
    if (0 < DAT_004ed1c0) {
      puVar2 = &DAT_0053d300;
      do {
        wsprintfA(local_40,s_TIME_CHECK_E_d_C_d_004ea010,DAT_0053b9b4,iVar1);
        FUN_004b1e70(s_BEST_TIMES_004ea024,local_40,*puVar2);
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar1 < DAT_004ed1c0);
    }
  }
  return;
}

