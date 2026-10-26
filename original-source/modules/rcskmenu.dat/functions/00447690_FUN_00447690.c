/*
 * FUN_00447690 at 00447690
 * undefined __register FUN_00447690(int * param_1, char param_2, int param_3)
 * Address ranges: 00447690-0044779b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447690(int *param_1,char param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar6;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  
  if (param_2 != '\0') {
    puStack_30 = (undefined1 *)0x4476a5;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffd4,in_stack_ffffffd8);
    param_3 = extraout_ECX;
  }
  puStack_30 = (undefined1 *)0x4476b8;
  FUN_00402e7c(param_1,'\0',param_3);
  param_1[3] = 4;
  param_1[5] = param_3;
  param_1[0x1c] = 0x40000;
  param_1[6] = 0xc;
  if ((*(char *)(param_3 + 0x4b) == '\x01') || (*(char *)(param_3 + 0x4b) == '\x02')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *(undefined1 *)(param_1 + 7) = uVar1;
  puStack_30 = (undefined1 *)0x447708;
  iVar2 = FUN_004471e4((int *)&LAB_0043c5c0,'\x01',(int)param_1);
  param_1[0x19] = iVar2;
  puStack_30 = (undefined1 *)0x44771a;
  piVar3 = FUN_00417cf4((int *)&PTR_FUN_00416258,'\x01',extraout_ECX_00);
  param_1[4] = (int)piVar3;
  puStack_30 = (undefined1 *)0x44772e;
  uVar4 = FUN_0041e8ac(0,0xffffff);
  puStack_30 = (undefined1 *)0x447737;
  FUN_00417e74(piVar3,uVar4);
  puStack_30 = (undefined1 *)0x44773f;
  FUN_00447858((int)param_1);
  puStack_34 = &LAB_0044779c;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_30 = &stack0xfffffffc;
  iVar2 = FUN_0044268c(param_3);
  if (-1 < iVar2 + -1) {
    iVar5 = 0;
    do {
      uVar6 = 0;
      uVar4 = FUN_00442650(param_3,iVar5);
      (**(code **)(*param_1 + 8))(param_1,uVar4,3,uVar6);
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_004473c0(param_1[0x19]);
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_004477a3;
  puStack_34 = (undefined1 *)0x44779b;
  FUN_0044785c((int)param_1);
  return;
}

