/*
 * FUN_00428490 at 00428490
 * undefined FUN_00428490(void)
 * Address ranges: 00428490-00428684
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00428490(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 float param_5,undefined4 param_6,float param_7)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar7 = (undefined4 *)(DAT_00680ba0 + 0x14 + (&DAT_00508620)[DAT_00508670] * 0x178);
  puVar8 = local_40;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  local_10 = param_2;
  local_c = param_3;
  local_8 = param_4;
  iVar5 = FUN_00427ed0(param_1);
  puVar7 = local_40;
  puVar8 = (undefined4 *)(&DAT_00535020 + iVar5 * 300);
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar5 = FUN_00427ed0(param_1);
  *(undefined4 *)(&DAT_00535148 + iVar5 * 300) = 1;
  FUN_0048f4e0();
  uVar1 = __ftol();
  iVar5 = FUN_00427ed0(param_1);
  *(undefined4 *)(&DAT_00535138 + iVar5 * 300) = uVar1;
  iVar5 = FUN_004be6c9();
  iVar6 = FUN_00427ed0(param_1);
  *(int *)(&DAT_0053513c + iVar6 * 300) = iVar5 % 3;
  iVar2 = FUN_004be6c9();
  iVar3 = FUN_004be6c9();
  iVar4 = FUN_004be6c9();
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = *(int *)(&DAT_00535138 + iVar5 * 300);
  iVar5 = FUN_00427ed0(param_1);
  iVar5 = iVar5 * 300;
  *(float *)(&DAT_00535120 + iVar5) = ((float)iVar2 * 7.629627e-06 + 0.75) * param_5;
  *(float *)(&DAT_00535124 + iVar5) = ((float)(iVar4 % 0x23) + 9.0) / (float)iVar6;
  *(float *)(&DAT_00535128 + iVar5) = ((float)iVar3 * 7.629627e-06 + 0.75) * param_7;
  iVar5 = FUN_00427ed0(param_1);
  *(undefined4 *)(&DAT_00535140 + iVar5 * 300) = 0x40e00000;
  iVar5 = FUN_00427ed0(param_1);
  *(undefined4 *)(&DAT_00535144 + iVar5 * 300) = 0x40e00000;
  iVar5 = FUN_00427ed0(param_1);
  iVar6 = FUN_00427f00(0);
  *(undefined4 *)(&DAT_00535070 + iVar5 * 300 + iVar6 * 0x20) = DAT_00534f40;
  return;
}

