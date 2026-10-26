/*
 * FUN_004b4310 at 004b4310
 * undefined FUN_004b4310(void)
 * Address ranges: 004b4310-004b4427
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004b4310(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar5 = (uint)(param_1 == 0);
  uVar6 = 0;
  if (0 < DAT_006ab78c) {
    iVar7 = uVar5 * 0x44;
    iVar4 = 0;
    do {
      if ((((uVar6 != uVar5) && (uVar6 != param_1)) && (iVar2 = FUN_004b3f30(uVar6), iVar2 == 0)) &&
         (*(int *)(iVar4 + 0x38 + DAT_006ab798) < *(int *)(iVar7 + 0x38 + DAT_006ab798))) {
        uVar5 = uVar6;
        iVar7 = iVar4;
      }
      uVar6 = uVar6 + 1;
      iVar4 = iVar4 + 0x44;
    } while ((int)uVar6 < DAT_006ab78c);
  }
  FUN_004afce0(s_deleting__d_005005b4,uVar5);
  iVar4 = uVar5 * 0x44;
  piVar1 = *(int **)(iVar4 + 0x28 + DAT_006ab798);
  iVar7 = (**(code **)(*piVar1 + 0x48))(piVar1);
  if (iVar7 != 0) {
    uVar3 = FUN_004b3910(iVar7);
    FUN_004afee0(s__s__d____error_releasing_sound_b_00500578,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x2a2,uVar3);
  }
  piVar1 = *(int **)(iVar4 + 0x28 + DAT_006ab798);
  (**(code **)(*piVar1 + 8))(piVar1);
  *(undefined4 *)(iVar4 + 0x30 + DAT_006ab798) = 0;
  uVar6 = 0;
  *(undefined4 *)(iVar4 + 0x38 + DAT_006ab798) = 0;
  if (0 < DAT_006ab78c) {
    iVar4 = 0;
    iVar7 = DAT_006ab798;
    do {
      iVar2 = *(int *)(iVar4 + 0x38 + iVar7);
      if (((iVar2 != 10000) && (uVar6 != uVar5)) && (1 < iVar2)) {
        *(int *)(iVar4 + 0x38 + iVar7) = iVar2 + -1;
        iVar7 = DAT_006ab798;
      }
      uVar6 = uVar6 + 1;
      iVar4 = iVar4 + 0x44;
    } while ((int)uVar6 < DAT_006ab78c);
  }
  return uVar5;
}

