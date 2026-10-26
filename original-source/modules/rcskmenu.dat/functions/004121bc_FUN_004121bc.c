/*
 * FUN_004121bc at 004121bc
 * undefined __register FUN_004121bc(void)
 * Address ranges: 004121bc-004122d6;00412330-00412347;0041236e-00412374
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004121bc(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 uVar6;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar7;
  int iVar8;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  if (DAT_0047d61c == (code *)0x0) {
    return;
  }
  puStack_20 = (undefined1 *)0x4121dc;
  FUN_0040bf7c(DAT_0047d618);
  puStack_24 = &LAB_00412367;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_2c = (undefined1 *)0x4121f4;
  puStack_20 = &stack0xfffffffc;
  piVar1 = (int *)FUN_0040fa70(DAT_0047d630);
  puStack_30 = &LAB_00412348;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  if (piVar1[2] < 1) {
    *in_FS_OFFSET = uStack_34;
    puStack_2c = &LAB_0041234f;
    puStack_30 = (undefined1 *)0x412347;
    FUN_0040fad4(DAT_0047d630);
    return;
  }
  puStack_38 = (undefined1 *)0x41221a;
  puStack_2c = &stack0xfffffffc;
  FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX);
  puStack_3c = &LAB_00412329;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  puStack_44 = (undefined1 *)0x412237;
  puStack_38 = &stack0xfffffffc;
  piVar2 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
  puStack_48 = &LAB_004122d7;
  uStack_4c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_4c;
  iVar8 = 0;
  puStack_44 = &stack0xfffffffc;
  do {
    while( true ) {
      if (piVar1[2] <= iVar8) {
        *in_FS_OFFSET = uStack_4c;
        puStack_44 = &LAB_004122de;
        puStack_48 = (undefined1 *)0x4122d6;
        FUN_00402eac(piVar2);
        return;
      }
      piVar3 = (int *)FUN_0040f6b0(piVar1,iVar8);
      iVar4 = (*DAT_0047d61c)(piVar3[4]);
      uVar6 = extraout_ECX_01;
      uVar7 = extraout_EDX;
      if (iVar4 == 0) break;
LAB_00412278:
      if (iVar4 != 0) {
        iVar4 = FUN_00412074(iVar4,(char *)piVar3[5]);
        FUN_0040d3f4((int *)piVar3[1],(undefined4 *)piVar3[3],iVar4);
        uVar6 = extraout_ECX_03;
        uVar7 = extraout_EDX_01;
      }
      FUN_0041213c(piVar3[1],uVar7,uVar6,(int)&stack0xfffffffc);
      FUN_0040f550(piVar1,iVar8);
      FUN_00402eac(piVar3);
    }
    uVar5 = FUN_0040d380((int *)piVar3[1],(undefined4 *)piVar3[3]);
    uVar6 = extraout_ECX_02;
    uVar7 = extraout_EDX_00;
    if (uVar5 != 0) goto LAB_00412278;
    FUN_00412174(piVar3[1],extraout_EDX_00,extraout_ECX_02,(int)&stack0xfffffffc);
    iVar8 = iVar8 + 1;
  } while( true );
}

