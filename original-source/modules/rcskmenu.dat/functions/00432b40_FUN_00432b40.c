/*
 * FUN_00432b40 at 00432b40
 * undefined __register FUN_00432b40(int * param_1, uint * param_2)
 * Address ranges: 00432b40-00432bc4;00432bcc-00432bd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432b40(int *param_1,uint *param_2)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined1 in_ZF;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x432b54;
  FUN_00403ee0((uint *)param_1[0x11],param_2);
  if (!(bool)in_ZF) {
    puStack_14 = (undefined1 *)0x432b60;
    FUN_00403ba4(param_1 + 0x11,param_2);
    if (*(short *)((int)param_1 + 0xd2) == 0) {
      puStack_14 = (undefined1 *)0x432b88;
      piVar1 = FUN_00425ed0((int *)&PTR_FUN_00425e34,'\x01',param_1);
      puStack_14 = (undefined1 *)0x432b95;
      FUN_00426b30(piVar1,param_2);
      puStack_18 = &LAB_00432bc5;
      uStack_1c = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_1c;
      puStack_14 = &stack0xfffffffc;
      FUN_00403088(piVar1,extraout_EDX,extraout_ECX);
      *in_FS_OFFSET = uStack_1c;
      puStack_14 = (undefined1 *)0x432bcc;
      puStack_18 = (undefined1 *)0x432bc4;
      FUN_00402eac(piVar1);
      return;
    }
    puStack_14 = (undefined1 *)0x432b78;
    (*(code *)param_1[0x34])(param_1[0x35],param_1);
  }
  return;
}

