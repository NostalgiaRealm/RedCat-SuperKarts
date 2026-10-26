/*
 * FUN_00464060 at 00464060
 * undefined __register FUN_00464060(int * param_1)
 * Address ranges: 00464060-00464287
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464060(int *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int local_b0;
  int iStack_ac;
  POINT PStack_a0;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  LONG LStack_58;
  LONG LStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  FUN_00463e4c(param_1,&local_b0);
  uVar4 = FUN_00417bb4(*(int *)(param_1[0x83] + 0x10));
  cVar3 = (**(code **)(*param_1 + 0x4c))();
  if (cVar3 == '\0') {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),*(undefined4 *)(param_1[0x80] + 0xc));
  }
  else if ((char)param_1[0x84] == '\0') {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),*(undefined4 *)(param_1[0x80] + 0xc));
  }
  else {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),param_1[0x82]);
  }
  iVar2 = iStack_ac;
  iVar1 = local_b0;
  FUN_0040ebd0(local_b0 + 5,iStack_ac + 4,&LStack_58);
  PStack_a0.x = LStack_58;
  PStack_a0.y = LStack_54;
  FUN_0040ebd0(local_b0 + 5,iVar2 + 7,&uStack_50);
  uStack_98 = uStack_50;
  uStack_94 = uStack_4c;
  FUN_0040ebd0(iVar1 + 6,iStack_ac + 7,&uStack_48);
  uStack_90 = uStack_48;
  uStack_8c = uStack_44;
  FUN_0040ebd0(local_b0 + 6,iStack_ac + 4,&uStack_40);
  uStack_88 = uStack_40;
  uStack_84 = uStack_3c;
  iVar5 = iVar2 + 5;
  FUN_0040ebd0(iVar1 + 4,iVar5,&uStack_38);
  uStack_80 = uStack_38;
  uStack_7c = uStack_34;
  FUN_0040ebd0(iVar1 + 7,iVar5,&uStack_30);
  uStack_78 = uStack_30;
  uStack_74 = uStack_2c;
  FUN_0040ebd0(local_b0 + 7,iVar2 + 6,&uStack_28);
  uStack_70 = uStack_28;
  uStack_6c = uStack_24;
  FUN_0040ebd0(local_b0 + 4,iStack_ac + 6,&uStack_20);
  uStack_68 = uStack_20;
  uStack_64 = uStack_1c;
  FUN_0040ebd0(local_b0 + 4,iVar5,&uStack_18);
  uStack_60 = uStack_18;
  uStack_5c = uStack_14;
  FUN_0041863c((int *)param_1[0x83],&PStack_a0,8);
  FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),uVar4);
  return;
}

