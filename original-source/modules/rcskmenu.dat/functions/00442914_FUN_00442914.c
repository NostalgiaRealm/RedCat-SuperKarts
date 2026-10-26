/*
 * FUN_00442914 at 00442914
 * undefined __register FUN_00442914(int * param_1)
 * Address ranges: 00442914-00442a9e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442914(int *param_1)

{
  ATOM AVar1;
  undefined4 uVar2;
  BOOL BVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uStack_d8;
  undefined1 *puStack_d4;
  undefined1 *puStack_d0;
  byte *local_c4;
  int local_c0;
  undefined1 local_bc;
  tagWNDCLASSA local_b8;
  undefined1 local_90 [7];
  byte local_89;
  int local_74;
  WNDCLASSA local_6c;
  CHAR local_44 [64];
  
  puStack_d0 = &stack0xfffffffc;
  local_c4 = (byte *)0x0;
  puStack_d4 = &LAB_00442a9f;
  uStack_d8 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_d8;
  (**(code **)(*param_1 + 0x90))(param_1,local_90);
  if ((local_74 == 0) && ((local_89 & 0x40) != 0)) {
    piVar4 = (int *)param_1[1];
    if ((piVar4 != (int *)0x0) && ((*(byte *)(piVar4 + 8) & 2) != 0)) {
      uVar2 = FUN_00403024(piVar4,(int)&PTR_FUN_0043be00);
      if ((char)uVar2 != '\0') {
        local_74 = FUN_00445724(piVar4);
        goto LAB_004429c0;
      }
    }
    local_c0 = param_1[2];
    local_bc = 0xb;
    piVar4 = &local_c0;
    uVar2 = 0;
    FUN_00405438((undefined4 *)PTR_PTR_0047c8a8,(int *)&local_c4);
    uVar2 = FUN_0040aca0((int)&DAT_0040de0c,'\x01',local_c4,uVar2,piVar4);
    FUN_00403604(uVar2);
  }
LAB_004429c0:
  param_1[0x4f] = (int)local_6c.lpfnWndProc;
  BVar3 = GetClassInfoA(local_6c.hInstance,local_44,&local_b8);
  if ((BVar3 == 0) || (local_b8.lpfnWndProc != FUN_0043c7ac)) {
    if (BVar3 != 0) {
      UnregisterClassA(local_44,local_6c.hInstance);
    }
    local_6c.lpfnWndProc = FUN_0043c7ac;
    local_6c.lpszClassName = local_44;
    AVar1 = RegisterClassA(&local_6c);
    if (AVar1 == 0) {
      FUN_0040bd58();
    }
  }
  DAT_0047b8f8 = param_1;
  (**(code **)(*param_1 + 0x94))(param_1,local_90);
  if (param_1[0x53] == 0) {
    FUN_0040bd58();
  }
  FUN_00408574(param_1[0x15]);
  param_1[0x15] = 0;
  FUN_00445a2c((int)param_1);
  uVar5 = 1;
  uVar2 = FUN_004176e4(param_1[0x16]);
  FUN_004405f0((int)param_1,0x30,uVar2,uVar5);
  if ((char)param_1[0x13] != '\0') {
    FUN_00403088(param_1,extraout_EDX,extraout_ECX);
  }
  *in_FS_OFFSET = uStack_d8;
  puStack_d0 = &LAB_00442aa6;
  puStack_d4 = (undefined1 *)0x442a9e;
  FUN_00403b50((int *)&local_c4);
  return;
}

