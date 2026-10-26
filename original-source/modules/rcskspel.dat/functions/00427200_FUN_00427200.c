/*
 * FUN_00427200 at 00427200
 * undefined FUN_00427200(void)
 * Address ranges: 00427200-004272b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00427200(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00429210();
  if (iVar1 == 1) {
    FUN_004b08e0(DAT_006a64c0);
    iVar1 = (**(code **)(*DAT_006a64c0 + 0x14))
                      (DAT_006a64c0,param_1,DAT_0052d4f8,param_2,0x1000000,0);
    if (iVar1 != 0) {
      uVar2 = FUN_004b0190(iVar1);
      FUN_004afee0(s__s__d____blitting_error___s___004e7840,
                   s_D__work_rcsk_Code_game_gfx_sky_c_004e781c,0x57,uVar2);
    }
  }
  else if (iVar1 == 2) {
    FUN_004b08e0(DAT_006a64a0);
    iVar1 = (**(code **)(*DAT_006a64a0 + 0x14))
                      (DAT_006a64a0,param_1,DAT_0052d4f8,param_2,0x1000000,0);
    if (iVar1 != 0) {
      uVar2 = FUN_004b0190(iVar1);
      FUN_004afee0(s__s__d____blitting_error___s___004e7884,
                   s_D__work_rcsk_Code_game_gfx_sky_c_004e7860,0x60,uVar2);
      return;
    }
  }
  return;
}

