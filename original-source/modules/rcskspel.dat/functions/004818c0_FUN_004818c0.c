/*
 * FUN_004818c0 at 004818c0
 * undefined FUN_004818c0(void)
 * Address ranges: 004818c0-00481a49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004818c0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 local_c [12];
  
  if ((DAT_0053b9f0 != 0) && (DAT_0053ba38 != 0)) {
    FUN_004b1d60(s_game_ini_004f9994);
    uVar1 = FUN_004b1ed0(&DAT_004f99b0,s_maxparticles_004f99a0);
    FUN_004afce0(s_rain___i_004f99b8,uVar1);
    uVar2 = FUN_004b1ed0(&DAT_004f99d4,s_maxparticles_004f99c4);
    FUN_004afce0(s_snow___i_004f99dc,uVar2);
    FUN_004b1d60(s_track_ini_004f99e8);
    uVar3 = FUN_0042abc0(param_1);
    FUN_004bea92(local_c,s_TRACK_d_d_004f99f4,uVar3);
    iVar4 = FUN_004b1ed0(local_c,&DAT_004f9a00);
    iVar5 = FUN_004b1ed0(local_c,s_count_004f9a08);
    if (iVar4 == 1) {
      iVar4 = FUN_004b1ed0(local_c,s_enable_004f9a10);
      param_1 = CONCAT31(param_1._1_3_,iVar4 != 0);
      FUN_00481be0(DAT_0053be28,DAT_0053be28,uVar1,param_1);
      puVar6 = operator_new(iVar5 * 4);
      DAT_005450b4 = puVar6;
      DAT_005450b8 = iVar5;
    }
    else {
      if (iVar4 != 2) {
        return;
      }
      iVar4 = FUN_004b1ed0(local_c,s_enable_004f9a18);
      param_1 = CONCAT31(param_1._1_3_,iVar4 != 0);
      FUN_00481a80(DAT_0053be28,DAT_0053be28,uVar2,param_1);
      puVar6 = operator_new(iVar5 * 4);
      DAT_005450ac = puVar6;
      DAT_005450b0 = iVar5;
    }
    if ((puVar6 != (undefined4 *)0x0) && (iVar4 = 0, 0 < iVar5)) {
      do {
        FUN_004bea92(&param_1,&DAT_004f9a20,iVar4);
        uVar1 = FUN_004b1ed0(local_c,&param_1);
        *puVar6 = uVar1;
        iVar4 = iVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar4 < iVar5);
    }
  }
  return;
}

