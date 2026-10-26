/*
 * FUN_00473ddc at 00473ddc
 * undefined __register FUN_00473ddc(void)
 * Address ranges: 00473ddc-00473f0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473ddc(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_ECX;
  byte bVar4;
  int unaff_EBX;
  int *piVar5;
  undefined4 *unaff_EDI;
  int *in_FS_OFFSET;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 *local_2c;
  undefined4 *local_28;
  int local_24;
  undefined1 *local_20;
  undefined4 *local_1c;
  int *piVar8;
  
  local_1c = (undefined4 *)&stack0xfffffffc;
  iVar3 = 5;
  do {
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_20 = &LAB_00473f0b;
  local_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_24;
  local_28 = (undefined4 *)0x473e0b;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_20);
  local_28 = (undefined4 *)0x473e16;
  FUN_004081c4(local_20,(int *)&local_1c);
  local_28 = local_1c;
  local_2c = (undefined4 *)&DAT_00473f24;
  FUN_00403e90((int *)&stack0xffffffe8,3);
  piVar1 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_EDI);
  piVar2 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  bVar4 = 0;
  piVar5 = (int *)&DAT_0047e44c;
  piVar8 = (int *)&DAT_0047e45c;
  do {
    uVar7 = 0;
    puVar6 = &stack0xfffffff0;
    FUN_00407f60((uint)bVar4,&local_24);
    (**(code **)*piVar1)(piVar1,"CHARPICS",local_24,puVar6,uVar7);
    if (unaff_EBX != 0) {
      FUN_00454510((int)piVar2,unaff_EBX);
      FUN_0045471c((int)piVar2,1,(int *)&local_28);
      FUN_00403ba4(piVar5,local_28);
      FUN_0045471c((int)piVar2,2,(int *)&local_2c);
      FUN_00403ba4(piVar8,local_2c);
    }
    bVar4 = bVar4 + 1;
    piVar8 = piVar8 + 1;
    piVar5 = piVar5 + 1;
  } while (bVar4 != 4);
  FUN_00402eac(piVar1);
  FUN_00402eac(piVar2);
  *in_FS_OFFSET = (int)"shellimg.dat";
  local_28 = (undefined4 *)&LAB_00473f12;
  local_2c = (undefined4 *)0x473f02;
  FUN_00403b74((int *)&local_2c,6);
  local_2c = (undefined4 *)0x473f0a;
  FUN_00403b50((int *)&stack0xfffffff0);
  return;
}

