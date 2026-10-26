/*
 * FUN_004270f0 at 004270f0
 * undefined FUN_004270f0(void)
 * Address ranges: 004270f0-004271d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004270f0(void)

{
  undefined *puVar1;
  
  DAT_0052d4f8 = 0;
  if ((DAT_0053b9f0 == 0) && (DAT_0053b9c4 == 0)) {
    if (DAT_0053b9ac == 0) {
      puVar1 = &DAT_0053a6ee + DAT_0053b9b4 * 0x94;
    }
    else {
      if (DAT_0053b9ac != 1) {
        FUN_004afee0(s__init_moving_sky___s__d____Inval_004e77ec,
                     s_D__work_rcsk_Code_game_gfx_sky_c_004e77c8,0x2f);
        return;
      }
      puVar1 = &DAT_0053a6fc + DAT_0053b9b4 * 0x94;
    }
    DAT_0052d4f8 = FUN_004b2c80(puVar1,&DAT_0052d508,&DAT_0052d50c);
    DAT_0052d510 = DAT_004fe930;
    _DAT_0052d504 = 0;
    DAT_0052d4fc = 0;
    DAT_0052d514 = DAT_004fe934 - DAT_004fe934 / 3;
    DAT_0052d500 = 0;
    FUN_00427300();
    DAT_0052d55c = 1;
  }
  return;
}

