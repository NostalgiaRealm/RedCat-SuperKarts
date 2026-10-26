/*
 * FUN_00449360 at 00449360
 * undefined FUN_00449360(void)
 * Address ranges: 00449360-00449470
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00449360(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar1 = (&DAT_0053f99c)[param_1 * 0xd0];
  iVar4 = FUN_00444ba0(param_1);
  uVar5 = *(undefined4 *)(&DAT_0053f67c + iVar4 * 0x340);
  iVar4 = FUN_00444ba0(param_1);
  uVar2 = *(undefined4 *)(&DAT_0053f680 + iVar4 * 0x340);
  iVar4 = FUN_00444ba0(param_1);
  uVar3 = *(undefined4 *)(&DAT_0053f684 + iVar4 * 0x340);
  iVar4 = iVar1 * 0xd0;
  iVar6 = DAT_006a5c38 + *(int *)(iVar4 + 0xc + DAT_0067ee20) * 0xa9;
  *(undefined4 *)(iVar6 + 0x50) = uVar5;
  *(undefined4 *)(iVar6 + 0x54) = uVar2;
  *(undefined4 *)(iVar6 + 0x58) = uVar3;
  *(undefined4 *)(iVar4 + 0x44 + DAT_0067ee20) = 1;
  *(code **)(iVar4 + 0x58 + DAT_0067ee20) = FUN_004170a0;
  *(undefined4 *)(iVar4 + 0x38 + DAT_0067ee20) = 0xffffffff;
  iVar4 = DAT_0067ee20 + iVar4;
  uVar5 = FUN_004977d0(DAT_0053be40,uVar5,uVar2,uVar3);
  *(undefined4 *)(iVar4 + 0x1c) = uVar5;
  FUN_00407b60(iVar1,3,5,0xffffffff,param_1);
  return 1;
}

