/*
 * FUN_0045ae70 at 0045ae70
 * undefined FUN_0045ae70(void)
 * Address ranges: 0045ae70-0045b130
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045ae70(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *unaff_EBX;
  undefined4 *unaff_ESI;
  undefined *unaff_EDI;
  undefined4 *in_FS_OFFSET;
  char *pcVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puStack_28;
  undefined *puStack_24;
  undefined4 *puStack_20;
  undefined *puStack_10;
  undefined4 *puStack_c;
  uint uStack_8;
  
  puStack_20 = (undefined4 *)&stack0xfffffffc;
  puStack_10 = (undefined *)0x4;
  do {
    uStack_8 = 0;
    puStack_10 = puStack_10 + -1;
  } while (puStack_10 != (undefined *)0x0);
  puStack_24 = &UNK_0045b131;
  puStack_28 = (undefined *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_28;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&puStack_10);
  FUN_004081c4(puStack_10,(int *)&puStack_c);
  FUN_00403dd8((int *)&puStack_c,(undefined4 *)"game.ini");
  piVar3 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',puStack_c);
  uStack_8 = (**(code **)(*piVar3 + 8))(piVar3,"PROGRAM","resolution",3);
  uVar4 = (**(code **)(*piVar3 + 8))(piVar3,"OPTIONS","FILTER",1);
  iVar5 = (int)uVar4 >> 1;
  if (iVar5 < 0) {
    iVar5 = iVar5 + (uint)((uVar4 & 1) != 0);
  }
  *(char *)(param_1 + 0x34) = (char)iVar5;
  uVar1 = (**(code **)(*piVar3 + 8))(piVar3,"OPTIONS",&UNK_0045b1a4,0);
  *(undefined1 *)(param_1 + 0x40) = uVar1;
  if (5 < uStack_8) {
    uStack_8 = 0;
  }
  *(undefined1 *)(param_1 + 5) = (undefined1)uStack_8;
  FUN_00402eac(piVar3);
  FUN_00403e1c((int *)&stack0xffffffec,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)&UNK_0045b1b4)
  ;
  piVar3 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_EBX);
  uVar6 = (**(code **)(*piVar3 + 8))(piVar3,"GFX OPTIONS","focus",0);
  *(undefined4 *)(param_1 + 0x3c) = uVar6;
  uVar6 = (**(code **)(*piVar3 + 8))(piVar3,"GFX OPTIONS","gamma",0);
  *(undefined4 *)(param_1 + 0x30) = uVar6;
  uVar6 = (**(code **)(*piVar3 + 8))(piVar3,"GFX OPTIONS","alpha_blending",2);
  *(undefined4 *)(param_1 + 0x38) = uVar6;
  bVar2 = (**(code **)(*piVar3 + 8))(piVar3,"GFX OPTIONS","particles",1);
  *(byte *)(param_1 + 0x41) = bVar2 ^ 1;
  FUN_00402eac(piVar3);
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&stack0xffffffe4);
  FUN_004081c4(unaff_EDI,(int *)&stack0xffffffe8);
  FUN_00403dd8((int *)&stack0xffffffe8,(undefined4 *)"race.ini");
  piVar3 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_ESI);
  uVar4 = (**(code **)(*piVar3 + 8))(piVar3,"GAME_SETTINGS","control",0);
  if (2 < uVar4) {
    uVar4 = 0;
  }
  *(char *)(param_1 + 4) = (char)uVar4;
  iVar5 = (**(code **)(*piVar3 + 8))(piVar3,"GAME_SETTINGS","FX_VOLUME",0);
  FUN_0045bb6c(param_1,iVar5);
  iVar5 = (**(code **)(*piVar3 + 8))(piVar3,"GAME_SETTINGS","MX_VOLUME",0);
  FUN_0045bb8c(param_1,iVar5);
  FUN_00402eac(piVar3);
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&puStack_28);
  FUN_004081c4(puStack_28,(int *)&puStack_24);
  puVar8 = &UNK_0045b28c;
  pcVar7 = "settings.ini";
  puVar9 = puStack_24;
  FUN_00403e90((int *)&puStack_20,3);
  piVar3 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',puStack_20);
  uVar4 = (**(code **)(*piVar3 + 8))(piVar3,"settings","rendermode",1,pcVar7,puVar8,puVar9);
  if (1 < uVar4) {
    uVar4 = 0;
  }
  *(char *)(param_1 + 6) = (char)uVar4;
  uVar1 = (**(code **)(*piVar3 + 8))(piVar3,"shell","shellstate",0);
  FUN_0045bbac(param_1,uVar1);
  uVar6 = (**(code **)(*piVar3 + 8))(piVar3,"shell","lastplayer",0);
  *(undefined4 *)(param_1 + 0x14) = uVar6;
  uVar1 = (**(code **)(*piVar3 + 8))(piVar3,"shell","startinfo",1);
  *(undefined1 *)(param_1 + 0x18) = uVar1;
  uVar1 = (**(code **)(*piVar3 + 8))(piVar3,"shell","firsttime");
  *(undefined1 *)(param_1 + 0x19) = uVar1;
  FUN_00402eac(piVar3);
  *in_FS_OFFSET = 1;
  FUN_00403b74((int *)&puStack_28,8);
  return;
}

