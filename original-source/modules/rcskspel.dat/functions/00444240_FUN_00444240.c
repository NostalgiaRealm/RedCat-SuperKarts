/*
 * FUN_00444240 at 00444240
 * undefined FUN_00444240(void)
 * Address ranges: 00444240-0044439d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444240(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_004a6200(s_racer_5_004eeec8);
  iVar2 = FUN_0048fb60(0,0,0,0,0,0,uVar1,0,0,FUN_00434c40,0,0);
  FUN_0043b760(iVar2,s_POLITIE_SIRENE_004eeed0);
  FUN_0048fda0(iVar2,0,0,0,0,0x44960000,0x3e4ccccd,0x40800000,0x3f800000);
  FUN_004939d0(iVar2);
  iVar3 = iVar2 * 0xd0;
  *(undefined4 *)(iVar3 + 0x48 + DAT_0067ee20) = 1;
  *(undefined4 *)(iVar3 + 0x44 + DAT_0067ee20) = 0;
  *(code **)(iVar3 + 0x58 + DAT_0067ee20) = FUN_004170a0;
  if ((param_1 < 0) || (DAT_00543760 <= param_1)) {
    FUN_004afee0(s__s___d__Path_does_not_exist__Pat_004eef04,
                 s_D__work_rcsk_Code_game_pth_cop_c_004eeee0,0x48,param_1,DAT_00543760);
  }
  (&DAT_0053f99c)[param_1 * 0xd0] = iVar2;
  return;
}

