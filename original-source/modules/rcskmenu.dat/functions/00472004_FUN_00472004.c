/*
 * FUN_00472004 at 00472004
 * undefined __register FUN_00472004(int param_1)
 * Address ranges: 00472004-0047214d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472004(int param_1)

{
  int *piVar1;
  undefined4 extraout_ECX;
  int *piVar2;
  byte *pbVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  uint *local_2c;
  undefined4 *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  puStack_3c = &stack0xfffffffc;
  local_2c = (uint *)0x0;
  local_28 = (undefined4 *)0x0;
  puStack_40 = &LAB_0047214e;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  local_8 = param_1;
  FUN_00403e1c((int *)&local_28,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  local_10 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_28);
  local_c = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  local_14 = (**(code **)(*local_10 + 8))(local_10,"CHARDATA","count");
  if (0 < local_14) {
    local_20 = 0;
    if (-1 < local_14 + -1) {
      local_18 = 0;
      piVar2 = &DAT_0047e2f4;
      pbVar3 = &DAT_0047c50c;
      local_24 = local_14;
      do {
        piVar1 = (int *)FUN_00472960(local_8,*piVar2 + 1);
        local_1c = FUN_00472a40(local_8,local_20 + 1);
        local_20 = local_20 + 1;
        if (local_1c != 0) {
          FUN_0045c4f0(*pbVar3,(int *)&local_2c);
          FUN_00452c0c(*(int *)(local_1c + 300),local_2c);
        }
        if (piVar1 != (int *)0x0) {
          if (local_14 + -1 == local_18) {
            FUN_00452c0c(piVar1[0x4b],(uint *)piVar2[3]);
          }
          else {
            FUN_00452c0c(piVar1[0x4b],(uint *)piVar2[2]);
          }
          FUN_0043fb28(piVar1);
        }
        local_18 = local_18 + 1;
        pbVar3 = pbVar3 + 1;
        piVar2 = piVar2 + 9;
        local_24 = local_24 + -1;
      } while (local_24 != 0);
    }
  }
  FUN_00402eac(local_c);
  FUN_00402eac(local_10);
  *in_FS_OFFSET = 0;
  puStack_40 = &LAB_00472155;
  uStack_44 = 0x47214d;
  FUN_00403b74((int *)&local_2c,2);
  return;
}

