/*
 * FUN_00476a1c at 00476a1c
 * undefined __register FUN_00476a1c(void)
 * Address ranges: 00476a1c-00476ad8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00476a1c(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  char *pcVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 *local_1c;
  undefined *local_18;
  int local_14;
  undefined4 *local_10;
  undefined4 uStack_c;
  int *local_8;
  
  puStack_2c = &stack0xfffffffc;
  local_8 = (int *)0x0;
  uStack_c = 0;
  local_10 = (undefined4 *)0x0;
  local_14 = 0;
  local_18 = (undefined *)0x0;
  local_1c = (undefined4 *)0x0;
  puStack_30 = &LAB_00476ad9;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_18);
  FUN_004081c4(local_18,&local_14);
  puVar4 = &DAT_00476af0;
  pcVar3 = "shellimg.dat";
  iVar5 = local_14;
  FUN_00403e90((int *)&local_10,3);
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_10);
  uStack_c._3_1_ = '\n';
  piVar2 = (int *)&DAT_0047e524;
  puVar1 = (undefined4 *)PTR_PTR_0047c8b4;
  do {
    (**(code **)*local_8)(local_8,"HIGHSCOREPICS",*puVar1,&local_1c,0,pcVar3,puVar4,iVar5);
    FUN_00403ba4(piVar2,local_1c);
    piVar2 = piVar2 + 1;
    puVar1 = puVar1 + 1;
    uStack_c._3_1_ = uStack_c._3_1_ + -1;
  } while (uStack_c._3_1_ != '\0');
  FUN_00402eac(local_8);
  *in_FS_OFFSET = pcVar3;
  FUN_00403b74((int *)&local_1c,4);
  return;
}

