/*
 * FUN_0046e9bc at 0046e9bc
 * undefined __register FUN_0046e9bc(int param_1, byte param_2)
 * Address ranges: 0046e9bc-0046ecc9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e9bc(int param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_EDX;
  int iVar8;
  uint *in_FS_OFFSET;
  bool bVar9;
  int local_68;
  undefined *local_64;
  undefined *local_60;
  int local_5c;
  undefined1 *local_58;
  undefined1 *local_54;
  undefined *local_50;
  undefined1 *local_4c;
  undefined *local_48;
  undefined *local_44;
  undefined4 *local_40;
  undefined *local_3c;
  undefined4 *local_38;
  int local_34;
  undefined *local_30;
  undefined *puStack_2c;
  uint local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  
  iVar7 = 0xc;
  do {
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  LOCK();
  UNLOCK();
  local_20 = (undefined1 *)0x46e9e8;
  FUN_00404300((int)&local_34,(int)&DAT_0046e6ac);
  local_24 = &LAB_0046ecca;
  local_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (uint)&local_28;
  puStack_2c = (undefined *)0x46e9fd;
  local_20 = &stack0xfffffffc;
  FUN_0046e7e8(param_1);
  iVar1 = *(int *)PTR_DAT_0047c9ac;
  puStack_2c = (undefined *)0x46ea1b;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_3c);
  puStack_2c = (undefined *)0x46ea26;
  FUN_004081c4(local_3c,(int *)&local_38);
  puStack_2c = (undefined *)0x46ea33;
  FUN_00403dd8((int *)&local_38,(undefined4 *)"game.ini");
  puStack_2c = (undefined *)0x46ea42;
  piVar4 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_38);
  puStack_2c = (undefined *)0x46ea54;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_44);
  puStack_2c = (undefined *)0x46ea5f;
  FUN_004081c4(local_44,(int *)&local_40);
  puStack_2c = (undefined *)0x46ea6c;
  FUN_00403dd8((int *)&local_40,(undefined4 *)"race.ini");
  puStack_2c = (undefined *)0x46ea7b;
  piVar5 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_40);
  puStack_2c = (undefined *)0x46ea85;
  FUN_0046edd0();
  iVar7 = 0;
  puStack_2c = (undefined *)(iVar1 + 1);
  local_30 = (undefined *)0x46eaa1;
  (**(code **)(*piVar5 + 0xc))(piVar5,"CHARDATA","count");
  local_34 = 0x46eab4;
  local_30 = (undefined *)0x0;
  (**(code **)(*piVar5 + 0xc))(piVar5,"RACETYPEINFO","RaceType");
  local_38 = (undefined4 *)0x46eaca;
  local_34 = iVar1;
  (**(code **)(*piVar5 + 0xc))(piVar5,"RACETYPEINFO","opponents");
  local_38 = (undefined4 *)(uint)param_2;
  local_3c = (undefined *)0x46eae2;
  (**(code **)(*piVar5 + 0xc))(piVar5,"ETAPPE","etappe");
  if ((3 < iVar1) || (iVar1 == 1)) {
    local_3c = (undefined *)0x46eafb;
    FUN_0046efa8(param_1,CONCAT31((int3)((uint)extraout_EDX >> 8),param_2),(int)&local_34);
    local_3c = local_30;
    local_40 = (undefined4 *)&DAT_0046ed8c;
    local_44 = puStack_2c;
    local_48 = &DAT_0046ed8c;
    local_4c = (undefined1 *)0x46eb16;
    FUN_00407f60(local_28,(int *)&local_48);
    local_4c = local_48;
    local_50 = &DAT_0046ed8c;
    local_54 = (undefined1 *)0x46eb29;
    FUN_00407f60(local_24,(int *)&local_4c);
    local_54 = local_4c;
    local_58 = (undefined1 *)0x46eb39;
    FUN_00403e90((int *)&local_20,7);
    local_58 = local_20;
    local_5c = 0x46eb48;
    FUN_00407f60(0,(int *)&local_50);
    local_5c = 0x46eb58;
    (**(code **)(*piVar5 + 4))(piVar5,"CHARDATA",local_50);
    iVar7 = 1;
  }
  local_3c = (undefined *)0x46eb62;
  iVar6 = FUN_0046ef14(param_1);
  if (iVar6 < 0) {
    local_3c = (undefined *)0x46eb75;
    FUN_0044c75c((uint *)"SaveToFile: unable to find playerindex - setting to 0");
    iVar6 = 0;
  }
  iVar8 = 0;
  do {
    if (iVar1 <= iVar7) break;
    local_3c = (undefined *)0x46eb96;
    cVar3 = FUN_0046e74c(param_1,*(byte **)(param_1 + 8 + iVar8 * 0x14));
    bVar9 = cVar3 == '\0';
    if (!bVar9) {
      local_3c = (undefined *)0x46ebad;
      FUN_00403ee0(*(uint **)(param_1 + 8 + iVar8 * 0x14),*(uint **)(param_1 + 8 + iVar6 * 0x14));
      if (!bVar9) {
        local_3c = *(undefined **)(param_1 + 8 + iVar8 * 0x14);
        local_40 = (undefined4 *)&DAT_0046ed8c;
        local_44 = *(undefined **)(param_1 + 0xc + iVar8 * 0x14);
        local_48 = &DAT_0046ed8c;
        local_4c = (undefined1 *)0x46ebcd;
        FUN_00407f60(*(undefined4 *)(param_1 + 0x10 + iVar8 * 0x14),(int *)&local_54);
        local_4c = local_54;
        local_50 = &DAT_0046ed8c;
        local_54 = (undefined1 *)0x46ebe1;
        FUN_00407f60(*(undefined4 *)(param_1 + 0x14 + iVar8 * 0x14),(int *)&local_58);
        local_54 = local_58;
        local_58 = (undefined1 *)0x46ebf1;
        FUN_00403e90((int *)&local_20,7);
        local_58 = local_20;
        local_5c = 0x46ec00;
        FUN_00407f60(iVar7,&local_5c);
        iVar2 = local_5c;
        local_5c = 0x46ec10;
        (**(code **)(*piVar5 + 4))(piVar5,"CHARDATA",iVar2);
        iVar7 = iVar7 + 1;
      }
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 10);
  if (-1 < iVar6) {
    local_3c = *(undefined **)(param_1 + 8 + iVar6 * 0x14);
    local_40 = (undefined4 *)&DAT_0046ed8c;
    local_44 = *(undefined **)(param_1 + 0xc + iVar6 * 0x14);
    local_48 = &DAT_0046ed8c;
    local_4c = (undefined1 *)0x46ec46;
    FUN_00407f60(0xffffffff,(int *)&local_60);
    local_4c = local_60;
    local_50 = &DAT_0046ed8c;
    local_54 = (undefined1 *)0x46ec5a;
    FUN_00407f60(*(undefined4 *)(param_1 + 0x14 + iVar6 * 0x14),(int *)&local_64);
    local_54 = local_64;
    local_58 = (undefined1 *)0x46ec6a;
    FUN_00403e90((int *)&local_20,7);
    local_58 = local_20;
    local_5c = 0x46ec79;
    FUN_00407f60(iVar7,&local_68);
    local_5c = 0x46ec89;
    (**(code **)(*piVar5 + 4))(piVar5,"CHARDATA",local_68);
  }
  local_3c = (undefined *)0x46ec91;
  FUN_00402eac(piVar4);
  local_3c = (undefined *)0x46ec99;
  FUN_00402eac(piVar5);
  *in_FS_OFFSET = (uint)local_38;
  local_30 = &LAB_0046ecd1;
  local_34 = 0x46ecb3;
  FUN_00403b74(&local_68,0xd);
  local_34 = 0x46ecc1;
  FUN_004043cc((int)&local_34,(int)&DAT_0046e6ac);
  local_34 = 0x46ecc9;
  FUN_00403b50((int *)&local_20);
  return;
}

