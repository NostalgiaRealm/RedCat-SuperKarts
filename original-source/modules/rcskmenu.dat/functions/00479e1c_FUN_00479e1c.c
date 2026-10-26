/*
 * FUN_00479e1c at 00479e1c
 * undefined __register FUN_00479e1c(void)
 * Address ranges: 00479e1c-00479ef7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00479e1c(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  int local_18;
  int local_14;
  undefined *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined *)0x0;
  local_14 = 0;
  local_18 = 0;
  puStack_28 = &LAB_00479ef8;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_10);
  FUN_004081c4(local_10,(int *)&local_c);
  FUN_00403dd8((int *)&local_c,(undefined4 *)"game.ini");
  piVar2 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_c);
  cVar1 = (**(code **)(*piVar2 + 8))(piVar2,"HELPDESK","COMPLETE_SHELL");
  FUN_00402eac(piVar2);
  if (cVar1 != '\x01') {
    FUN_00403be8((int *)&local_8,0x479f50);
    FUN_0045c7cc(local_8,&local_14);
    iVar3 = FUN_00403dd0(local_14);
    if (iVar3 < 1) {
      FUN_0044c75c((uint *)"Stop de Redcat SuperKarts spel CD in je CD-ROM-speler.");
      FUN_0045c7cc(local_8,&local_18);
      FUN_00403dd0(local_18);
    }
  }
  *in_FS_OFFSET = 0;
  puStack_28 = &LAB_00479eff;
  uStack_2c = 0x479ef7;
  FUN_00403b74(&local_18,5);
  return;
}

