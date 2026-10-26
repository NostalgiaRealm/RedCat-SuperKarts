/*
 * FUN_00457518 at 00457518
 * undefined __register FUN_00457518(int param_1, byte param_2)
 * Address ranges: 00457518-004575d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457518(int param_1,byte param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  char *pcVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined3 uStack_8;
  byte local_5;
  
  puStack_20 = &stack0xfffffffc;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  uStack_8 = 0;
  puStack_24 = &LAB_004575d8;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  uVar5 = *(undefined4 *)PTR_DAT_0047c694;
  puVar4 = &DAT_004575f0;
  pcVar3 = "soundset.dat";
  local_5 = param_2;
  FUN_00403e90((int *)&local_10,3);
  piVar2 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_10);
  (**(code **)*piVar2)
            (piVar2,"SOUNDSETS",(&PTR_s_REDCAT_0047c0a4)[local_5],&local_c,0,pcVar3,puVar4,uVar5);
  puVar1 = local_c;
  FUN_00403e90((int *)&local_c,3);
  if (local_c != (undefined4 *)0x0) {
    FUN_00457298(*(int *)(param_1 + 4 + (uint)local_5 * 4),local_c);
  }
  FUN_00402eac(piVar2);
  *in_FS_OFFSET = puVar1;
  FUN_00403b74((int *)&local_10,2);
  return;
}

