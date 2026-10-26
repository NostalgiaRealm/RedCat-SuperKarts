/*
 * FUN_00472494 at 00472494
 * undefined __register FUN_00472494(undefined4 param_1)
 * Address ranges: 00472494-0047264e;00472663-00472680
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472494(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int *piVar5;
  int iVar6;
  int unaff_EDI;
  int *in_FS_OFFSET;
  int *piVar7;
  undefined4 uVar8;
  int iStack_40;
  undefined1 *puStack_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 *local_24;
  undefined1 *local_20;
  int local_10;
  int *local_c;
  undefined4 local_8;
  
  local_20 = &stack0xfffffffc;
  local_2c = (undefined4 *)&stack0xfffffffc;
  local_38 = (undefined4 *)&stack0xfffffffc;
  local_10 = 6;
  do {
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  local_24 = (undefined4 *)&LAB_004726b3;
  local_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_28;
  local_30 = (undefined4 *)&LAB_00472681;
  local_34 = (undefined4 *)*in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_34;
  puStack_3c = &LAB_0047264f;
  iStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_40;
  local_8 = param_1;
  FUN_00403e1c((int *)&local_24,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_24);
  piVar1 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  piVar2 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX_00);
  puVar3 = (undefined1 *)(**(code **)(*local_c + 8))(local_c,"CHARDATA","count");
  if ((0 < (int)puVar3) && (-1 < (int)(puVar3 + -1))) {
    iVar6 = 0;
    piVar5 = &DAT_0047e2f0;
    local_20 = puVar3;
    do {
      uVar8 = 0;
      piVar7 = &local_10;
      FUN_00407f60(iVar6,&local_28);
      (**(code **)*local_c)(local_c,"CHARDATA",local_28,piVar7,uVar8);
      iVar4 = FUN_00403dd0(local_10);
      if (0 < iVar4) {
        FUN_00454510((int)piVar1,local_10);
        *piVar5 = iVar6;
        FUN_0045471c((int)piVar1,0,(int *)&local_2c);
        FUN_00403ba4(piVar5 + -4,local_2c);
        FUN_0045471c((int)piVar1,1,(int *)&local_30);
        FUN_00403ba4(piVar5 + -3,local_30);
        iVar4 = FUN_004546b4((int)piVar1,2);
        piVar5[-2] = iVar4;
        iVar4 = FUN_004546b4((int)piVar1,3);
        piVar5[-1] = iVar4;
        FUN_00472b20(local_8,piVar5[-4],&stack0xffffffe4);
        FUN_00454510((int)piVar2,unaff_EDI);
        FUN_0045471c((int)piVar2,1,(int *)&local_34);
        FUN_00403ba4(piVar5 + 3,local_34);
        FUN_0045471c((int)piVar2,0,(int *)&local_38);
        FUN_00403ba4(piVar5 + 4,local_38);
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 9;
      local_20 = local_20 + -1;
    } while (local_20 != (undefined1 *)0x0);
  }
  FUN_00472750();
  *in_FS_OFFSET = 0;
  *in_FS_OFFSET = (int)local_38;
  local_30 = (undefined4 *)&LAB_00472688;
  local_34 = (undefined4 *)0x472678;
  FUN_00402eac(local_c);
  local_34 = (undefined4 *)0x472680;
  FUN_00402eac(piVar1);
  return;
}

