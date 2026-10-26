/*
 * FUN_00424c80 at 00424c80
 * undefined FUN_00424c80(void)
 * Address ranges: 00424c80-00424d1b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424c80(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  CHAR local_40 [64];
  
  FUN_004b1d60(s_SndGfx_ini_004e6e50);
  DAT_0050de68 = FUN_004b1ed0(s_PROGRESS_004e6e68,s_CALCULATE_004e6e5c);
  iVar1 = FUN_004b1ed0(s_PROGRESS_004e6e7c,s_COUNT_004e6e74);
  if ((iVar1 < 0) || (1000 < iVar1)) {
    FUN_004afee0(s__s___d__nr_percents_read_incorre_004e6eac,
                 s_D__work_rcsk_Code_game_gfx_pbar__004e6e88,0x4b,iVar1);
  }
  iVar3 = 0;
  if (0 < iVar1) {
    puVar4 = &DAT_0050bf1c;
    do {
      wsprintfA(local_40,s_percent_d_004e6ed4,iVar3);
      uVar2 = FUN_004b1ed0(s_PROGRESS_004e6ee0,local_40);
      *puVar4 = uVar2;
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

