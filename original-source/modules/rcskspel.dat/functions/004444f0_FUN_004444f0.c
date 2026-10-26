/*
 * FUN_004444f0 at 004444f0
 * undefined FUN_004444f0(void)
 * Address ranges: 004444f0-004446cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004444f0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar1 = FUN_004a6200(s_C_HELI_004eef60);
  iVar2 = FUN_0048fb60(0,0,0,0,0,0,uVar1,0,0,0,0,0);
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar4 = 0;
  uVar3 = 0;
  uVar5 = 0;
  uVar6 = 0;
  uVar1 = FUN_004a6200(s_C_LBLADE_004eef68);
  FUN_00492620(iVar2,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9);
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar4 = 0x3cd4fdf4;
  uVar3 = 0;
  uVar5 = 0x40e1eb85;
  uVar6 = 0xc29b2b02;
  uVar1 = FUN_004a6200(s_C_SBLADE_004eef74);
  FUN_00492620(iVar2,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9);
  *(undefined4 *)(iVar2 * 0xd0 + 0x44 + DAT_0067ee20) = 0;
  FUN_0043b760(iVar2,&DAT_004eef80);
  if ((param_1 < 0) || (DAT_00543760 <= param_1)) {
    FUN_004afee0(s__s___d__Path_does_not_exist__Pat_004eefac,
                 s_D__work_rcsk_Code_game_pth_heli__004eef88,0x46,param_1,DAT_00543760);
  }
  (&DAT_0053f99c)[param_1 * 0xd0] = iVar2;
  return;
}

