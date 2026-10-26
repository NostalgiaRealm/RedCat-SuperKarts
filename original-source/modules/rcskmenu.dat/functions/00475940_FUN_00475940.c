/*
 * FUN_00475940 at 00475940
 * undefined __register FUN_00475940(void)
 * Address ranges: 00475940-00475a5c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475940(void)

{
  undefined4 extraout_ECX;
  byte bVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 *local_24;
  undefined4 *local_20;
  int local_1c;
  undefined4 *local_18;
  int *local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  puStack_34 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = 0;
  local_14 = (int *)0x0;
  local_18 = (undefined4 *)0x0;
  local_1c = 0;
  local_20 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  puStack_38 = &LAB_00475a5d;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  FUN_00403e90((int *)&local_18,3);
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_18);
  local_c = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  bVar1 = 0;
  piVar2 = (int *)&DAT_0047e478;
  local_14 = (int *)&DAT_0047e488;
  do {
    uVar4 = 0;
    piVar3 = &local_10;
    FUN_00407f60((uint)bVar1,&local_1c);
    (**(code **)*local_8)(local_8,"CHARPICS",local_1c,piVar3,uVar4);
    if (local_10 != 0) {
      FUN_00454510((int)local_c,local_10);
      FUN_0045471c((int)local_c,1,(int *)&local_20);
      FUN_00403ba4(piVar2,local_20);
      FUN_0045471c((int)local_c,2,(int *)&local_24);
      FUN_00403ba4(local_14,local_24);
    }
    bVar1 = bVar1 + 1;
    local_14 = local_14 + 1;
    piVar2 = piVar2 + 1;
  } while (bVar1 != 4);
  FUN_00402eac(local_8);
  if (local_c != (int *)0x0) {
    FUN_00402eac(local_c);
  }
  *in_FS_OFFSET = "shellimg.dat";
  FUN_00403b74((int *)&local_24,4);
  FUN_00403b50(&local_10);
  return;
}

