/*
 * FUN_00441840 at 00441840
 * undefined FUN_00441840(void)
 * Address ranges: 00441840-00441899
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00441840(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  *(undefined4 *)(param_1 + 0x4c) = 1;
  *(undefined4 *)(param_1 + 0x58) = 0;
  (**(code **)(**(int **)(param_1 + 0x54) + 0xc))(*(int **)(param_1 + 0x54),param_1);
  piVar1 = *(int **)(*(int *)(*DAT_006a62e8 + unaff_ESI * 4) + 0x2c);
  iVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,*(undefined4 *)(param_1 + 0x50));
  if (iVar2 != 0) {
    uVar3 = FUN_004aaa00(iVar2);
    FUN_004afee0(s__s__d____error_setting_material_a_004ecd18,
                 s____Libs_win3dlib_Include_viewpor_004ecd50,0x5e,uVar3);
  }
  return;
}

