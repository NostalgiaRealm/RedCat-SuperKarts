/*
 * FUN_00476b28 at 00476b28
 * undefined __register FUN_00476b28(void)
 * Address ranges: 00476b28-00476c80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00476b28(void)

{
  undefined4 extraout_ECX;
  int *piVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  undefined4 *unaff_EDI;
  undefined4 *in_FS_OFFSET;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined *local_20;
  char cVar3;
  int local_10;
  int *local_c;
  int *local_8;
  
  local_20 = &stack0xfffffffc;
  local_10 = 5;
  do {
    local_8 = (int *)0x0;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  local_24 = (undefined4 *)&LAB_00476c81;
  local_28 = (undefined4 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &local_28;
  local_2c = (undefined4 *)0x476b58;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_20);
  local_2c = (undefined4 *)0x476b63;
  FUN_004081c4(local_20,(int *)&stack0xffffffe4);
  local_30 = (undefined4 *)&DAT_00476c98;
  local_2c = unaff_EDI;
  FUN_00403e90((int *)&stack0xffffffe8,3);
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_ESI);
  local_c = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  cVar3 = '\x06';
  piVar1 = (int *)&DAT_0047e4c4;
  puVar2 = (undefined4 *)PTR_PTR_0047c804;
  do {
    (**(code **)*local_8)(local_8,"COUNTRYPICS",*puVar2,&local_10,0);
    if (local_10 != 0) {
      FUN_00454510((int)local_c,local_10);
      FUN_0045471c((int)local_c,0,(int *)&local_24);
      FUN_00403ba4(piVar1,local_24);
      FUN_0045471c((int)local_c,1,(int *)&local_28);
      FUN_00403ba4(piVar1 + 1,local_28);
      FUN_0045471c((int)local_c,2,(int *)&local_2c);
      FUN_00403ba4(piVar1 + 2,local_2c);
      FUN_0045471c((int)local_c,3,(int *)&local_30);
      FUN_00403ba4(piVar1 + 3,local_30);
    }
    piVar1 = piVar1 + 4;
    puVar2 = puVar2 + 1;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  FUN_00402eac(local_8);
  FUN_00402eac(local_c);
  *in_FS_OFFSET = "shellimg.dat";
  local_2c = (undefined4 *)&LAB_00476c88;
  local_30 = (undefined4 *)0x476c78;
  FUN_00403b74((int *)&local_30,7);
  local_30 = (undefined4 *)0x476c80;
  FUN_00403b50(&local_10);
  return;
}

