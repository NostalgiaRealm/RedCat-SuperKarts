/*
 * FUN_00457298 at 00457298
 * undefined __register FUN_00457298(int param_1, undefined4 * param_2)
 * Address ranges: 00457298-0045733e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457298(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 **ppuVar2;
  undefined4 uVar3;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int local_18;
  undefined4 *local_14;
  int *local_10;
  undefined4 *local_c;
  int local_8;
  
  local_18 = 0;
  local_14 = (undefined4 *)0x0;
  puStack_28 = (undefined1 *)0x4572b7;
  local_c = param_2;
  local_8 = param_1;
  FUN_00403f84((int)param_2);
  puStack_2c = &LAB_0045733f;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  local_10 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_c);
  uVar1 = 0;
  do {
    uVar3 = 0;
    ppuVar2 = &local_14;
    FUN_00407f60(uVar1 & 0x7f,&local_18);
    (**(code **)*local_10)(local_10,"SAMPLE_SET",local_18,ppuVar2,uVar3);
    FUN_00403ba4((int *)(local_8 + 4 + (uVar1 & 0x7f) * 4),local_14);
    uVar1 = uVar1 + 1;
  } while ((char)uVar1 != 'I');
  FUN_00402eac(local_10);
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_00457346;
  puStack_2c = (undefined1 *)0x457336;
  FUN_00403b74(&local_18,2);
  puStack_2c = (undefined1 *)0x45733e;
  FUN_00403b50((int *)&local_c);
  return;
}

