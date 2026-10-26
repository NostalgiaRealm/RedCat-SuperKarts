/*
 * FUN_0041a000 at 0041a000
 * undefined FUN_0041a000(void)
 * Address ranges: 0041a000-0041a113;0041a138-0041a141
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0041a000(int *param_1,int *param_2)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  if (param_2 != (int *)0x0) {
    puStack_20 = (undefined1 *)0x41a018;
    iVar4 = FUN_00402df4(param_1);
    puStack_20 = (undefined1 *)0x41a021;
    iVar5 = FUN_00402df4(param_2);
    if (iVar4 == iVar5) {
      bVar1 = true;
      goto LAB_0041a02b;
    }
  }
  bVar1 = false;
LAB_0041a02b:
  puStack_20 = (undefined1 *)0x41a035;
  cVar2 = (**(code **)(*param_1 + 0x1c))();
  if (cVar2 == '\0') {
    puStack_20 = (undefined1 *)0x41a040;
    cVar2 = (**(code **)(*param_2 + 0x1c))();
    if (cVar2 == '\0') {
      if (!bVar1) {
        return 0;
      }
      puStack_20 = (undefined1 *)0x41a07e;
      piVar6 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',extraout_ECX);
      puStack_24 = &LAB_0041a131;
      uStack_28 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_28;
      puStack_2c = (undefined1 *)0x41a099;
      puStack_20 = &stack0xfffffffc;
      (**(code **)(*param_1 + 0x44))(param_1,piVar6);
      puStack_2c = (undefined1 *)0x41a0a5;
      piVar7 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',extraout_ECX_00);
      puStack_30 = &LAB_0041a114;
      uStack_34 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_34;
      puStack_2c = &stack0xfffffffc;
      (**(code **)(*param_2 + 0x44))(param_2,piVar7);
      iVar4 = FUN_004118b0(piVar6);
      iVar5 = FUN_004118b0(piVar7);
      if (iVar4 == iVar5) {
        uVar8 = FUN_004118b0(piVar6);
        FUN_00407ce4((int *)piVar6[1],(int *)piVar7[1],uVar8);
      }
      *in_FS_OFFSET = uStack_34;
      puStack_2c = &LAB_0041a11b;
      puStack_30 = (undefined1 *)0x41a113;
      uVar3 = FUN_00402eac(piVar7);
      return uVar3;
    }
  }
  puStack_20 = (undefined1 *)0x41a04b;
  cVar2 = (**(code **)(*param_1 + 0x1c))();
  if (cVar2 != '\0') {
    puStack_20 = (undefined1 *)0x41a056;
    cVar2 = (**(code **)(*param_2 + 0x1c))();
    if (cVar2 != '\0') {
      return 1;
    }
  }
  return 0;
}

