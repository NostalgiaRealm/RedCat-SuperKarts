/*
 * FUN_00452624 at 00452624
 * undefined __register FUN_00452624(int * param_1, int param_2, int param_3, int param_4)
 * Address ranges: 00452624-004526cc;004526e4-004526f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452624(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar2;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  if (((((param_2 != param_1[0x23]) || (param_3 != param_1[0x10])) || (param_1[0xf] != param_4)) ||
      ((param_1[0x12] != param_1[0x125] || (param_1[0x13] != param_1[0x126])))) ||
     (param_1[0x14] != param_1[0x127])) {
    if ((param_2 < 1) || (param_3 < 1)) {
      puStack_18 = (undefined1 *)0x45267a;
      FUN_00451c90(param_1,param_2,param_3);
    }
    else {
      puStack_18 = (undefined1 *)0x452688;
      piVar1 = FUN_004507f8((int *)&PTR_FUN_004501d8,'\x01',param_3);
      puStack_1c = &LAB_004526cd;
      uStack_20 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_20;
      uVar2 = 0;
      puStack_18 = &stack0xfffffffc;
      FUN_004508a8(piVar1,param_2,param_3,'\0',*(char *)(param_1[9] + 0x42c),param_1 + 0x25,
                   param_1 + 0x125,param_4);
      *in_FS_OFFSET = uVar2;
      FUN_004524e4((int)param_1,(int)piVar1);
      *(undefined1 *)((int)param_1 + 0x1a) = 1;
    }
  }
  return;
}

