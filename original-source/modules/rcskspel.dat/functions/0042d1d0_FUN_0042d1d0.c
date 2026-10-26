/*
 * FUN_0042d1d0 at 0042d1d0
 * undefined FUN_0042d1d0(void)
 * Address ranges: 0042d1d0-0042d2e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d1d0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00428df0();
  switch(uVar1) {
  case 0:
    DAT_0053b9b0 = 1;
    DAT_0053b9ac = 0;
    DAT_0053b9f0 = 0;
    FUN_00493130(0);
    return;
  case 1:
    DAT_0053b9f0 = 0;
    DAT_0053b9ac = 1;
    DAT_0053b9b0 = 1;
    FUN_00493130(0);
    return;
  case 2:
  case 3:
    DAT_0053b9b0 = 0;
    DAT_0053b9ac = 1;
    DAT_0053b9f0 = 1;
    FUN_00493130(1);
    return;
  case 4:
    DAT_0053b9f0 = 1;
    DAT_0053b9ac = 2;
    DAT_0053b9b0 = 0;
    FUN_00493130(1);
    return;
  case 5:
    DAT_0053b9ac = 0;
    DAT_0053b9b0 = 0;
    DAT_0053b9f0 = 0;
    FUN_00493130(0);
    return;
  case 6:
    DAT_0053b9f0 = 1;
    DAT_0053b9ac = 3;
    DAT_0053b9b0 = 0;
    FUN_00493130(1);
    return;
  default:
    uVar1 = FUN_00428df0();
    FUN_004afee0(s__set_game_display___s__d____Inva_004ea608,
                 s_D__work_rcsk_Code_game_gm_init_c_004ea5e4,0x1c7,uVar1);
    FUN_00493130(DAT_0053b9f0);
    return;
  }
}

