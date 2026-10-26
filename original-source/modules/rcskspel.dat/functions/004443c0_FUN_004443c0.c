/*
 * FUN_004443c0 at 004443c0
 * undefined FUN_004443c0(void)
 * Address ranges: 004443c0-004444bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004443c0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_004afce0(s_Handling_init_cop_path_type_004eef40);
  iVar4 = FUN_004028f0(param_1);
  if (iVar4 == 0) {
    iVar4 = (&DAT_0053f99c)[param_1 * 0xd0];
    iVar5 = FUN_00444ba0(param_1);
    uVar1 = *(undefined4 *)(&DAT_0053f67c + iVar5 * 0x340);
    iVar5 = FUN_00444ba0(param_1);
    uVar2 = *(undefined4 *)(&DAT_0053f680 + iVar5 * 0x340);
    iVar5 = FUN_00444ba0(param_1);
    uVar3 = *(undefined4 *)(&DAT_0053f684 + iVar5 * 0x340);
    iVar5 = iVar4 * 0xd0;
    iVar6 = DAT_006a5c38 + *(int *)(iVar5 + 0xc + DAT_0067ee20) * 0xa9;
    *(undefined4 *)(iVar6 + 0x50) = uVar1;
    *(undefined4 *)(iVar6 + 0x54) = uVar2;
    *(undefined4 *)(iVar6 + 0x58) = uVar3;
    *(code **)(iVar5 + 0x58 + DAT_0067ee20) = FUN_004170a0;
    *(undefined4 *)(iVar5 + 0x44 + DAT_0067ee20) = 1;
    FUN_00412c50(iVar4,1);
    FUN_004027a0(iVar4,param_1);
    return 1;
  }
  return 1;
}

