/*
 * FUN_0043de04 at 0043de04
 * undefined __register FUN_0043de04(char param_1)
 * Address ranges: 0043de04-0043e029;0043e05e-0043e062
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043de04(char param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined3 extraout_var;
  int *piVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  int *piVar8;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int local_18;
  int local_14;
  undefined3 uVar7;
  
  puStack_20 = &stack0xfffffffc;
  puStack_2c = &stack0xfffffffc;
  piVar8 = (int *)0x0;
  if ((DAT_0047d7bc == (int *)0x0) || ((char)DAT_0047d7bc[0xc] != '\0')) {
    return;
  }
  puStack_24 = &LAB_0043e057;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  piVar1 = DAT_0047d7bc;
  puStack_30 = &LAB_0043e02a;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  *(undefined1 *)(DAT_0047d7bc + 0xc) = 1;
  FUN_0043cd98(DAT_0047d7bc,DAT_0047d7c4);
  if (DAT_0047d7d8 == '\x02') {
    piVar8 = (int *)FUN_0040303c(DAT_0047d7bc,(int)&PTR_FUN_0043ae18);
    (**(code **)(*piVar8 + 0x30))();
    *(bool *)(piVar8 + 0x1b) = piVar8[1] == 0;
  }
  if (DAT_0047d7bc[1] == 0) {
LAB_0043ded3:
    local_18 = DAT_0047d7bc[3];
    local_14 = DAT_0047d7bc[4];
  }
  else {
    uVar4 = FUN_00403024((int *)DAT_0047d7bc[1],(int)&PTR_FUN_0043b888);
    if ((char)uVar4 == '\0') goto LAB_0043ded3;
    local_18 = DAT_0047d7bc[5];
    local_14 = DAT_0047d7bc[6];
  }
  cVar2 = FUN_0043dd94();
  if (cVar2 != '\0') {
    if ((DAT_0047d7d8 == '\x02') && ((char)piVar8[0x1b] != '\0')) {
LAB_0043df12:
      if (param_1 != '\0') {
        cVar2 = '\x01';
        goto LAB_0043df1e;
      }
    }
    else if (DAT_0047d7d8 != '\0') {
      bVar3 = FUN_0043d6b8(CONCAT31(extraout_var,1));
      if (bVar3) goto LAB_0043df12;
    }
  }
  cVar2 = '\0';
LAB_0043df1e:
  if (DAT_0047d7d8 == '\x02') {
    if ((cVar2 != '\0') && ((char)piVar8[0x1b] != '\0')) {
      piVar5 = FUN_004298bc((int *)piVar8[0xe]);
      if ((piVar5 != (int *)0x0) && (piVar5[0x82] == piVar8[0xe])) {
        FUN_0042d2b4(piVar5,(int *)0x0,extraout_ECX);
      }
      FUN_004405f0(DAT_0047d7b8,0xb03a,0,DAT_0047d7bc);
    }
  }
  else if (DAT_0047d7dc == 0) {
    SetCursor(DAT_0047d7d0);
  }
  else {
    FUN_00447040(DAT_0047d7dc);
  }
  DAT_0047d7b8 = 0;
  DAT_0047d7bc = (int *)0x0;
  if (piVar1[1] != 0) {
    uVar7 = (undefined3)((uint)piVar1 >> 8);
    uVar6 = CONCAT31(uVar7,3);
    if (cVar2 == '\0') {
      uVar6 = CONCAT31(uVar7,4);
      piVar1[3] = 0;
      piVar1[4] = 0;
      local_18 = 0;
      local_14 = 0;
    }
    FUN_0043d5c0((HWND)piVar1[2],uVar6,piVar1,piVar1 + 3,piVar1[1]);
  }
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_0043e031;
  puStack_30 = (undefined1 *)0x43dffc;
  FUN_00402eac(DAT_0047d7e4);
  DAT_0047d7e4 = (int *)0x0;
  *(undefined1 *)(piVar1 + 0xc) = 0;
  puStack_30 = (undefined1 *)local_14;
  uStack_34 = CONCAT31((int3)((uint)local_14 >> 8),cVar2);
  (**(code **)*piVar1)(piVar1,piVar1[1],local_18);
  DAT_0047d7bc = (int *)0x0;
  return;
}

