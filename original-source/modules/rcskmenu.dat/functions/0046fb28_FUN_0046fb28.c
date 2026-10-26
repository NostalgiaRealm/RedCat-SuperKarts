/*
 * FUN_0046fb28 at 0046fb28
 * undefined __register FUN_0046fb28(void)
 * Address ranges: 0046fb28-0046fc6a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046fb28(void)

{
  undefined4 extraout_ECX;
  int *piVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  undefined4 *unaff_EDI;
  undefined4 *in_FS_OFFSET;
  char *pcVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  char cVar6;
  int local_10;
  int *local_c;
  int *local_8;
  
  local_20 = (undefined4 *)&stack0xfffffffc;
  local_10 = 4;
  do {
    local_8 = (int *)0x0;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  local_24 = (undefined4 *)&LAB_0046fc6b;
  local_28 = (undefined4 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &local_28;
  uVar5 = *(undefined4 *)PTR_DAT_0047c694;
  puVar4 = &DAT_0046fc84;
  pcVar3 = "shellimg.dat";
  FUN_00403e90((int *)&stack0xffffffe8,3);
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_ESI);
  local_c = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  cVar6 = '\x06';
  piVar1 = (int *)&DAT_0047e240;
  puVar2 = (undefined4 *)PTR_PTR_0047c804;
  do {
    (**(code **)*local_8)(local_8,"COUNTRYPICS",*puVar2,&local_10,0,pcVar3,puVar4,uVar5);
    if (local_10 != 0) {
      FUN_00454510((int)local_c,local_10);
      FUN_0045471c((int)local_c,0,(int *)&stack0xffffffe4);
      FUN_00403ba4(piVar1,unaff_EDI);
      FUN_0045471c((int)local_c,1,(int *)&local_20);
      FUN_00403ba4(piVar1 + 1,local_20);
      FUN_0045471c((int)local_c,2,(int *)&local_24);
      FUN_00403ba4(piVar1 + 2,local_24);
      FUN_0045471c((int)local_c,3,(int *)&local_28);
      FUN_00403ba4(piVar1 + 3,local_28);
    }
    piVar1 = piVar1 + 4;
    puVar2 = puVar2 + 1;
    cVar6 = cVar6 + -1;
  } while (cVar6 != '\0');
  FUN_00402eac(local_8);
  FUN_00402eac(local_c);
  *in_FS_OFFSET = pcVar3;
  FUN_00403b74((int *)&local_28,5);
  FUN_00403b50(&local_10);
  return;
}

