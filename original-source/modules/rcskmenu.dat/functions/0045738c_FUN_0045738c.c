/*
 * FUN_0045738c at 0045738c
 * undefined FUN_0045738c(void)
 * Address ranges: 0045738c-00457432
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045738c(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 **ppuVar2;
  undefined4 uVar3;
  undefined4 uStack_30;
  undefined *puStack_2c;
  undefined1 *puStack_28;
  int iStack_18;
  undefined4 *puStack_14;
  int *piStack_10;
  undefined4 *puStack_c;
  int iStack_8;
  
  iStack_18 = 0;
  puStack_14 = (undefined4 *)0x0;
  puStack_28 = (undefined1 *)0x4573ab;
  puStack_c = param_2;
  iStack_8 = param_1;
  FUN_00403f84((int)param_2);
  puStack_2c = &UNK_00457433;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  piStack_10 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',puStack_c);
  uVar1 = 0;
  do {
    uVar3 = 0;
    ppuVar2 = &puStack_14;
    FUN_00407f60(uVar1 & 0x7f,&iStack_18);
    (**(code **)*piStack_10)(piStack_10,"GENERIC_SAMPLES",iStack_18,ppuVar2,uVar3);
    FUN_00403ba4((int *)(iStack_8 + 4 + (uVar1 & 0x7f) * 4),puStack_14);
    uVar1 = uVar1 + 1;
  } while ((char)uVar1 != 'o');
  FUN_00402eac(piStack_10);
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &UNK_0045743a;
  puStack_2c = (undefined *)0x45742a;
  FUN_00403b74(&iStack_18,2);
  puStack_2c = (undefined *)0x457432;
  FUN_00403b50((int *)&puStack_c);
  return;
}

